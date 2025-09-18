% https://www.mathworks.com/help/deeplearning/ug/create-simple-deep-learning-network-for-classification.html
% unzip("DigitsData.zip"); % MNIST

epoch=8; %50
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
    imageInputLayer([240 240 3], "Min",0, "Max",1, NormalizationDimension="auto", Normalization="rescale-zero-one", SplitComplexInputs=0 )

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

    convolution2dLayer(1,256,Padding="same")
    batchNormalizationLayer
    reluLayer(Name="Lay")
 
    fullyConnectedLayer( numberOfClass )
    softmaxLayer
    %flattenLayer

    ];


%{

   1   'input'             Image Input           256×256×3 images
     2   'conv1'             2-D Convolution       32 3×3×3 convolutions with stride [1  1] and padding 'same'
     3   'batchnorm1'        Batch Normalization   Batch normalization with 32 channels
     4   'leakyrelu1'        Leaky ReLU            Leaky ReLU with scale 0.1
     5   'conv2'             2-D Convolution       64 3×3×32 convolutions with stride [2  2] and padding [1  0  1  0]
     6   'batchnorm2'        Batch Normalization   Batch normalization with 64 channels
     7   'leakyrelu2'        Leaky ReLU            Leaky ReLU with scale 0.1
     8   'conv3'             2-D Convolution       32 1×1×64 convolutions with stride [1  1] and padding 'same'
     9   'batchnorm3'        Batch Normalization   Batch normalization with 32 channels
    10   'leakyrelu3'        Leaky ReLU            Leaky ReLU with scale 0.1
    11   'conv4'             2-D Convolution       64 3×3×32 convolutions with stride [1  1] and padding 'same'
    12   'batchnorm4'        Batch Normalization   Batch normalization with 64 channels
    13   'leakyrelu4'        Leaky ReLU            Leaky ReLU with scale 0.1
    14   'res1'              Addition              Element-wise addition of 2 inputs
    15   'conv5'             2-D Convolution       128 3×3×64 convolutions with stride [2  2] and padding [1  0  1  0]
    16   'batchnorm5'        Batch Normalization   Batch normalization with 128 channels
    17   'leakyrelu5'        Leaky ReLU            Leaky ReLU with scale 0.1
    18   'conv6'             2-D Convolution       64 1×1×128 convolutions with stride [1  1] and padding 'same'
    19   'batchnorm6'        Batch Normalization   Batch normalization with 64 channels
    20   'leakyrelu6'        Leaky ReLU            Leaky ReLU with scale 0.1
    21   'conv7'             2-D Convolution       128 3×3×64 convolutions with stride [1  1] and padding 'same'
    22   'batchnorm7'        Batch Normalization   Batch normalization with 128 channels
    23   'leakyrelu7'        Leaky ReLU            Leaky ReLU with scale 0.1
    24   'res2'              Addition              Element-wise addition of 2 inputs
    25   'conv8'             2-D Convolution       64 1×1×128 convolutions with stride [1  1] and padding 'same'
    26   'batchnorm8'        Batch Normalization   Batch normalization with 64 channels
    27   'leakyrelu8'        Leaky ReLU            Leaky ReLU with scale 0.1
    28   'conv9'             2-D Convolution       128 3×3×64 convolutions with stride [1  1] and padding 'same'
    29   'batchnorm9'        Batch Normalization   Batch normalization with 128 channels
    30   'leakyrelu9'        Leaky ReLU            Leaky ReLU with scale 0.1
    31   'res3'              Addition              Element-wise addition of 2 inputs
    32   'conv10'            2-D Convolution       256 3×3×128 convolutions with stride [2  2] and padding [1  0  1  0]
    33   'batchnorm10'       Batch Normalization   Batch normalization with 256 channels
    34   'leakyrelu10'       Leaky ReLU            Leaky ReLU with scale 0.1
    35   'conv11'            2-D Convolution       128 1×1×256 convolutions with stride [1  1] and padding 'same'
    36   'batchnorm11'       Batch Normalization   Batch normalization with 128 channels
    37   'leakyrelu11'       Leaky ReLU            Leaky ReLU with scale 0.1
    38   'conv12'            2-D Convolution       256 3×3×128 convolutions with stride [1  1] and padding 'same'
    39   'batchnorm12'       Batch Normalization   Batch normalization with 256 channels
    40   'leakyrelu12'       Leaky ReLU            Leaky ReLU with scale 0.1
    41   'res4'              Addition              Element-wise addition of 2 inputs
    42   'conv13'            2-D Convolution       128 1×1×256 convolutions with stride [1  1] and padding 'same'
    43   'batchnorm13'       Batch Normalization   Batch normalization with 128 channels
    44   'leakyrelu13'       Leaky ReLU            Leaky ReLU with scale 0.1
    45   'conv14'            2-D Convolution       256 3×3×128 convolutions with stride [1  1] and padding 'same'
    46   'batchnorm14'       Batch Normalization   Batch normalization with 256 channels
    47   'leakyrelu14'       Leaky ReLU            Leaky ReLU with scale 0.1
    48   'res5'              Addition              Element-wise addition of 2 inputs
    49   'conv15'            2-D Convolution       128 1×1×256 convolutions with stride [1  1] and padding 'same'
    50   'batchnorm15'       Batch Normalization   Batch normalization with 128 channels
    51   'leakyrelu15'       Leaky ReLU            Leaky ReLU with scale 0.1
    52   'conv16'            2-D Convolution       256 3×3×128 convolutions with stride [1  1] and padding 'same'
    53   'batchnorm16'       Batch Normalization   Batch normalization with 256 channels
    54   'leakyrelu16'       Leaky ReLU            Leaky ReLU with scale 0.1
    55   'res6'              Addition              Element-wise addition of 2 inputs
    56   'conv17'            2-D Convolution       128 1×1×256 convolutions with stride [1  1] and padding 'same'
    57   'batchnorm17'       Batch Normalization   Batch normalization with 128 channels
    58   'leakyrelu17'       Leaky ReLU            Leaky ReLU with scale 0.1
    59   'conv18'            2-D Convolution       256 3×3×128 convolutions with stride [1  1] and padding 'same'
    60   'batchnorm18'       Batch Normalization   Batch normalization with 256 channels
    61   'leakyrelu18'       Leaky ReLU            Leaky ReLU with scale 0.1
    62   'res7'              Addition              Element-wise addition of 2 inputs
    63   'conv19'            2-D Convolution       128 1×1×256 convolutions with stride [1  1] and padding 'same'
    64   'batchnorm19'       Batch Normalization   Batch normalization with 128 channels
    65   'leakyrelu19'       Leaky ReLU            Leaky ReLU with scale 0.1
    66   'conv20'            2-D Convolution       256 3×3×128 convolutions with stride [1  1] and padding 'same'
    67   'batchnorm20'       Batch Normalization   Batch normalization with 256 channels
    68   'leakyrelu20'       Leaky ReLU            Leaky ReLU with scale 0.1
    69   'res8'              Addition              Element-wise addition of 2 inputs
    70   'conv21'            2-D Convolution       128 1×1×256 convolutions with stride [1  1] and padding 'same'
    71   'batchnorm21'       Batch Normalization   Batch normalization with 128 channels
    72   'leakyrelu21'       Leaky ReLU            Leaky ReLU with scale 0.1
    73   'conv22'            2-D Convolution       256 3×3×128 convolutions with stride [1  1] and padding 'same'
    74   'batchnorm22'       Batch Normalization   Batch normalization with 256 channels
    75   'leakyrelu22'       Leaky ReLU            Leaky ReLU with scale 0.1
    76   'res9'              Addition              Element-wise addition of 2 inputs
    77   'conv23'            2-D Convolution       128 1×1×256 convolutions with stride [1  1] and padding 'same'
    78   'batchnorm23'       Batch Normalization   Batch normalization with 128 channels
    79   'leakyrelu23'       Leaky ReLU            Leaky ReLU with scale 0.1
    80   'conv24'            2-D Convolution       256 3×3×128 convolutions with stride [1  1] and padding 'same'
    81   'batchnorm24'       Batch Normalization   Batch normalization with 256 channels
    82   'leakyrelu24'       Leaky ReLU            Leaky ReLU with scale 0.1
    83   'res10'             Addition              Element-wise addition of 2 inputs
    84   'conv25'            2-D Convolution       128 1×1×256 convolutions with stride [1  1] and padding 'same'
    85   'batchnorm25'       Batch Normalization   Batch normalization with 128 channels
    86   'leakyrelu25'       Leaky ReLU            Leaky ReLU with scale 0.1
    87   'conv26'            2-D Convolution       256 3×3×128 convolutions with stride [1  1] and padding 'same'
    88   'batchnorm26'       Batch Normalization   Batch normalization with 256 channels
    89   'leakyrelu26'       Leaky ReLU            Leaky ReLU with scale 0.1
    90   'res11'             Addition              Element-wise addition of 2 inputs
    91   'conv27'            2-D Convolution       512 3×3×256 convolutions with stride [2  2] and padding [1  0  1  0]
    92   'batchnorm27'       Batch Normalization   Batch normalization with 512 channels
    93   'leakyrelu27'       Leaky ReLU            Leaky ReLU with scale 0.1
    94   'conv28'            2-D Convolution       256 1×1×512 convolutions with stride [1  1] and padding 'same'
    95   'batchnorm28'       Batch Normalization   Batch normalization with 256 channels
    96   'leakyrelu28'       Leaky ReLU            Leaky ReLU with scale 0.1
    97   'conv29'            2-D Convolution       512 3×3×256 convolutions with stride [1  1] and padding 'same'
    98   'batchnorm29'       Batch Normalization   Batch normalization with 512 channels
    99   'leakyrelu29'       Leaky ReLU            Leaky ReLU with scale 0.1
    100   'res12'             Addition              Element-wise addition of 2 inputs
    101   'conv30'            2-D Convolution       256 1×1×512 convolutions with stride [1  1] and padding 'same'
    102   'batchnorm30'       Batch Normalization   Batch normalization with 256 channels
    103   'leakyrelu30'       Leaky ReLU            Leaky ReLU with scale 0.1
    104   'conv31'            2-D Convolution       512 3×3×256 convolutions with stride [1  1] and padding 'same'
    105   'batchnorm31'       Batch Normalization   Batch normalization with 512 channels
    106   'leakyrelu31'       Leaky ReLU            Leaky ReLU with scale 0.1
    107   'res13'             Addition              Element-wise addition of 2 inputs
    108   'conv32'            2-D Convolution       256 1×1×512 convolutions with stride [1  1] and padding 'same'
    109   'batchnorm32'       Batch Normalization   Batch normalization with 256 channels
    110   'leakyrelu32'       Leaky ReLU            Leaky ReLU with scale 0.1
    111   'conv33'            2-D Convolution       512 3×3×256 convolutions with stride [1  1] and padding 'same'
    112   'batchnorm33'       Batch Normalization   Batch normalization with 512 channels
    113   'leakyrelu33'       Leaky ReLU            Leaky ReLU with scale 0.1
    114   'res14'             Addition              Element-wise addition of 2 inputs
    115   'conv34'            2-D Convolution       256 1×1×512 convolutions with stride [1  1] and padding 'same'
    116   'batchnorm34'       Batch Normalization   Batch normalization with 256 channels
    117   'leakyrelu34'       Leaky ReLU            Leaky ReLU with scale 0.1
    118   'conv35'            2-D Convolution       512 3×3×256 convolutions with stride [1  1] and padding 'same'
    119   'batchnorm35'       Batch Normalization   Batch normalization with 512 channels
    120   'leakyrelu35'       Leaky ReLU            Leaky ReLU with scale 0.1
    121   'res15'             Addition              Element-wise addition of 2 inputs
    122   'conv36'            2-D Convolution       256 1×1×512 convolutions with stride [1  1] and padding 'same'
    123   'batchnorm36'       Batch Normalization   Batch normalization with 256 channels
    124   'leakyrelu36'       Leaky ReLU            Leaky ReLU with scale 0.1
    125   'conv37'            2-D Convolution       512 3×3×256 convolutions with stride [1  1] and padding 'same'
    126   'batchnorm37'       Batch Normalization   Batch normalization with 512 channels
    127   'leakyrelu37'       Leaky ReLU            Leaky ReLU with scale 0.1
    128   'res16'             Addition              Element-wise addition of 2 inputs
    129   'conv38'            2-D Convolution       256 1×1×512 convolutions with stride [1  1] and padding 'same'
    130   'batchnorm38'       Batch Normalization   Batch normalization with 256 channels
    131   'leakyrelu38'       Leaky ReLU            Leaky ReLU with scale 0.1
    132   'conv39'            2-D Convolution       512 3×3×256 convolutions with stride [1  1] and padding 'same'
    133   'batchnorm39'       Batch Normalization   Batch normalization with 512 channels
    134   'leakyrelu39'       Leaky ReLU            Leaky ReLU with scale 0.1
    135   'res17'             Addition              Element-wise addition of 2 inputs
    136   'conv40'            2-D Convolution       256 1×1×512 convolutions with stride [1  1] and padding 'same'
    137   'batchnorm40'       Batch Normalization   Batch normalization with 256 channels
    138   'leakyrelu40'       Leaky ReLU            Leaky ReLU with scale 0.1
    139   'conv41'            2-D Convolution       512 3×3×256 convolutions with stride [1  1] and padding 'same'
    140   'batchnorm41'       Batch Normalization   Batch normalization with 512 channels
    141   'leakyrelu41'       Leaky ReLU            Leaky ReLU with scale 0.1
    142   'res18'             Addition              Element-wise addition of 2 inputs
    143   'conv42'            2-D Convolution       256 1×1×512 convolutions with stride [1  1] and padding 'same'
    144   'batchnorm42'       Batch Normalization   Batch normalization with 256 channels
    145   'leakyrelu42'       Leaky ReLU            Leaky ReLU with scale 0.1
    146   'conv43'            2-D Convolution       512 3×3×256 convolutions with stride [1  1] and padding 'same'
    147   'batchnorm43'       Batch Normalization   Batch normalization with 512 channels
    148   'leakyrelu43'       Leaky ReLU            Leaky ReLU with scale 0.1
    149   'res19'             Addition              Element-wise addition of 2 inputs
    150   'conv44'            2-D Convolution       1024 3×3×512 convolutions with stride [2  2] and padding [1  0  1  0]
    151   'batchnorm44'       Batch Normalization   Batch normalization with 1024 channels
    152   'leakyrelu44'       Leaky ReLU            Leaky ReLU with scale 0.1
    153   'conv45'            2-D Convolution       512 1×1×1024 convolutions with stride [1  1] and padding 'same'
    154   'batchnorm45'       Batch Normalization   Batch normalization with 512 channels
    155   'leakyrelu45'       Leaky ReLU            Leaky ReLU with scale 0.1
    156   'conv46'            2-D Convolution       1024 3×3×512 convolutions with stride [1  1] and padding 'same'
    157   'batchnorm46'       Batch Normalization   Batch normalization with 1024 channels
    158   'leakyrelu46'       Leaky ReLU            Leaky ReLU with scale 0.1
    159   'res20'             Addition              Element-wise addition of 2 inputs
    160   'conv47'            2-D Convolution       512 1×1×1024 convolutions with stride [1  1] and padding 'same'
    161   'batchnorm47'       Batch Normalization   Batch normalization with 512 channels
    162   'leakyrelu47'       Leaky ReLU            Leaky ReLU with scale 0.1
    163   'conv48'            2-D Convolution       1024 3×3×512 convolutions with stride [1  1] and padding 'same'
    164   'batchnorm48'       Batch Normalization   Batch normalization with 1024 channels
    165   'leakyrelu48'       Leaky ReLU            Leaky ReLU with scale 0.1
    166   'res21'             Addition              Element-wise addition of 2 inputs
    167   'conv49'            2-D Convolution       512 1×1×1024 convolutions with stride [1  1] and padding 'same'
    168   'batchnorm49'       Batch Normalization   Batch normalization with 512 channels
    169   'leakyrelu49'       Leaky ReLU            Leaky ReLU with scale 0.1
    170   'conv50'            2-D Convolution       1024 3×3×512 convolutions with stride [1  1] and padding 'same'
    171   'batchnorm50'       Batch Normalization   Batch normalization with 1024 channels
    172   'leakyrelu50'       Leaky ReLU            Leaky ReLU with scale 0.1
    173   'res22'             Addition              Element-wise addition of 2 inputs
    174   'conv51'            2-D Convolution       512 1×1×1024 convolutions with stride [1  1] and padding 'same'
    175   'batchnorm51'       Batch Normalization   Batch normalization with 512 channels
    176   'leakyrelu51'       Leaky ReLU            Leaky ReLU with scale 0.1
    177   'conv52'            2-D Convolution       1024 3×3×512 convolutions with stride [1  1] and padding 'same'
    178   'batchnorm52'       Batch Normalization   Batch normalization with 1024 channels
    179   'leakyrelu52'       Leaky ReLU            Leaky ReLU with scale 0.1
    180   'res23'             Addition              Element-wise addition of 2 inputs
    181   'avg1'              2-D Average Pooling   8×8 average pooling with stride [1  1] and padding [0  0  0  0]
    182   'conv53'            2-D Convolution       1000 1×1×1024 convolutions with stride [1  1] and padding 'same'
    183   'softmax'           Softmax               softmax
    184   'softmax_flatten'   Flatten               Flatten

    
%}


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
analyzeNetwork(net)

TIME_TRAIN_TIME = datetime('now');

scores = minibatchpredict(net,imdsValidation);
YValidation = scores2label(scores,classNames);

TValidation = imdsValidation.Labels;
accuracy = mean(YValidation == TValidation)

TIME_ACCURACY_TIME = datetime('now');

if(true) % No generate on CPU !
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

