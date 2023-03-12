# InSituNeedle_Manipulation_FBG_FEM_ROS2
This repo tries to set the project in FBG_MATLAB on ROS2

# Initialization matlab_ros2 communication 
# Custom msg and srv type in matlab
Place ros2 .msg file in ./needle_simulation_control/custom/package_name/msg
Place ros2 .srv file in ./needle_simulation_control/custom/package_name/srv
# pwd = './needle_simulation'
# Automatically remove and auto build the matlab_ros2 workspace
generate_ros2msg(pwd)

For matlab_ros2 communication, see:
test_matlabros_class.m
test_MatlabRosSrvCli.m
