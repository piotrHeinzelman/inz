% https://www.mathworks.com/help/deeplearning/ref/dlnetwork.initialize.html
%
gpuDevice()
epoch=125;
load("trainData.mat");
load('detector');


dataDir = "../../imagesAndRegions/sas/";
trainData.imageFilename = fullfile(dataDir,trainData.imageFilename);
imds = imageDatastore(trainData.imageFilename);
%imds = imageDatastore(trainData.imageFilename);
blds = boxLabelDatastore(trainData(:,2:end));
ds = combine(imds,blds);

inputSize = [240 240 3];
trainingDataForEstimation = transform(ds,@(data)preprocessData(data,inputSize));

%numAnchors = 6;
%[anchors, meanIoU] = estimateAnchorBoxes( trainingDataForEstimation.UnderlyingDatastores{1,1}, numAnchors );
%area = anchors(:,1).*anchors(:,2);
%[~,idx] = sort(area,"descend");
%anchors = anchors(idx,:);
%anchorBoxes = {anchors(1:3,:);anchors(4:6,:)};

classes = ["sas"];
anchorBoxes = {[70,110;70,110;70,120] };
detector = yolov4ObjectDetector(detector.Network, classes,anchorBoxes,InputSize=inputSize);


options = trainingOptions("sgdm", ...
    InitialLearnRate=0.001, ...
    MiniBatchSize=16,...
    MaxEpochs=5, ...
    ResetInputNormalization=true,...
    VerboseFrequency=30);

detector = trainYOLOv4ObjectDetector(ds,detector,options );

I = imread("dedra_www2.jpg");

[bboxes, scores, labels] = detect(detector,I,Threshold=0.48);
detectedImg = insertObjectAnnotation(I,"Rectangle",bboxes,labels);
figure
imshow(detectedImg)




%{










dataFolder = "../../imagesAndRegions/sas/";
imds = imageDatastore(dataFolder, ...
    IncludeSubfolders=true, ...
    LabelSource="foldernames");

classNames = categories(imds.Labels);
labelCount = countEachLabel(imds);
numberOfClass=2;


numTrainFiles = 10;
[imdsTrain,imdsValidation] = splitEachLabel(imds,numTrainFiles,"randomize");

options = trainingOptions( "adam",...
    InitialLearnRate=0.01, ...
    MaxEpochs=epoch, ...
    Shuffle="every-epoch", ...
    ValidationData=imdsValidation, ...
    ValidationFrequency=30, ...
    Plots="training-progress", ...
    Verbose=false);



%imds = imageDatastore(trainingData.imageFilename);
%blds = boxLabelDatastore(trainingData(:,2:end));
%ds = combine(imdsTrain, boxLabelDatastore(trainData).sas );


%ds=imageStore(trainData);

%ds= DataStore(trainData);
load('detector');
 
%train detector MLP
detector = trainYOLOv4ObjectDetector( imds, detector,options)




% predict !

I = imread("dedra_www.jpg");
[bboxes, scores, labels] = detect(detector, I, Threshold=0.8);
objBoxes = bboxes(labels=="sas", :);
detectedImg = insertObjectAnnotation(I, "Rectangle", objBoxes, "sas");
figure
imshow(detectedImg)

%}
