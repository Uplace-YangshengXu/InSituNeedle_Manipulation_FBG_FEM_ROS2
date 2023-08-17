% created at 6/06/2023 by yangsheng xu
% this script is used to determine the ratio of change of 
% wavelength in each fiber under the influence of temperature

clear;
clc;

namefilelist = {'tem_comp_ground_truth.xls','tem_comp_Tvar_C0.xls'};
sheet_name = 'Temp_vari_data';

% data file
% format
% 1st unbent data
% 2nd-end bend data with various cur

ratio_AA1 = [0;0;0];
ratio_AA2 = [0;0;0];

data_ref  = readmatrix(namefilelist{1},'Sheet',sheet_name);
data_ref_dif = data_ref - data_ref(1,:);

for i = 2:size(namefilelist,2)
    namefile = namefilelist{i};
    data = readmatrix(namefile,'Sheet',sheet_name);
    % calculate the diff
    dif = data - data_ref;


    % for AA1
    figure(1)
    plot(dif(:,1),dif(:,5),'-o');
    hold on
    plot(dif(:,1),dif(:,9),'-o');


    ratio_12 = dif(:,1)'/dif(:,5)'; % channel 1 vs channel 2
    ratio_13 = dif(:,1)'/dif(:,9)'; % channel 1 va channel 3
    

    plot(dif(:,1),dif(:,1)/ratio_12,'-*');
    plot(dif(:,1),dif(:,1)/ratio_13,'-*');

%     figure(3)
%     plot(dif(:,1) ,dif(:,9) - dif(:,1) ./ ratio_13);
    %overall ratio 1:2:3
    ratio_AA1 = ratio_AA1 + [1;1/ratio_12;1/ratio_13];
    
    legend("ori 1:2","ori 1:3","pre 1:2","pre 1:3");

    % for AA2
    figure(2)
    plot(dif(:,2),dif(:,6),'-o');
    hold on
    plot(dif(:,2),dif(:,10),'-o');
    ratio_12 = dif(:,2)'/dif(:,6)'; % channel 1 vs channel 2
    ratio_13 = dif(:,2)'/dif(:,10)'; % channel 1 va channel 3

    plot(dif(:,2),dif(:,2)/ratio_12,'-*');
    plot(dif(:,2),dif(:,2)/ratio_13,'-*');

    % get the overall ratio 1:2:3
    ratio_AA2 = ratio_AA2 + [1;1/ratio_12;1/ratio_13];
    
    legend("ori 1:2","ori 1:3","pre 1:2","pre 1:3");

end

% normalize the ratio
ratio_AA1 = ratio_AA1./ratio_AA1(1)
ratio_AA2 = ratio_AA2./ratio_AA2(1)
save('temp_comp_ratios','ratio_AA1','ratio_AA2');
