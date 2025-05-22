import os


def world_path(*path: str) -> str:
    return os.path.join('/World', *path)
