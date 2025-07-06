import os
from isaac_utils.utils.path import pedestrian_path
from isaac_utils.utils.prim import ensure_path
from omni.isaac.core import World
from pedestrian.simulator.logic.people.person import Person
from rclpy.qos import QoSProfile

from isaacsim_msgs.srv import Pedestrian

from .utils import safe

profile = QoSProfile(depth=2000)


@safe()
def pedestrian_spawn(request, response):
    # Get service attributes
    world = World.instance()
    people = request.people

    for person in people:
        usd_path = pedestrian_path(person.stage_prefix)
        ensure_path(os.path.dirname(usd_path))
        if not person.controller_stats:
            p = Person(world, usd_path, person.character_name, person.initial_pose, person.orientation)
            # inav = nav.acquire_interface()
            # navmesh = inav.get_navmesh()
            # if navmesh:
            #     navmesh_path = navmesh.query_shortest_path(person.initial_pose, person.goal_pose)
            #     if navmesh_path:
            #         path_points = navmesh_path.get_points()
            #         p.update_target_position(path_points, person.velocity)
            #     else:
            #         carb.log_error(f"NavMesh could not query points")
        else:
            p = Person(world, usd_path, person.character_name, person.initial_pose, person.orientation, person.controller_name)

    response.ret = True
    return response


def spawn_ped(controller):
    service = controller.create_service(
        srv_type=Pedestrian,
        qos_profile=profile,
        srv_name='isaac/spawn_pedestrian',
        callback=pedestrian_spawn
    )
    return service
