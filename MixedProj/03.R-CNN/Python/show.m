
I = imread("PythonDog2.jpg"); 
detectedImg = insertObjectAnnotation(I,"Rectangle",[ 130 450  470 700],["dog"]);
figure
imshow(detectedImg)
 
