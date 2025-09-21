
I = imread("path/to/dog.jpg"); 
detectedImg = insertObjectAnnotation(I,"Rectangle",[ 3*4 1*4  640*1.9 480*1.9],["dog"]);
figure
imshow(detectedImg)
 
