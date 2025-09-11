


%unzip("DigitsData.zip")

% imds = imageDatastore("DigitsData", ...
% imds = imageDatastore("D:\\INZ\\SAS_and_NoSAS_train_Data\\", IncludeSubfolders=true, LabelSource="foldernames");
imds = imageDatastore("D:\\INZ\\SAS_and_NoSAS_train_Data_240\\", IncludeSubfolders=true, LabelSource="foldernames");
	
	numTrainFiles = 800;
[imdsTrain,imdsTest] = splitEachLabel(imds,numTrainFiles,"randomized");

inputSize = [240 240 3];
classNames = categories(imds.Labels);
numClasses = numel(classNames);

 

layers = [
    imageInputLayer(inputSize)
    convolution2dLayer(11,20)
    batchNormalizationLayer
    reluLayer
    convolution2dLayer(5,20)
    batchNormalizationLayer
    reluLayer
    convolution2dLayer(3,20)
    batchNormalizationLayer
    reluLayer
    fullyConnectedLayer(numClasses)
    softmaxLayer];
	
options = trainingOptions("sgdm", ...
    MaxEpochs=30, ...
    Verbose=false, ...
    Plots="training-progress", ...
    Metrics="accuracy");
	
net = trainnet(imdsTrain,layers,"crossentropy",options);
save("D:\\INZ\\SAS_and_NoSAS_train_Data_240\\net.mat",net);
%accuracy = testnet(net,imdsTest,"accuracy")


%scoresTest = minibatchpredict(net,imdsTest);
%YTest = scores2label(scoresTest,classNames);

%confusionchart(imdsTest.Labels,YTest)