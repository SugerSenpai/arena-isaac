import os
import omni
from omni.isaac.core import World
from omni.isaac.core.objects import FixedCuboid
from pxr import Gf
from rclpy.qos import QoSProfile
from isaacsim_msgs.srv import SpawnElevator
from isaac_utils.utils.path import world_path
from .utils import safe

profile = QoSProfile(depth=2000)

@safe()
def elevator_spawner(request, response):
    prim_path = world_path('Elevators', request.name)
    pos = Gf.Vec3d(*request.position)
    size = Gf.Vec3f(*request.size)
    material = request.material

    world = World.instance()
    world.scene.add(FixedCuboid(
        prim_path=prim_path,
        name=os.path.basename(prim_path),
        position=pos,
        scale=size,
    ))
    # TODO: Add material binding if needed

    response.ret = True
    return response

def spawn_elevator(controller):
    service = controller.create_service(
        srv_type=SpawnElevator,
        qos_profile=profile,
        srv_name='isaac/spawn_elevator',
        callback=elevator_spawner
    )
    return service