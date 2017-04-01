clear
clc
close all
Input_v2
disp('Done! Input');
Simulation_Time=1500;
sim('ModelPlant_DP_v3.slx')
disp('Done! Simulink');
Plot
disp('Done! Plot');

