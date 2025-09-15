%path="/home/john/inz_DATA/GROUPS/jpg/";


load("/home/john/inz/MixedProj/04.R-CNN/Matlab/trainingData.mat");

%trainingData = Data.Data.vehicleTrainingData;

%save('trainingData', 'trainingData');

%trainingData1.imageFilename(1) = "/home/john/inz_DATA/Groups_small/group_1074.jpga";
%trainingData1.vehicle{1} = [6.16259501406154,12.0616543130181,34.2760466778522,36.2677829970486];


%dataDir = fullfile(toolboxdir("/home/john/inz_DATA/GROUPS/jpg/"),"visiondata");
%trainingData.imageFilename = fullfile(dataDir,trainingData.imageFilename);
 
detector = yolov4ObjectDetector("tiny-yolov4-coco")
detector.Network

imds = imageDatastore(trainingData.imageFilename);
blds = boxLabelDatastore(trainingData(:,2:end));
ds = combine(imds,blds);
