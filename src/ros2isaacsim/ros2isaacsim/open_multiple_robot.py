#launch Isaac Sim before any other imports
#default first two lines in any standalone application
from isaacsim import SimulationApp
simulation_app = SimulationApp({"headless": True}) # we can also run as headless. Notice: if headless parameter was True, there will not be any window popup

from omni.isaac.cortex.cortex_world import CortexWorld
from omni.isaac.core.prims import XFormPrim
import omni.isaac.core.utils.stage as stage_utils
from omni.isaac.core.utils.prims import delete_prim,get_prim_at_path,set_prim_attribute_value,get_prim_attribute_value,get_prim_attribute_names
from omni.isaac.core.robots import Robot
from omni.isaac.core.utils.stage import add_reference_to_stage
from omni.isaac.core.articulations import Articulation
from omni.isaac.core.utils.extensions import get_extension_path_from_name
from pxr import Gf, PhysxSchema, Sdf, UsdLux, UsdPhysics, UsdGeom
from omni.isaac.core.objects import DynamicCuboid
from omni.isaac.dynamic_control import _dynamic_control
import omni.kit.commands
import numpy as np
import omni


world = CortexWorld()
world.scene.add_default_ground_plane()
stage = omni.usd.get_context().get_stage()

distantLight = UsdLux.DistantLight.Define(stage, Sdf.Path("/DistantLight"))
distantLight.CreateIntensityAttr(300)

path="/World/Camera/MyCamera"
prim_type="Camera"
translation=(1,1,40)

camera_prim = stage.DefinePrim(path, prim_type)

camera_prim_2 = stage.DefinePrim("/World/Camera/MyCamera_2", prim_type)

xform_api=UsdGeom.XformCommonAPI(camera_prim)
xform_api_2=UsdGeom.XformCommonAPI(camera_prim_2)

xform_api.SetTranslate(translation)
xform_api.SetRotate(Gf.Vec3f(0, 0, 90))

xform_api_2.SetTranslate((18.9,-9.5,14.67))
xform_api_2.SetRotate(Gf.Vec3f(56, 0, 60))

add_reference_to_stage(usd_path="/home/sora/Arena4-IsaacSim/robot_models/Arena_rosnav/User/burger.usd", prim_path="/World/waffle")
add_reference_to_stage(usd_path="/home/sora/Arena4-IsaacSim/robot_models/Arena_rosnav/User/burger.usd", prim_path="/World/burger")
# add_reference_to_stage(usd_path="/home/ducanh/Arena4-IsaacSim/robot_models/Arena_rosnav/turtlebot3_burger.usd", prim_path="/World/turtlebot3_burger")

world.scene.add(XFormPrim(prim_path="/World/waffle", name="robot1", position=[0.5,1,0]))
world.scene.add(XFormPrim(prim_path="/World/burger", name="robot2", position=[0.5,0,0]))
# world.scene.add(XFormPrim(prim_path="/World/turtlebot3_burger", name="robot3", position=[0.5,-1,0]))
world.scene.add(DynamicCuboid(prim_path="/World/cube_0",
    name = "cube_0",
    position=np.array([3, 0, 0.25]),
    scale=np.array([0.5, 0.5, 0.5]),
    color=np.array([.2,.3,0.])))

world.scene.add(DynamicCuboid(prim_path="/World/cube_1",
    name = "cube_1",
    position=np.array([-1, 2, 0.25]),
    scale=np.array([0.5, 0.5, 0.5]),
    color=np.array([.2,.3,0.])))

world.scene.add(DynamicCuboid(prim_path="/World/cube_2",
    name = "cube_2",
    position=np.array([-2, 3, 0.25]),
    scale=np.array([0.5, 1.0, 0.5]),
    color=np.array([.2,.4,0.])))
    
world.scene.add(DynamicCuboid(prim_path="/World/cube_3",
    name = "cube_3",
    position=np.array([-1, -1, 0.25]),
    scale=np.array([0.5, 0.5, 0.5]),
    color=np.array([.2,.2,0.])))

world.scene.add(DynamicCuboid(prim_path="/World/cube_4",
    name = "cube_4",
    position=np.array([-2, -2, 0.25]),
    scale=np.array([0.5, 0.5, 0.5]),
    color=np.array([.2,.3,0.])))

world.scene.add(DynamicCuboid(prim_path="/World/cube_5",
    name = "cube_5",
    position=np.array([0.6, -1.4, 0.25]),
    scale=np.array([0.5, 0.5, 0.5]),
    color=np.array([.2,.3,0.])))

world.scene.add(DynamicCuboid(prim_path="/World/cube_6",
    name = "cube_6",
    position=np.array([0.18, 1.77, 0.25]),
    scale=np.array([0.5, 0.5, 0.5]),
    color=np.array([.2,.3,0.])))


stage = omni.usd.get_context().get_stage()

# Get handle to the Drive API for both wheels
left_wheel_drive_waffle = UsdPhysics.DriveAPI.Get(stage.GetPrimAtPath("/World/waffle/base_link/wheel_left_joint"), "angular")
right_wheel_drive_waffle = UsdPhysics.DriveAPI.Get(stage.GetPrimAtPath("/World/waffle/base_link/wheel_right_joint"), "angular")

