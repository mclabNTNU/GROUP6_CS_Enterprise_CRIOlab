% Bow thruster
%BT_min_pwm     = 3.03;
%BT_max_pwm     = 6.90;
%BT_u2pwm_gain  = (BT_max_pwm-BT_min_pwm)/2;
%BT_zero_pwm    = BT_min_pwm + BT_u2pwm_gain;

% Voith Schneider propellers
VSP_min_pwm    = 3.12;
VSP_max_pwm    = 6.90;
VSP_u2pwm_gain = (VSP_max_pwm-VSP_min_pwm)/2;
VSP_zero_pwm   = VSP_min_pwm + VSP_u2pwm_gain;

% Servos
%              Servo1 servo2 servo3 servo4
measurments = [4.25   5.20   4.95   3.85  % N
               4.30   4.50   5.60   3.90  % NE
               4.90   4.05   5.89   4.38  % E
               5.40   4.10   5.60   5.00  % SE
               5.99   4.70   4.95   5.50  % S
               5.75   5.50   4.35   5.40  % SW
               5.25   5.75   4.15   4.85  % W
               4.60   5.65   4.20   4.30  % NW
               4.90   4.82   4.83   4.52];% origo

for i=1:4
data = measurments(:,i);

mapping = [data(9)+(data(8)-data(9))*sqrt(2) NaN                                data(1)                            NaN                                data(9)+(data(2)-data(9))*sqrt(2)
           NaN                               data(8)                            data(9)+(data(1)-data(9))*sqrt(.5) data(2)                            NaN
           data(7)                           data(9)+(data(7)-data(9))*sqrt(.5) data(9)                            data(9)+(data(3)-data(9))*sqrt(.5) data(3)
           NaN                               data(6)                            data(9)+(data(5)-data(9))*sqrt(.5) data(4)                            NaN
           data(9)+(data(6)-data(9))*sqrt(2) NaN                                data(5)                            NaN                                data(9)+(data(4)-data(9))*sqrt(2)];

mapping(1,2) = mapping(3,2)+(mapping(2,2)-mapping(3,2))*sqrt(2);
mapping(1,4) = mapping(3,4)+(mapping(2,4)-mapping(3,4))*sqrt(2);

mapping(2,5) = mapping(2,3)+(mapping(2,4)-mapping(2,3))*sqrt(2);
mapping(4,5) = mapping(4,3)+(mapping(4,4)-mapping(4,3))*sqrt(2);

mapping(5,4) = mapping(3,4)+(mapping(4,4)-mapping(3,4))*sqrt(2);
mapping(5,2) = mapping(3,2)+(mapping(4,2)-mapping(3,2))*sqrt(2);

mapping(4,1) = mapping(4,3)+(mapping(4,2)-mapping(4,3))*sqrt(2);
mapping(2,1) = mapping(2,3)+(mapping(2,2)-mapping(2,3))*sqrt(2);

servo_mapping(:,:,i) = mapping;
end

