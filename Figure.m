Acc = sqrt(axg.*axg+ayg.*ayg+azg.*azg);
Gyro = sqrt(wxdegs.*wxdegs+wydegs.*wydegs+wzdegs.*wzdegs);

% Make the first time to be zero
Times(1) = 0;
for i = 2:1:length(Times)
    Times(i) = Times(i-1) + 0.04;
end

subplot(4,1,1);
p = plot(Times,Acc,'k'); set(p,'LineWidth',1.5); grid on;
xlabel('Time (s)','FontSize',15,'FontName','Times');
ylabel('Acc_x (g)','FontSize',15,'FontName','Times');
title('Figure 1: X axis of Acc','FontSize',18,'FontName','Times'); hold on;

subplot(4,1,2);
p = plot(Times,Gyro,'k'); set(p,'LineWidth',1.5); grid on;
xlabel('Time (s)','FontSize',15,'FontName','Times');
ylabel('Acc_y (g)','FontSize',15,'FontName','Times');
title('Figure 2: Angle ','FontSize',18,'FontName','Times'); hold on;

subplot(4,1,3);
p = plot(Times,azg,'k'); set(p,'LineWidth',1.5); grid on;
xlabel('Time (s)','FontSize',15,'FontName','Times');
ylabel('Acc_z (g)','FontSize',15,'FontName','Times');
title('Figure 3: Magnitude Against Time While Upstairs','FontSize',18,'FontName','Times'); hold on;

subplot(4,1,4);
p = plot(Times,PressurePa,'k'); set(p,'LineWidth',1.5); grid on;
xlabel('Time (s) 10 Steps'); ylabel('Pressure (Pa)');
title('Figure 4: Pressure Against Time While Upstairs'); hold on;

clear all