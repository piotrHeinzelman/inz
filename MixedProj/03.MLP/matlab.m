
% Osowski / Szmurlo matematyczne modele
% page 89



x1 = [   1.5377    1.6715    0.8978   -0.0891    2.4193;
    2.8339   -0.2075    0.7586    1.0326    1.2916 ];


x2 = [  -1.1596    0.9080   -1.9771   -2.2938   -3.3617;
   -2.8880   -1.1748   -2.2620   -2.8479   -1.5450 ];


x3 = [   3.1832    1.9358    1.9333    4.0001    3.9111;
    1.9702    4.6035    3.9337    1.3358    3.5946 ];


 x1= 1+randn(20,5);
 x2=-2+randn(20,5);
 x3= 3+randn(20,5);

  x =[x1;x2;x3]'
  d =[ ones(20,1);
  2*ones(20,1);
  3*ones(20,1)]'





% struktura MLP 2 warstwy ukryte
% i warstwa 5 neuronow, druga 2 naurony
% algorytm uczacy mozna zmienic na inny

net = feedforwardnet([5,2],'trainlm');

% uczenie sieci:
% x - dane wejsciowe
% d wartosci zadane (destination)
net = train(net,x,d);

y=net(x)

% prezentacja struktury sieci

%view(net);
a=net

% testowanie sieci na danych wejsciowych x

n_errors = sum(abs(round(y-d)))
perf=perform(net,d,y)



% przykladowy wynik uruchomienia
% >> r06_mlp
% n_errors =2
% perf=0.0667


%x1 = [   1.5377    1.6715    0.8978   -0.0891    2.4193;
%    2.8339   -0.2075    0.7586    1.0326    1.2916 ];


%x2 = [  -1.1596    0.9080   -1.9771   -2.2938   -3.3617;
%   -2.8880   -1.1748   -2.2620   -2.8479   -1.5450 ];


%x3 = [   3.1832    1.9358    1.9333    4.0001    3.9111;
%    1.9702    4.6035    3.9337    1.3358    3.5946 ];


% x1= 1+randn(20,5);
% x2=-2+randn(20,5);
% x3= 3+randn(20,5);

%  x =[x1;x2;x3]'
%  d =[ ones(20,1);
%  2*ones(20,1);
%  3*ones(20,1)]'


