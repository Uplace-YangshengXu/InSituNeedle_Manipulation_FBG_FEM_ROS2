function invH = invert_H_2d(H)
R = H(1:2, 1:2);
t = H(1:2, 3);
invH = [transpose(R), - transpose(R)*t; 0, 0, 1];
end