package pl.heinzelman.tasks;

import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.LayerDeep.LayerPoolingMax;
import pl.heinzelman.LayerDeep.LayerReLU;
import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;
import pl.heinzelman.tools.Tools;

import javax.tools.Tool;
import java.awt.image.BufferedImage;
import java.util.Arrays;

public class Task_CNN implements Task{

    private float[][] testX;
    private float[][] testY;
    private float[][] trainX;
    private float[][] trainY;


    private float[][][] testXX;
    private float[][][] trainXX;


    private LayerConv layer1Conv = new LayerConv( 5 , 20 , null, null );
    private LayerReLU layer2ReLU = new LayerReLU();
    private LayerPoolingMax layer3PoolingMax = new LayerPoolingMax(2, 2);
    private LayerFlatten layer4Flatten = new LayerFlatten();





    private Layer layer1;
    private Layer layer2;
    private Layer layer3;

    private Tools tools = new Tools();

    int numOfEpoch=500;
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



        layer1=new Layer( LType.sigmod , 64 ,2880 ); layer1.setName("Layer1"); // n neurons
        //layer1=new Layer( LType.sigmod , 64 ,784 ); layer1.setName("Layer1"); // n neurons
        layer1.rnd();

        layer2=new Layer( LType.sigmod , 64 ,64 ); layer2.setName("Layer2"); // n neurons
        layer2.rnd();

        layer3=new Layer( LType.softmaxMultiClass , 10 ,64 ); layer3.setName("Layer3"); // n neurons
        layer3.rnd();


        // ****************************

        float[][][] oneX = new float[1][28][28];
        oneX[0] = trainXX[0]; // extract One X
        layer1Conv.setUpByX( oneX );
        //System.out.println( "oneX" +  Tools.AryToString( oneX ));

        //System.out.println( layer1Conv );
        //System.out.println( layer2ReLU );
        //System.out.println( layer3PoolingMax );
        //System.out.println( layer4Flatten );
        //System.out.println(Arrays.toString( layer5X ));
        //System.out.println( layer5X.length );

        // ****************************

    }

    @Override
    public void run() {

        for (int cycle=0;cycle<1;cycle++) {

            float Loss = 0.0f;
            int step=1;
            for (int epoch = 0; epoch < numOfEpoch; epoch++) {
                step++;
                for ( int index = 0; index < trainX.length; index++ ) {

                    // ONE CYCLE
                    int ind_ex = /*index; //*/ (index * step) % trainX.length;

                    float[][][] oneX = new float[1][][];

                    oneX[0] = trainXX[ind_ex];
                    //System.out.println( Tools.AryToString( oneX ));
                    //System.out.println(  Arrays.toString( trainY[ind_ex] ) );
                    //System.out.println(  Arrays.toString( trainX[ind_ex] ) );

                    layer1Conv.setX(oneX);
                    // System.out.println( "Ysize:" + layer1Conv.Forward().length * layer1Conv.Forward()[0].length* layer1Conv.Forward()[0].length );
                    layer2ReLU.setX(layer1Conv.Forward());
                    layer3PoolingMax.setX(layer2ReLU.Forward());
                    float[] CX = layer4Flatten.Forward(layer3PoolingMax.Forward());
                    //System.out.println("SIZE: " + CX.length);

                    //if (index==1) { tools.saveVectorAsImg( CX , "cx" ); }
                    //if (true) throw new RuntimeException("!");
// --->1
                    layer1.setX(CX);
                    // layer1.setX( trainX[ ind_ex ] );
                    layer1.nForward();
                    layer2.setX(layer1.getZ());
                    layer2.nForward();
                    layer3.setX(layer2.getZ());
                    layer3.nForward();

                    float[] S_Z = tools.vectorSubstSsubZ(trainY[ind_ex], layer3.getZ());
                    layer3.nBackward(S_Z);
                    Loss += Tools.crossEntropyMulticlassError(layer3.getZ());
                    layer2.nBackward(layer3.getEout());
                    layer1.nBackward(layer2.getEout());
                    float[] FC_Eout = layer1.getEout();

// --- TRAIN ---
                    // if (index==1 || true) { tools.saveVectorAsImg( CX , "cx" ); }
                    float[][][] delta4 = layer4Flatten.Backward(FC_Eout);
                    float[][][] delta3 = layer3PoolingMax.Backward(delta4);
                    float[][][] delta2 = layer2ReLU.Backward(delta3);
                    float[][][] delta = layer1Conv.Backward(delta2);

                    if (false) {
                        if (index == 1 || true) {
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
            System.out.println( Arrays.toString( layer1.getNeuronWeight(0)));
            System.out.println( Arrays.toString( layer3.getX()));
            System.out.println( Arrays.toString( layer3.getZ()));

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
                layer1.setX( CX );
                // layer1.setX( testX[i] );
                layer1.nForward();
                layer2.setX( layer1.getZ() );
                layer2.nForward();
                layer3.setX( layer2.getZ() );
                layer3.nForward();

                int netClassId = tools.getIndexMaxFloat( layer3.getZ() );
                int fileClassId = tools.getIndexMaxFloat( testY[i] );
                if (fileClassId == netClassId) {
                    accuracy++;
                }
            }
            System.out.println(100.0f * accuracy / len + "%");
        }
    }
}
