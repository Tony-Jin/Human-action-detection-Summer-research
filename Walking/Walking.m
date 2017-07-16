Acc = sqrt(axg.*axg+ayg.*ayg+azg.*azg);
Gyro = sqrt(wxdegs.*wxdegs+wydegs.*wydegs+wzdegs.*wzdegs);

maxAcc = Acc(1);
for i = 2:1:length(Acc)
    if Acc(i) > maxAcc
        maxAcc = Acc(i);
    end
end

minAcc = Acc(1);
for i = 2:1:length(Acc)
    if Acc(i) < minAcc
        minAcc = Acc(i);
    end
end

maxGyro = Gyro(1);
for i = 2:1:length(Gyro)
    if Gyro(i) > maxGyro
        maxGyro = Gyro(i);
    end
end

minGyro = Gyro(1);
for i = 2:1:length(Gyro)
    if Gyro(i) < minGyro
        minGyro = Gyro(i);
    end
end

maxAcc
minAcc
maxGyro
minGyro