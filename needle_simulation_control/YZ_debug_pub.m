clear
node2 = ros2node('n2');
pub = ros2publisher(node2, '/sm130', 'std_msgs/Bool');
msg = ros2message('std_msgs/Bool');
msg.data = true;
while 1
    send(pub, msg);
end
% msg_received = receive(sub, 10);