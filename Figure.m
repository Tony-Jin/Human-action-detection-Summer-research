Acc = sqrt(axg.*axg+ayg.*ayg+azg.*azg);
Gyro = sqrt(wxdegs.*wxdegs+wydegs.*wydegs+wzdegs.*wzdegs);

% Make the first time to be zero
Time1 = Times(1);
for i = 1:1:length(Times)
    Times(i) = Times(i) - Time1;
end

subplot(3,1,1);
plot(Times,axg,'r',Times,ayg,'y',Times,azg,'b'); xlabel('Time (s) 20 Steps'); ylabel('Acc (g)');
title('Figure 1: Acc Against Time While Walking'); hold on;

subplot(3,1,2);
plot(Times,Acc); xlabel('Time (s) 20 Steps'); ylabel('Acc (g)');
title('Figure 1: Acc Against Time While Walking'); hold on;

%subplot(3,1,3);
%plot(Times,Gyro); xlabel('Times (s) 20 Steps'); ylabel('Angular Velocity (deg/s)');
%title('Figure 2: Angular Velocity Against Time While Walking'); hold on;

%subplot(3,1,3);
%plot(Times,hx,'r',Times,hy,'y',Times,hz,'b'); xlabel('Time (s) 20 Steps'); ylabel('Magnetism (deg)');
%title('Figure 3: Magnetism Against Time While Walking'); hold on;

subplot(3,1,3);
plot(Times,PressurePa); xlabel('Time (s) 20 Steps'); ylabel('Pressure (Pa)');
title('Figure 4: Pressure Against Time While Walking'); hold on;

clear all