function lambdas = lookup_compressions(x, y, ti, Interval, Constraints, constraint_interval)
needle_coord = [x, y]; % N_node x 2

lambdas = ones(length(x), 1); % initialize as ones
bound = 2*constraint_interval; % determines search neighborhood for constraints at each needle point

if ~isempty(Constraints)
    constr_coord = Constraints(1:2, :)'; % N_constraint x 2
    needle_coord_x_in = ceil(x) > Interval{1}(1);
    needle_coord_in = needle_coord(needle_coord_x_in, :);
    vert_dist = zeros(size(needle_coord_in, 1), 1);
    if ~isempty(vert_dist)
        for i = 1:size(needle_coord_in, 1)
            constraint_candidates = constr_coord(...
                (constr_coord(:, 1) > needle_coord_in(i, 1) - bound) & ...
                (constr_coord(:, 1) < needle_coord_in(i, 1) + bound), ...
                :);
            if isempty(constraint_candidates)
                error('I cannot find constraint point when I should! Consider increasing search bound.')
            end
            K = dsearchn(constraint_candidates, needle_coord_in(i, :));
            vert_dist(i) = abs(needle_coord_in(i, 2) - constraint_candidates(K, 2));
        end
        lambdas(end - length(vert_dist) + 1: end) = (ti - vert_dist)/ti;
    end
end
end