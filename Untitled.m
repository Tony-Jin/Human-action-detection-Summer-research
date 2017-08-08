coe = [0.04398 0.0975 0.14908 0.18639 0.2 0.18639 0.14908 0.0975 0.04398]';
VA = sqrt(VarName1.*VarName1+VarName2.*VarName2+VarName3.*VarName3);
Acc = VA;
for i = 9:1:length(Acc)
    Acc(i) = 0;
    for j = 1:1:9
        Acc(i) = Acc(i) + coe(j)*VA(i-j+1);
    end
end

plot(Acc);