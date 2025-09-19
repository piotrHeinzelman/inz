I = imread("DaneUczace_DetektorCNNRegiony_MATLAB.jpg");

%<box top='93' left='119' width='379' height='671'>
position = [ 119/4  93/4   671/4  379/4 ];
detectedImg = insertObjectAnnotation(I,"rectangle",position,"");
figure
imshow(detectedImg)
 
 
 