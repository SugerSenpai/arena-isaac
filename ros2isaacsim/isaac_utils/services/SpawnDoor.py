import math
import os
import typing

import numpy as np
import omni
from isaac_utils.graphs import Graph
from isaac_utils.utils.path import world_path
from omni.isaac.core import World
from omni.isaac.core.objects import FixedCuboid
from omni.isaac.core.utils.rotations import euler_angles_to_quat
from pxr import Gf, UsdGeom
from rclpy.qos import QoSProfile

from isaacsim_msgs.srv import SpawnDoor

from .utils import safe

profile = QoSProfile(depth=2000)


def _sliding_door_controller(door_prim_path: str, name: str):
    graph = Graph(f"/World/Doors/{name}/Controller")

    # nodes
    on_tick = graph.node("on_playback_tick", "omni.graph.action.OnPlaybackTick")

    # context
    get_context = graph.node("get_context", "omni.isaac.core_nodes.IsaacGetContext")
    get_stage = graph.node("get_stage", "omni.isaac.core_nodes.IsaacGetStage")

    # door
    door_prim = graph.node("door_prim", "omni.isaac.core_nodes.OgnGetPrimAtPath")
    door_prim.attribute("primPath", door_prim_path)

    # door scale
    door_scale_attr = graph.node("door_scale_attr", "omni.isaac.core_nodes.OgnGetAttribute")
    door_scale_attr.attribute("prim", door_prim.path)
    door_scale_attr.attribute("attrName", "xformOp:scale")

    # door pose
    door_pose_attr = graph.node("door_pose_attr", "omni.isaac.core_nodes.OgnGetAttribute")
    door_pose_attr.attribute("prim", door_prim.path)
    door_pose_attr.attribute("attrName", "xformOp:translate")

    # peds
    ped_prims = graph.node("ped_prims", "omni.isaac.core_nodes.OgnGetPrimAtPath")
    ped_prims.attribute("primPath", "/World/pedestrians/*")

    # robots
    robot_prims = graph.node("robot_prims", "omni.isaac.core_nodes.OgnGetPrimAtPath")
    robot_prims.attribute("primPath", "/World/Robots/*")

    # combined actors
    actors = graph.node("actors", "omni.graph.nodes.Combine")
    actors.connect("inputs:a", ped_prims, "outputs:prims")
    actors.connect("inputs:b", robot_prims, "outputs:prims")

    # distance
    distance = graph.node("distance", "omni.isaac.core_nodes.OgnIsaacComputeDistance")
    distance.attribute("inputs:prim", door_prim.path)
    distance.connect("inputs:prims", actors, "outputs:combined")

    # if-condition
    condition = graph.node("condition", "omni.graph.nodes.If")
    condition.connect("inputs:condition", distance, "outputs:distance", outputs_prefix="")
    condition.attribute("inputs:threshold", 2.0)

    # scale door
    scale_door = graph.node("scale_door", "omni.isaac.core_nodes.OgnSetAttribute")
    scale_door.attribute("inputs:value", Gf.Vec3f(0.1, 1, 1))
    scale_door.connect("inputs:attr", door_scale_attr, "outputs:attr")

    # reset door
    reset_door = graph.node("reset_door", "omni.isaac.core_nodes.OgnSetAttribute")
    reset_door.attribute("inputs:value", Gf.Vec3f(1, 1, 1))
    reset_door.connect("inputs:attr", door_scale_attr, "outputs:attr")

    # connections
    on_tick.connect("outputs:tick", distance, "inputs:execIn")
    distance.connect("outputs:execOut", condition, "inputs:execIn")
    condition.connect("outputs:true", scale_door, "inputs:execIn")
    condition.connect("outputs:false", reset_door, "inputs:execIn")

    graph.execute(omni.graph.core.Controller())


@safe()
def door_spawner(request, response):
    # Get service attributes
    name = request.name
    kind = request.kind
    width = request.width
    height = request.height
    thickness = request.thickness
    pose = request.pose

    prim_path = world_path('Doors', name)

    # create door
    stage = omni.usd.get_context().get_stage()
    world = World.instance()

    world.scene.add(FixedCuboid(
        prim_path=prim_path,
        name=os.path.basename(prim_path),
        position=np.array([pose.position.x, pose.position.y, pose.position.z]),
        scale=np.array([width, thickness, height]),
        orientation=euler_angles_to_quat([0, 0, pose.orientation.z]),
    ))

    if kind == 'sliding':
        _sliding_door_controller(prim_path, name)

    response.ret = True
    return response


def spawn_door(controller):
    service = controller.create_service(
        srv_type=SpawnDoor,
        qos_profile=profile,
        srv_name='isaac/spawn_door',
        callback=door_spawner
    )
    return service
