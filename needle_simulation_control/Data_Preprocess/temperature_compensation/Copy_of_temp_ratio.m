% this copy of script is to test the ratio of AA3 and AA4

addpath temp_demo_data/
namefilelist = {'tem_comp_Tvar_C0.xls','tem_comp_Tvar_C1.xls','tem_comp_Tvar_C2.xls','tem_comp_Tvar_C3.xls'};
%namefilelist = {'tem_comp_Tvar_C0.xls'};
sheet_name = 'Temp_vari_data';

% data file
% format
% 1st unbent data
% 2nd bend data with room temp
% 3rd-end bend data with various temp

ratio_AA3 = [0;0];
ratio_AA4 = [0;0];

%data_ref  = readmatrix('tem_comp_ground_truth.xls','Sheet',sheet_name);

for i = 1:size(namefilelist,2)
    cmap = hsv(2*size(namefilelist, 2));

    namefile = namefilelist{i};
    data = readmatrix(namefile,'Sheet',sheet_name);
    [r,c ] = size(data); % row and col
    %ref = data_ref(i,:);
    ref = data(1,:);
    % calculate the diff
    dif = data(1:end,:) - ref;


    % for AA3'o');
    figure(1)
    axis equal
    plot(dif(:,3),dif(:,7),'o', 'Color', cmap(2*i - 1, :));
    hold on


    ratio_12 = dif(:,3)'/dif(:,7)'; % channel 1 vs channel 2
    %ratio_13 = dif(:,1)'/dif(:,9)'; % channel 1 va channel 3

    plot(dif(:,3),dif(:,3)./ratio_12,'-*', 'Color', cmap(2*i - 1, :));
    %plot(dif(:,1),dif(:,1)./ratio_13,'-*', 'Color', cmap(2*i, :));

    %overall ratio 1:2:3
    ratio_AA3 = ratio_AA3 + [1;1/ratio_12];
    
    % for AA2
    figure(2)
    axis equal
    plot(dif(:,4),dif(:,8),'o', 'Color', cmap(2*i - 1, :));
    hold on
    %plot(dif(:,2),dif(:,10),'o', 'Color', cmap(2*i, :));
    ratio_12 = dif(:,4)'/dif(:,8)'; % channel 1 vs channel 2
    %ratio_13 = dif(:,2)'/dif(:,10)'; % channel 1 va channel 3

    plot(dif(:,4),dif(:,4)./ratio_12,'-*', 'Color', cmap(2*i - 1, :));
    %plot(dif(:,2),dif(:,2)./ratio_13,'-*', 'Color', cmap(2*i, :));

    % get the overall ratio 1:2:3
    ratio_AA4 = ratio_AA4 + [1;1/ratio_12];
    
    %legend("ori 1:2","ori 1:3","pre 1:2","pre 1:3");

end

% normalize the ratio
ratio_AA3 = ratio_AA3./ratio_AA3(1)
ratio_AA4 = ratio_AA4./ratio_AA4(1)
%save('temp_comp_ratios','ratio_AA1','ratio_AA2');
