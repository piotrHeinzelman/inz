% https://www.mathworks.com/help/deeplearning/ug/create-simple-deep-learning-network-for-classification.html
% unzip("DigitsData.zip"); % MNIST

epoch=50;
GPU=true;

TIME_START=datetime('now');

dataFolder = "../../240pix2classSAS/";
imds = imageDatastore(dataFolder, ...
    IncludeSubfolders=true, ...
    LabelSource="foldernames");
%{
figure
tiledlayout("flow");
perm = randperm(1764,20);
for i = 1:20
    nexttile
    imshow(imds.Files{perm(i)});
end
%}

classNames = categories(imds.Labels);
labelCount = countEachLabel(imds);
numberOfClass=2;

img = readimage(imds,1);
size(img);


numTrainFiles = 800;
[imdsTrain,imdsValidation] = splitEachLabel(imds,numTrainFiles,"randomize");


TIME_LOAD_AND_PREPARE_DATA = datetime('now');




% layers std
%layers = [
%    imageInputLayer([240 240 3])
%    convolution2dLayer(3,8,Padding="same")
%    batchNormalizationLayer
%    reluLayer

%    maxPooling2dLayer(2,Stride=2)

%    convolution2dLayer(3,16,Padding="same")
%    batchNormalizationLayer
%    reluLayer

%    maxPooling2dLayer(2,Stride=2)

%    convolution2dLayer(3,32,Padding="same")
%    batchNormalizationLayer
%    reluLayer

%    fullyConnectedLayer( numberOfClass )
%    softmaxLayer];


