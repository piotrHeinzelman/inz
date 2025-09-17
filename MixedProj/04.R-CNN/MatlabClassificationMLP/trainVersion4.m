% openExample('vision/TrainYOLOV4NetworkForVehicleDetectionExample')

%Train YOLO v4 Network for Vehicle Detection
%This example shows how to fine-tune a pretrained YOLO v4 object detector for detecting vehicles in an image.
%Load a tiny YOLO v4 object detector, pretrained on the COCO dataset, and inspect its properties.
detector = yolov4ObjectDetector("tiny-yolov4-coco")
%The number of anchor boxes must be same the number of output layers in the YOLO v4 network. The tiny YOLO v4 network contains two output layers.
detector.Network
%Prepare Training Data
%Load a .mat file containing the vehicle data set to use for training, in which data is stored as a table. The first column contains the training images and the remaining columns contain the labeled bounding boxes.


data = load("toolsTrainingData.mat");
%data = load("vehicleTrainingData.mat");

trainingData = data.vehicleTrainingData;
%Specify the directory in which to store the training samples. Add the full path to the file names in training data.
dataDir = fullfile(toolboxdir("vision"),"visiondata");
trainingData.imageFilename = fullfile(dataDir,trainingData.imageFilename);
%Create an ImageDatastore using the files from the table.
imds = imageDatastore(trainingData.imageFilename);
%Create a boxLabelDatastore using the label columns from the table.
blds = boxLabelDatastore(trainingData(:,2:end));
%Combine the datastores.
ds = combine(imds,blds);
%Specify the input size to use for resizing the training images. The size of the training images must be a multiple of 32 for when you use the tiny-yolov4-coco and csp-darknet53-coco pretrained YOLO v4 deep learning networks. You must also resize the bounding boxes based on the specified input size.
inputSize = [224 224 3];
%Resize and rescale the training images and the bounding boxes using the preprocessData helper function. Convert the preprocessed data to a datastore object using the transform function.
trainingDataForEstimation = transform(ds,@(data)preprocessData(data,inputSize));
%Estimate Anchor Boxes
%Estimate the anchor boxes from the training data. You must assign the same number of anchor boxes to each output layer in the YOLO v4 network.
numAnchors = 6;
[anchors,meanIoU] = estimateAnchorBoxes(trainingDataForEstimation,numAnchors);
area = anchors(:,1).*anchors(:,2);
[~,idx] = sort(area,"descend");
anchors = anchors(idx,:);
anchorBoxes = {anchors(1:3,:);anchors(4:6,:)};
%Configure and Train YOLO v4 Network
%Specify the class names and configure the pretrained YOLO v4 deep learning network to be retrained for the new data set using the yolov4ObjectDetector function.
classes = ["vehicle"];
detector = yolov4ObjectDetector("tiny-yolov4-coco",classes,anchorBoxes,InputSize=inputSize);
%Specify the training options and retrain the pretrained YOLO v4 network on the new data set using the trainYOLOv4ObjectDetector function.
options = trainingOptions("sgdm", ...
    InitialLearnRate=0.001, ...
    MiniBatchSize=16, ...
    MaxEpochs=40, ...
    ResetInputNormalization=false, ...
    VerboseFrequency=30);
trainedDetector = trainYOLOv4ObjectDetector(ds,detector,options);

%Detect Vehicles in Test Image
%Load a test image from the workspace.
I = imread("highway.png");
%Use the fine-tuned YOLO v4 object detector to detect vehicles in the test image and display the detection results.
[bboxes,scores,labels] = detect(trainedDetector,I,Threshold=0.05);
detectedImg = insertObjectAnnotation(I,"Rectangle",bboxes,labels);
figure
imshow(detectedImg)

%Supporting Functions
function data = preprocessData(data,targetSize)
for num = 1:size(data,1)
    I = data{num,1};
    imgSize = size(I);
    bboxes = data{num,2};
    I = im2single(imresize(I,targetSize(1:2)));
    scale = targetSize(1:2)./imgSize(1:2);
    bboxes = bboxresize(bboxes,scale);
    data(num,1:2) = {I,bboxes};
end
end
%Copyright 2024 The MathWorks, Inc.
