# Use the isaacsim to import SimulationApp
from isaacsim import SimulationApp

# Setting the config for simulation and make an simulation.
CONFIG = {"renderer": "RayTracedLighting", "headless": False}
simulation_app = SimulationApp(CONFIG)

# Import dependencies.
import carb
import omni
import omni.graph.core as og
import usdrt.Sdf
from omni.isaac.core import SimulationContext
from omni.isaac.core.utils import extensions, stage
from omni.isaac.nucleus import get_assets_root_path
from omni.kit.viewport.utility import get_active_viewport
from omni.isaac.core.world import World
from pxr import Gf, Usd, UsdGeom
import rclpy
from rclpy.node import Node
from isaacsim_msgs.msg import Euler, Quat
from isaacsim_msgs.srv import ImportUsd

#======================================Base======================================
# Setting up world and enable ros2_bridge extentions.
world = World()
extensions.enable_extension("omni.isaac.ros2_bridge")
simulation_app.update() #update the simulation once for update ros2_bridge.
simulation_context = SimulationContext(stage_units_in_meters=1.0) #currently we use 1m for simulation.

# update the simulation.
def run():
    simulation_app.update()
#================================================================================
#============================usd importer service================================
# Usd importer (service) -> bool.
def usd_importer(request, response):
    usd_path = request.usd_path
    prim_path = request.prim_path
    print(f"usd: {usd_path}, prim: {prim_path}")
    stage.add_reference_to_stage(usd_path, prim_path)
    response.ret = True
    return response 

# Usd importer service callback.
def ImportUSD():
    node = rclpy.create_node('ImportUSD')
    service = node.create_service(srv_type=ImportUsd, 
                        srv_name='import_usd', 
                        callback=usd_importer)
    timer = node.create_timer(1/60, callback=run)
    return node, service
#=================================================================================
#======================================main=======================================
def main(arg=None):
    rclpy.init()
    world.scene.add_default_ground_plane()
    node_usd, service_usd = ImportUSD()
    rclpy.spin(node_usd)
    node.destroy_node()
    rclpy.shutdown()
    return
#=================================================================================
if __name__ == "__main__":
    main()
