%Acc = sqrt(axg.*axg+ayg.*ayg+azg.*azg);
%Gyro = sqrt(wxdegs.*wxdegs+wydegs.*wydegs+wzdegs.*wzdegs);

% Make the first time to be zero
%Time1 = Times(1);
%for i = 1:1:length(Times)
%    Times(i) = Times(i) - Time1;
%end

N = length(Times);                      % Sampling 32 times
Ts = 2/N;                    % Sampling for two seconds and set sampling interval
fs = 1/Ts;                   % Set sampling rate
df = fs/N;                   % Set frequency-domain resolution
%n = [0:N-1]';                % Vector of 32 time indices
t = Times;                    % Vector of times
x = Acc; % Vector of 32 x(t) function values
%X = fftshift(Ts*fft(x));     % Vector of 32 approx X(f) CTFT values
X = fftshift(Ts*fft(x,N));
k = [-N/2:N/2-1]';           % Vector of 16 frequency indices

% Graph the results
subplot(3,1,1);
p = plot(t,x,'k'); set(p,'LineWidth',2); grid on;
xlabel('Time, t (s)'); ylabel('x(t)');
subplot(3,1,2);
p = plot(k*df,abs(X),'k'); set(p,'LineWidth',2); grid on;
xlabel('Frequency, f (Hz)'); ylabel('|X(f)|');
subplot(3,1,3);
p = plot(k*df,angle(X),'k'); set(p,'LineWidth',2); grid on;
xlabel('Frequency, f (Hz)'); ylabel('Phase of X(f)');

%clear all