%%build the custom message and service type
%%ros packge under pwd/custom/msg or pwd/custom/srv

% folderPath = fullfile(pwd,"custom");
% ros2genmsg(folderPath)

%%
% clc
% clear all
cli_node = ros2node('/cli_node')
client = ros2svcclient(cli_node,"/test","example_interfaces/AddTwoInts")
[connectionStatus,connectionStatustext] = waitForServer(client);
request = ros2message(client);

request.a = int64(1);
request.b = int64(1);
pause(1)

if(isServerAvailable(client))
    disp(request)
    response = call(client,request);
end

%%
% device = ros2device('localhost');
% device.ROS2Folder = '/opt/ros/galactic';
% device
% device.AvailableNodes