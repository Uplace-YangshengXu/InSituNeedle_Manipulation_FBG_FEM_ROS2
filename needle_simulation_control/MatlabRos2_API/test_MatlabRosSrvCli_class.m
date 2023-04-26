% test the MatlabRosSrvCli

client = MatlabRosSrvCli('client','/cli_node',"/cal_curv","fbg_msgs/CalCurvature");

[connectionStatus,connectionStatustext] = waitForServer(client.cli);

if exist('client','var') && waitForServer(client.cli)
    msg_received = getResponseMsg(client);
    curvatures_xy = msg_received.curvature_xy;
    curvatures_xz = msg_received.curvature_xz;
end