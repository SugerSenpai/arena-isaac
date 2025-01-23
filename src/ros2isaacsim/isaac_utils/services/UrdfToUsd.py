#TODO: Work across different robots % work with yaml
import omni.kit.commands as commands
import yaml
from isaacsim_msgs.srv import UrdfToUsd
import sys
from pathlib import Path
parent_dir = Path(__file__).resolve().parent.parent
sys.path.insert(0,str(parent_dir))
from yaml_utils import read_yaml_config


def urdf_to_usd(request, response):
    name = request.name
    urdf_path = request.urdf_path
    # config_path = request.config_path
        
    status, import_config = commands.execute("URDFCreateImportConfig")
    print(import_config)
    import_config.set_merge_fixed_joints(False)
    import_config.set_convex_decomp(False)
    import_config.set_import_inertia_tensor(False)
    import_config.set_make_default_prim(False)
    import_config.set_distance_scale(1.0)
    import_config.set_fix_base(False)
    import_config.set_default_drive_type(2)
    import_config.set_self_collision(False)
    
    
    # usd_path = f"/home/ubuntu/arena4_ws/src/arena/isaac/robot_models/{request.name}.usd"
    
    
    # print(robot_model)
    
    status, articulation_root_path = commands.execute(
        "URDFParseAndImportFile",
        urdf_path=urdf_path,
        # urdf_robot = robot_model,
        import_config=import_config,
        dest_path="",
        get_articulation_root=True,
    )
    
    # print(usd_path)
    
    response.usd_path = articulation_root_path
    return response
    
# Urdf importer service callback.
def convert_urdf_to_usd(controller):
    service = controller.create_service(srv_type=UrdfToUsd, 
                        srv_name='isaac/urdf_to_usd', 
                        callback=urdf_to_usd)
    return service