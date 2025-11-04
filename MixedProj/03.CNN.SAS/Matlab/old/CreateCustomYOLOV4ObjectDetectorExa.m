% openExample('vision/CreateCustomYOLOV4ObjectDetectorExample')

%basenet = imagePretrainedNetwork("darknet53",Weights="none");%pretrained
%Use analyzeNetwork to display the architecture of the base network.

%The first layer in the base network is the image input layer. Inspect the property of the image input layer in the base network.
load("basenet.mat")

if(false)
for i=(14:96)
 n=basenet.Layers(14).Name
 basenet = basenet.removeLayers(n);
end    
end
%
%basenet = basenet.removeLayers();


basenet.Layers(1)
analyzeNetwork(basenet)

%To create a YOLO v4 deep learning network you must set the Normalization property of the ImageInputLayer in the base network to "none". Define an image input layer with the Normalization property set as "none" and other property values the same as those of the base network.
imageSize = basenet.Layers(1).InputSize;
layerName = basenet.Layers(1).Name;
newInputLayer = imageInputLayer(imageSize,Normalization="none",Name=layerName);
%Replace the image input layer in the base network with the new input layer.
dlnet = replaceLayer(basenet,layerName,newInputLayer);
%Specify the names of the feature extraction layers in the base network to use as the detection heads.
featureExtractionLayers = ["leakyrelu22","leakyrelu40"];
%Specify the class names and anchor boxes to use for training the YOLO v4 deep learning network created using ResNet-50 as the base network.
classes = ["sas","person"];
anchorBoxes = {[122,177;223,84;80,94];...
               [111,38;33,47;37,18]};
%Create a YOLO v4 object detector by using the specified base network and the detection heads.
detector = yolov4ObjectDetector(dlnet,classes,anchorBoxes, ...
    DetectionNetworkSource=featureExtractionLayers);
%Display and inspect the properties of the YOLO v4 object detector.
disp(detector) 
%Use analyzeNetwork to display the YOLO v4 network architecture and get information about the network layers.
%analyzeNetwork(detector.Network);



I = imread("dedra_www.jpg");
[bboxes, scores, labels] = detect(detector, I, Threshold=0.4);
objBoxes = bboxes(labels=="sas", :);
detectedImg = insertObjectAnnotation(I, "Rectangle", objBoxes, "sas");
figure
imshow(detectedImg)