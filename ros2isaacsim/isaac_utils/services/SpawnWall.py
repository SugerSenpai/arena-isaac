import math
import os

import numpy as np
import omni
from isaac_utils.utils.path import world_path
from omni.isaac.core import World
from omni.isaac.core.objects import FixedCuboid
from omni.isaac.core.utils.rotations import euler_angles_to_quat
from pxr import Gf
from rclpy.qos import QoSProfile
from pathlib import Path
import yaml

from isaacsim_msgs.srv import SpawnWall

from .utils import safe

profile = QoSProfile(depth=2000)


@safe()
def wall_spawner(request, response):
    # Get service attributes
    prim_path = world_path('Walls', request.name)
    # asset_prim_path = world_path('Walls',request.name + "_part")
    height = request.height
    width = request.width
    wall_material = request.material
    z_offset = request.z_offset

    start = np.append(np.array(request.start[:2]), z_offset + height / 2)
    end = np.append(np.array(request.end[:2]), z_offset + height / 2)

    start_vec = Gf.Vec3d(*start)
    end_vec = Gf.Vec3d(*end)

    vector_ab = end - start

    center = (start_vec + end_vec) / 2

    length = np.linalg.norm(vector_ab[:2])
    angle = math.atan2(vector_ab[1], vector_ab[0])
    # print("wall angle", angle)
    scale = Gf.Vec3f(*[length, width, height])

    # create wall
    stage = omni.usd.get_context().get_stage()
    world = World.instance()

    world.scene.add(FixedCuboid(
        prim_path=prim_path,
        name=os.path.basename(prim_path),
        position=center,
        scale=scale,
        orientation=euler_angles_to_quat([0, 0, angle]),
    ))
    if wall_material != '':
        mdl_path = wall_material
        material_name = request.material_name
        mtl_path = f"/World/Looks/Wall_{request.name}_Material"
        mtl = stage.GetPrimAtPath(mtl_path)

        if not (mtl and mtl.IsValid()):
            create_res = omni.kit.commands.execute(
                'CreateMdlMaterialPrimCommand',
                mtl_url=mdl_path,
                mtl_name=material_name,
                mtl_path=mtl_path)

            bind_res = omni.kit.commands.execute(
                'BindMaterialCommand',
                prim_path=prim_path,
                material_path=mtl_path)

    response.ret = True
    return response


def spawn_wall(controller):
    service = controller.create_service(
        srv_type=SpawnWall,
        qos_profile=profile,
        srv_name='isaac/spawn_wall',
        callback=wall_spawner
    )
    return service
