% Yolo v2
% Matlab, tworzenie przetrenowanego obiektu
% wymaga : Computer Vision Toolbox™
% Computer Vision Toolbox Model for YOLO v2 Object Detection

% Yolo Matlab v2
% https://www.mathworks.com/help/vision/ug/getting-started-with-yolo-v2.html
% https://www.mathworks.com/help/vision/ref/yolov2objectdetector.html

if (false)
    name = "tiny-yolov2-coco";
    detector = yolov2ObjectDetector( name );
end


% Yolo Matlab v3
% https://www.mathworks.com/help/vision/ref/yolov3objectdetector.html
% autorun Example: openExample('vision/DetectObjectsUsingYOLOV3DetectorExample')

if (false)
    name = "tiny-yolov3-coco";
    detector = yolov3ObjectDetector( name );
end  

% yolo 4
% https://www.mathworks.com/help/vision/ref/yolov4objectdetector.html
if (true)
    name = "tiny-yolov4-coco";
    detector = yolov4ObjectDetector( name );
end  
 
% Load YOLO v8 model
% https://github.com/matlab-deep-learning/Pretrained-YOLOv8-Network-For-Object-Detection?tab=readme-ov-file#object-detection-1
if (false)
    name = "yolov8s";
    detector = yolov8ObjectDetector( name );
%    analyzeNetwork(detector.Network)
%yolov8n
%yolov8s
%yolov8m
%yolov8l
%yolov8x

end



disp(detector)




% detekcja
 img = imread('dog-5519360_1280.jpg'); 
% img = imread('dog-7956828_1280.jpg'); 
%img = imread('sherlock.jpg'); 
[bboxes,scores,labels] = detect(detector,img); 

detectedImg = insertObjectAnnotation(img,"Rectangle",bboxes,labels);
figure
imshow(detectedImg)
 






% Yolo Matlab v4
% https://www.mathworks.com/help/vision/ug/getting-started-with-yolo-v4.html