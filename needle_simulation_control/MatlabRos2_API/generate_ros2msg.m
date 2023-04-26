% matlab ros msg folder generation

function generate_ros2msg(current_working_path)

% build the custom message and service type
% ros packge under pwd/custom/msg or pwd/custom/srv

folderPath = fullfile(current_working_path,"../custom");
matlab_msg_folderpath = fullfile(folderPath,"matlab_msg_gen");

% delete exist matlab msg folder
if exist(matlab_msg_folderpath,'file')
    status = rmdir(matlab_msg_folderpath,'s');
    if status == 1
        disp("deleted matlab msg folder");
    end
end

% generate matlab msg folder
ros2genmsg(folderPath)

end