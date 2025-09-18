% https://www.mathworks.com/help/vision/ref/trainyolov4objectdetector.html#d126e346295
% Subnetworks to freeze during training, specified as one of these values:
%    "none" — Do not freeze subnetworks
%    "backbone" — Freeze the feature extraction subnetwork
%    "backboneAndNeck" — Freeze both the feature extraction and the path aggregation subnetworks

path="../../imagesAndRegions/sequence_1/";
load("netCNN_SAS.mat");
load("toolsTrainingData.mat");
trainingData=toolsTrainingData;


dataDir = fullfile(path );
trainingData.imageFilename = fullfile("",trainingData.imageFilename);


imds = imageDatastore(trainingData.imageFilename);
blds = boxLabelDatastore(trainingData(:,2:end));
ds = combine(imds,blds);

inputSize = [240 240 3];
trainingDataForEstimation = transform(ds,@(data)preprocessData(data,inputSize));

numAnchors = 6;
[anchors,meanIoU] = estimateAnchorBoxes( blds, numAnchors);
area = anchors(:,1).*anchors(:,2);
[~,idx] = sort(area,"descend");
anchors = anchors(idx,:);
anchorBoxes = {anchors(1:3,:);anchors(4:6,:)};
aboxes=anchorBoxes;

classes = ["sas"];

%netUpdated = removeLayers( net , layerNames );
netUpdated = removeLayers( net , ['softmax'] );
net2 = removeLayers( netUpdated , ['fc'] );
detector = yolov4ObjectDetector(net2,classes,aboxes);
%Network must not have any fully connected layers.

%detector = yolov4ObjectDetector(baseNet,classes,aboxes,DetectionNetworkSource=layer)


%detector = yolov4ObjectDetector(net,classes,anchorBoxes,InputSize=inputSize);
 %}