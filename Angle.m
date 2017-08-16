Angle1 = AngleZdeg;
for i = 1:1:length(Angle1)
    sum3 = AngleXdeg(i)+AngleYdeg(i)+AngleZdeg(i);
    Angle1(i) = sum3 - max([AngleXdeg(i) AngleYdeg(i) AngleZdeg(i)]) - max([AngleXdeg(i) AngleYdeg(i) AngleZdeg(i)]);
end
plot(Angle1);