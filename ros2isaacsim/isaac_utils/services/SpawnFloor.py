import math
import os

import numpy as np
import omni
from omni.isaac.core import World
from omni.isaac.core.objects import FixedCuboid,GroundPlane
from omni.isaac.core.utils.rotations import (euler_angles_to_quat)
from pxr import Gf


from isaacsim_msgs.srv import SpawnFloor
from isaac_utils.utils.path import world_path
from rclpy.qos import QoSProfile
from .utils import safe
import yaml 
from pathlib import Path

profile = QoSProfile(depth=2000)

@safe()
def floor_spawner(request, response):
    # Get service attributes
    prim_path = world_path('Floors', request.name)
    x_len = request.x_length
    y_len = request.y_length
    pos = Gf.Vec3d(*np.append(np.array(request.pos),0.0))
    floor_material = request.material

    materials_path = os.path.join(os.environ['ARENA_WS_DIR'],f'src/arena/simulation-setup/entities/materials/materials.yaml')
    materials_data = yaml.safe_load(Path(materials_path).read_text())

    stage = omni.usd.get_context().get_stage()
    world = World.instance()
    scale = Gf.Vec3f(*[x_len,y_len,0.01])
    world.scene.add(FixedCuboid(
        prim_path=prim_path,
        name=os.path.basename(prim_path),
        scale=scale,
        position=pos,
    ))
    
    if floor_material != '':
        for material in materials_data.get("floor_mat",[]):
            if material.get('material') == floor_material:
                mdl_path = material.get('url')
                mtl_name = material.get('material_name')
        mtl_path = "/World/Looks/FloorMaterial"
        mtl = stage.GetPrimAtPath(mtl_path)
        if not (mtl and mtl.IsValid()):
            create_res = omni.kit.commands.execute('CreateMdlMaterialPrimCommand',
                                                mtl_url=mdl_path,
                                                mtl_name=mtl_name,
                                                mtl_path=mtl_path)

        bind_res = omni.kit.commands.execute('BindMaterialCommand',
                                            prim_path=prim_path,
                                            material_path=mtl_path)

    response.ret = True
    return response


def spawn_floor(controller):
    service = controller.create_service(
        srv_type=SpawnFloor,
        qos_profile=profile,
        srv_name='isaac/spawn_floor',
        callback=floor_spawner
    )
    return service
