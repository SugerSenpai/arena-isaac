import os

import numpy as np
import omni
from isaac_utils.utils import xform
from omni.isaac.core.utils import prims
from rclpy.qos import QoSProfile

from isaacsim_msgs.srv import ImportObstacles

profile = QoSProfile(depth=2000)


def obstacle_importer(request, response):
    name = request.name
    usd_path = request.usd_path
    model_prim = prims.create_prim(
        prim_path=f"/World/{name}",
        position=np.array(xform.Translation.parse(request.pose.position).tuple()),
        orientation=np.array(xform.Rotation.parse(request.pose.orientation).quat()),
        usd_path=os.path.abspath(usd_path),
    )

    response.ret = True

    return response


def import_obstacle(controller):
    service = controller.create_service(
        srv_type=ImportObstacles,
        qos_profile=profile,
        srv_name='isaac/import_obstacle',
        callback=obstacle_importer
    )
    return service
