function output = gradient_radian_conversion(input, direction)
% convert between gradient and radian
% Input: 'direction' has to be either 'r2g' (radian to gradient) or 'g2r'
% (gradient to radian)
% Output: output of conversion based on conversion direction

if strcmp(direction, 'r2g')
    output = tan(input);
elseif strcmp(direction, 'g2r')
    output = atan(input);
end
end