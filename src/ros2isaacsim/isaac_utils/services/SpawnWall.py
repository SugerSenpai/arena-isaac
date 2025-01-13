import omni
import numpy as np
from pxr import Gf, UsdGeom, Usd, Sdf
import math
import rclpy
from isaacsim_msgs.srv import SpawnWall
from omni.isaac.core.utils.rotations import euler_angles_to_quat, quat_to_euler_angles
from omni.isaac.core.objects import cuboid, sphere, capsule
from omni.isaac.core import World

def wall_spawner(request,response):
    #Get service attributes
    name = request.name
    world_path = request.world_path
    height = request.height
    
    start = np.append(np.array(request.start),height/2)
    end =  np.append(np.array(request.end),height/2)
    
    print(name)
    start_vec = Gf.Vec3d(*start)
    end_vec = Gf.Vec3d(*end)

    vector_ab = end - start 
    print(vector_ab)
    
    center = (start_vec + end_vec)/2
    print(center)
    length = np.linalg.norm(vector_ab[:2])
    angle = math.atan2(vector_ab[1], vector_ab[0])
    print(angle)
    
    scale=Gf.Vec3f(*[length/2,0.05, height/2])

    #create wall
    stage = omni.usd.get_context().get_stage()
    world = World.instance()
    
    # wall = UsdGeom.Cube.Define(stage, f"{world_path}/{name}")
    # wall_transform = UsdGeom.XformCommonAPI(wall)
    
    # prim: Usd.Prim = stage.GetPrimAtPath(f"{world_path}/{name}")
    
    # wall.AddTranslateOp().Set(center)
    # wall_transform.SetScale(scale)
    # wall.AddRotateXOp().Set(0)
    # wall.AddRotateYOp().Set(0)
    # wall.AddRotateZOp().Set(math.degrees(angle))
    # wall.AddRotateWOp().Set(0)
    
    
    world.scene.add(cuboid.VisualCuboid(
    prim_path=f"{world_path}/{name}",
    name = name,
    position=center,
    scale=scale,
    orientation = euler_angles_to_quat([0,0,math.degrees(angle)]),
    color=np.array([0, 0, 0.02]),
    ))



    response.ret = True
    return response

def spawn_wall(controller):
    service = controller.create_service(srv_type=SpawnWall, 
                        srv_name='isaac/spawn_wall', 
                        callback=wall_spawner)
    return service