# front_left_wheel_drive_jackal = UsdPhysics.DriveAPI.Get(stage.GetPrimAtPath("/World/jackal/chassis_link/front_left_wheel_joint"), "angular")
# front_right_wheel_drive_jackal = UsdPhysics.DriveAPI.Get(stage.GetPrimAtPath("/World/jackal/chassis_link/front_right_wheel_joint"), "angular")
# rear_left_wheel_drive_jackal = UsdPhysics.DriveAPI.Get(stage.GetPrimAtPath("/World/jackal/chassis_link/rear_left_wheel_joint"), "angular")
# rear_right_wheel_drive_jackal = UsdPhysics.DriveAPI.Get(stage.GetPrimAtPath("/World/jackal/chassis_link/rear_right_wheel_joint"), "angular")

left_wheel_drive_burger = UsdPhysics.DriveAPI.Get(stage.GetPrimAtPath("/World/burger/base_link/wheel_left_joint"), "angular")
right_wheel_drive_burger = UsdPhysics.DriveAPI.Get(stage.GetPrimAtPath("/World/burger/base_link/wheel_right_joint"), "angular")

# Set the velocity drive target in degrees/second
left_wheel_drive_waffle.GetTargetVelocityAttr().Set(150)
right_wheel_drive_waffle.GetTargetVelocityAttr().Set(200)

# front_left_wheel_drive_jackal.GetTargetVelocityAttr().Set(200)
# front_right_wheel_drive_jackal.GetTargetVelocityAttr().Set(150)
# rear_left_wheel_drive_jackal.GetTargetVelocityAttr().Set(150)
# rear_right_wheel_drive_jackal.GetTargetVelocityAttr().Set(150)

left_wheel_drive_burger.GetTargetVelocityAttr().Set(150)
right_wheel_drive_burger.GetTargetVelocityAttr().Set(200)

# Set the drive damping, which controls the strength of the velocity drive
left_wheel_drive_waffle.GetDampingAttr().Set(20000)
right_wheel_drive_waffle.GetDampingAttr().Set(20000)

# front_left_wheel_drive_jackal.GetDampingAttr().Set(100000000)
# front_right_wheel_drive_jackal.GetDampingAttr().Set(100000000)
# rear_left_wheel_drive_jackal.GetDampingAttr().Set(20000)
# rear_right_wheel_drive_jackal.GetDampingAttr().Set(20000)

left_wheel_drive_burger.GetDampingAttr().Set(20000)
right_wheel_drive_burger.GetDampingAttr().Set(20000)

# Set the drive stiffness, which controls the strength of the position drive
# In this case because we want to do velocity control this should be set to zero
left_wheel_drive_waffle.GetStiffnessAttr().Set(0)
right_wheel_drive_waffle.GetStiffnessAttr().Set(0)

# front_left_wheel_drive_jackal.GetStiffnessAttr().Set(0)
# front_right_wheel_drive_jackal.GetStiffnessAttr().Set(0)
# # rear_left_wheel_drive_jackal.GetStiffnessAttr().Set(0)
# rear_right_wheel_drive_jackal.GetStiffnessAttr().Set(0)

left_wheel_drive_burger.GetStiffnessAttr().Set(0)
right_wheel_drive_burger.GetStiffnessAttr().Set(0)

from omni.isaac.core.utils.rotations import quat_to_euler_angles
# Start simulation
omni.timeline.get_timeline_interface().play()
i = 0
j = 0
print(get_prim_attribute_names(f"/World/waffle"))
while i>-1:
    world.step()
    waffle = get_prim_at_path("/World/waffle")
    print(waffle.GetAttributes())
    print(type(waffle.GetAttribute("xformOp:orient").Get()))
    print(np.array(waffle.GetAttribute("xformOp:orient").Get()))
    quat = waffle.GetAttribute("xformOp:orient").Get()
    print(quat.real)
    print(quat.imaginary[0],quat.imaginary[1],quat.imaginary[2])

    orient_float = np.array(quat_to_euler_angles([quat.real,quat.imaginary[0], quat.imaginary[1], quat.imaginary[2]]),dtype=np.float32)
    print(orient_float)
    quat_float32 = np.array([quat.real, quat.imaginary[0], quat.imaginary[1], quat.imaginary[2]], dtype=np.float32)
    print("Quaternion as float32:", quat_float32)



    print(waffle.GetAttribute("xformOp:orient").Get())
    # print the translation
    print(waffle.GetAttribute("xformOp:translate").Get())
    print(waffle.GetAttribute("xformOp:scale").Get())
    print(waffle.GetAttribute("visibility").Get())
    print(waffle.GetAttribute("purpose").Get())        
    print(waffle.GetAttribute("xformOpOrder").Get())
    set_prim_attribute_value(f"/World/waffle", attribute_name="xformOp:translate", value=np.array([0,0,0]))
    if i == 5:
        break
    i+=1
simulation_app.close()