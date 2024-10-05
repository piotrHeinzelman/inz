import matplotlib.pyplot as plt

A=[ 20   , 65536 ]
M=[ 0.11 , 0.57 ]
P=[ 0.036, 3.16 ]
J=[ 0.003, 0.11 ]
C=[0.000136, 0.411]

hold off;
hold on;
plot(A,C,'DisplayName','C');
plot(A,C,'DisplayName','o');

plot(A,J,'DisplayName','J');
plot(A,J,'DisplayName','o');

plot(A,M,'DisplayName','M');
plot(A,M,'DisplayName','o');

plot(A,P,'DisplayName','P');
plot(A,P,'DisplayName','o');
hold off;

