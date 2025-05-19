# TODO: Work across different robots % work with yaml
import os
import sys
from pathlib import Path

from isaac_utils.graphs import joint_states
import isaac_utils.graphs.odom as odom
import omni.kit.commands as commands

from isaacsim_msgs.srv import UrdfToUsd
from isaac_utils.graphs import control

parent_dir = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(parent_dir))


def urdf_to_usd(request, response):
    name = request.name
    urdf_path = request.urdf_path
    robot_model = request.robot_model

    status, import_config = commands.execute("URDFCreateImportConfig")
    import_config.set_merge_fixed_joints(False)
    import_config.set_convex_decomp(False)
    import_config.set_import_inertia_tensor(False)
    import_config.set_make_default_prim(False)
    import_config.set_distance_scale(1.0)
    import_config.set_fix_base(False)
    import_config.set_default_drive_type(2)
    import_config.set_self_collision(False)

    status, usd_path = commands.execute(
        "URDFParseAndImportFile",
        urdf_path=urdf_path,
        # urdf_robot = robot_model,
        import_config=import_config,
        dest_path=f"",
        get_articulation_root=True,
    )

    if usd_path is None:
        return response

    usd_path = os.path.abspath(usd_path)

    # print(usd_path)
    if not request.no_localization:
        odom.odom(
            f'/{name}/odom_publisher',
            prim_path=usd_path,
            base_frame_id=f'{name}/{request.base_frame}',
            odom_frame_id=f'{name}/{request.odom_frame}',
        )

    # joint_states.joint_states(
    #     f'/{name}/joint_state_publisher',
    #     robot_model=robot_model,
    #     joint_states_topic=f"/task_generator_node/{name}/joint_states",
    # )

    control.Control(
        prim_path=os.path.dirname(usd_path),
        cmd_vel_topic=f"/task_generator_node/{name}/cmd_vel",
    ).parse(
        robot_model=robot_model,
    )

    response.usd_path = usd_path
    return response

# Urdf importer service callback.


def convert_urdf_to_usd(controller):
    service = controller.create_service(srv_type=UrdfToUsd,
                                        srv_name='isaac/urdf_to_usd',
                                        callback=urdf_to_usd)
    return service
