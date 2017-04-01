%% TMR 4240 Project 2
% Author: Spence, Silas; Holven; Wu, Zhenying;
% Date: Mar. 28, 2017
% Discription: This file initilizes the CSE1 simulation
%%
close all
caseNumber=input('input the case number (1, 2 or 3)\n');
%% Setup for simulation
%for caseNumber = 1         What does this one do?!

%% In put to Unitest SafetyZone Test
lim=[20;-20;9;-9];
lim_2=[25;-25;10;-10];
K=[2;10];
%% controller
p=0.1;%adjustment factor
% K1=p*diag([1,1,4]);
% K2=p*diag([200,50,3]);
K1=diag([1,1,4]);
K2=diag([200,50,3]);
%% vessel parameter
m=14.79;
%% observer parameter
L_1=0.1;
L_2=2;
L_3=0.01;
BiasOffset=0;
l1=[1 0 0;0 1 0;0 0 0.05];
l2=[1 0 0;0 1 0;0 0 0.05];
l3=[1 0 0;0 1 0;0 0 0.05];

switch caseNumber
    case 1  % DP mode
        DesiredPath=0;
        eta_dot_ini = [2;0;0];
        pd=[2 10;0 4];
        Elipscenter_radi=[6 5;0 3 ];
        U_ref=0.16 ;%DP speed
        mu=[0 0.1 1 10];
        mu=mu(1);
        LAW=1; %Task =1 give  gradient update law, =~1 give modified gradient update law
        T_initialDP=90;%Input in seconds
        disp('Running Case 1');
    case 2  % back and forth motion along straight line, with varying speed
        DesiredPath=0;
        eta_dot_ini = [6;5;0];
        pd=[2 10 2 10;0 4 0 4];
        Elipscenter_radi=[6 5;0 3 ];
        U_ref=0.25;%U_max/5
        mu=[0 0.1 1 10];
        mu=mu(2);
        LAW=0; %Task =1 give  gradient update law, =~1 give modified gradient update law
        T_initialDP=0;%Input in seconds
        disp('Running Case 2');
    case 3  %infinite ellipsoid motion
        DesiredPath=1; %ellipsoidal path
        eta_dot_ini = [7;0;0];
        pd=[2 10;0 4];

        Elipscenter_radi=[6 5;0 3 ];
        U_ref=0.1;%U_max/5
        mu=[0 0.1 1 10];
        mu=mu(2);
        LAW=0; %Task =1 give  gradient update law, =~1 give modified gradient update law
        T_initialDP=0;%Input in seconds
        disp('Running Case 3');
end
%end
%%

T_initialDP=T_initialDP*100;





