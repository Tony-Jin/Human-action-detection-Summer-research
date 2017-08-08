Acc = sqrt(axg.*axg+ayg.*ayg+azg.*azg);
Gyro = sqrt(wxdegs.*wxdegs+wydegs.*wydegs+wzdegs.*wzdegs);
square = sqrt(axg.*axg+ayg.*ayg);
acc_ang = atan(azg./axg)/3.1415926.*180;

% Make the first time to be zero
Times(1) = 0;
for i = 2:1:length(Times)
    Times(i) = Times(i-1) + 0.02;
end

%subplot(2,1,1);
%plot(Times,axg,'*-',Times,ayg,'y',Times,azg,'b'); xlabel('Time (s) 10 Steps'); ylabel('Acc (g)');
%title('Figure 1: Acc Against Time While Running'); hold on;

%subplot(1,1,1);
%plot(Times,Gyro,'*-'); xlabel('Times (s) 10 Steps'); ylabel('Angular Velocity (deg/s)');
%title('Figure 2: Angular Velocity Against Time While Running'); hold on;

%subplot(1,1,1);
%plot(Times,acc_ang);
%hold on;

%subplot(4,1,3);
%plot(Times,hx,Times,hy,Times,hz); xlabel('Time (s) 10 Steps'); ylabel('Magnetism (deg)');
%title('Figure 3: Magnetism Against Time While Running'); hold on;

subplot(1,1,1);
plot(Times,PressurePa,'*-'); xlabel('Time (s) 10 Steps'); ylabel('Pressure (Pa)');
title('Figure 4: Pressure Against Time While Running'); hold on;

%subplot(1,1,1);
%plot(Times,AngleXdeg,'r',Times,AngleYdeg,'*-',Times,AngleZdeg,'b');
%hold on;


%clear all