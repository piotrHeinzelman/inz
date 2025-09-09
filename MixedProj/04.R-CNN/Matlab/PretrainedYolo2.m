% Yolo v2
% Matlab, tworzenie przetrenowanego obiektu
% wymaga : Computer Vision Toolbox™
% Computer Vision Toolbox Model for YOLO v2 Object Detection

% Yolo Matlab v2
% https://www.mathworks.com/help/vision/ref/yolov3objectdetector.html

% Yolo Matlab v3
% https://www.mathworks.com/help/vision/ref/yolov3objectdetector.html
% autorun Example: openExample('vision/DetectObjectsUsingYOLOV3DetectorExample')

 
%name = "tiny-yolov2-coco";
%detector = yolov2ObjectDetector(name);

%name = "tiny-yolov3-coco";
%detector = yolov3ObjectDetector(name);

%name = "tiny-yolov4-coco";
%detector = yolov4ObjectDetector(name);

%
% Load YOLO v8 model
det = yolov8ObjectDetector('yolov8s');
%
% Analyze loaded model
%analyzeNetwork(det.Network);
%
%yolov8n
%yolov8s
%yolov8m
%yolov8l
%yolov8x
% https://github.com/matlab-deep-learning/Pretrained-YOLOv8-Network-For-Object-Detection?tab=readme-ov-file#object-detection-1

disp(detector)




% detekcja
img = imread('sherlock.jpg');
%img = imread('img.jpg');
[bboxes,scores,labels] = detect(detector,img); 

detectedImg = insertObjectAnnotation(img,"Rectangle",bboxes,labels);
figure
imshow(detectedImg)











% Yolo Matlab v4
% https://www.mathworks.com/help/vision/ug/getting-started-with-yolo-v4.html