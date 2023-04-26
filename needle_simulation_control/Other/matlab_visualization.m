% initialize the needleshape sub
close all;
clear;
clc;

Interval = {[0, 100]};
xd = [30 -2 -0.1];
curvature_switch = 1;
%%
% initialize the needleshape sub
needle_subscriber = MatlabRosPubSub('sub','matlab_needle_shape_subscriber','/needle_shape','fbg_msgs/NeedleShape');

if curvature_switch == 1
    if exist("cur_client",'var')
        delete(cur_client)
    end
    cur_client = MatlabRosSrvCli('client','/curv_cli_node',"/cal_curv","fbg_msgs/CalCurvature");
    [connectionStatus,connectionStatustext] = waitForServer(cur_client.cli);

end

[msg_received,status,statustext] = needle_subscriber.getSubMsg(10);

AA_lcn = msg_received.active_area_location;
L = double(msg_received.needle_total_length);
x_new = msg_received.needle_x_axis;
y_new = msg_received.needle_y_axis;
k_new = msg_received.needle_slope;

sz_x_new = size(x_new);
sz_y_new = size(y_new);
sz_k_new = size(k_new);

index_aa  = (AA_lcn  / L)*(size(x_new,1) - 1);
index_tip = (L / L)*(size(x_new,1) - 1);

%%
f = gcf;
set(f, 'Name', sprintf('FEM Needle Reconstruction'));
set(f, 'position', [200,200,2000,1500]);
plt1 = plot(x_new, y_new, 'k-', 'Parent', gca,'LineWidth',5);
hold on
plt2 = plot(x_new(index_aa+1), y_new(index_aa+1), 'r*', 'Parent', gca,'LineWidth', 5);
hold on
plt3 = plot(x_new(index_tip+1), y_new(index_tip+1), 'b*', 'Parent', gca,'LineWidth', 5);
hold on
plt4 = plot(x_new(1),y_new(1),'g*','Parent',gca,'LineWidth',5);
hold on 
plt5 = plot(xd(1),xd(2),'g*','Parent',gca,'LineWidth',5);
hold on

tip_text = text(0,0,"",'FontSize',20,'Parent',gca);
base_text = text(0,0,"",'FontSize',20,'Parent',gca);
AA1_text = text(10,-40,"",'FontSize',20,'Parent',gca);
AA2_text = text(40,-40,"",'FontSize',20,'Parent',gca);
AA3_text = text(70,-40,"",'FontSize',20,'Parent',gca);
AA4_text = text(100,-40,"",'FontSize',20,'Parent',gca);

grid on

xlabel("length",'FontSize',20);
ylabel("deflection",'FontSize',20);
set(gca, "FontSize", 20);

%axis equal;
xlim([-L, 100]);
ylim([-60,60]);

%%
num_inter = size(Interval, 1); 
Ps = [];
titles = [];
Py_Lims = get(gca, 'YLim');
Py_offset = 0;
for j = 1:num_inter
    Px = [Interval{j}(1), Interval{j}(2), Interval{j}(2), Interval{j}(1)];
    Py = [Py_Lims(1) - Py_offset, Py_Lims(1) - Py_offset, Py_Lims(2) + Py_offset, Py_Lims(2) + Py_offset];
    if j == 1
        Ps = patch(Px, Py, 'y', 'FaceAlpha', 0.2);
    else
        Ps = [Ps, patch(Px, Py, j/num_inter, 'FaceAlpha', 0.2)];
    end
end

%%
while 1

    [msg_received,status,statustext] = needle_subscriber.getSubMsg(10);
    x_new = msg_received.needle_x_axis;
    y_new = msg_received.needle_y_axis;
    k_new = msg_received.needle_slope;

    set(plt1,'XData', x_new(1:sz_x_new(1),1:sz_x_new(2)));
    set(plt1, 'YData',y_new(1:sz_y_new(1),1:sz_y_new(2)));
    
    K_tip = k_new(index_tip + 1);
    K_base = k_new(1);
    % plot AA area and tip
    set(plt2,'XData',x_new(index_aa+1))  
    set(plt2,'YData',y_new(index_aa + 1));
    set(plt3,'XData',x_new(index_tip+1))
    set(plt3,'YData',y_new(index_tip + 1));
    set(plt4,'XData',x_new(1));
    set(plt4,'YData',y_new(1));


    str = "Tip: "+ newline + "["+num2str(x_new(index_tip+1)) + "," + num2str(y_new(index_tip+1)) + ";" + num2str(k_new(index_tip+1)) + "]";
    str2 = "Base: "+ newline + "["+num2str(x_new(1)) + "," + num2str(y_new(1)) + ";" + num2str(k_new(1)) + "]";
    set(tip_text,'Position',[x_new(index_tip+1)-5,y_new(index_tip+1)-5], 'String', str);
    set(base_text,'Position',[x_new(1)-5,y_new(1)-5],'String',str2 );
    %% Curvature plotting
    if curvature_switch ==1

        curv_received = getResponseMsg(cur_client);
        curvatures_xy = curv_received.curvature_xy;
        curvatures_xz = curv_received.curvature_xz;

        for i = 1:size(AA_lcn,1)
            if ~(size(curvatures_xz,1))
                curvatures_xz = [0;0;0;0];
            end
            switch i
                case 1 
                    str_A1 = "FBG-AA1: " + newline +num2str(curvatures_xz(1))+" (1/m)";
                    set(AA1_text,'Position',[x_new(index_aa(1)+1)-10,y_new(index_aa(1)+1)+10], 'String', str_A1);
                case 2
                    str_A2 = "FBG-AA2: " + newline +num2str(curvatures_xz(2))+" (1/m)";
                    set(AA2_text,'Position',[x_new(index_aa(2)+1)-10,y_new(index_aa(2)+1)-10], 'String', str_A2);
                case 3
                    str_A3 = "FBG-AA3: " + newline +num2str(curvatures_xz(3))+" (1/m)";
                    set(AA3_text,'Position',[x_new(index_aa(3)+1)-10,y_new(index_aa(3)+1)+10], 'String', str_A3);
                case 4
                    str_A4 = "FBG-AA4: " + newline +num2str(curvatures_xz(4))+" (1/m)";
                    set(AA4_text,'Position',[x_new(index_aa(4)+1)-10,y_new(index_aa(4)+1)-10], 'String', str_A4);
            end
        end
    end
    %%
    drawnow

end
