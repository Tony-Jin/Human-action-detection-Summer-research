Acc = sqrt(axg.*axg+ayg.*ayg+azg.*azg);
Gyro = sqrt(wxdegs.*wxdegs+wydegs.*wydegs+wzdegs.*wzdegs);

% Make the first time to be zero
Times(1) = 0;
for i = 2:1:length(Times)
    Times(i) = Times(i-1) + 0.035;
end

<<<<<<< HEAD
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
=======
subplot(4,1,1);
plot(Times,Acc); xlabel('Time (s) 10 Steps'); ylabel('Acc (g)');
title('Figure 1: Acc Against Time While Running'); hold on;

subplot(4,1,2);
plot(Times,Gyro); xlabel('Times (s) 10 Steps'); ylabel('Angular Velocity (deg/s)');
title('Figure 2: Angular Velocity Against Time While Running'); hold on;

subplot(4,1,3);
plot(Times,hx,Times,hy,Times,hz); xlabel('Time (s) 10 Steps'); ylabel('Magnetism (deg)');
title('Figure 3: Magnetism Against Time While Running'); hold on;

subplot(4,1,4);
plot(Times,PressurePa); xlabel('Time (s) 10 Steps'); ylabel('Pressure (Pa)');
title('Figure 4: Pressure Against Time While Running'); hold on;
>>>>>>> bf5568f68e16431f01d757c5afd11935453918d4

clear all