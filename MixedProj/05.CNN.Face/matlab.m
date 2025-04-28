% S.Osowski, R.Szmurlo : modele matematyczne uczenia maszynowego 
% Alexnet - tryb Transfer Learning
% https://www.mathworks.com/help/deeplearning/ug/introduction-to-convolutional-neural-networks.html

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

if ( 1==1 )

    fileIMG=fopen( 'data/trainY','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    ytmp=fileData(15*10)';
    ysize=15*10;
    yyy=zeros(1,ysize);
    for i=(1:ysize)
        d=ytmp(i);
        d=d+1;
        yyy(i)=d ;
    end
    ytrain=categorical(yyy);

    fileData=1;

    fileIMG=fopen( 'data/testY','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);

    ytmp=fileData(5*10)';
    ysize=5*10;
    yyy=zeros(1,ysize);
    for i=(1:ysize)
        d=ytmp(i);
        d=d+1;
        yyy(i)=d ;
    end
    ytest=categorical(yyy);

    fileIMG=fopen( 'data/trainX','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    tmp=fileData(15*10*75*100);

    for i=15*10*75*100
        col=tmp(1+(i-1)*100*75:i*100*75);
        row=col';
        ary=zeros(100,75);
        for j=1:100
            for k=1:75
                val=row(k+((j-1)*75));
                xtrain(j,k,1,i)=val; %/255
            end
        end
    end
    fileData=1;

    fileIMG=fopen( 'data/testX','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    tmp=fileData(5*10*75*100);

    for i=5*10*75*100
        col=tmp(1+(i-1)*100*75:i*100*75);
        row=col';
        ary=zeros(100,75);
        for j=1:100
            for k=1:75
                val=row(k+((j-1)*75));
                xtest(j,k,1,i)=val; %/255
            end
        end
    end
    fileData=1;
end

input = imageInputLayer([100 75 1]);  % 28x28px 1 channel
conv1 = convolution2dLayer(10, 3); % 10 filter, 5x5
relu1 = reluLayer;                    %reLU
max1 = maxPooling2dLayer(3,Stride=2);
conv2 = convolution2dLayer(5, 48); % 10 filter, 5x5
relu2 = reluLayer;                    %reLU
max2 = maxPooling2dLayer(2,Stride=2);


fc = fullyConnectedLayer(10);
sm = softmaxLayer;
co = classificationLayer;

epochs=500;

layers = [ input
    conv1
    relu1
    fc
    sm
    co];


options=trainingOptions('adam', 'MaxEpochs',epochs, 'ExecutionEnvironment','gpu','ValidationPatience',10 , 'Verbose',0);


ST = datetime('now');

	netTransfer = trainNetwork( xtrain, ytrain, layers, options);

ED = datetime('now');
D = duration( ED-ST );




weights_first=netTransfer.Layers(2,1).Weights(:,:,1,1);
%image(weights_first*255)


%for i=(1:10)
%    netTransfer = trainNetwork( xtrain, ytrain, layers, options);
%    weights_first=netTransfer.Layers(2,1).Weights(:,:,1,1)
%    image(weights_first*255)
%end

%a=netTransfer;
%a=netTransfer.Layers;
%a=netTransfer.Layers(2,1);
%a=netTransfer.Layers(2,1).Weights;
%weights_first=netTransfer.Layers(2,1).Weights(:,:,1,1);
%image(weights_first*255);



 predictedLabels = classify(netTransfer, xtest);
  accuracy = accuracyCheck( predictedLabels', ytest );

    fprintf('# CNN: 5x5 * 20 *  500 cycles: (Linux GPU, batch mode)\n' );
    fprintf( '# accuracy: a:%f\n\n' , accuracy );
    fprintf ('m[]=%f\n' , seconds(D)  );


