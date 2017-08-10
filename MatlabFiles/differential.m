vx = axg;
vy = axg;
vz = axg;

Time1 = Times(1);
for i = 1:1:length(Times)
    Times(i) = Times(i) - Time1;
end

vx(1) = 0;
vy(1) = 0;
vz(1) = 0;

for i = 2:1:length(Times)
    vx(i) = vx(i - 1) + axg(i)*(Times(i) - Times(i - 1));
    vy(i) = vy(i - 1) + ayg(i)*(Times(i) - Times(i - 1));
    vz(i) = vz(i - 1) + azg(i)*(Times(i) - Times(i - 1));
end

%v = sqrt(vx.*vx+vy.*vy+vz.*vz);
plot(Times,vx,'r', Times,vy,'y',Times,vz,'b');

clear all