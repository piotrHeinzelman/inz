

epoch=10;

load('detector');


options = trainingOptions("sgdm", ...
    InitialLearnRate=0.01, ...
    MaxEpochs=epoch, ...
    Shuffle="every-epoch", ... % ValidationData=imdsValidation, ...
    ValidationFrequency=30, ...
    Plots="training-progress", ... % Metrics="accuracy", ...
    Verbose=false);

%train detector MLP
detector = trainYOLOv4ObjectDetector(trainingData,detector,options)
 





I = imread("dedra_www.jpg");
[bboxes, scores, labels] = detect(detector, I, Threshold=0.8);
objBoxes = bboxes(labels=="sas", :);
detectedImg = insertObjectAnnotation(I, "Rectangle", objBoxes, "sas");
figure
imshow(detectedImg)

 