import os
import omni.graph.core as og
from isaac_utils.graphs import Graph
from omni.isaac.core.utils import extensions

extensions.enable_extension("omni.graph.nodes")
extensions.enable_extension("omni.isaac.core_nodes")
extensions.enable_extension("omni.isaac.ros2_bridge")


def odom(
    graph_path: str,
    prim_path: str,
    tf_prefix: str,
    base_frame_id: str = 'base_link',
    odom_frame_id: str = 'odom',
    map_frame_id: str = 'map',
) -> bool:
    """
    Creates an OmniGraph Action Graph to publish nav2 - type odometry information for a given prim
    using ROS2.

    Args:
        graph_path(str): The USD path where the Action Graph will be created(e.g., '/ActionGraph').
        prim_path(str): The USD path to the prim for which to publish odometry(e.g., '/World/MyRobot/chassis').
        base_frame_id(str): The name of the base frame for the robot(e.g., 'base_link').
        odom_frame_id(str): The name of the odometry frame(e.g., 'odom').
        map_frame_id(str): The name of the map frame(included for completeness but not used in this graph).

    Returns:
        bool: True if the graph was created successfully, False otherwise.
    """

    controller = og.Controller()

    graph = Graph(graph_path)

    prefixer_node_name = f"tf_prefixer_node_{graph_path.replace('/', '_')}"

    internal_tf_topic = os.path.join(prefixer_node_name, 'tf_internal')

    on_playback_tick = graph.node('on_playback_tick', 'omni.graph.action.OnPlaybackTick')
    read_simulation_time = graph.node('read_simulation_time', 'omni.isaac.core_nodes.IsaacReadSimulationTime')
    get_transform = graph.node('get_transform', 'omni.graph.nodes.GetPrimLocalToWorldTransform')
    extract_translation = graph.node('extract_translation', 'omni.graph.nodes.GetMatrix4Translation')
    extract_rotation = graph.node('extract_rotation', 'omni.graph.nodes.GetMatrix4Quaternion')
    publish_map = graph.node('publish_odom_static', 'omni.isaac.ros2_bridge.ROS2PublishRawTransformTree')
    publish_odom = graph.node('publish_odom', 'omni.isaac.ros2_bridge.ROS2PublishRawTransformTree')
    get_base_prim = graph.node('get_base_prim', 'omni.replicator.core.OgnGetPrimAtPath')
    publish_robot = graph.node('publish_robot', 'omni.isaac.ros2_bridge.ROS2PublishTransformTree')
    prefix_transform = graph.node('prefix_transform', 'omni.graph.scriptnode.ScriptNode')

    on_playback_tick.connect('tick', publish_odom, 'execIn')
    on_playback_tick.connect('tick', publish_map, 'execIn')
    on_playback_tick.connect('tick', publish_robot, 'execIn')
    on_playback_tick.connect('tick', get_base_prim, 'execIn')
    on_playback_tick.connect('tick', prefix_transform, 'execIn')
    read_simulation_time.connect('simulationTime', publish_odom, 'timeStamp')
    read_simulation_time.connect('simulationTime', publish_map, 'timeStamp')
    read_simulation_time.connect('simulationTime', publish_robot, 'timeStamp')

    get_transform.attribute('primPath', prim_path)
    get_transform.connect('localToWorldTransform', extract_translation, 'matrix')
    get_transform.connect('localToWorldTransform', extract_rotation, 'matrix')

    publish_odom.attribute('parentFrameId', odom_frame_id)
    publish_odom.attribute('childFrameId', base_frame_id)
    extract_translation.connect('translation', publish_odom, 'translation')
    extract_rotation.connect('quaternion', publish_odom, 'rotation')

    publish_map.attribute('parentFrameId', map_frame_id)
    publish_map.attribute('childFrameId', odom_frame_id)
    publish_map.attribute('translation', [0., 0., 0.])
    publish_map.attribute('rotation', [0., 0., 0., 1.])

    get_base_prim.attribute('paths', [prim_path])
    get_base_prim.connect('prims', publish_robot, 'parentPrim')
    get_base_prim.connect('prims', publish_robot, 'targetPrims')

    publish_robot.attribute('topicName', internal_tf_topic)

    prefix_transform.create_attribute('inputs:prefix', 'string')
    prefix_transform.attribute('prefix', tf_prefix)
    prefix_transform.create_attribute('inputs:topic', 'string')
    prefix_transform.attribute('topic', internal_tf_topic)
    prefix_transform.create_attribute('inputs:name', 'string')
    prefix_transform.attribute('name', prefixer_node_name)
    prefix_transform.attribute('script', PREFIX_SCRIPT)

    return graph.execute(controller)


PREFIX_SCRIPT = """
import rclpy
from tf2_msgs.msg import TFMessage
import os

def setup(db: og.Database):
    node_name = db.inputs.name
    if not node_name:
        return False

    try:
        rclpy.init()
        db.internal_state.rclpy_was_shutdown = True
    except:
        db.internal_state.rclpy_was_shutdown = False

    db.internal_state.node = rclpy.create_node(node_name)
    db.internal_state.last_message = None

    def tf_callback(msg):
        db.internal_state.last_message = msg

    input_topic = db.inputs.topic
    if not input_topic:
        return False

    db.internal_state.subscriber = db.internal_state.node.create_subscription(
        TFMessage,
        input_topic,
        tf_callback,
        10)

    db.internal_state.publisher = db.internal_state.node.create_publisher(
        TFMessage,
        "/tf",
        10)

    db.internal_state.node.get_logger().info(
        f"'{node_name}' active. Subscribed to '{input_topic}', publishing to '/tf'."
    )

def cleanup(db: og.Database):
    if db.internal_state.node:
        db.internal_state.node.get_logger().info("Shutting down tf_prefixer node.")
        db.internal_state.node.destroy_node()
        db.internal_state.node = None
    if db.internal_state.rclpy_was_shutdown:
        rclpy.shutdown()

def compute(db: og.Database):
    node = db.internal_state.node
    if not node or not rclpy.ok():
        return True

    rclpy.spin_once(node, timeout_sec=0)

    if db.internal_state.last_message is not None:
        incoming_message = db.internal_state.last_message
        db.internal_state.last_message = None

        prefix = db.inputs.prefix

        modified_message = TFMessage()
        for transform in incoming_message.transforms:
            new_transform = transform

            # Only apply prefix if the input string is not empty
            if prefix:
                new_transform.header.frame_id = os.path.join(prefix, transform.header.frame_id)
                new_transform.child_frame_id = os.path.join(prefix, transform.child_frame_id)

            modified_message.transforms.append(new_transform)

        if modified_message.transforms:
            db.internal_state.publisher.publish(modified_message)

    return True
"""
