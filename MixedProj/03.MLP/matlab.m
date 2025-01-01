
% Osowski / Szmurlo matematyczne modele
% page 89
% https://www.tensorflow.org/?hl=pl
% https://www.mathworks.com/help/deeplearning/ref/feedforwardnet.html
% https://www.mathworks.com/help/overview/ai-and-statistics.html?s_tid=hc_product_group_bc
% https://www.youtube.com/watch?v=aircAruvnKk

% To train a deep learning network, use trainnet.


function accuracy = accuracyCheck( first, second )
    goals=0;
    s=size(first);
    s=s(2);
    for i=(1:s)
        val1=first(i);
        val2=second(i);
        if (val1==val2)
            goals=goals+1;
        end    
    end 
    accuracy = goals/s;
end


function index = indexOfMaxInVector( vec ) % 
    val=vec(1);
    index=1;
    s=size(vec);
    s=s(1);
    for i = (2:s)
        if (val<vec(i))
            index=i;
            val=vec(i);
        end    
    end
end

%vec = [0.1, 0.3, 0.15, 0.2]';
%i = indexOfMaxInVector( vec )


function aryOfInt = aryOfVectorToAryOfInt( aryOfVec )
    s = size( aryOfVec );
    h=s(1);
    s=s(2);
    aryOfInt=zeros(1,s);
    for i=1:s
      vec=aryOfVec(1:h,i);  
      index = indexOfMaxInVector(vec);   
      if index==10
          index=0;
      end    
      aryOfInt(i)=index; 
    end    
end

%aryOfVec=[.2, .1
 %         .3, .15
%         -.2, .2
%          .4, .5
%          .5, .4
%          .2, .3]


% flat = aryOfVectorToAryOfInt( aryOfVec );



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
 
neurons = 32;
net = feedforwardnet([ neurons,neurons ],'traingd'); % traingd - spadek gradientowy % trainlm - Levenberg-Marquardt
%net = fitnet([ 24,24 ],'trainlm'); % traingd - spadek gradientowy % trainlm - Levenberg-Marquardt

net.trainParam.epochs = 1500;
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

datasetSize = percent
layerSize = neurons
maxCycles = net.trainParam.epochs
for i=1:15

    ST = datetime('now');
    net = train( net, xtrain, ytrain );
    ED = datetime('now');
    trainTime = duration( ED-ST );
    
    z = net( xtest );
    flatZ = aryOfVectorToAryOfInt( z );
    flatZtest = aryOfVectorToAryOfInt( ytest ); 
    accuracy = accuracyCheck(flatZ, flatZtest)

end 

%perf=perform( net, ytest, z )

 

% testowanie sieci na danych wejsciowych x

if (1==2)
    z1 = net( xtrain(1:784,1) )
    z1 = net( xtrain(1:784,2) )
    z1 = net( xtrain(1:784,3) )

    %showx( xtest , 5 );
    %showx( xtest , 2 );
    %showx( xtrain , 3 );
end





%exit();

%disp("test data:")
%zt = net(xt);
%n_errors = sum(abs(round(zt-yt)))
%perf=perform(net,yt,zt)




% [net,Y,E,Pf,Af,tr] = adapt( net, x, y );
% disp(tr)


% przykladowy wynik uruchomienia
% >> r06_mlp
% n_errors =2
% perf=0.0667

