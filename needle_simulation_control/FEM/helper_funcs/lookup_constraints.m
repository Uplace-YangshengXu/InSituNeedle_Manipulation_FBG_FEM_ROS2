function constraint_list = lookup_constraints(x, y, k, Interval, Constraints)
needle_coord = [x, y, k]; % N_node x 3
constraint_list = zeros(3, length(x));
bound = 80;

if ~isempty(Constraints)
    constr_coord = Constraints'; % N_constraint x 3
    needle_coord_x_in = floor(x) > Interval{1}(1);
    needle_coord_in = needle_coord(needle_coord_x_in, :);

    constraints_found = zeros(size(needle_coord_in));
    if ~isempty(constraints_found)
        for i = 1:size(needle_coord_in, 1)
            constraint_candidates = constr_coord(...
                (constr_coord(:, 1) > needle_coord_in(i, 1) - bound) & ...
                (constr_coord(:, 1) < needle_coord_in(i, 1) + bound), ...
                :);
            if isempty(constraint_candidates)
                error('I cannot find constraint point when I should! Consider increasing search bound.')
            end
            K = dsearchn(constraint_candidates, needle_coord_in(i, :));
            constraints_found(i, :) = constraint_candidates(K, :);
        end
        constraint_list(:, end - size(constraints_found, 1) + 1 : end) = constraints_found';
    end
end
end