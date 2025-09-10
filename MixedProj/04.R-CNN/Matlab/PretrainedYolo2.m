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
if (false)
    name = "tiny-yolov4-coco";
    detector = yolov4ObjectDetector( name );
end  
 
% Load YOLO v8 model
% https://github.com/matlab-deep-learning/Pretrained-YOLOv8-Network-For-Object-Detection?tab=readme-ov-file#object-detection-1
if (true)
    %name = "yolov8s";
    %name = "yolov8m";
    %name = "yolov8l";
    name = "yolov8x";
    detector = yolov8ObjectDetector( name );
%    analyzeNetwork(detector.Network)
%yolov8n
%yolov8s
%yolov8m
%yolov8l
%yolov8x

%                   'yolov8n'   Use this model for speed and efficiency.
%
%                   'yolov8s'   Use this model for a balance between speed
%                               and accuracy, suitable for applications
%                               requiring real-time performance with good
%                               segmentation quality.
%
%                   'yolov8m'   Use this model for higher accuracy with
%                               moderate computational demands.
%
%                   'yolov8l'   Use this model to prioritize maximum
%                               segmentation accuracy for high-end systems,
%                               at the cost of computational intensity.
%
%                   'yolov8x'   Use this model to get most accurate
%                               segmentation but requires significant
%                               computational resources, ideal for high-end
%                               systems prioritizing segmentation
%                               performance.

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