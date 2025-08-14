import typing
import omni
import numpy as np
from pxr import Gf, UsdGeom, Sdf, Usd

class DoorManager:
    def __init__(self):
        self._doors = {}
        self._robots = []
        self._pedestrians = []
        self._door_open_distance = 3.0  # meters

    def add_robot(self, prim_path: str):
        self._robots.append(prim_path)
        print(f"DEBUG: Added robot to door manager: {prim_path}")

    def add_pedestrian(self, prim_path: str):
        self._pedestrians.append(prim_path)
        print(f"DEBUG: Added pedestrian to door manager: {prim_path}")

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
            print(f"DEBUG: Added door to door manager: {prim_path}")
        else:
            print(f"DEBUG: Failed to add door - invalid prim: {prim_path}")

    def reset(self):
        self._pedestrians.clear()
        # Close all doors on reset
        for door_path, door_data in self._doors.items():
            self._close_door(door_data)

    def update(self):
        stage = omni.usd.get_context().get_stage()
        entities_to_check = self._robots + self._pedestrians

        if not self._doors:
            print("DEBUG: No doors registered with DoorManager.")

        # Always print something each tick. If there are no entities, still print door positions.
        for door_path, door_data in self._doors.items():
            door_prim = door_data["prim"]
            if not door_prim.IsValid():
                print(f"DEBUG: Door prim invalid: {door_path}")
                continue

            door_pos = self._get_prim_position(door_prim)
            # Print door world position every tick
            print(f"DOOR_POS: {door_path} = ({door_pos[0]:.3f}, {door_pos[1]:.3f}, {door_pos[2]:.3f})")

            if entities_to_check:
                for entity_path in entities_to_check:
                    entity_prim = stage.GetPrimAtPath(entity_path)
                    if not (entity_prim and entity_prim.IsValid()):
                        print(f"DEBUG: Entity prim invalid or missing: {entity_path}")
                        continue
                    entity_pos = self._get_prim_position(entity_prim)
                    distance = float(np.linalg.norm(door_pos - entity_pos))
                    # Always print the distance (per your request)
                    print(f"DISTANCE: Door {door_path} -> Entity {entity_path} = {distance:.3f} m (open={door_data['open']})")

                    # Maintain open/close behavior based on threshold
                    if distance < self._door_open_distance:
                        if not door_data["open"]:
                            print(f"DEBUG: Opening door {door_path} (entity within {self._door_open_distance}m)")
                            self._open_door(door_data)
                    else:
                        if door_data["open"]:
                            print(f"DEBUG: Closing door {door_path} (no entities within {self._door_open_distance}m)")
                            self._close_door(door_data)
            else:
                # No entities registered — print a placeholder distance message every tick
                print(f"DISTANCE: Door {door_path} -> (no entities registered)")

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

door_manager = DoorManager()
