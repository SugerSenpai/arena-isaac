from isaac_utils.utils import geom

from isaacsim_msgs.srv import MovePrim
from isaac_utils.utils.path import world_path


def prim_mover(request, response):
    prim_path = world_path(request.name)
    position = request.pose.position
    orientation = request.pose.orientation

    geom.move(
        prim_path=prim_path,
        translation=geom.Translation.parse(position),
        rotation=geom.Rotation.parse(orientation),
    )

    response.ret = True
    return response


def move_prim(controller):
    service = controller.create_service(
        srv_type=MovePrim,
        srv_name='isaac/move_prim',
        callback=prim_mover
    )
    return service
