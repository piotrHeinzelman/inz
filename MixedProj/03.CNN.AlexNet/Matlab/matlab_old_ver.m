% przy mniejszych wygenerowanych wagach proces uczenia zaczyna się.
% uczenie przy większym współczynniku i mniejszym spadku z eopki na eopkę.

% https://www.mathworks.com/help/vision/ug/getting-started-with-r-cnn-fast-r-cnn-and-faster-r-cnn.html#mw_10e85d83-0e31-4896-bde9-8730b448441d
% krok 1 wagi warstw = 0, wagi warstwy 2 { layers(2).Weights = 0.0001 * randn([filterSize numChannels numFilters]); }
% zapis wag do pliku


% url = 'https://www.cs.toronto.edu/~kriz/cifar-10-matlab.tar.gz';
% helperCIFAR10Data.download(url,cifar10Data);


cifar10Data = 'X:\';
[trainingImages,trainingLabels] = loadData('D:\INZ\cifar-100-matlab\train');
[testImages,testLabels] = loadData('D:\INZ\cifar-100-matlab\test');



%[trainingImages,trainingLabels,testImages,testLabels] = helperCIFAR10Data.load(cifar10Data);
size(trainingImages)

numImageCategories = 10;
categories(trainingLabels)

figure
thumbnails = trainingImages(:,:,:,1:100);
montage(thumbnails)

% imageInputLayer (Deep Learning Toolbox) - Image input layer
% convolution2dLayer (Deep Learning Toolbox) - 2D convolution layer for Convolutional Neural Networks
% reluLayer (Deep Learning Toolbox) - Rectified linear unit (ReLU) layer
% maxPooling2dLayer (Deep Learning Toolbox) - Max pooling layer
% fullyConnectedLayer (Deep Learning Toolbox) - Fully connected layer
% softmaxLayer (Deep Learning Toolbox) - Softmax layer
% classificationLayer (Deep Learning Toolbox) - Classification output layer for a neural network

% Create the image input layer for 32x32x3 CIFAR-10 images.
[height,width,numChannels, ~] = size(trainingImages);

imageSize = [height width numChannels];
inputLayer = imageInputLayer(imageSize)
 
% Convolutional layer parameters
filterSize = [5 5];
numFilters = 32;

middleLayers = [
    
% The first convolutional layer has a bank of 32 5x5x3 filters. A
% symmetric padding of 2 pixels is added to ensure that image borders
% are included in the processing. This is important to avoid
% information at the borders being washed away too early in the
% network.
convolution2dLayer(filterSize,numFilters,'Padding',2)

% Note that the third dimension of the filter can be omitted because it
% is automatically deduced based on the connectivity of the network. In
% this case because this layer follows the image layer, the third
% dimension must be 3 to match the number of channels in the input
% image.

% Next add the ReLU layer:
reluLayer()

% Follow it with a max pooling layer that has a 3x3 spatial pooling area
% and a stride of 2 pixels. This down-samples the data dimensions from
% 32x32 to 15x15.
maxPooling2dLayer(3,'Stride',2)

% Repeat the 3 core layers to complete the middle of the network.
convolution2dLayer(filterSize,numFilters,'Padding',2)
reluLayer()
maxPooling2dLayer(3, 'Stride',2)

convolution2dLayer(filterSize,2 * numFilters,'Padding',2)
reluLayer()
maxPooling2dLayer(3,'Stride',2)

]












finalLayers = [
    
% Add a fully connected layer with 64 output neurons. The output size of
% this layer will be an array with a length of 64.
fullyConnectedLayer(64)

% Add an ReLU non-linearity.
reluLayer

% Add the last fully connected layer. At this point, the network must
% produce 10 signals that can be used to measure whether the input image
% belongs to one category or another. This measurement is made using the
% subsequent loss layers.
fullyConnectedLayer(numImageCategories)

% Add the softmax loss layer and classification layer. The final layers use
% the output of the fully connected layer to compute the categorical
% probability distribution over the image classes. During the training
% process, all the network weights are tuned to minimize the loss over this
% categorical distribution.
softmaxLayer
classificationLayer
]





layers = [
    inputLayer
    middleLayers
    finalLayers
    ]
	
	
	
	
	
	
%	
% 2 krok:
%
%
%



% Set the network training options
opts = trainingOptions('sgdm', ...
    'Momentum', 0.9, ...
    'InitialLearnRate', 0.001, ...
    'LearnRateSchedule', 'piecewise', ...
    'LearnRateDropFactor', 0.9, ...
    'LearnRateDropPeriod', 15, ...
    'L2Regularization', 0.004, ...
    'MaxEpochs', 140, ...
    'MiniBatchSize', 128, ...
    'Verbose', true);
	
	
	
	
	
	
