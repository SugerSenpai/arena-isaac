from omni.isaac.lab.app import AppLauncher
import argparse
import rclpy
from rclpy.node import Node

class run_isaacsim(Node):
    def __init__(self):
        super().__init__("isaacsim")
        parser = argparse.ArgumentParser(description="Tutorial on creating an empty stage.")
        # append AppLauncher cli args
        AppLauncher.add_app_launcher_args(parser)
        # parse the arguments
        args_cli = parser.parse_args()
        # launch omniverse app
        app_launcher = AppLauncher(args_cli)
        simulation_app = app_launcher.app
                
def main(arg=None):
    rclpy.init()
    node = run_isaacsim()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
    return

if __name__ == "__main__":
    main()