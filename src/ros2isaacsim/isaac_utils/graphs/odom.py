import omni.graph.core as og
from isaac_utils.graphs import Graph


def odom(
    graph_path: str,
    prim_path: str,
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

    on_playback_tick = graph.node('on_playback_tick', 'omni.graph.action.OnPlaybackTick')
    get_robot_prim = graph.node('get_robot_prim', 'omni.replicator.core.OgnGetPrimAtPath')
    get_pose = graph.node('get_pose', 'omni.isaac.core_nodes.IsaacReadWorldPose')
    extract_translation = graph.node('extract_translation', 'omni.graph.nodes.ExtractAttribute')
    extract_rotation = graph.node('extract_rotation', 'omni.graph.nodes.ExtractAttribute')
    publish_odom = graph.node('publish_odom', 'omni.isaac.ros2_bridge.ROS2PublishRawTransformTree')
    publish_map = graph.node('publish_odom_static', 'omni.isaac.ros2_bridge.ROS2PublishRawTransformTree')

    on_playback_tick.connect('tick', publish_odom, 'execIn')
    on_playback_tick.connect('tick', publish_map, 'execIn')

    get_robot_prim.attribute('paths', [prim_path])
    get_robot_prim.connect('prims', get_pose, 'prim')

    extract_translation.attribute('attrName', 'xformOp:translate')
    extract_rotation.attribute('attrName', 'xformOp:orient')
    get_pose.connect('primsBundle', extract_translation, 'data', outputs_prefix='outputs_')
    get_pose.connect('primsBundle', extract_rotation, 'data', outputs_prefix='outputs_')

    publish_odom.attribute('parentFrameId', odom_frame_id)
    publish_odom.attribute('childFrameId', base_frame_id)
    extract_translation.connect('output', publish_odom, 'translation')
    extract_rotation.connect('output', publish_odom, 'rotation')

    publish_map.attribute('parentFrameId', map_frame_id)
    publish_map.attribute('childFrameId', odom_frame_id)
    publish_map.attribute('translation', [0., 0., 0.])
    publish_map.attribute('rotation', [0., 0., 0., 1.])

    return graph.execute(controller)
