import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ducanh/Arena4-IsaacSim/install/ros2isaacsim'
