% https://www.mathworks.com/help/vision/ref/trainyolov4objectdetector.html#d126e346295
% Subnetworks to freeze during training, specified as one of these values:
%    "none" — Do not freeze subnetworks
%    "backbone" — Freeze the feature extraction subnetwork
%    "backboneAndNeck" — Freeze both the feature extraction and the path aggregation subnetworks

path="../../imagesAndRegions/sequence_1/";
load("toolsTrainingData.mat");
load("netCNN_SAS.mat");
load("dlnet.mat");
net=dlnet;
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

%netUpdated = removeLayers( net , ['softmax'] );
%net2 = removeLayers( netUpdated , ['fc'] );
 

imageSize = net.Layers(1).InputSize;
layerName = net.Layers(1).Name;
newInputLayer = imageInputLayer(imageSize,Normalization="none",Name=layerName);
%Replace the image input layer in the base network with the new input layer.
dlnet = replaceLayer(net,layerName,newInputLayer);
%Specify the names of the feature extraction layers in the base network to use as the detection heads.
featureExtractionLayers = ["activation_22_relu","activation_40_relu"]% ["activation_22_relu","activation_40_relu"];

detector = yolov4ObjectDetector(dlnet,classes,anchorBoxes, ...
    DetectionNetworkSource=featureExtractionLayers);


disp(detector) 
analyzeNetwork(detector.Network)

I = imread("dedra_www.jpg");
[bboxes, scores, labels] = detect(detector, I, Threshold=0.4);
objBoxes = bboxes(labels=="person", :);
detectedImg = insertObjectAnnotation(I, "Rectangle", objBoxes, "person");
figure
imshow(detectedImg)



% detector = yolov4ObjectDetector(net2,classes,aboxes);
%yolov4ObjectDetector(net2,classes,aboxes,'DetectionNetworkSource',layer);
%Network must not have any fully connected layers.




%detector = yolov4ObjectDetector(baseNet,classes,aboxes,DetectionNetworkSource=layer)


%detector = yolov4ObjectDetector(net,classes,anchorBoxes,InputSize=inputSize);
 %}