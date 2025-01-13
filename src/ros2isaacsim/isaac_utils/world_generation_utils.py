import math
import random
import numpy as np
import omni.replicator.core as rep
import omni.usd
from pxr import Gf, UsdGeom
from yaml_utils import read_yaml_config
from services.SpawnWall import wall_spawner
from omni.isaac.core import World

def register_wall_spawner(forklift_prim, walls_config):
    """
    Registers a randomizer function that spawns walls around the forklift_prim.
    Each time `rep.randomizer.spawn_walls()` is triggered, new walls are generated.
    """
    data = read_yaml_config(walls_config)
    
    walls = data.get("walls",[])
    
    def spawn_walls():        
        # 2) For each wall, pick a random angle and radius, then compute start & end in the XY plane
        for wall in walls.items():
            wall_name = wall[0]
            params = wall[1]
            request = {
            "name": wall_name,
            "world_path": "/World/Walls",  # A parent prim path for all walls
            "start": params["start"],
            "end":   params["end"],
            "height": params["height"],
            }
            response = wall_spawner(request)
        
        return response.ret  # we return None or the node, but randomizers typically return a node handle

    # Finally, register this spawn_walls function as a randomizer in Replicator
    rep.randomizer.register(spawn_walls)
