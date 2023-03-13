function get_key_press
% Help get character code for key pressed
disp('Press any key with current window active')
waitforbuttonpress;
value = double(get(gcf,'CurrentCharacter'));
fprintf('ASCII code: %d\n', value);
close
end