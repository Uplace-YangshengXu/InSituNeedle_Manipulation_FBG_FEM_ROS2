A = rand(2,3);
delta = [];

a = 5*rand()

for i = 1:3
th = 0;
delta = [delta 10*rand*[sin(th),-sin(pi/3+th),sin(pi/3-th)]'+0.01*randn(3,1)];
th = 90;
delta = [delta 10*rand*[sin(th),-sin(pi/3+th),sin(pi/3-th)]'+0.01*randn(3,1)];
end

C = A*(delta)
A3 = C/delta(1:2,:);
A2 = C/[delta(1,:);delta(3,:)];
A1 = C/delta(2:3,:);

D = A - A3*[1 0 0;0 1 0];
null(D);

y3 = (A*(delta(1:3,1)+[a;a;a])-A3*(delta(1:2,1)+[a;a]));
y2 = (A*(delta(1:3,1)+[a;a;a])-A2*([delta(1,1);delta(3,1)]+[a;a]));
y1 = (A*(delta(1:3,1)+[a;a;a])-A1*(delta(2:3,1)+[a;a]));

x3 = (A*[1;1;1;]-A3*[1;1]);
x2 = (A*[1;1;1;]-A2*[1;1]);
x1 = (A*[1;1;1;]-A1*[1;1]);

apre = [y3 y2 y1]/[x3 x2 x1];

a_preict = 1/2*(apre(1,1)+apre(2,2))

C_pre = A*(delta+a-a_preict)
C_nopre = A*(delta+a)

%%
th = 0;
delta_0 = 10*[sin(th) + 0.1*randn,-sin(pi/3+th),sin(pi/3-th)]'+0.1*randn(3,1)
C_0 = A * delta_0

C_pre_0 = A*(delta_0+a-a_preict)
C_nopre_0 = A*(delta_0+a)