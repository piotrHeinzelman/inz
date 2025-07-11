% zbior obrazow uczacych i testowych, kod wczytujący dane
%path='D:\INZ\03.Matlab.10';

%InitialLearnRate', 0.001 - batchsize 500 uczy sie !!!
%InitialLearnRate', 0.01 - batchsize 290  nie uczy sie !!!
path = 'X:\03.Matlab.10';
if ( false )
 url = 'https://www.cs.toronto.edu/~kriz/cifar-10-matlab.tar.gz';
 helperCIFAR10Data.download(url,path);
end
if ( false )
 [trainingImages, trainingLabels, testImages, testLabels] = helperCIFAR10Data.load(path);
 save( append(path,'\trainingImages.mat'),'trainingImages');
 save( append(path,'\trainingLabels.mat'),'trainingLabels');
 save( append(path,'\testImages.mat'),'testImages');
 save( append(path,'\testLabels.mat'),'testLabels');
end

 %load( append(path,'\trainingImages.mat'));
 %load( append(path,'\trainingLabels.mat'));
 %load( append(path,'\testImages.mat'));
 %load( append(path,'\testLabels.mat'));

 load( append(path,'\trainingImagesUP.mat') );
 load( append(path,'\trainingLabelsUP.mat') ); 
 load( append(path,'\testImagesUP.mat') );
 load( append(path,'\testLabelsUP.mat') ); 

%upscale 
if (false)
    for i = (1:1000)
        small=testImages(:,:,:,i);
        upscale = imresize( small, [227 227]); % returns image B that has the number of rows and columns specified by the two-element vector [numrows numcols].
        testImagesUP(:,:,:,i) = upscale;
        testLabelsUP(i)=testLabels(i);
    end
    save( append(path,'\testImagesUP.mat'),'testImagesUP','-v7.3');
    save( append(path,'\testLabelsUP.mat'),'testLabelsUP');
end

%upscale 
if (false)
    for i = (1:5000)
        small=trainingImages(:,:,:,i);
        upscale = imresize( small, [227 227]); % returns image B that has the number of rows and columns specified by the two-element vector [numrows numcols].
        trainingImagesUP(:,:,:,i) = upscale;
        trainingLabelsUP(i)=trainingLabels(i);
    end
    save( append(path,'\trainingImagesUP.mat'),'trainingImagesUP','-v7.3');
    save( append(path,'\trainingLabelsUP.mat'),'trainingLabelsUP');
end

trainingLabels = trainingLabelsUP;
trainingImages = trainingImagesUP;
testImages = testImagesUP;
testLabels = testLabelsUP;

%[trainingImages,trainingLabels] = loadData('D:\INZ\cifar-100-matlab\train.mat');
%[testImages,testLabels] = loadData('D:\INZ\cifar-100-matlab\test.mat');
%train = load('D:\INZ\cifar-100-matlab\train.mat' ); % batch_label, coarse_label, data, filenames, fine_labels
%trainingImages = reshape(train.data , 32,32,3,[]);
%trainingImages = reshape(train.data , 32,32,3,[]);
%trainingImages = permute(trainingImages, [2 1 3 4]);
%trainingLabels = categorical( train.fine_labels, 0:99 );
 
size(trainingLabels);
numImageCategories = 100;
%categories( trainingLabels )

if (false)
figure
thumbnails = trainingImages(:,:,:,1:81);
%thumbnails = trainingImages(:,:,:,1:100);
montage(thumbnails)
end

%exit();
epochs=1500; 
% AlexNet
% inputLayer @3 224x224 % (50176)

% 1.convolution @96 11x11 stride 4
% 1.maxpool  3x3 stride 2

% 2.convolution @256 5x5 padding 5
% 2.maxpool  3x3 stride 2

% 3.convolution @384 3x3 padding 1
% 4.convolution @384 3x3 padding 1
% 5.convolution @256 3x3 padding 1
% 5.maxpool  3x3 stride 2

