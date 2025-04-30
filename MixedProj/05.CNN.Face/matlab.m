% Sieci neuronowe do przetwarzania informacji Stanisław Osowski p.446  Alexnet 227x227x3 channel
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
    percent=10*5; % 5 i 15

    fileIMG=fopen( 'data/trainY','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    ytmp=fileData';
    ysize=percent*3;
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

    ytmp=fileData';
    ysize=percent*1;
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
    tmp=fileData;

    for i=1:percent*3
       onePic=tmp(1+(i-1)*227*227*3:i*227*227*3);
        for j=1:227
            for k=1:227
		for l=1:3
           	   val=onePic( 1+ (l-1) + (k-1)*3 + (j-1 )*(3*227)   );
                   xtrain(j,k,l,i)=val/255;
		end
            end
        end
    end
    fileData=1;

    fileIMG=fopen( 'data/testX','r');
    fileData=fread( fileIMG, 'uint8' );
    fclose(fileIMG);
    tmp=fileData;

    for i=1:percent*1
        onePic=tmp(1+(i-1)*227*227*3:i*227*227*3);
        for j=1:227
            for k=1:227
		for l=1:3
           	   val=onePic( 1+ (l-1) + (k-1)*3 + (j-1 )*(3*227)   );
                   xtest( j,k,l,i)=val/255;
		end
            end
        end
    end
    fileData=1;

    if(false)
       AAAA=xtest(:,:,:,1);
       imshow(AAAA);
       fileData=1;
   end

end

input = imageInputLayer([227 227 3]);  % 28x28px 1 channel
conv1 = convolution2dLayer([11 11], 96, 'Stride', [4 4], 'Padding', [0 0] ); % 96 filter, 11x11 stride [4,4] % ([6 4],16,'Stride',4,'Padding',[1 0])
relu1 = reluLayer;                    %reLU
cross1= crossChannelNormalizationLayer(5);
max1 = maxPooling2dLayer([3 3], 'Stride',[2 2], 'Padding',[0 0]);

conv2 = convolution2dLayer([5 5], 256, 'Stride', [1 1], 'Padding', [2 2] );
relu2 = reluLayer;
cross2= crossChannelNormalizationLayer(5);
max2 = maxPooling2dLayer([3 3], 'Stride',[2 2], 'Padding',[0 0]);

conv3 = convolution2dLayer([3 3], 384, 'Stride', [1 1], 'Padding', [1 1] );
relu3 = reluLayer;

conv4 = convolution2dLayer([3 3], 384, 'Stride', [1 1], 'Padding', [1 1] );
relu4 = reluLayer;

conv5 = convolution2dLayer([3 3], 256, 'Stride', [1 1], 'Padding', [1 1] );
relu5 = reluLayer;
max5 = maxPooling2dLayer([3 3], 'Stride',[2 2], 'Padding',[0 0]);

fc6 = fullyConnectedLayer(4096);
relu6 = reluLayer;
drop6 = dropoutLayer(0.5);

fc7 = fullyConnectedLayer(4096);
relu7 = reluLayer;
drop7 = dropoutLayer(0.5);

fc8 = fullyConnectedLayer(10);
sm = softmaxLayer;
co = classificationLayer;


epochs=500;

layers = [ input
conv1
relu1
cross1
max1

conv2
relu2
cross2
max2

conv3
relu3

conv4
relu4

conv5
relu5
max5

fc6
relu6
drop6

fc7
relu7
drop7

fc8
sm
co];


options=trainingOptions('adam', 'MaxEpochs',epochs, 'MiniBatchSize', 12 , 'ExecutionEnvironment','gpu','ValidationPatience',10 , 'Verbose',1);


ST = datetime('now');

	netTransfer = trainNetwork( xtrain, ytrain, layers, options);

ED = datetime('now');
D = duration( ED-ST );



weights_first=netTransfer.Layers(2,1).Weights(:,:,1,1);
%image(weights_first*255)


predictedLabels = classify(netTransfer, xtest);
  accuracy = accuracyCheck( predictedLabels', ytest );

    fprintf('# CNN face: Alexnet 500 cycles: (Linux GPU)\n' );
    fprintf( '# accuracy testX: a:%f\n\n' , accuracy );
    fprintf ('m[]=%f\n' , seconds(D)  );

predictedLabels = classify(netTransfer, xtrain);
  accuracy = accuracyCheck( predictedLabels', ytrain );

    fprintf( '# accuracy trainX: a:%f\n\n' , accuracy );
    fprintf ('m[]=%f\n' , seconds(D)  );


