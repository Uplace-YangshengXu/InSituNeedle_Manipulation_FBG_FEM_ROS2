clear
node1 = ros2node('n1');
sub = ros2subscriber(node1, '/sm130');
msg_r = receive(sub, 20);
disp(msg_r.data)
% msg_received = receive(sub, 10);