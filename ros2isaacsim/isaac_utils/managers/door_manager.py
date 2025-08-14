import typing
import omni
import numpy as np
from pxr import Gf, UsdGeom, Sdf, Usd
import time

# try to import rclpy and message types for subscribing to external pose topics
try:
    import rclpy
    from rclpy.qos import QoSProfile
    from people_msgs.msg import People
    from nav_msgs.msg import Odometry
    from std_msgs.msg import String as StdString
except Exception:
    rclpy = None
    People = None
    Odometry = None
    QoSProfile = None
    StdString = None

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
        # Distance thresholds (meters)
        self._door_open_distance = 3.0  # open when entity is closer than this
        self._door_close_margin = 0.5   # hysteresis margin; close when farther than open_distance + margin
        # Minimum seconds between toggles for a given door to avoid rapid spam
        self._door_min_toggle_interval = 0.5

        # Controller node (set by register_node)
        self._controller = None
        # Cached entity poses published over ROS topics: prim_path -> np.array([x,y,z])
        self._entity_poses: dict[str, np.ndarray] = {}
        # robot subscriptions by registered prim path
        self._robot_subs: dict[str, object] = {}
        # control verbose per-tick logging (DOOR_POS and DISTANCE). Set to False to silence.
        self._log_every_tick = False
        # Optional list of substrings to filter per-entity logs. If set, DISTANCE
        # logs will only be printed when any substring matches entity_path.
        # Example: door_manager._log_entity_filter = ['gazebo_actor']
        # or door_manager._log_entity_filter = ['jackal']
        self._log_entity_filter: list[str] | None = None

    def register_node(self, controller):
        """Attach rclpy subscriptions to the provided controller node so DoorManager
        receives live poses for pedestrians and robots published by the task_generator.
        """
        self._controller = controller
        # subscribe to people topic if available
        if People is not None:
            try:
                qos_depth = 10
                controller.create_subscription(People, '/task_generator_node/people', self._people_cb, qos_depth)
                _log_info('Subscribed to /task_generator_node/people for pedestrian poses')
            except Exception as e:
                _log_warn(f'Failed to subscribe to people topic: {e}')
        else:
            _log_warn('people_msgs.People message type not available; pedestrian topic not subscribed')

        # Also subscribe to simple registration topic so external processes can register prims
        if StdString is not None:
            try:
                controller.create_subscription(StdString, '/isaac/register_entity', self._register_entity_cb, 10)
                _log_info('Subscribed to /isaac/register_entity for external entity registrations')
            except Exception as e:
                _log_warn(f'Failed to subscribe to /isaac/register_entity: {e}')
        else:
            _log_warn('std_msgs.String not available; registration topic not subscribed')

        # ensure robot subscriptions for already-registered robots
        for prim_path in list(self._robots):
            try:
                self._ensure_robot_subscription(prim_path)
            except Exception as e:
                _log_warn(f'Failed to ensure robot subscription for {prim_path}: {e}')

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
                        sub = self._controller.create_subscription(Odometry, topic, lambda msg, rp=prim_path: self._odom_cb(msg, rp), qos_depth)
                        self._robot_subs[prim_path] = sub
                        _log_info(f'Subscribed to {topic} for robot {robot_name}')
                    except Exception as e:
                        _log_warn(f'Failed to subscribe to {topic}: {e}')
                else:
                    _log_warn('nav_msgs/Odometry type not available; robot odom not subscribed')
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
            _log_debug(f'odom update for {prim_path}: {self._entity_poses[prim_path]}')
        except Exception as e:
            _log_debug(f'odom_cb error: {e}')

    def _people_cb(self, msg):
        try:
            _log_debug('people topic message received')
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
                "initial_translate": Gf.Vec3f(0, 0, 0),
                "open": False
                ,"last_toggle_time": 0.0
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

            # Store initial local translation if present (fallback to local xform translation)
            translate_attr = prim.GetAttribute('xformOp:translate')
            if translate_attr and translate_attr.Get() is not None:
                self._doors[prim_path]["initial_translate"] = translate_attr.Get()
            else:
                # fallback: use local xform translation (preferred over world position)
                try:
                    xformable = UsdGeom.Xformable(prim)
                    transform = xformable.GetLocalTransformation()
                    tx = transform.GetRow(3)[0]
                    ty = transform.GetRow(3)[1]
                    tz = transform.GetRow(3)[2]
                    self._doors[prim_path]["initial_translate"] = Gf.Vec3f(float(tx), float(ty), float(tz))
                except Exception:
                    wp = self._get_prim_position(prim)
                    self._doors[prim_path]["initial_translate"] = Gf.Vec3f(float(wp[0]), float(wp[1]), float(wp[2]))

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
        entities_to_check = self._robots + self._pedestrians

        if not self._doors:
            _log_debug("No doors registered with DoorManager.")

        # Always print something each tick. If there are no entities, still print door positions.
        for door_path, door_data in self._doors.items():
            door_prim = door_data["prim"]
            if not door_prim.IsValid():
                _log_warn(f"Door prim invalid: {door_path}")
                continue

            door_pos = self._get_prim_position(door_prim)
            # Optionally print door world position every tick
            if self._log_every_tick:
                _log_info(f"DOOR_POS: {door_path} = ({door_pos[0]:.3f}, {door_pos[1]:.3f}, {door_pos[2]:.3f})")

            if entities_to_check:
                # Compute positions for all entities and their distances to the door
                distances = []
                entity_positions = {}
                for entity_path in entities_to_check:
                    try:
                        if entity_path in self._entity_poses:
                            entity_pos = self._entity_poses[entity_path]
                        else:
                            entity_prim = stage.GetPrimAtPath(entity_path)
                            if not (entity_prim and entity_prim.IsValid()):
                                resolved_path = self._resolve_entity_prim(entity_path)
                                entity_prim = stage.GetPrimAtPath(resolved_path)
                                if entity_prim and entity_prim.IsValid():
                                    _log_debug(f"Resolved entity prim for distance checks: {entity_path} -> {resolved_path}")
                                    entity_path = resolved_path
                        if not (entity_prim and entity_prim.IsValid()):
                            _log_warn(f"Entity prim invalid or missing: {entity_path}")
                            continue
                        entity_pos = self._get_prim_position(entity_prim)
                        dist = float(np.linalg.norm(door_pos - entity_pos))
                        distances.append((dist, entity_path))
                        entity_positions[entity_path] = entity_pos
                    except Exception as e:
                        _log_debug(f'Error computing distance for {entity_path}: {e}')

                if not distances:
                    if self._log_every_tick:
                        _log_info(f"DISTANCE: Door {door_path} -> (no valid entities found)")
                    continue

                # Use the minimum distance across all entities to decide open/close
                distances.sort(key=lambda x: x[0])
                min_distance, closest_entity = distances[0]

                # Optionally print per-entity distance for the closest entity only
                if self._log_every_tick:
                    if (self._log_entity_filter is None or any(substr in closest_entity for substr in self._log_entity_filter)):
                        _log_info(f"DISTANCE: Door {door_path} -> Entity {closest_entity} = {min_distance:.3f} m (open={door_data['open']})")

                # Hysteresis + cooldown: decide once per door using min_distance
                now = time.time()
                if min_distance < self._door_open_distance:
                    if (not door_data["open"] and (now - door_data.get("last_toggle_time", 0.0) > self._door_min_toggle_interval)):
                        _log_info(f"Opening door {door_path} (closest entity {closest_entity} within {self._door_open_distance}m)")
                        self._open_door(door_data)
                        door_data["last_toggle_time"] = now
                elif min_distance > (self._door_open_distance + self._door_close_margin):
                    if (door_data["open"] and (now - door_data.get("last_toggle_time", 0.0) > self._door_min_toggle_interval)):
                        _log_info(f"Closing door {door_path} (no entities within {self._door_open_distance}m)")
                        self._close_door(door_data)
                        door_data["last_toggle_time"] = now
            else:
                # No entities registered — optionally print a placeholder distance message
                if self._log_every_tick:
                    _log_info(f"DISTANCE: Door {door_path} -> (no entities registered)")

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
            # Slide the door along its local X axis by a sensible offset based on its size
            try:
                size_x = float(door_data.get("initial_scale")[0]) if door_data.get("initial_scale") is not None else 1.0
                opening_offset = max(0.5, size_x * 0.9)
                init_t = door_data.get("initial_translate", Gf.Vec3f(0, 0, 0))
                target_t = Gf.Vec3f(init_t[0] + opening_offset, init_t[1], init_t[2])
                # Use XformCommonAPI to set translate so we respect xformOp order
                xform_api = UsdGeom.XformCommonAPI(prim)
                xform_api.SetTranslate((float(target_t[0]), float(target_t[1]), float(target_t[2])))

                # Verify translate took effect; if not, fallback to scale-based shrink (some doors are animated by scale)
                try:
                    translate_attr = prim.GetAttribute('xformOp:translate')
                    current_t = translate_attr.Get() if translate_attr is not None else None
                except Exception:
                    current_t = None

                moved = False
                if current_t is not None:
                    try:
                        # compare components with a small tolerance
                        moved = any(abs(float(current_t[i]) - float(target_t[i])) > 1e-3 for i in range(3))
                    except Exception:
                        # conservative: assume moved
                        moved = True

                if not moved:
                    # Fallback: use scale (shrink width) to simulate opening
                    _log_debug(f"Translation did not visibly change door {prim.GetPath().pathString}; falling back to scale-based opening")
                    target_scale = Gf.Vec3f(door_data["initial_scale"][0], 0.1, door_data["initial_scale"][2])
                    scale_attr = prim.GetAttribute('xformOp:scale')
                    if scale_attr:
                        scale_attr.Set(target_scale)
                    else:
                        scale_attr = prim.CreateAttribute('xformOp:scale', Sdf.ValueTypeNames.Float3)
                        scale_attr.Set(target_scale)
                door_data["open"] = True
                _log_info(f"Door {prim.GetPath().pathString} opened -> translate set to {target_t}")
            except Exception as e:
                _log_warn(f"Failed to open door {prim.GetPath().pathString}: {e}")

    def _close_door(self, door_data):
        if door_data["kind"] == 'sliding':
            prim = door_data["prim"]
            try:
                init_t = door_data.get("initial_translate", Gf.Vec3f(0, 0, 0))
                xform_api = UsdGeom.XformCommonAPI(prim)
                xform_api.SetTranslate((float(init_t[0]), float(init_t[1]), float(init_t[2])))

                # Also restore scale if fallback was used previously
                try:
                    scale_attr = prim.GetAttribute('xformOp:scale')
                    if scale_attr:
                        scale_attr.Set(door_data.get("initial_scale", Gf.Vec3f(1,1,1)))
                except Exception:
                    pass

                door_data["open"] = False
                _log_info(f"Door {prim.GetPath().pathString} closed -> translate reset to {init_t}")
            except Exception as e:
                _log_warn(f"Failed to close door {prim.GetPath().pathString}: {e}")

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
        _log_debug(f"Added robot to door manager: {prim_path} -> resolved: {resolved}")
        try:
            self._ensure_robot_subscription(resolved)
        except Exception as e:
            _log_warn(f'Failed to ensure robot subscription on add: {e}')

    def add_pedestrian(self, prim_path: str):
        """Register a pedestrian prim for distance checks. Poses for
        pedestrians are primarily updated via the people topic; this method
        just records the prim path.
        """
        resolved = self._resolve_entity_prim(prim_path)
        if resolved not in self._pedestrians:
            self._pedestrians.append(resolved)
        _log_debug(f"Added pedestrian to door manager: {prim_path} -> resolved: {resolved}")

    def _register_entity_cb(self, msg):
        """Handle simple registration messages published on /isaac/register_entity.
        Expected payload: '<role>|<prim_path>' where role is 'robot' or 'pedestrian'.
        """
        try:
            data = getattr(msg, 'data', '')
            _log_info(f'REGISTER_ENTITY received: {data}')
            if not data:
                return
            parts = data.split('|', 1)
            if len(parts) != 2:
                _log_warn(f'Invalid register_entity payload: {data}')
                return
            role, prim_path = parts[0].strip().lower(), parts[1].strip()
            if role == 'robot':
                self.add_robot(prim_path)
                _log_info(f'Robot registered with DoorManager: {prim_path}')
            elif role == 'pedestrian' or role == 'ped':
                self.add_pedestrian(prim_path)
                _log_info(f'Pedestrian registered with DoorManager: {prim_path}')
            else:
                _log_warn(f'Unknown role in register_entity payload: {role}')
                return
            # show current registry
            _log_debug(f'Current robots: {self._robots}, pedestrians: {self._pedestrians}')
        except Exception as e:
            _log_debug(f'_register_entity_cb error: {e}')


door_manager = DoorManager()
