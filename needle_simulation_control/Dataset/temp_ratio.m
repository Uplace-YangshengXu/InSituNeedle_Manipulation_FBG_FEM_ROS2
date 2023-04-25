% created at 24/04/2023 by yangsheng xu
% this script is used to determine the ratio of change of 
% wavelength in each fiber under the influence of temperature

namefilelist = {'temp_fbg_data9.xls','temp_fbg_data8.xls','temp_fbg_data7.xls','temp_fbg_data6.xls','temp_fbg_data5.xls','temp_fbg_data4.xls','temp_fbg_data3.xls','temp_fbg_data2.xls'};

sheet_name = 'Temp_vari_data';

% data file
% format
% 1st unbent data
% 2nd bend data with room temp
% 3rd-end bend data with various temp

ratio_AA1 = [0;0;0];
ratio_AA2 = [0;0;0];

for i = 1:size(namefilelist,2)
    namefile = namefilelist{i};
    data = readmatrix(namefile,'Sheet',sheet_name);
    [r,c ] = size(data); % row and col
    ref = data(1,:);
    unbend = data(2,:);
    % calculate the diff
    dif = data(3:end,:) - unbend;


    % for AA1
    %figure(1)
    %plot(dif(:,1),dif(:,5),'-o');
    %hold on
    %plot(dif(:,1),dif(:,9),'-o');
    ratio_12 = dif(:,1)\dif(:,5); % channel 1 vs channel 2
    ratio_13 = dif(:,1)\dif(:,9); % channel 1 va channel 3
    %plot(dif(:,1),dif(:,1).*ratio_12,'-*');
    %plot(dif(:,1),dif(:,1).*ratio_13,'-*');
    %overall ratio 1:2:3
    ratio_AA1 = ratio_AA1 + [1;ratio_12;ratio_13];
    %legend("ori 1:2","ori 1:3","pre 1:2","pre 1:3");

    % for AA2
    %figure(2)
    %plot(dif(:,2),dif(:,6),'-o');
    %hold on
    %plot(dif(:,2),dif(:,10),'-o');
    ratio_12 = dif(:,2)\dif(:,6); % channel 1 vs channel 2
    ratio_13 = dif(:,2)\dif(:,10); % channel 1 va channel 3
    %plot(dif(:,2),dif(:,2).*ratio_12,'-*');
    %plot(dif(:,2),dif(:,2).*ratio_13,'-*');
    % get the overall ratio 1:2:3
    ratio_AA2 = ratio_AA2 + [1;ratio_12;ratio_13];
    %legend("ori 1:2","ori 1:3","pre 1:2","pre 1:3");

end

% normalize the ratio
ratio_AA1 = ratio_AA1./ratio_AA1(1)
ratio_AA2 = ratio_AA2./ratio_AA2(1)
save('temp_comp_ratios','ratio_AA1','ratio_AA2');