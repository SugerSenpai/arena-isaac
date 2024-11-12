from setuptools import find_packages
from setuptools import setup

setup(
    name='isaacsim_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('isaacsim_msgs', 'isaacsim_msgs.*')),
)
