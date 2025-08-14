import typing
import omni
import numpy as np
from pxr import Gf, UsdGeom, Sdf, Usd

# try to import rclpy and message types for subscribing to external pose topics
try:
    import rclpy
    from rclpy.qos import QoSProfile
    from people_msgs.msg import People
    from nav_msgs.msg import Odometry
except Exception:
    rclpy = None
    People = None
    Odometry = None
    QoSProfile = None

# Prefer rclpy logger when available so messages appear in ros2/launch logs; fallback to print
try:
    from rclpy.logging import get_logger
    _LOGGER = get_logger('isaac_door_manager')
except Exception:
    _LOGGER = None


def _log_debug(msg: str):
    try:
        if _LOGGER:
            _LOGGER.debug(msg)
            return
    except Exception:
        pass
    print(msg)


def _log_info(msg: str):
    try:
        if _LOGGER:
            _LOGGER.info(msg)
            return
    except Exception:
        pass
    print(msg)


def _log_warn(msg: str):
    try:
        if _LOGGER:
            _LOGGER.warn(msg)
            return
    except Exception:
        pass
    print(msg)


def _log_error(msg: str):
    try:
        if _LOGGER:
            _LOGGER.error(msg)
            return
    except Exception:
        pass
    print(msg)


class DoorManager:
    def __init__(self):
        self._doors = {}
        self._robots = []
        self._pedestrians = []
        self._door_open_distance = 3.0  # meters

        # Controller node (set by register_node)
        self._controller = None
        # Cached entity poses published over ROS topics: prim_path -> np.array([x,y,z])
        self._entity_poses: dict[str, np.ndarray] = {}
        # robot subscriptions by registered prim path
        self._robot_subs: dict[str, object] = {}
        # Dirty flag to trigger distance computation only when needed
        self._dirty = False

    def register_node(self, controller):
        """Attach rclpy subscriptions to the provided controller node so DoorManager
        receives live poses for pedestrians and robots published by the task_generator.
        """
        try:
            self._controller = controller
            # subscribe to people topic if available
            # Pedestrian/topic-based pose updates are disabled for now. Keep code
            # around for later – currently we only use robot odometry for door logic.
            if People is not None:
                _log_debug('people_msgs available but pedestrian subscriptions are disabled in this build')
            else:
                _log_debug('people_msgs not available; pedestrian subscriptions skipped')

            # ensure robot subscriptions for already-registered robots
            for prim_path in list(self._robots):
                try:
                    self._ensure_robot_subscription(prim_path)
                except Exception as e:
                    _log_warn(f'Failed to ensure robot subscription for {prim_path}: {e}')
        except Exception as e:
            # Catch any unexpected errors during registration to avoid crashing the IsaacSim process
            _log_error(f'register_node failed: {e}')
            # leave controller unset on failure
            self._controller = None

    def _ensure_robot_subscription(self, prim_path: str):
        if self._controller is None:
            return
        if prim_path in self._robot_subs:
            return
        # derive robot name from prim path: /World/<robot_name>/...
        try:
            parts = prim_path.split('/')
            if len(parts) >= 3 and parts[1] == 'World':
                robot_name = parts[2]
                topic = f'/task_generator_node/{robot_name}/odom'
                if Odometry is not None:
                    try:
                        qos_depth = 10
                        # ensure controller exposes create_subscription before calling
                        if hasattr(self._controller, 'create_subscription'):
                            sub = self._controller.create_subscription(Odometry, topic, lambda msg, rp=prim_path: self._odom_cb(msg, rp), qos_depth)
                            self._robot_subs[prim_path] = sub
                            _log_info(f'Subscribed to {topic} for robot {robot_name}')
                        else:
                            _log_warn('Controller does not support create_subscription; skipping robot subscription')
                    except Exception as e:
                        _log_warn(f'Failed to subscribe to {topic}: {e}')
                else:
                    _log_warn('nav_msgs/Odometry type not available; robot odom not subscribed')
            else:
                _log_warn(f'Could not derive robot name from prim path: {prim_path}')
        except Exception:
            pass

    def _odom_cb(self, msg, prim_path: str):
        try:
            pose = getattr(msg, 'pose', None)
            if pose is None:
                return
            pb = getattr(pose, 'pose', pose)  # handle Odometry vs nested
            pos = getattr(pb, 'position', None)
            if pos is None:
                return
            self._entity_poses[prim_path] = np.array([pos.x, pos.y, pos.z])
            # mark dirty so update() will compute distances on next tick
            self._dirty = True
        except Exception as e:
            _log_debug(f'odom_cb error: {e}')

    def _people_cb(self, msg):
        try:
            people = getattr(msg, 'people', None)
            if people is None:
                return
            for p in people:
                # try several common field names
                stage_prefix = getattr(p, 'stage_prefix', None) or getattr(p, 'name', None) or getattr(p, 'id', None)
                # get pose
                pose = getattr(p, 'pose', None) or getattr(p, 'position', None)
                if pose is None:
                    continue
                pb = getattr(pose, 'position', None) or getattr(pose, 'pose', None) or pose
                if pb is None:
                    continue
                x = getattr(pb, 'x', None) or getattr(pb, 'x', 0.0)
                y = getattr(pb, 'y', None) or getattr(pb, 'y', 0.0)
                z = getattr(pb, 'z', None) or getattr(pb, 'z', 0.0)
                # match to registered pedestrian prims
                if stage_prefix is not None:
                    for reg in self._pedestrians:
                        if reg.endswith('/' + str(stage_prefix)) or reg.endswith(str(stage_prefix)):
                            self._entity_poses[reg] = np.array([float(x), float(y), float(z)])
                            _log_debug(f'Updated pose for {reg} from people topic')
                else:
                    # fallback: try to update closest registered pedestrian by name similarity
                    for reg in self._pedestrians:
                        self._entity_poses[reg] = np.array([float(x), float(y), float(z)])
        except Exception as e:
            _log_debug(f'people_cb error: {e}')

    def add_door(self, prim_path: str, kind: typing.Literal['sliding'] = 'sliding'):
        stage = omni.usd.get_context().get_stage()
        prim = stage.GetPrimAtPath(prim_path)
        if prim.IsValid():
            self._doors[prim_path] = {
                "prim": prim,
                "kind": kind,
                "initial_scale": Gf.Vec3f(1, 1, 1),
                "open": False
            }
            # Store initial scale
            scale_attr = prim.GetAttribute('xformOp:scale')
            if scale_attr:
                self._doors[prim_path]["initial_scale"] = scale_attr.Get()
            else:
                # If no scale attribute exists, try to get it from the xform
                xformable = UsdGeom.Xformable(prim)
                transform = xformable.GetLocalTransformation()
                # Extract scale from transformation matrix
                scale_x = transform.GetRow(0).GetLength()
                scale_y = transform.GetRow(1).GetLength()
                scale_z = transform.GetRow(2).GetLength()
                self._doors[prim_path]["initial_scale"] = Gf.Vec3f(scale_x, scale_y, scale_z)
            _log_debug(f"Added door to door manager: {prim_path}")
        else:
            _log_warn(f"Failed to add door - invalid prim: {prim_path}")

    def reset(self):
        self._pedestrians.clear()
        # Close all doors on reset
        for door_path, door_data in self._doors.items():
            self._close_door(door_data)

    def update(self):
        stage = omni.usd.get_context().get_stage()
        # Only run distance computations when flagged dirty to avoid per-tick checks
        if not self._dirty:
            return

        entities_to_check = self._robots + self._pedestrians

        if not self._doors:
            _log_debug("No doors registered with DoorManager.")

        # Compute distances once; clear dirty flag after processing
        for door_path, door_data in self._doors.items():
            door_prim = door_data["prim"]
            if not door_prim.IsValid():
                _log_warn(f"Door prim invalid: {door_path}")
                continue

            door_pos = self._get_prim_position(door_prim)
            # Print door world position every tick
            _log_info(f"DOOR_POS: {door_path} = ({door_pos[0]:.3f}, {door_pos[1]:.3f}, {door_pos[2]:.3f})")

            # Only consider robots for now (ignore pedestrians)
            entities_to_check = list(self._robots)
            if entities_to_check:
                for entity_path in entities_to_check:
                    # prefer ROS-published pose cache if available
                    if entity_path in self._entity_poses:
                        entity_pos = self._entity_poses[entity_path]
                    else:
                        # ensure we operate on the resolved prim if possible
                        entity_prim = stage.GetPrimAtPath(entity_path)
                        if not (entity_prim and entity_prim.IsValid()):
                            # try to resolve an alternative sub-prim dynamically
                            resolved_path = self._resolve_entity_prim(entity_path)
                            entity_prim = stage.GetPrimAtPath(resolved_path)
                            if entity_prim and entity_prim.IsValid():
                                _log_debug(f"Resolved entity prim for distance checks: {entity_path} -> {resolved_path}")
                                entity_path = resolved_path
                        if not (entity_prim and entity_prim.IsValid()):
                            _log_warn(f"Entity prim invalid or missing: {entity_path}")
                            continue
                        entity_pos = self._get_prim_position(entity_prim)

                    distance = float(np.linalg.norm(door_pos - entity_pos))
                    # Always print the distance (per your request)
                    _log_info(f"DISTANCE: Door {door_path} -> Entity {entity_path} = {distance:.3f} m (open={door_data['open']})")

                    # Maintain open/close behavior based on threshold
                    if distance < self._door_open_distance:
                        if not door_data["open"]:
                            _log_info(f"Opening door {door_path} (entity within {self._door_open_distance}m)")
                            self._open_door(door_data)
                    else:
                        if door_data["open"]:
                            _log_info(f"Closing door {door_path} (no entities within {self._door_open_distance}m)")
                            self._close_door(door_data)
            else:
                # No robots registered — keep a minimal placeholder
                _log_info(f"DISTANCE: Door {door_path} -> (no robots registered)")

        # Completed computation; clear dirty so we don't repeat every tick
        self._dirty = False

    def _get_prim_position(self, prim):
        try:
            xform_cache = UsdGeom.XformCache(Usd.TimeCode.Default())
            matrix = xform_cache.GetLocalToWorldTransform(prim)
            tx = matrix[3][0]
            ty = matrix[3][1]
            tz = matrix[3][2]
            return np.array([tx, ty, tz])
        except Exception:
            xformable = UsdGeom.Xformable(prim)
            translation = xformable.GetLocalTransformation().GetRow(3)
            return np.array([translation[0], translation[1], translation[2]])

    def _open_door(self, door_data):
        if door_data["kind"] == 'sliding':
            prim = door_data["prim"]
            target_scale = Gf.Vec3f(door_data["initial_scale"][0], 0.1, door_data["initial_scale"][2])
            scale_attr = prim.GetAttribute('xformOp:scale')
            if scale_attr:
                scale_attr.Set(target_scale)
            else:
                # Create the attribute if it doesn't exist
                scale_attr = prim.CreateAttribute('xformOp:scale', Sdf.ValueTypeNames.Float3)
                scale_attr.Set(target_scale)
            door_data["open"] = True

    def _close_door(self, door_data):
        if door_data["kind"] == 'sliding':
            prim = door_data["prim"]
            scale_attr = prim.GetAttribute('xformOp:scale')
            if scale_attr:
                scale_attr.Set(door_data["initial_scale"])
            else:
                # Create the attribute if it doesn't exist
                scale_attr = prim.CreateAttribute('xformOp:scale', Sdf.ValueTypeNames.Float3)
                scale_attr.Set(door_data["initial_scale"])
            door_data["open"] = False

    def _resolve_entity_prim(self, prim_path: str) -> str:
        """Try to resolve a dynamic/moving sub-prim for a given USD prim path.
        If the given prim is valid return it, otherwise attempt common suffixes
        and a shallow child-name search. Always return a string path (fallback
        to the original prim_path).
        """
        try:
            stage = omni.usd.get_context().get_stage()
            prim = stage.GetPrimAtPath(prim_path)
            if prim and prim.IsValid():
                return prim_path

            # Common candidate suffixes for robots/actors
            candidates = [
                'base_link',
                'base_footprint',
                'base',
                'man_root',
                'ManRoot',
                'root',
                'actor',
            ]
            for c in candidates:
                p = prim_path.rstrip('/') + '/' + c
                pr = stage.GetPrimAtPath(p)
                if pr and pr.IsValid():
                    return p

            # Shallow search children for likely moving prims
            if prim and prim.IsValid():
                for child in prim.GetChildren():
                    name = child.GetName().lower()
                    if any(k in name for k in ('base', 'root', 'man', 'actor')):
                        return child.GetPath().pathString
        except Exception as e:
            _log_debug(f'_resolve_entity_prim error: {e}')
        return prim_path

    def add_robot(self, prim_path: str):
        """Register a robot prim for distance checks. Resolves to a moving
        sub-prim if possible and ensures an odom subscription is created when
        a controller node is registered.
        """
        resolved = self._resolve_entity_prim(prim_path)
        if resolved not in self._robots:
            self._robots.append(resolved)
            _log_info(f'Robot registered with DoorManager: {resolved}')
        else:
            _log_debug(f'Robot already registered: {resolved}')

        # Check whether the prim exists; warn if not found
        try:
            stage = omni.usd.get_context().get_stage()
            prim = stage.GetPrimAtPath(resolved)
            if not (prim and prim.IsValid()):
                _log_warn(f'Robot prim not found in stage: {resolved}')
        except Exception:
            pass

        try:
            self._ensure_robot_subscription(resolved)
        except Exception as e:
            _log_warn(f'Failed to ensure robot subscription on add: {e}')

        # trigger a distance check after registration
        self._dirty = True

    def add_pedestrian(self, prim_path: str):
        """Register a pedestrian prim for distance checks. Poses for
        pedestrians are primarily updated via the people topic; this method
        just records the prim path.
        """
        resolved = self._resolve_entity_prim(prim_path)
        if resolved not in self._pedestrians:
            self._pedestrians.append(resolved)
        _log_debug(f"Added pedestrian to door manager: {prim_path} -> resolved: {resolved}")
        # pedestrian handling is currently disabled
