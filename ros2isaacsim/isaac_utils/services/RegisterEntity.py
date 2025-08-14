import typing
import omni
from isaac_utils.managers.door_manager import door_manager
from rclpy.qos import QoSProfile
from isaacsim_msgs.srv import RegisterEntity

profile = QoSProfile(depth=10)


def register_entity_service(request: RegisterEntity.Request, response: RegisterEntity.Response):
    prim_path = request.prim_path
    role = request.role.lower()
    try:
        if role == 'robot':
            door_manager.add_robot(prim_path)
        elif role == 'pedestrian' or role == 'ped':
            door_manager.add_pedestrian(prim_path)
        else:
            # treat unknown roles as robots by default
            door_manager.add_robot(prim_path)
        response.ret = True
    except Exception as e:
        print(f"RegisterEntity: failed to register {prim_path} as {role}: {e}")
        response.ret = False
    return response


def register_entity(controller):
    service = controller.create_service(
        srv_type=RegisterEntity,
        qos_profile=profile,
        srv_name='isaac/register_entity',
        callback=register_entity_service
    )
    return service
