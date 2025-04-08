package pl.heinzelman.tasks;

import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.LayerDeep.LayerPoolingMax;
import pl.heinzelman.LayerDeep.LayerReLU;
import pl.heinzelman.neu.LayerSigmoidFullConn;
import pl.heinzelman.neu.LayerSoftmaxMultiClass;
import pl.heinzelman.tools.Tools;

public class Task_CNN implements Task{

    private float[][] testX;
    private float[][] testY;
    private float[][] trainX;
    private float[][] trainY;


    private float[][][] testXX;
    private float[][][] trainXX;


    private LayerConv layer1Conv = new LayerConv( 5 , 8 , null, null );
    private LayerReLU layer2ReLU = new LayerReLU();
    private LayerPoolingMax layer3PoolingMax = new LayerPoolingMax(2, 2);
    private LayerFlatten layer4Flatten = new LayerFlatten();


    private LayerSigmoidFullConn layerFC;
    private LayerSoftmaxMultiClass layerSoftmax;

    private Tools tools = new Tools();

    int numOfEpoch=150;
    float[] CSBin_data=new float[numOfEpoch];

    @Override
    public void prepare() {

        int dataSize = 1;
        tools.prepareDataAsFlatArray( dataSize );

        testXX = tools.getTestAryX();
        trainXX = tools.getTrainAryX();

        tools.prepareData( dataSize );

        testX = tools.getTestX();
        testY = tools.getTestY();
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();

        //layerFC =new LayerSigmoidFullConn( 2880, 10 ); layerFC.setName("Layer1"); // n neurons
        layerFC =new LayerSigmoidFullConn( 1152, 10 ); layerFC.setName("Layer1"); // n neurons
        layerSoftmax =new LayerSoftmaxMultiClass( 10 ); layerSoftmax.setName("Layer3"); // n neurons

        // ****************************

        float[][][] oneX = new float[1][28][28];
        oneX[0] = trainXX[0]; // extract One X
        layer1Conv.setUpByX( oneX );

        layer1Conv.setX( oneX );
        float[][][] ZConv = layer1Conv.Forward();
        layer2ReLU.setX( ZConv );
        float[][][] ZReLU = layer2ReLU.Forward();
        layer3PoolingMax.setX( ZReLU );
        float[][][] ZPool = layer3PoolingMax.Forward();
        layer4Flatten.Forward( ZPool );
    }

    @Override
    public void run() {

        for (int cycle=0;cycle<20;cycle++) {

            float Loss = 0.0f;
            int step=1;
            for (int epoch = 0; epoch < numOfEpoch; epoch++) {
                step++;
                for ( int index = 0; index < trainX.length; index++ ) {

                    // ONE CYCLE
                    int ind_ex = /*index; //*/ (index * step) % trainX.length;

                    float[][][] oneX = new float[1][][];

                    oneX[0] = trainXX[ind_ex];
                    layer1Conv.setX(oneX);
                    layer2ReLU.setX(layer1Conv.Forward());
                    layer3PoolingMax.setX(layer2ReLU.Forward());
                    float[] CX = layer4Flatten.Forward(layer3PoolingMax.Forward());

// ---> 1

                    float[] CxX = layerFC.nForward( CX );
                    float[] Z = layerSoftmax.nForward( CxX );

                    float[] S_Z = tools.vectorSubstSsubZ(trainY[ind_ex], Z );
                    float[] eOUT = layerSoftmax.nBackward(S_Z);

                    Loss += Tools.crossEntropyMulticlassError( Z );

                    layerFC.nBackward( eOUT );

// --- TRAIN --- >

                    float[][][] delta4 = layer4Flatten.Backward( layerFC.getEout() );
                    float[][][] delta3 = layer3PoolingMax.Backward(delta4);
                    float[][][] delta2 = layer2ReLU.Backward(delta3);
                    float[][][] delta = layer1Conv.Backward(delta2);

                    if (false) {
                        if (index == 1 || true) {
                            tools.saveVectorAsImg(delta4[0], "FC_Eout");
                            tools.saveVectorAsImg(delta4[0], "delta4");
                            tools.saveVectorAsImg(delta3[0], "delta3");
                            tools.saveVectorAsImg(delta2[0], "delta2");
                            tools.saveVectorAsImg(delta[0], "delta");
                        }
                    if (true) throw new RuntimeException("!");
                    }
                }
                CSBin_data[epoch]=Loss/trainX.length;

            }


            float[][][] oneX = new float[1][][];
            // check accuracy
            int len = testX.length;
            int accuracy = 0;
            for (int i = 0; i < len; i++) {

                oneX[0]=trainXX[i];
// ----------->
                layer1Conv.setX( oneX );
                layer2ReLU.setX( layer1Conv.Forward() );
                layer3PoolingMax.setX( layer2ReLU.Forward() );
                float[] CX = layer4Flatten.Forward(layer3PoolingMax.Forward());
// ---------->
                layerFC.nForward( CX );
                float[] CxX = layerFC.getZ();
                layerSoftmax.nForward(CxX);

                int netClassId = tools.getIndexMaxFloat( layerSoftmax.getZ() );
                int fileClassId = tools.getIndexMaxFloat( testY[i] );
                if (fileClassId == netClassId) {
                    accuracy++;
                }
            }
            System.out.println(100.0f * accuracy / len + "%");
        }
    }
}
