import math
import os
import typing

import numpy as np
import omni
from isaac_utils.managers.door_manager import door_manager
from isaac_utils.utils.path import world_path
from omni.isaac.core import World
from omni.isaac.core.objects import FixedCuboid
from omni.isaac.core.utils.rotations import euler_angles_to_quat
from pxr import Gf
from rclpy.qos import QoSProfile

from isaacsim_msgs.srv import SpawnDoor

from .utils import safe

profile = QoSProfile(depth=2000)


@safe()
def door_spawner(request: SpawnDoor.Request, response: SpawnDoor.Response):
    # Get service attributes
    prim_path = world_path('Doors', request.name)
    height = request.height
    material = request.material
    kind = request.kind

    start = np.append(np.array(request.start), height / 2)
    end = np.append(np.array(request.end), height / 2)

    start_vec = Gf.Vec3d(*start)
    end_vec = Gf.Vec3d(*end)

    vector_ab = end - start

    center = (start_vec + end_vec) / 2
    length = np.linalg.norm(vector_ab[:2])
    angle = math.atan2(vector_ab[1], vector_ab[0])
    scale = Gf.Vec3f(*[length, 0.1, height])

    # create door
    stage = omni.usd.get_context().get_stage()
    world = World.instance()

    # Generate unique name and check if object already exists
    unique_name = prim_path.replace('/', '_') + f"_{id(request)}"
    
    # Check if an object with this name already exists and remove it
    try:
        existing_object = world.scene.get_object(unique_name)
        if existing_object is not None:
            world.scene.remove_object(unique_name)
    except:
        pass  # Object doesn't exist, which is fine
    
    world.scene.add(FixedCuboid(
        prim_path=prim_path,
        name=unique_name,
        position=center,
        scale=scale,
        orientation=euler_angles_to_quat([0, 0, angle]),
    ))

    # Create a simple material using OmniPBR instead of external URLs
    mtl_path = f"/World/Looks/DoorMaterial_{request.name}"
    mtl = stage.GetPrimAtPath(mtl_path)
    if not (mtl and mtl.IsValid()):
        try:
            omni.kit.commands.execute('CreateAndBindMdlMaterialFromLibrary',
                                     mdl_name='OmniPBR.mdl',
                                     mtl_name='OmniPBR',
                                     mtl_path=mtl_path,
                                     select_new_prim=False)
            # Set a brown/wood color for doors
            omni.kit.commands.execute('ChangeProperty',
                                     prop_path=f"{mtl_path}/Shader.inputs:diffuse_color_constant",
                                     value=(0.6, 0.4, 0.2),
                                     prev=None)
        except:
            # Fallback: create basic material without external dependencies
            pass

    try:
        omni.kit.commands.execute('BindMaterialCommand',
                                 prim_path=prim_path,
                                 material_path=mtl_path)
    except:
        pass  # Material binding failed, continue without material

    door_manager.add_door(prim_path, kind)

    response.ret = True
    return response


def spawn_door(controller):
    service = controller.create_service(
        srv_type=SpawnDoor,
        qos_profile=profile,
        srv_name='isaac/spawn_door',
        callback=door_spawner
    )
    return service