% 6.FullConnected 4096 sigmoid
% 7.FullConnected 4096 sigmoid
% 8.FullConnected 1000 softmax <- mutation 100 klas

input = imageInputLayer([227 227 3]);  % 28x28px 1 channel

conv1 = convolution2dLayer([11 11], 96, 'Stride', [4 4], 'Padding', [0 0] ); % 96 filter, 11x11 stride [4,4], padding [0,0]
relu1 = reluLayer;
%cross1= crossChannelNormalizationLayer(5); % ???
max1 = maxPooling2dLayer([3 3], 'Stride',[2 2], 'Padding',[0 0]);


conv2 = convolution2dLayer([5 5], 256, 'Stride', [1 1], 'Padding', [5 5] );  
relu2 = reluLayer;
%cross2= crossChannelNormalizationLayer(5); % ???
max2 = maxPooling2dLayer([3 3], 'Stride',[2 2], 'Padding',[0 0]);


conv3 = convolution2dLayer([3 3], 384, 'Stride', [1 1], 'Padding', [1 1] );  
relu3 = reluLayer;

conv4 = convolution2dLayer([3 3], 384, 'Stride', [1 1], 'Padding', [1 1] );  
relu4 = reluLayer;

conv5 = convolution2dLayer([3 3], 256, 'Stride', [1 1], 'Padding', [1 1] );  
relu5 = reluLayer;
max5  = maxPooling2dLayer([3 3], 'Stride',[2 2], 'Padding',[0 0]);

fc6 = fullyConnectedLayer(4096);
relu6 = reluLayer;
drop6 = dropoutLayer(0.5);

fc7 = fullyConnectedLayer(4096);
relu7 = reluLayer;
drop7 = dropoutLayer(0.5);

fc8 = fullyConnectedLayer(10);
sm = softmaxLayer;
co = classificationLayer;



 



layers = [
input;
conv1;
relu1;
max1;

conv2;  
relu2;
max2;

conv3;  
relu3;

conv4;  
relu4;

conv5;  
relu5;
max5;

fc6;
relu6;
drop6;

fc7;
relu7;
drop7;

fc8;
sm;
co;
]
	
%opts = trainingOptions('sgdm', 'Momentum', 0.9, 'InitialLearnRate', 0.001, 'LearnRateSchedule', 'piecewise', 'LearnRateDropFactor', 0.9,'LearnRateDropPeriod', 15, 'L2Regularization', 0.004, 'MaxEpochs', 140,'MiniBatchSize', 128, 'Verbose', true);
options=trainingOptions('adam', 'MaxEpochs',epochs, 'MiniBatchSize', 1500 ,...
    'InitialLearnRate', 0.0001, 'LearnRateDropFactor', 0.9,'LearnRateDropPeriod', 15, 'L2Regularization', 0.04, ...
    'ExecutionEnvironment','gpu', ...
    'ValidationPatience',10 , 'Verbose',1); %    ...


ST = datetime('now');

	AlexNet = trainNetwork( trainingImages, trainingLabels, layers, options);

ED = datetime('now');
trainTime = duration( ED-ST );
	
	save(append(path,'\AlexNet.mat'),'AlexNet');

if false    
    % Load pre-trained detector for the example.
    load(append(path,'\AlexNet.mat'),'AlexNet');      
end	


% Extract the first convolutional layer weights
w = conv1.Weights;

% rescale the weights to the range [0, 1] for better visualization
w = rescale(w);
figure
montage(w)


CST = datetime('now');

% Run the network on the test set.
YTest = classify(AlexNet, testImages);

CED = datetime('now');
classifyTime = duration( CED-CST );

% Calculate the accuracy.
accuracy = sum(YTest == testLabels)/numel(testLabels);


fprintf('# Alexnet: %f epochs, datasize: %f, test size: %f\n', epochs, size( trainingImages ), size( testImages )  );
fprintf('# traint time: %f[s], classify time: %f[s], accuracy: a:%f\n\n' ,seconds(trainTime), seconds(classifyTime), accuracy ); 

 


 
  