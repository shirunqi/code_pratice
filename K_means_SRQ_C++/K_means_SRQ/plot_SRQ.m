clc;
clear all;
close all;

load data_original.txt
x = data_original(:,1);
y = data_original(:,2);
figure(1)
for i = 1:10
    plot(x(i),y(i),'*b');
    hold on
end
for i = 11:20
    plot(x(i),y(i),'*r');
    hold on
end
for i = 21:30
    plot(x(i),y(i),'*y');
    hold on
end
for i = 31:40
    plot(x(i),y(i),'*g');
    hold on
end
% for i = 1:length(x)
%     plot(x(i),y(i),'*');
%     hold on
% end
% plot(x,y);