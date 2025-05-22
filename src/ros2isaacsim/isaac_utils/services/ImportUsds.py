import os

import numpy as np
from isaac_utils.utils import geom
from omni.isaac.core.utils.prims import set_prim_attribute_value

from isaacsim_msgs.srv import ImportUsd


def usd_importer(stage, request, response):
    name = request.name
    usd_path = request.usd_path
    prim_path = os.path.join(request.prim_path, name)
    stage.add_reference_to_stage(usd_path, prim_path)
    set_prim_attribute_value(prim_path, attribute_name="xformOp:translate", value=np.array(geom.Translation.parse(request.pose.position).tuple))
    set_prim_attribute_value(prim_path, attribute_name="xformOp:orient", value=np.array(geom.Rotation.parse(request.pose.orientation).euler))
    response.ret = True


def import_usd(controller):
    service = controller.create_service(
        srv_type=ImportUsd,
        srv_name='isaac/import_usd',
        callback=usd_importer
    )
    return service
