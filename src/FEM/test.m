% % folderPath = fullfile(pwd,"custom");
% % ros2genmsg(folderPath)
% cli_node = ros2node('matlab_cli');
% % ros2 node list
% % ros2 service list
% serviceTypes = ros2("service","type","/cal_curv")
% testclient = ros2svcclient(cli_node,"/cal_curv","fbg_msgs/CalCurvature");
% % % testreq = ros2message(testclient)
node_1 = ros2node('node_1_service_client');
node_2 = ros2node('node_2_service_client');
ros2 node list

server = ros2svcserver(node_1,'/test','test_msgs/BasicTypes',@flipString);
client = ros2svcclient(node_2,'/test','test_msgs/BasicTypes');
[connectionStatus,connectionStatustext] = waitForServer(client);
request = ros2message(client);
request.string_value = 'hello world';

if(isServerAvailable(client))
    response = call(client,request,'Timeout',3);
end

response.string_value

function resp = flipString(req,resp)
% FLIPSTRING Reverses the order of a string in REQ and returns it in RESP.
resp.string_value = fliplr(req.string_value);
end