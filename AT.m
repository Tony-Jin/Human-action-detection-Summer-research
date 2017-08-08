aveave = linspace(PressurePa(1),PressurePa(1),length(PressurePa))';
dfffff = linspace(0,0,length(PressurePa))';
for i = 1:1:length(PressurePa)
    
    sumsum = 0;
    count = 0;
    for j = i-200:1:i
        if j >= 1
            count = count + 1;
            sumsum = sumsum + PressurePa(j);
        end
    end
    aveave(i) = sumsum/count;
    if i >= 3
        dfffff(i) = (PressurePa(i) + PressurePa(i - 1))/2 - aveave(i - 2);
    end
end

reeeee = dfffff;
for k = 1:1:length(dfffff)
    if dfffff(k) < -2.3
        reeeee(k) = 1;
    elseif dfffff(k) > 2
        reeeee(k) = -1;
    else
        reeeee(k) = 0;
    end
end
    
    
    
subplot(3,1,1);
plot(dfffff); hold on;grid on;
subplot(3,1,2);
plot(PressurePa); hold on;
        grid on;
        subplot(3,1,3);
plot(reeeee); hold on;grid on;