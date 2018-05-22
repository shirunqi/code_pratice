clc
clear all
close all

load data1.txt
load data2.txt
load data3.txt
load data4.txt
load data5.txt

figure(1)
plot(data1(:,1),data1(:,2),'*r',data2(:,1),data2(:,2),'og',data3(:,1),data3(:,2),'+b',data4(:,1),data4(:,2),'sk');
hold on 
plot(data5(:,1),data5(:,2),'pc')
grid on