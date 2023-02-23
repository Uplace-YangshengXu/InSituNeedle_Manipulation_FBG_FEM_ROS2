function g = ini_motor_controller(address,port)
% old Galil Motor Controller
% address = '192.168.1.201';
% new Galil Motor Controller
address =  '192.168.1.33';
port = 23;
g = galil_connect(address,port); % A connection needs to be made before this line
res = galil_command(g, [char(18), char(22)]);

galil_command(g, 'PT 1,1,1,1');
galil_command(g, 'KP 323,261,300,5');
galil_command(g, 'KI 9,6,7,0');
galil_command(g, 'KD 2746,2453,2600,90');
galil_command(g, 'AC 9216,9216,9216,9260');
galil_command(g, 'DC 9216,9216,9216,9260');
galil_command(g, 'SP 25000,25000,25000,80000');

end
