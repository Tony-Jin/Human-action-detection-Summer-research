Acc = sqrt(axg.*axg+ayg.*ayg+azg.*azg);

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


maxAcc
minAcc

clear all