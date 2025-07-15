% S.Osowski / R.Szmurlo matematyczne modele
% page 89
% https://www.tensorflow.org/?hl=pl
% https://www.mathworks.com/help/deeplearning/ref/feedforwardnet.html
% https://www.mathworks.com/help/overview/ai-and-statistics.html?s_tid=hc_product_group_bc
% https://www.youtube.com/watch?v=aircAruvnKk

% To train a deep learning network, use trainnet.

%D = gpuDevice;

percent=100;
epoch=5000;
gpu=true;


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




if ( true )
    

    fileIMG=fopen( '../data/train-labels-idx1-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    ytmp=fileData(9:8+(percent*600))';
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

    fileIMG=fopen( '../data/t10k-labels-idx1-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);

    ytmp=fileData(9:8+(percent*100))';
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


    fileIMG=fopen( '../data/train-images-idx3-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    tmp=fileData(17:16+(percent*784*600));

    for i=1:percent*600
        col=tmp(1+(i-1)*784:i*784);
        xtrain(1:784,i)=col';
    end
    xtrain=xtrain/255;
    fileData=1;

    fileIMG=fopen( '../data/t10k-images-idx3-ubyte','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    tmp=fileData(17:16+(percent*784*100));

    for i=1:percent*100
        col=tmp(1+(i-1)*784:i*784);
        xtest(1:784,i)=col';
    end
    xtest=xtest/255;
    fileData=1;
end

if (false)
showx( xtrain , 1 );
end

neurons = 64;

    net = feedforwardnet([ neurons,neurons ],'traingd'); % traingd - spadek gradientowy % trainlm - Levenberg-Marquardt

    %net.trainParam.mc = 0;
    net.trainParam.epochs = epoch;
    net.trainParam.goal   = 0.00000003;
    net.input.processFcns = {'mapminmax'}; % https://www.mathworks.com/matlabcentral/answers/278051-output-processing-function-removeconstantrows-is-not-supported-with-gpu
    net.output.processFcns = {'mapminmax'};%


    gxtrain = gpuArray( xtrain );
    gytrain = gpuArray( ytrain );

    timeTrainStart = datetime('now');


    if ( gpu )
        %GPU
        net = configure(net,xtrain,ytrain);
        net = train(net, gxtrain, gytrain,'useParallel','yes','useGPU','yes');
    else
        %No GPU
        %net = configure(net,xtrain,ytrain);
        net = train( net, xtrain, ytrain );
    end

    timeTrainEnd = datetime('now');

    timeForwardStart = datetime('now');
    z = net( xtest );
    timeForwardEnd = datetime('now');

    flatZ = aryOfVectorToAryOfInt( z );
    flatZtest = aryOfVectorToAryOfInt( ytest );
    accuracy = accuracyCheck(flatZ, flatZtest);

    str='CPU';    
    if gpu
        str='GPU';
    end    

    fprintf('# Matlab, MLP: 2x %i Neu, data size=%i\n', neurons, percent*600 );
    fprintf('# train: epochs=%i, time=%f[s], one epoch time=%f[s] , one forward&backward time=%f[ms]\n', epoch,  seconds( duration(timeTrainEnd-timeTrainStart)), seconds( duration(timeTrainEnd-timeTrainStart))/(epoch), seconds( duration(timeTrainEnd-timeTrainStart))/(epoch*percent*0.6) );
    fprintf( '# accuracy=%f, forward one epoch time=%f[s], one propagation time=%f[ms] \n ' , accuracy, seconds( duration(timeForwardEnd-timeForwardStart)) , seconds( duration(timeForwardEnd-timeForwardStart))/(percent*0.10) );



%timeTrainStart
%timeTrainEnd
%seconds( duration( ED-ST ))
%timeForwardStart
%timeForwardEnd