import rclpy
from rclpy.node import Node
from isaacsim_msgs.srv import ImportUsd
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Twist   # <-- New import for geometry_msgs/Twist
import cv2
import numpy

class controller(Node):
    def __init__(self):
        super().__init__("controller")
        
        # 1. Create a client for the ImportUsd service
        self.client = self.create_client(
            srv_type=ImportUsd,
            srv_name='isaac/import_usd',
        )
        self.request = ImportUsd.Request()
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        
        # 2. Spawn the Waffle robot
        future = self.send(
            name='waffle', 
            usd_path='/home/ubuntu/arena4_ws/src/arena/isaac/robot_models/waffle.usd', 
            prim_path='/World', 
            control=True
        )
        rclpy.spin_until_future_complete(self, future)
        self.response = future.result()
        self.get_logger().info("Spawn complete!")

        # 3. Subscribe to the robot joint states (if you still need that info)
        self.info = JointState()
        self.subscriber_ = self.create_subscription(
            msg_type=JointState,
            topic='/waffle_states',
            callback=self.get_data,
            qos_profile=1
        )

        # 4. Prepare Twist publisher (instead of JointState publisher)
        self.twist_pub = self.create_publisher(
            Twist,
            '/cmd_vel',   # Standard topic for differential-drive velocity commands
            qos_profile=1
        )

        # 5. Initialize velocities for keyboard control
        self.linear_vel = 0.0
        self.angular_vel = 0.0

        # 6. Create a timer to call self.control
        self.timer_ = self.create_timer(1/60, self.control)

        # 7. OpenCV canvas (just for capturing key input visually)
        self.canvas = numpy.zeros((300, 300))

    def control(self):
        # Show the "control" window and get the key pressed
        cv2.imshow('control', self.canvas)
        key = cv2.waitKey(1)

        # Adjust linear velocity
        if key == ord('s'):  # Increase linear velocity
            self.linear_vel += 0.1
        if key == ord('k'):  # Decrease linear velocity
            self.linear_vel -= 0.1

        # Adjust angular velocity
        if key == ord('a'):  # Turn left
            self.angular_vel += 0.1
        if key == ord('l'):  # Turn right
            self.angular_vel -= 0.1

        # Create and publish Twist message
        twist_msg = Twist()
        twist_msg.linear.x = float(self.linear_vel)
        twist_msg.angular.z = float(self.angular_vel)
        self.twist_pub.publish(twist_msg)

    def get_data(self, msg):
        """Store and log the latest joint states (if needed)."""
        self.info.header = msg.header
        self.info.name = msg.name
        self.info.position = msg.position
        self.info.velocity = msg.velocity
        self.info.effort = msg.effort
        self.get_logger().info(f"""
        header: {self.info.header}
        name: {self.info.name}
        position: {self.info.position}
        velocity: {self.info.velocity}
        effort: {self.info.effort}
        """)

    def send(self, name, usd_path, prim_path, control):
        """Helper method to spawn the robot in Isaac Sim."""
        self.request.name = name
        self.request.usd_path = usd_path
        self.request.prim_path = prim_path
        self.request.control = control
        return self.client.call_async(self.request)

def main(args=None):
    rclpy.init()
    node = controller()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
