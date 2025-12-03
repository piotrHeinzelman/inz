 
input = imageInputLayer([5 5 1]);  % 28x28px 1 channel
conv = convolution2dLayer(3, 1, "BiasInitializer", 'ones' , 'Weights',[1,2,3;4,5,6;7,8,9]); % 1 filter, 3x3
relu = reluLayer;                    %reLU
maxPooling2dLayer(2,Stride=2);
fc = fullyConnectedLayer(2);
sm = softmaxLayer;
co = classificationLayer;

epochs=1;

layers = [ input
    conv
    relu
    fc
    sm
    co];


options=trainingOptions('adam', 'MaxEpochs',epochs, 'ExecutionEnvironment','gpu','Verbose',0);


xtest1 = [1,2,3,4,5
    6,7,8,9,10
    11,12,13,14,15
    16,17,18,19,20
    21,22,23,24,25];
xtest2 = [25,24,23,22,21
            20,19,18,17,16
            15,14,13,12,11
            10,9,8,7,6
            5,4,3,2,1];

xtest = zeros(5,5,2);
xtest(:,:,1) = xtest1;
xtest(:,:,2) = xtest2;
ytest(1) = categorical(1);
ytest(2) = categorical(9);
 
netTransfer = trainNetwork( xtest, ytest, layers, options);


weights_first=netTransfer.Layers(2,1).Weights(:,:,1,1)
 
  