function [S2C, C2S] = produce_constraint_tf_2d(Constraints)
% Calculate change-of-view transformation from constraint points
% Constraint is a 3xn matrix

if isempty(Constraints)
    S2C = eye(3);
    C2S = eye(3);
else
    H_C_S = form_H_2d(Constraints(1, :), Constraints(2, :), Constraints(3, :)); % constraint H
    C2S = H_C_S(1:3, 1:3); % {C} described in {S}
    S2C = invert_H_2d(C2S); % {S} described in {C}
end