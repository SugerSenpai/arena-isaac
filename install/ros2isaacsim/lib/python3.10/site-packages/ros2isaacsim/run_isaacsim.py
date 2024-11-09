from isaacsim import SimulationApp
import argparse
import rclpy
from rclpy.node import Node

class run_isaacsim(Node):
    def __init__(self):
        super().__init__("isaacsim")
        # launch omniverse app
        self.simulation_app = SimulationApp({
            "headless": False
        })
        from omni.isaac.core import World
        self.world = World()
        self.world.scene.add_default_ground_plane()
        self.fps = 500
        self.timer_ = self.create_timer(1/self.fps, self.run)

    def run(self):
        self.world.step()
                
def main(arg=None):
    rclpy.init()
    node = run_isaacsim()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
    return

if __name__ == "__main__":
    main()