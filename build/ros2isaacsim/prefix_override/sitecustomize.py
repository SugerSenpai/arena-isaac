import sys
<<<<<<< HEAD
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/sora/Arena4-IsaacSim/install/ros2isaacsim'
=======
if sys.prefix == '/home/kien/arena4_ws/src/arena/arena-rosnav/.venv':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/kien/Documents/Arena4-IsaacSim/install/ros2isaacsim'
>>>>>>> an
