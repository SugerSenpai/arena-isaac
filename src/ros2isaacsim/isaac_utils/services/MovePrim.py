import omni.kit.commands as commands
from isaacsim_msgs.srv import MovePrim
from omni.isaac.core.utils.rotations import euler_angles_to_quat, quat_to_euler_angles

def prim_mover(request,response):
    name = request.name
    prim_path = request.prim_path
    position, orientation = request.values
    position = tuple(position.values)
    orientation_euler = orientation.values
    orientation = tuple(euler_angles_to_quat(orientation_euler))

    # orientation = 
    commands.execute(
        "IsaacSimTeleportPrim",
        prim_path = prim_path,
        translation = position,
        rotation = orientation,
    )

    response.ret = True
    return response

def move_prim(controller):
    service = controller.create_service(srv_type=MovePrim, 
                        srv_name='isaac/move_prim', 
                        callback=prim_mover)
    return service