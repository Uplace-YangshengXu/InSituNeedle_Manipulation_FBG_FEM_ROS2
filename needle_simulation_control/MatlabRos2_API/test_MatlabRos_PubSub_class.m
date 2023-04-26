% test the MatlabRosPubSub

%publisher = MatlabRosPubSub('pub','matlab_test_publisher','/sm130_pub','fbg_msgs/FbgReading');
subscriber = MatlabRosPubSub('sub','matlab_curvature_subscriber','/sm130','fbg_msgs/FBGReading');

%msg = ros2message("fbg_msgs/FbgReading");
%msg.signal_reading = [];
%publisher.sendPubMsg(msg)
[msg_received,status,statustext] = subscriber.getSubMsg(10);
disp(msg_received.signal_reading)

delete(subscriber);