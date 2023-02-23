folderPath = fullfile(pwd,"custom");
ros2genmsg(folderPath)
% 
% 

%%
% clc
% clear all
clear cli_node
cli_node = ros2node('/cli_node')
ros2 node list
testclient = ros2svcclient(cli_node,"/cal_curv","fbg_msgs/CalCurvature")
[connectionStatus,connectionStatustext] = waitForServer(testclient);
request = ros2message(testclient);
request.command ='requested';
isServerAvailable(testclient)




if(isServerAvailable(testclient))
    ros2 node list
    disp(request)
    response = call(testclient,request)
end
% testreq = ros2message(testclient)
%%
device = ros2device('localhost');
device.ROS2Folder = '/opt/ros/galactic';
device
device.AvailableNodes