# InSituNeedle_Manipulation_FBG_FEM_ROS2
This repo tries to set the project in FBG_MATLAB on ROS2

## Configurate matlab_ros2 communication 
## Custom msg and srv type in matlab
Place ros2 .msg file in ./needle_simulation_control/custom/package_name/msg

Place ros2 .srv file in ./needle_simulation_control/custom/package_name/srv

##Automatically remove and auto build the matlab_ros2 workspace

    generate_ros2msg(pwd)
pwd: the absolute dir of ./needle_simulation_control

For matlab_ros2 communication, see:

test_matlabros_class.m

test_MatlabRosSrvCli.m

##Usage

Publisher node: 

Recieve data from the interrogator.


    ros2 run sm130_interrogator talker

Server node: 

Provide curvature calculation service, which also sub to the aforementioned pub.


    ros2 run curvature_srvcli server

Or using launch file:

    ro2 launch curvature_srvcli curvature_launch.xml

##Other executable:

Client node:

    ros2 run curvature_srvcli client

Publihser node for matlab pubsub communication:

Publishing curvature.msg to matlab. 

    ros2 run curvature_srvcli publisher
    ros2 launch curvature_srvcli sm130_launch.xml



