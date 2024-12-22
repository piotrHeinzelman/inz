
% Osowski / Szmurlo matematyczne modele
% page 89
% https://www.tensorflow.org/?hl=pl
% https://www.mathworks.com/help/deeplearning/ref/feedforwardnet.html


if ( 1==1 ) 
    percent=0.1;

    fileIMG=fopen( 'data/train-labels-idx1-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    ytrain=fileData(9:8+percent*600)';
    fileData=1;

    fileIMG=fopen( 'data/t10k-labels-idx1-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);

    ytest=fileData(9:8+percent*100)';
    fileData=1;

    fileIMG=fopen( 'data/train-images-idx3-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);    
    fileData(17:16+percent*784*600);
    
    for i=1:percent*600
        col=fileData(1+(i-1)*784:i*784);
        xtrain(1:784,i)=col';
    end    
    xtrain=xtrain/255;
    fileData=1;

    fileIMG=fopen( 'data/t10k-images-idx3-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);    
    fileData(17:16+percent*784*100);
    
    for i=1:percent*100
        col=fileData(1+(i-1)*784:i*784);
        xtest(1:784,i)=col';
    end    
    xtest=xtest/255;
    fileData=1;
end


%  t10k-images-idx3-ubyte
%  t10k-labels-idx1-ubyte
%  train-images-idx3-ubyte
%  train-labels-idx1-ubyte



% exit();


% struktura MLP 2 warstwy ukryte
% i warstwa 24 neuronow, druga 24 naurony
% algorytm uczacy mozna zmienic na inny
 
net = feedforwardnet([ 24,24,10 ],'trainlm');

% uczenie sieci:
% x - dane wejsciowe
% y - wartosci zadane (destination)

%net = train(net,x,y);
net = train( net, xtrain, ytrain );
 

z = net(xtrain);

a = net
exit();

% prezentacja struktury sieci
% view(net);

% testowanie sieci na danych wejsciowych x

n_errors = sum(abs(round(z-y)));
perf=perform(net,y,z);


disp("test data:")
zt = net(xt);
n_errors = sum(abs(round(zt-yt)))
perf=perform(net,yt,zt)




% [net,Y,E,Pf,Af,tr] = adapt( net, x, y );
% disp(tr)


% przykladowy wynik uruchomienia
% >> r06_mlp
% n_errors =2
% perf=0.0667
