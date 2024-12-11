# Will reminder: delete old thread
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, PointCloud2
from sensor_msgs_py import point_cloud2
from cv_bridge import CvBridge
import cv2
import numpy as np
import argparse
import sys

class CameraSubscriber(Node):
    def __init__(self, mode):
        super().__init__('camera_subscriber')
        self.mode = mode
        self.bridge = CvBridge()

        if self.mode == 'rgb':
            self.subscription = self.create_subscription(
                Image,
                '/camera_rgb',
                self.rgb_callback,
                10)
            self.get_logger().info("Subscribed to /camera_rgb")

        elif self.mode == 'depth':
            self.subscription = self.create_subscription(
                Image,
                '/camera_depth',
                self.depth_callback,
                10)
            self.get_logger().info("Subscribed to /camera_depth")

        elif self.mode == 'pointcloud':
            self.subscription = self.create_subscription(
                PointCloud2,
                '/camera_pointcloud',
                self.pointcloud_callback,
                10)
            self.get_logger().info("Subscribed to /camera_pointcloud")

        else:
            self.get_logger().error("Unknown mode! Use 'rgb', 'depth', or 'pointcloud'.")

    def rgb_callback(self, msg):
        # Convert ROS Image message to OpenCV image
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        cv2.imshow('RGB Image', cv_image)
        cv2.waitKey(1)

    def depth_callback(self, msg):
        # Assuming the depth image is in 32FC1 format
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="32FC1")
        # Normalize depth for visualization
        depth_vis = cv2.normalize(cv_image, None, 0, 255, cv2.NORM_MINMAX)
        depth_vis = np.uint8(depth_vis)
        cv2.imshow('Depth Image', depth_vis)
        cv2.waitKey(1)

    def pointcloud_callback(self, msg):
        # Convert PointCloud2 to an array of points
        points_list = list(point_cloud2.read_points(msg, field_names=("x", "y", "z"), skip_nans=True))

        # Ensure that points_list is a simple list of (x, y, z) tuples
        # points_list should already be something like [(x1, y1, z1), (x2, y2, z2), ...]
        # but if not, you can enforce it:
        points_list = [(p[0], p[1], p[2]) for p in points_list]

        # Now convert to a float32 NumPy array
        points = np.array(points_list, dtype=np.float32)

        # Simple visualization approach:
        # 1. Normalize the X and Y coordinates to image coordinates.
        # 2. Normalize Z to create a grayscale intensity value.

        # For demonstration, let's just scale X and Y to fit in a 640x480 image:
        # This is arbitrary and doesn't represent the actual camera projection.
        img_width, img_height = 640, 480

        xs = points[:,0]
        ys = points[:,1]
        zs = points[:,2]

        # Normalize X and Y around 0 for display
        # Assuming the point cloud is centered around (0,0):
        xs_norm = (xs - xs.min()) / (xs.max() - xs.min() + 1e-9)
        ys_norm = (ys - ys.min()) / (ys.max() - ys.min() + 1e-9)

        # Map normalized coordinates to image pixels
        x_pix = (xs_norm * (img_width - 1)).astype(np.int32)
        y_pix = (ys_norm * (img_height - 1)).astype(np.int32)

        # Normalize Z for intensity
        z_norm = (zs - zs.min()) / (zs.max() - zs.min() + 1e-9)
        z_int = (z_norm * 255).astype(np.uint8)

        # Create blank image and plot the points
        pc_image = np.zeros((img_height, img_width), dtype=np.uint8)
        pc_image[y_pix, x_pix] = z_int

        # Display the point cloud as a grayscale image
        cv2.imshow('PointCloud Image (Projected)', pc_image)
        cv2.waitKey(1)

def main(args=None):
    parser = argparse.ArgumentParser()
    parser.add_argument('--mode', type=str, default='rgb', help="Mode: 'rgb', 'depth', or 'pointcloud'")
    parsed_args = parser.parse_args(sys.argv[1:])

    rclpy.init(args=args)
    node = CameraSubscriber(mode=parsed_args.mode)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

