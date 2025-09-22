 
%plt.style.use('_mpl-gallery');
 
library=(1:3);
%d0=[None,None,None]
%d1=[None,None,None]
%d2=[None,None,None]

%#################################

% net: tiny-yolov2-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :2.230185;
% load image time: 0.083492; detect object time: 1.877422
library(1)="Yolo3 DOG find(1) ";
d0(1)=0.04591965675354004;
d1(1)=56.78736448287964;
d2(1)=0.4355125427246094;


% Create Model:
% Training Model:
% Detect time:

% net: tiny-yolov3-coco; task:team; class: person score: 0.949395;  prepare detectortime: :0.301683;
% load image time: 0.016144; detect object time: 0.165678
library(2)="Yolo3 DOG2 find(1)";
d0(2)=0.043099164962768555;
d1(2)=0.016144;
d2(2)=1.0444037914276123;
% Create Model:
% Detect time:
% net: tiny-yolov4-coco; task:team; class: person score: 0.718039;  prepare detectortime: :0.345861;
% load image time: 0.011555; detect object time: 0.260877
library(3)="Yolo3 TEAM find(7)";
d0(3)=0.07130837440490723;
d1(3)=0.016144;
d2(3)=1.0438988208770752;
% Create Model:
% Detect time:


bar_width = 0.28;
x = ["DOG" "DOG2" "TEAM find(7)" ];
%x = ['1'  '2' 'c' ] ;
offset = bar_width/2;


y=[  0.04591965675354004 0.4355125427246094; 0.043099164962768555 1.0444037914276123; 0.07130837440490723 1.0438988208770752 ];
bar( x, y);
%plt.style.use('_mpl-gallery');


% Grouped Bar Plot
% bar( x          , d0);%,  label='przygotowanie detektora');
%plt.bar( x         , d1, bar_width, label='wczytanie obrazów z dysku')
% bar( x         , d2);% , label='detekcja F');

% Adding labels and title
%plt.xlabel('Yolo ')
ylabel('Time[s]');
xticks(x, library);
legend('przygotowanie detektora','detekcja F');
title('Yolo in Python');
label('a','b');

%savefig( '03_Yolo_Python.pdf',dpi=400 );
show()
%plt.close()
