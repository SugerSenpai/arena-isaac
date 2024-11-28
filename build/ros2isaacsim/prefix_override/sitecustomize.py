import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/sora/Arena4-IsaacSim/install/ros2isaacsim'
