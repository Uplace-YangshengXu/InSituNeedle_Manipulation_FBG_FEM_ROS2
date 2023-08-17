%% Simulation of Flexible Needle Insertion
% Yanzhou Wang
% Nov 27 2022

%% General environment setup
clear
close all
clc
addpath(genpath('./FEM'));

disp('Press ESC to quit')

%% Simulation environment and initial conditions
Alpha_1 = -1;
Mu_1 = 3e+4;
Alpha_2 = -1;
Mu_2 = 6e+3;

Mu = [Mu_1; Mu_2];
Alpha = [Alpha_1; Alpha_2];
Interval = {[0, 30]; [30, 80]};
Constraints = []; % to store constraint points [px, py]
Ti = [50; 50];

L = 50; % total length of the needle
global bx by bk % needle base config, can be changed by keyboard
bx = -51; % needle base x coord
by = 0; % needle base y coord
bk = 0; % needle base slope

x = linspace(bx, bx + L, L + 1)'; % nodal x coordinates; column vector
y = by*ones(size(x)); % nodal y coordinates
k = bk*ones(size(x)); % nodal slopes

%% Plotting setup
fig = figure;
hold on
set(fig, 'WindowKeyPressFcn', @KeyPressCallback);

% Needle
plt = plot(x, y, '-', 'LineWidth', 2, 'Color', 'k');
set(gca, 'XLim', [bx, Interval{end}(2)]);
axis equal
xL=xlim;
yL=ylim;

h_text_tip = text(0, 0, 'temp');
h_text_base = text(0, 0, 'temp');
f_text = text(0.99*xL(2), 0.99*yL(2), 'temp', ...
    'HorizontalAlignment','right','VerticalAlignment','top');


% Tissue patches
num_inter = size(Interval, 1);
cmap = colormap(parula(num_inter));
Ps = [];
titles = [];
Py_Lims = get(gca, 'YLim');
Py_offset = 0;
for j = 1:num_inter
    Px = [Interval{j}(1), Interval{j}(2), Interval{j}(2), Interval{j}(1)];
    Py = [Py_Lims(1) - Py_offset, Py_Lims(1) - Py_offset, Py_Lims(2) + Py_offset, Py_Lims(2) + Py_offset];
    Ps = [Ps, patch(Px, Py, cmap(j, :), 'FaceAlpha', 0.2)];
end

% Constraint points
c_plt = plot(0);
c_plt.XData = []; c_plt.YData = [];
c_plt.Marker = '+'; c_plt.LineStyle = 'none';

xlabel('Depth (mm)');
ylabel('Displacement (mm)');
hold off

%% Simulation
global ESC_PRESSED
ESC_PRESSED = 0;

while ~ESC_PRESSED && ishghandle(fig)
    dbx = bx - x(1); % change in base x coordinate
    dby = by - y(1); % change in base y coordinate
    dbk = bk - k(1); % change in base slope
    tic
    [x, y, k, Constraints] = planar_needle_FEM_wc(L, Mu, Alpha, Interval, Ti, ... % params
        x, y, k, Constraints, ...% previous states
        dbx, dby, dbk, ...
        [], []); % change in needle base config
    

%         [x, y, k] = planar_needle_FEM(L, Mu, Alpha, Interval, ... % params
%             x, y, k, ...% previous states
%             dbx, dby, dbk, ...
%             [], []); % change in needle base config
    t = toc;
    set(plt, 'XData', x);
    set(plt, 'YData', y);
    if ~isempty(Constraints)
        set(c_plt, 'XData', Constraints(1, :));
        set(c_plt, 'YData', Constraints(2, :));
    else
        set(c_plt, 'XData', []);
        set(c_plt, 'YData', []);
    end
    set(h_text_tip, 'String', sprintf('[%.2f, %.2f, %.2f]', x(end), y(end), k(end)));
    set(h_text_tip, 'Position', [x(end), y(end)]);
    set(h_text_base, 'String', sprintf('[%.2f, %.2f, %.2f]', x(1), y(1), k(1)));
    set(h_text_base, 'Position', [x(1), y(1)]);
    set(f_text, 'String', sprintf('%.0f Hz', 1/t));
    drawnow;
end
close all % close figure window

%% Key Press Function
function KeyPressCallback(source, eventdata)
global bx by bk
global ESC_PRESSED

key = eventdata.Key;
if strcmpi(key, 'rightArrow')
    bx = bx + 0.1;
elseif strcmpi(key, 'leftArrow')
    bx = bx - 0.1;
elseif strcmpi(key, 'upArrow')
    by = by + 0.1;
elseif strcmpi(key, 'downArrow')
    by = by - 0.1;
elseif strcmpi(key, 'equal')
    bk = bk + 0.01;
elseif strcmpi(key, 'hyphen')
    bk = bk - 0.01;
elseif strcmpi(key, 'escape')
    ESC_PRESSED = 1;
end
end