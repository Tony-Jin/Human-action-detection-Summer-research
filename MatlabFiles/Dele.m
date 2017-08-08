Acco = sqrt(axg.*axg+ayg.*ayg+azg.*azg);
%coe1 = [0.043982318366508011 0.097498858012192477 0.14908007258938771 0.18638961732985682 0.2 0.18638961732985682 0.14908007258938771 0.097498858012192477 0.043982318366508011]';
coe = [0.04398 0.0975 0.14908 0.18639 0.2 0.18639 0.14908 0.0975 0.04398]';
Acc = Acco;
for i = 9:1:length(Acc)
    Acc(i) = 0;
    for j = 1:1:9
        Acc(i) = Acc(i) + coe(j)*Acco(i-j+1);
    end
end

%plot(Acc); hold on;

%AccAver = Acc;
%for i = 2:1:length(AccAver)-1
%    AccAver(i) = (Acc(i-1)+Acc(i)+Acc(i+1))/3;
%end
Max = 0;
Min = 0;
AccTher = 1.2;
AccPP = 0;
flag = 1;
count1 = 1;
count2 = 1;
countStep = 1;

Result = linspace(0,0,length(PressurePa))';
re = linspace(0,0,length(PressurePa))';
sum1 = linspace(0,0,length(PressurePa))';
sum = 0;

angle = linspace(0,0,10)';
angleSum = linspace(0,0,length(AngleYdeg));
basicSum = 0;
sit = linspace(0,0,length(AngleYdeg));
c1 = 0;
c2 = 0;
c3 = 0;
for i = 1:1:length(Acc)
    if Acc(i) > AccTher && flag == 1
        count1 = i;
        flag = 0;
        Min = min(Acc(count2:count1,1:1:1));
        if AccPP > 0.2
            countStep = countStep + 1;
        end
    elseif Acc(i) <= AccTher && flag == 0
        count2 = i;
        Max = max(Acc(count1:count2,1:1:1));
        flag = 1;
    end
    AccTher = (Min+Max)/2;
    if AccTher < 1.2
        AccTher = 1.2;
    end
    AccPP = Max-Min;
    
    if i < 101
        sum = sum + PressurePa(i);
    elseif i > 101
        if isnan(PressurePa(i))
            PressurePa(i) = PressurePa(i - 1);
        end
        sum1(i) = sum1(i - 1) + PressurePa(i) - PressurePa(i - 100);
        if i > 130
            diff = sum1(i) - sum1(i - 25);
            re(i - 130) = diff;
            if diff > 75
                Result(i - 115) = -1;
            elseif diff < -80
                Result(i - 115) = 1;
            else
                Result(i - 115) = 0;
            end
        end
    else
        %sum1(105) = sum;
        sum1(i) = sum;
    end
    
    if i < 11
        angle(i) = AngleYdeg(i);%/32768*180;
        basicSum = basicSum + angle(i);
    else
        for u = 1:1:9
            angle(u) = angle(u + 1);
        end
        angle(10) = AngleYdeg(i);%/32768*180;
        angleSum(i) = 0;
        for v = 1:1:10
            angleSum(i) = angleSum(i) + angle(v);
        end
        
        base = (angleSum(i) - basicSum)/10;
        
        if base > 5.6 && c1 == 50
            c2 = 0;
            c3 = 0;
            sit(i - 55) = 1;
        elseif base > 5.6 && c1 < 50
            c1 = c1 + 1;
        elseif base <= 0 && c2 == 50
            c1 = 0;
            c3 = 0;
            sit(i - 55) = -1;
        elseif base <= 0 && c2 < 50
            c2 = c2 + 1;
        elseif base <= 5.6 && base > 0 && c3 == 50
            c1 = 0;
            c2 = 0;
            sit(i - 55) = 0;
        elseif base <= 5.6 && base > 0 && c3 < 50
            c3 = c3 + 1;
        end
    end
end

%plot(AccMax); hold on;
%plot(AccMin); hold on;
%plot(AccAll); hold on;
%plot(AccTher); hold on;
%plot(AccPP)
subplot(4,1,1);
plot(sit); hold on;
subplot(4,1,2);
plot(Acc); hold on;
subplot(4,1,3);
plot(Acco); hold on;
subplot(4,1,4);
plot(AngleYdeg); hold on;