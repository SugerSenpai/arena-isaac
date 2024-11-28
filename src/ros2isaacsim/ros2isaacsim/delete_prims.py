#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from simulation_service.srv import StartSimulation
import omni.timeline
from omni.isaac.core.utils.prims import delete_prim,get_prim_at_path,set_prim_attribute_value,get_prim_attribute_value,get_prim_attribute_names
import numpy as np

class SimulationServer(Node):
    def __init__(self):
        super().__init__('simulation_server')
        self.srv = self.create_service(
            StartSimulation, 
            'start_simulation', 
            self.simulation_callback
        )

    def simulation_callback(self, request, response):
        try:
            omni.timeline.get_timeline_interface().play()
            i = 0
            j = 0
            
            print(get_prim_attribute_names(f"/World/turtlebot3_waffle"))
            
            while i > -1:
                world.step()
                i += 1
                
                if i % 100 == 0:
                    if j < 7:
                        delete_prim(f"/World/cube_{j}")
                    j += 1
                
                if j == 6:
                    if get_prim_at_path("/World/jackal"):
                        delete_prim(f"/World/jackal")
                
                if j == 7:
                    set_prim_attribute_value(
                        f"/World/turtlebot3_waffle", 
                        attribute_name="xformOp:translate", 
                        value=np.array([0,0,0])
                    )
                
                if j == 10:
                    break
            
            response.success = True
            response.message = "Simulation completed successfully"
        except Exception as e:
            response.success = False
            response.message = f"Simulation failed: {str(e)}"
        
        return response

def main():
    rclpy.init()
    simulation_server = SimulationServer()
    print("Simulation service ready")
    try:
        rclpy.spin(simulation_server)
    except KeyboardInterrupt:
        pass
    finally:
        simulation_server.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