%layers a`la yolo4
layers = [
    imageInputLayer([240 240 3])
    convolution2dLayer(7,32,Padding="same")
    batchNormalizationLayer
    reluLayer
    maxPooling2dLayer(2, Stride=2)


    convolution2dLayer(5,64,Padding="same")
    batchNormalizationLayer
    reluLayer
    maxPooling2dLayer(2, Stride=2)

    convolution2dLayer(3,128,Padding="same")
    batchNormalizationLayer
    reluLayer
    maxPooling2dLayer(2, Stride=2)

    convolution2dLayer(3,256,Padding="same")
    batchNormalizationLayer
    reluLayer
    maxPooling2dLayer(2, Stride=2)


    %{ ** wymaganie matlab !!! na wyjsciu 18 kanalow ** %}
    convolution2dLayer(3,128,Padding="same")
    batchNormalizationLayer
    reluLayer
    maxPooling2dLayer(2, Stride=2)

    convolution2dLayer(3,64,Padding="same")
    batchNormalizationLayer
    reluLayer
    maxPooling2dLayer(2, Stride=2)

    convolution2dLayer(3,32,Padding="same")
    batchNormalizationLayer
    reluLayer
    maxPooling2dLayer(2, Stride=2)

    convolution2dLayer(3,18,Padding=1, Stride=2)
    batchNormalizationLayer
    reluLayer
    %{ ** wymaganie matlab !!! na wyjsciu 18 kanalow **  %}

    fullyConnectedLayer( numberOfClass )
    softmaxLayer ];


options = trainingOptions("sgdm", ...
    InitialLearnRate=0.01, ...
    MaxEpochs=epoch, ...
    Shuffle="every-epoch", ...
    ValidationData=imdsValidation, ...
    ValidationFrequency=30, ...
    Plots="training-progress", ...
    Metrics="accuracy", ...
    Verbose=false);


TIME_CREATE_MODEL = datetime('now');

net = trainnet(imdsTrain,layers,"crossentropy",options);

TIME_TRAIN_TIME = datetime('now');

scores = minibatchpredict(net,imdsValidation);
YValidation = scores2label(scores,classNames);

TValidation = imdsValidation.Labels;
accuracy = mean(YValidation == TValidation)

TIME_ACCURACY_TIME = datetime('now');

if(false) % No generate on CPU !
   save('netCNN_SAS','net');
end




%%%%%  REPORT %%%%%

timeLoadData   = seconds( duration( TIME_LOAD_AND_PREPARE_DATA-TIME_START ));
timeMakeLayers = seconds( duration( TIME_CREATE_MODEL-TIME_LOAD_AND_PREPARE_DATA));
timeTrainModel = seconds( duration( TIME_TRAIN_TIME-TIME_CREATE_MODEL));
timeAccuracy   = seconds( duration( TIME_ACCURACY_TIME-TIME_TRAIN_TIME));


fprintf ('## Epoch:%d, GPU:%s, loadData:%f, createLayers:%f, trainTime:%f, timeAccuracy:%f, accuracy: %f\n', epoch, GPU, timeLoadData, timeMakeLayers, timeTrainModel, timeAccuracy, accuracy );
fprintf ('library[0]="Matlab GPU"\n'  );
fprintf ('d0[0]=%f\n', timeLoadData   );
fprintf ('d1[0]=%f\n', timeMakeLayers );
fprintf ('d2[0]=%f/%d\n', timeTrainModel, epoch );
fprintf ('d3[0]=%f\n', timeAccuracy   );
%fprintf ('%s2[%d]=%f \n');


%{
Error using yolov4ObjectDetector>iValidateYOLOv4Network (line 1733)
Number of filters in the output convolutional layer must be 18 for 3 anchor boxes and 1 classes.

Error in yolov4ObjectDetector/parseDetectorInputs (line 1180)
                iValidateYOLOv4Network(params.Network, numClasses, params.AnchorBoxes, params.PredictedBoxType);

Error in yolov4ObjectDetector (line 286)
                params = yolov4ObjectDetector.parseDetectorInputs(varargin{:});

Error in trainYolo (line 37)
detector = yolov4ObjectDetector(net2,classes,aboxes);
%}


%{
  1   'input'             Image Input               416×416×3 images
     2   'conv2d_1'          2-D Convolution           16 3×3×3 convolutions with stride [1  1] and padding 'same'
     3   'batch_norm_1'      Batch Normalization       Batch normalization with 16 channels
     4   'leaky_relu_1'      Leaky ReLU                Leaky ReLU with scale 0.1
     5   'max_pooling_1'     2-D Max Pooling           2×2 max pooling with stride [2  2] and padding 'same'
     6   'conv2d_2'          2-D Convolution           32 3×3×16 convolutions with stride [1  1] and padding 'same'
     7   'batch_norm_2'      Batch Normalization       Batch normalization with 32 channels
     8   'leaky_relu_2'      Leaky ReLU                Leaky ReLU with scale 0.1
     9   'max_pooling_2'     2-D Max Pooling           2×2 max pooling with stride [2  2] and padding 'same'
    10   'conv2d_3'          2-D Convolution           64 3×3×32 convolutions with stride [1  1] and padding 'same'
    11   'batch_norm_3'      Batch Normalization       Batch normalization with 64 channels
    12   'leaky_relu_3'      Leaky ReLU                Leaky ReLU with scale 0.1
    13   'max_pooling_3'     2-D Max Pooling           2×2 max pooling with stride [2  2] and padding 'same'
    14   'conv2d_4'          2-D Convolution           128 3×3×64 convolutions with stride [1  1] and padding 'same'
    15   'batch_norm_4'      Batch Normalization       Batch normalization with 128 channels
    16   'leaky_relu_4'      Leaky ReLU                Leaky ReLU with scale 0.1
    17   'max_pooling_4'     2-D Max Pooling           2×2 max pooling with stride [2  2] and padding 'same'
    18   'conv2d_5'          2-D Convolution           256 3×3×128 convolutions with stride [1  1] and padding 'same'
    19   'batch_norm_5'      Batch Normalization       Batch normalization with 256 channels
    20   'leaky_relu_5'      Leaky ReLU                Leaky ReLU with scale 0.1
    21   'max_pooling_5'     2-D Max Pooling           2×2 max pooling with stride [2  2] and padding 'same'
    22   'conv2d_6'          2-D Convolution           512 3×3×256 convolutions with stride [1  1] and padding 'same'
    23   'batch_norm_6'      Batch Normalization       Batch normalization with 512 channels
    24   'leaky_relu_6'      Leaky ReLU                Leaky ReLU with scale 0.1
    25   'max_pooling_6'     2-D Max Pooling           2×2 max pooling with stride [1  1] and padding 'same'
    26   'conv2d_7'          2-D Convolution           1024 3×3×512 convolutions with stride [1  1] and padding 'same'
    27   'batch_norm_7'      Batch Normalization       Batch normalization with 1024 channels
    28   'leaky_relu_7'      Leaky ReLU                Leaky ReLU with scale 0.1
    29   'conv2d_8'          2-D Convolution           512 3×3×1024 convolutions with stride [1  1] and padding 'same'
    30   'batch_norm_8'      Batch Normalization       Batch normalization with 512 channels
    31   'leaky_relu_8'      Leaky ReLU                Leaky ReLU with scale 0.1
    32   'conv2d_9'          2-D Convolution           425 1×1×512 convolutions with stride [1  1] and padding [0  0  0  0]
    33   'yolov2Transform'   YOLO v2 Transform Layer   YOLO v2 Transform Layer with 5 anchors

%}
