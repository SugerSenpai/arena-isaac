import typing
import omni
import numpy as np
from pxr import Gf, UsdGeom, Sdf

class DoorManager:
    def __init__(self):
        self._doors = {}
        self._robots = []
        self._pedestrians = []
        self._door_open_distance = 3.0  # meters

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

    def add_robot(self, prim_path: str):
        self._robots.append(prim_path)

    def add_pedestrian(self, prim_path: str):
        self._pedestrians.append(prim_path)

    def reset(self):
        self._pedestrians.clear()
        # Close all doors on reset
        for door_path, door_data in self._doors.items():
            self._close_door(door_data)

    def update(self):
        stage = omni.usd.get_context().get_stage()
        entities_to_check = self._robots + self._pedestrians

        for door_path, door_data in self._doors.items():
            door_prim = door_data["prim"]
            if not door_prim.IsValid():
                continue

            door_pos = self._get_prim_position(door_prim)
            is_entity_nearby = False

            for entity_path in entities_to_check:
                entity_prim = stage.GetPrimAtPath(entity_path)
                if entity_prim.IsValid():
                    entity_pos = self._get_prim_position(entity_prim)
                    distance = np.linalg.norm(door_pos - entity_pos)
                    if distance < self._door_open_distance:
                        is_entity_nearby = True
                        break
            
            if is_entity_nearby and not door_data["open"]:
                self._open_door(door_data)
            elif not is_entity_nearby and door_data["open"]:
                self._close_door(door_data)

    def _get_prim_position(self, prim):
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
