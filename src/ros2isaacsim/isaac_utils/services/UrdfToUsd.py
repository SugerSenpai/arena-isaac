# TODO: Work across different robots % work with yaml
import os
import sys
from pathlib import Path

import isaac_utils.graphs.odom as odom
import omni.kit.commands as commands
from isaac_utils.graphs import control
from isaac_utils.utils import geom
from isaac_utils.utils.prim import ensure_path
from isaac_utils.utils.path import world_path

from isaacsim_msgs.srv import UrdfToUsd

parent_dir = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(parent_dir))


def urdf_to_usd(request, response):
    name = request.name
    urdf_path = request.urdf_path
    robot_model = request.robot_model

    prim_path = world_path(name)

    status, import_config = commands.execute("URDFCreateImportConfig")
    import_config.set_merge_fixed_joints(False)
    import_config.set_convex_decomp(False)
    import_config.set_import_inertia_tensor(False)
    import_config.set_make_default_prim(False)
    import_config.set_distance_scale(1.0)
    import_config.set_fix_base(False)
    import_config.set_default_drive_type(2)
    import_config.set_self_collision(False)

    ensure_path(os.path.dirname(prim_path))
    status, usd_path = commands.execute(
        "URDFParseAndImportFile",
        urdf_path=urdf_path,
        import_config=import_config,
        dest_path='',
    )

    if usd_path is None:
        return response

    commands.execute(
        "MovePrim",
        path_from=usd_path,
        path_to=prim_path,
        keep_world_transform=True
    )

    # print(usd_path)
    if not request.no_localization:
        odom.odom(
            os.path.join(prim_path, 'odom_publisher'),
            prim_path=prim_path,
            base_frame_id=f'{name}/{request.base_frame}',
            odom_frame_id=f'{name}/{request.odom_frame}',
        )

    # joint_states.joint_states(
    #     f'/{name}/joint_state_publisher',
    #     robot_model=robot_model,
    #     joint_states_topic=f"/task_generator_node/{name}/joint_states",
    # )

    control.Control(
        prim_path=prim_path,
        cmd_vel_topic=f"/task_generator_node/{name}/cmd_vel",
    ).parse(
        robot_model=robot_model,
    )

    response.usd_path = prim_path

    geom.move(
        prim_path=prim_path,
        translation=geom.Translation.parse(request.pose.position),
        rotation=geom.Rotation.parse(request.pose.orientation),
    )

    return response

# Urdf importer service callback.


def convert_urdf_to_usd(controller):
    service = controller.create_service(
        srv_type=UrdfToUsd,
        srv_name='isaac/urdf_to_usd',
        callback=urdf_to_usd
    )
    return service
