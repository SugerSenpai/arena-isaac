import os

import numpy as np
import omni
from omni.isaac.core.utils.rotations import euler_angles_to_quat
from rclpy.qos import QoSProfile

from isaacsim_msgs.srv import ImportObstacles
from isaac_utils.utils.xform import create_prim_safe
from isaac_utils.utils.path import world_path

profile = QoSProfile(depth=2000)


def obstacle_importer(request, response):
    name = request.name
    usd_path = request.usd_path
    position = request.position
    orientation = request.orientation
    model_prim = create_prim_safe(
        prim_path=world_path(name),
        position=np.array(position),
        orientation=euler_angles_to_quat(orientation),
        usd_path=os.path.abspath(usd_path),
    )

    response.ret = True

    return response


def import_obstacle(controller):
    service = controller.create_service(srv_type=ImportObstacles,
                                        qos_profile=profile,
                                        srv_name='isaac/import_obstacle',
                                        callback=obstacle_importer)
    return service
