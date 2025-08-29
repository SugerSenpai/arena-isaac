import math
import os

import numpy as np
import omni
from isaac_utils.utils.path import world_path
from omni.isaac.core import World
from omni.isaac.core.objects import FixedCuboid
from omni.isaac.core.utils.rotations import euler_angles_to_quat
from pxr import Gf
from rclpy.qos import QoSProfile
from pathlib import Path
import yaml 
from dataclasses import dataclass

from isaacsim_msgs.srv import SpawnWall

from .utils import safe

profile = QoSProfile(depth=2000)


@safe()
def wall_spawner(request, response):
    # Get service attributes
    prim_path = world_path('Walls', request.name)
    # asset_prim_path = world_path('Walls',request.name + "_part")
    height = request.height
    width = request.width
    wall_material = request.material
    z_offset = request.z_offset
    # type_path = os.path.join(os.environ['ARENA_WS_DIR'],f'src/arena/simulation-setup/entities/walls/{type_}.yaml')
    # data = yaml.safe_load(Path(type_path).read_text())

    materials_path = os.path.join(os.environ['ARENA_WS_DIR'],f'src/arena/simulation-setup/entities/materials/materials.yaml')
    materials_data = yaml.safe_load(Path(materials_path).read_text())

    # entries: list[AssetEntry] = []

    # for item in data.get("main", []):
    #     # detect whether this is a "fill" or a "tile"
    #     if "fill" in item:
    #         kind = "fill"
    #         name = item["fill"]
    #     elif "tile" in item:
    #         kind = "tile"
    #         name = item["tile"]
    #     else:
    #         # skip any other macro types for now
    #         continue

    #     entries.append(
    #         AssetEntry(
    #             kind=kind,
    #             name=name,
    #             file         = item.get("file", ""),
    #             every        = float(item.get("every",0.0)),
    #             height       = float(item.get("height", 0.0)),
    #             width        = float(item.get("width",0.0)),
    #             x_offset     = float(item.get("x_offset", item.get("x-offset", 0.0))),
    #             y_offset     = float(item.get("y_offset", item.get("y-offset", 0.0))),
    #             z_offset     = float(item.get("z_offset", item.get("z-offset", 0.0))),
    #             material     = item.get("material", ""),
    #         )
    #     )
    

    start = np.append(np.array(request.start), z_offset + height / 2)
    end = np.append(np.array(request.end), z_offset + height / 2)

    start_vec = Gf.Vec3d(*start)
    end_vec = Gf.Vec3d(*end)

    vector_ab = end - start

    center = (start_vec + end_vec) / 2

    length = np.linalg.norm(vector_ab[:2])
    angle = math.atan2(vector_ab[1], vector_ab[0])
    # print("wall angle", angle)
    scale = Gf.Vec3f(*[length, width , height])

    # create wall
    stage = omni.usd.get_context().get_stage()
    world = World.instance()

    world.scene.add(FixedCuboid(
        prim_path=prim_path,
        name=os.path.basename(prim_path),
        position=center,
        scale=scale,
        orientation=euler_angles_to_quat([0, 0, angle]),
    ))
    if wall_material != '':
        for material in materials_data.get("wall_mat",[]):
            if material.get('material') == wall_material:
                mdl_path = material.get('url')
                material_name = material.get('material_name')
            mtl_path = f"/World/Looks/Wall_{request.name}_Material"
            mtl = stage.GetPrimAtPath(mtl_path)

        if not (mtl and mtl.IsValid()):
            create_res = omni.kit.commands.execute('CreateMdlMaterialPrimCommand',
                                                        mtl_url=mdl_path,
                                                        mtl_name=material_name,
                                                        mtl_path=mtl_path)

            bind_res = omni.kit.commands.execute('BindMaterialCommand',
                                                    prim_path=prim_path,
                                                    material_path=mtl_path)
    # mdl_path = f"https://omniverse-content-production.s3.us-west-2.amazonaws.com/Materials/2023_1/Base/Wood/{material}.mdl"
    # mtl_path = "/World/Looks/WallMaterial"
    # mtl = stage.GetPrimAtPath(mtl_path)
    # if not (mtl and mtl.IsValid()):
    #     create_res = omni.kit.commands.execute('CreateMdlMaterialPrimCommand',
    #                                            mtl_url=mdl_path,
    #                                            mtl_name=material,
    #                                            mtl_path=mtl_path)

    # bind_res = omni.kit.commands.execute('BindMaterialCommand',
    #                                      prim_path=prim_path,
    #                                      material_path=mtl_path)

    # for asset in entries:
    #     if asset.kind == 'fill':
    #         asset_prim_path = world_path('Walls',request.name + "_" + asset.name)
    #         asset_start = np.append(np.array([request.start[0] - asset.x_offset,request.start[1]- asset.y_offset]), asset.z_offset)
    #         asset_end = np.append(np.array([request.end[0] - asset.x_offset,request.end[1]- asset.y_offset]), asset.z_offset)
    #         asset_start_vec = Gf.Vec3d(*asset_start)
    #         asset_end_vec = Gf.Vec3d(*asset_end)
    #         asset_center = (asset_start_vec + asset_end_vec)/2
    #         asset_vector_ab = asset_end - asset_start
    #         asset_length = np.linalg.norm(asset_vector_ab[:2])
    #         asset_scale = Gf.Vec3f(*[asset_length,0.075,asset.height])
    #         for material in materials_data.get("wall_mat",[]):
    #             if material.get('material') == asset.material:
    #                 asset_mdl_path = material.get('url')
    #                 asset_material_name = material.get('material_name')
    #         asset_mtl_path = f"/World/Looks/Wall_{asset.name}_Material"
    #         asset_mtl = stage.GetPrimAtPath(asset_mtl_path)

    #         world.scene.add(FixedCuboid(
    #             prim_path=asset_prim_path,
    #             name=os.path.basename(asset_prim_path),
    #             position=asset_center,
    #             scale=asset_scale,
    #             orientation=euler_angles_to_quat([0, 0, angle]),
    #         ))

    #         if not (asset_mtl and asset_mtl.IsValid()):
    #             create_res = omni.kit.commands.execute('CreateMdlMaterialPrimCommand',
    #                                                 mtl_url=asset_mdl_path,
    #                                                 mtl_name=asset_material_name,
    #                                                 mtl_path=asset_mtl_path)

    #         bind_res = omni.kit.commands.execute('BindMaterialCommand',
    #                                             prim_path=asset_prim_path,
    #                                             material_path=asset_mtl_path)

    response.ret = True
    return response


def spawn_wall(controller):
    service = controller.create_service(
        srv_type=SpawnWall,
        qos_profile=profile,
        srv_name='isaac/spawn_wall',
        callback=wall_spawner
    )
    return service
