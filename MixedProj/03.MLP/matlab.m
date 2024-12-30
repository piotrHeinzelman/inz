
% Osowski / Szmurlo matematyczne modele
% page 89
% https://www.tensorflow.org/?hl=pl
% https://www.mathworks.com/help/deeplearning/ref/feedforwardnet.html
% https://www.mathworks.com/help/overview/ai-and-statistics.html?s_tid=hc_product_group_bc
% https://www.youtube.com/watch?v=aircAruvnKk

% To train a deep learning network, use trainnet.


function showx( arrayx , i )
    img0=arrayx(1:784,i);
    img0=img0*256;
    image(img0);
    
    img=zeros(28,28);
        for i=(1:28)
            row=img0((i-1)*28+1:(i)*28);
           img(i,1:28)=row; 
        end    
    image(img)
end




if ( 1==1 ) 
    percent=100;

    fileIMG=fopen( 'data/train-labels-idx1-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    ytmp=fileData(9:8+percent*600)';
    ysize=size(ytmp);
    ysize=ysize(2);
    ytrain=zeros(10,ysize);
    for i=(1:ysize)
        d=ytmp(i);
        if (d==0)
            d=10; 
        end
        ytrain(d,i)=1;
    end
    
    fileData=1;

    fileIMG=fopen( 'data/t10k-labels-idx1-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);

    ytmp=fileData(9:8+percent*100)';
    ysize=size(ytmp);
    ysize=ysize(2);
    ytest=zeros(10,ysize);
    for i=(1:ysize)
        d=ytmp(i);
        if (d==0)
            d=10; 
        end
        ytest(d,i)=1;
    end


    fileIMG=fopen( 'data/train-images-idx3-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);    
    tmp=fileData(17:16+percent*784*600);
    
    for i=1:percent*600
        col=tmp(1+(i-1)*784:i*784);
        xtrain(1:784,i)=col';
    end    
    xtrain=xtrain/255;
    fileData=1;

    fileIMG=fopen( 'data/t10k-images-idx3-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);    
    tmp=fileData(17:16+percent*784*100);
    
    for i=1:percent*100
        col=tmp(1+(i-1)*784:i*784);
        xtest(1:784,i)=col';
    end    
    xtest=xtest/255;
    fileData=1;
end

%showx( xtrain , 4 );
%showx( xtrain , 1 );
%showx( xtrain , 2 );
%showx( xtrain , 3 );
%exit();


% struktura MLP 2 warstwy ukryte
% i warstwa 16 neuronow, druga 16 naurony
% algorytm uczacy mozna zmienic na inny
 
net = feedforwardnet([ 64,64 ],'traingd'); % traingd - spadek gradientowy % trainlm - Levenberg-Marquardt
%net = fitnet([ 24,24 ],'trainlm'); % traingd - spadek gradientowy % trainlm - Levenberg-Marquardt

net.trainParam.epochs = 5000;
net.trainParam.goal   = 0.03;

%min_grad	
%Minimum Gradient Magnitude

%max_fail	
%Maximum Number of Validation Increases

%time	
%Maximum Training Time

%goal	
%Minimum Performance Value

%epochs	
%Maximum Number of Training Epochs (Iterations)


% uczenie sieci:
% x - dane wejsciowe
% y - wartosci zadane (destination)

net = train( net, xtrain, ytrain );

z = net( xtest );
perf=perform( net, ytest, z )

 

% testowanie sieci na danych wejsciowych x

if (1==1)
    z = net( xtrain(1:784,1) )
    z = net( xtrain(1:784,2) )
    z = net( xtrain(1:784,3) )
end
%exit();

%disp("test data:")
%zt = net(xt);
n_errors = sum(abs(round(zt-yt)))
%perf=perform(net,yt,zt)




% [net,Y,E,Pf,Af,tr] = adapt( net, x, y );
% disp(tr)


% przykladowy wynik uruchomienia
% >> r06_mlp
% n_errors =2
% perf=0.0667

