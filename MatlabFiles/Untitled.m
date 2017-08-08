dd = linspace(0.01,0.01,length(VarName1))';
for i = 2:1:length(VarName1)
    dd(i) = VarName1(i) - VarName1(i - 1);
end

plot(dd);