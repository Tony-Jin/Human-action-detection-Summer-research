Numerator = [0 0.044977500977790512 0.098720098997901587 0.14990073316292735 0.18664442576367879 0.20000000000000001 0.18664442576367879 0.14990073316292735 0.098720098997901587 0.044977500977790512 0]';
Acc = sqrt(axg.*axg+ayg.*ayg+azg.*azg);
Acc_LPF = Acc;
for i = 11:1:length(Acc_LPF)
    Acc_LPF(i) = 0;
    for j = 1:1:10
        Acc_LPF(i) = Acc_LPF(i) + Numerator(j)*Acc(i-j);
    end
end

plot(Acc_LPF);
count = [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]';
index = 1;
flag = 0;
for i = 1:1:length(Acc_LPF)
    if Acc_LPF(i) > 1.32
        count(index) = count(index) + 1;
        flag = 1;
        continue;
    end
    if Acc_LPF(i) <= 1.32 && flag == 1
        index = index + 1;
        flag = 0;
        continue;
    end
    flag = 0;
end