
% Osowski / Szmurlo matematyczne modele
% page 89

x1=1+randn(20,5);
x2=-2+randn(20,5);
x3=3+randn(20,5);
x=[x1;x2;x3]';
d=[ ones(20,1);
  2*ones(20,1);
  3*ones(20,1)]';

% struktura MLP 2 warstwy ukryte
% o 5 i 2 nauronach
% algorytm uczacy mozna zmienic na inny

net = feedforwardnet([5,2],'trainlm');

% uczenie sieci:
% x - dane wejsciowe
% d wartosci zadane (destination)
net=train(net,x,d);

% prezentacja struktury sieci

view(net);

% testowanie sieci na danych wejsciowych x
y=net(x);

n_errors = sum(abs(round(y-d)))
perf=perform(net,d,y)

% przykladowy wynik uruchomienia
% >> r06_mlp
% n_errors =2
% perf=0.0667


