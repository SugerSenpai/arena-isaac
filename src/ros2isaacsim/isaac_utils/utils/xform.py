import typing

import attrs
import geometry_msgs.msg
import omni.kit.commands as commands
from omni.isaac.core.utils.rotations import (euler_angles_to_quat,
                                             quat_to_euler_angles)


@attrs.define
class Translation:
    x: float
    y: float
    z: float

    def tuple(self) -> typing.Tuple[float, float, float]:
        return self.x, self.y, self.z

    @classmethod
    def parse(cls, values: geometry_msgs.msg.Point | typing.Collection[float]) -> "Translation":
        if isinstance(values, geometry_msgs.msg.Point):
            return cls(
                x=values.x,
                y=values.y,
                z=values.z,
            )

        if len(values) == 3:
            return cls(*values)

        if len(values) == 2:
            return cls(
                *values,
                0.0,
            )

        raise ValueError(
            f"Translation must be [x,y] or [x,y,z], got {values}"
        )


@attrs.define
class Rotation:
    w: float
    x: float
    y: float
    z: float

    def quat(self, convention: str = 'wxyz') -> typing.List[float]:
        return [float(getattr(self, axis)) for axis in convention if axis in 'wxyz']

    def euler(self, convention: str = 'xyz') -> typing.List[float]:
        x, y, z = quat_to_euler_angles(self.quat)
        axes: dict[str, float] = dict(
            x=x,
            y=y,
            z=z,
        )
        return [axes[axis] for axis in convention if axis in 'xyz']

    @classmethod
    def parse(cls, values: geometry_msgs.msg.Quaternion | typing.Collection[float]) -> "Rotation":
        if isinstance(values, geometry_msgs.msg.Quaternion):
            return cls(
                x=values.x,
                y=values.y,
                z=values.z,
                w=values.w,
            )

        if len(values) == 4:
            return cls(
                *values
            )

        if len(values) == 3:
            return cls(
                *euler_angles_to_quat(values)
            )

        raise ValueError(
            f"Rotation must be [x,y,z] or [w,x,y,z], got {values}"
        )


def move(
    prim_path: str,
    translation: Translation,
    rotation: Rotation,


):
    commands.execute(
        "IsaacSimTeleportPrim",
        prim_path=prim_path,
        translation=translation.tuple(),
        rotation=rotation.quat('wxyz'),
    )
