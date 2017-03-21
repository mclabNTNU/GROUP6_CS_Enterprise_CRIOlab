%% Input to Safety Zone 

lim=[1.00;-20;6.45/2;-6.45/2];
lim_2=[1.5;-22;7;-7];
K_SZ=[1;1];

%% Input Parameterization 
%Initiate
DesiredPath=0;%Straight line by default; otherwise 1, ellipsoidal line
if DesiredPath==0
    eta_dot_ini = [6;5;0];
else
    eta_dot_ini = [7;0;0];
end
% if straight line
pd_0=[2;0];
pd_1=[10;4];
% if ellipsoidal line
Elipscenter_radi=[6 5;0 3 ];
%InitialPos=[7 ;0];

U_ref=0.1 ;%U_max/5
Kp=[0.2 0 0;0 0.2 0;0 0 0.2];
mu=[0 0.1 1 10];
mu=mu(1);
LAW=1; %Task =1 give  gradient update law, =~1&2 give modified gradient update law3
