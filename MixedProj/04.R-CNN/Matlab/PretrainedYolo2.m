% Yolo v2
% Matlab, tworzenie przetrenowanego obiektu
% wymaga : Computer Vision Toolbox™
% Computer Vision Toolbox Model for YOLO v2 Object Detection

name = "tiny-yolov2-coco";
detector = yolov2ObjectDetector(name);

disp(detector)


% detekcja
% img = imread('sherlock.jpg');
img = imread('img.jpg');
[bboxes,scores,labels] = detect(detector,img); 

detectedImg = insertObjectAnnotation(img,"Rectangle",bboxes,labels);
figure
imshow(detectedImg)


