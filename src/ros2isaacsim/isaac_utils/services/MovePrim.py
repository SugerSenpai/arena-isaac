from isaac_utils.utils import xform

from isaacsim_msgs.srv import MovePrim


def prim_mover(request, response):
    prim_path = request.prim_path
    position = request.pose.position
    orientation = request.pose.orientation

    xform.move(
        prim_path=prim_path,
        translation=xform.Translation.parse(position),
        rotation=xform.Rotation.parse(orientation),
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