% przy ustawieniach layers(2).Weights = 0.0001 * randn	... brak uczenia
	
	
% A trained network is loaded from disk to save time when running the
% example. Set this flag to true to train the network.
doTraining = true;

if doTraining    
    % krok 1:
    layers(2).Weights = 0.01 * randn([filterSize numChannels numFilters]);
    layers(5).Weights = 0.01 * randn([filterSize 32 32]);
    layers(8).Weights = 0.01 * randn([filterSize 32 64]);
    layers(11).Weights = 0.01 * randn([64 576]);
    layers(13).Weights = 0.01 * randn([10 64]);
    % Train a network.
	% load Lev2.mat;
    %load('X:\inz\MixedProj\03.CNN.Face\Matlab\03.Matlab.layers.mat','layers');
	
    
    cifar10Net = trainNetwork(trainingImages, trainingLabels, layers, opts);
    W2=layers(2).Weights;
    W5=layers(5).Weights;
    W8=layers(8).Weights;
    W11=layers(11).Weights;
    W13=layers(13).Weights; 
    save('X:\inz\MixedProj\03.CNN.Face\Matlab\03.Matlab.Weight1.net.mat','cifar10Net');
    save('X:\inz\MixedProj\03.CNN.Face\Matlab\03.lay2Weigh.mat','W2');
    save('X:\inz\MixedProj\03.CNN.Face\Matlab\03.lay5Weigh.mat','W5');
    save('X:\inz\MixedProj\03.CNN.Face\Matlab\03.lay8Weigh.mat','W8');
    save('X:\inz\MixedProj\03.CNN.Face\Matlab\03.lay11Weigh.mat','W11');
    save('X:\inz\MixedProj\03.CNN.Face\Matlab\03.lay13Weigh.mat','W13');

 
else
    % Load pre-trained detector for the example.
    load('X:\inz\MixedProj\03.CNN.Face\Matlab\03.Matlab.Weight1.net.mat','cifar10Net');      
end	










% Extract the first convolutional layer weights
w = cifar10Net.Layers(2).Weights;

% rescale the weights to the range [0, 1] for better visualization
w = rescale(w);

%figure
%montage(w)




w5 = cifar10Net.Layers(5).Weights;
w5 = rescale(w5);
%figure
%montage(w5)

w8 = cifar10Net.Layers(8).Weights;
w8 = rescale(w8);
%figure
%montage(w8)

w11 = cifar10Net.Layers(11).Weights;
w11 = rescale(w11);
figure
montage(w, w8, w11)

% Run the network on the test set.
YTest = classify(cifar10Net, testImages);

% Calculate the accuracy.
accuracy = sum(YTest == testLabels)/numel(testLabels)







% Load the ground truth data
data = load('stopSignsAndCars.mat', 'stopSignsAndCars');
stopSignsAndCars = data.stopSignsAndCars;

% Update the path to the image files to match the local file system
visiondata = fullfile(toolboxdir('vision'),'visiondata');
stopSignsAndCars.imageFilename = fullfile(visiondata, stopSignsAndCars.imageFilename);

% Display a summary of the ground truth data
summary(stopSignsAndCars)









% Only keep the image file names and the stop sign ROI labels
stopSigns = stopSignsAndCars(:, {'imageFilename','stopSign'});

% Display one training image and the ground truth bounding boxes
I = imread(stopSigns.imageFilename{1});
I = insertObjectAnnotation(I,'Rectangle',stopSigns.stopSign{1},'stop sign','LineWidth',8);

figure
imshow(I)






% A trained detector is loaded from disk to save time when running the
% example. Set this flag to true to train the detector.
doTraining = false;

if doTraining
    
    % Set training options
    options = trainingOptions('sgdm', ...
        'MiniBatchSize', 128, ...
        'InitialLearnRate', 1e-3, ...
        'LearnRateSchedule', 'piecewise', ...
        'LearnRateDropFactor', 0.1, ...
        'LearnRateDropPeriod', 100, ...
        'MaxEpochs', 100, ...
        'Verbose', true);
    
    % Train an R-CNN object detector. This will take several minutes.    
    rcnn = trainRCNNObjectDetector(stopSigns, cifar10Net, options, ...
    'NegativeOverlapRange', [0 0.3], 'PositiveOverlapRange',[0.5 1])
else
    % Load pre-trained network for the example.
    load('rcnnStopSigns.mat','rcnn')       
end





% Read test image
testImage = imread('stopSignTest.jpg');

% Detect stop signs
[bboxes,score,label] = detect(rcnn,testImage,'MiniBatchSize',128)






% Display the detection results
[score, idx] = max(score);

bbox = bboxes(idx, :);
annotation = sprintf('%s: (Confidence = %f)', label(idx), score);

outputImage = insertObjectAnnotation(testImage, 'rectangle', bbox, annotation);

figure
imshow(outputImage)