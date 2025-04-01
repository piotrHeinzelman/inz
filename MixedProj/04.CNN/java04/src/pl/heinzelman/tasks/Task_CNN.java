package pl.heinzelman.tasks;

import org.testng.annotations.Test;
import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.LayerDeep.LayerPoolingMax;
import pl.heinzelman.LayerDeep.LayerReLU;
import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;
import pl.heinzelman.tools.Tools;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Task_CNN implements Task{

    private float[][][] testX;
    private float[][] testY;
    private float[][][] trainX;
    private float[][] trainY;


    private LayerConv layer1Conv = new LayerConv( 5 , 2 , null, null );
    private LayerReLU layer2ReLU = new LayerReLU();
    private LayerPoolingMax layer3PoolingMax = new LayerPoolingMax(2, 2);
    private LayerFlatten layer4Flatten = new LayerFlatten();


    private Layer layer10;
    private Layer layer11;
    private Layer layer12;

    private Tools tools = new Tools();

    private float[][][] oneX = new float[1][28][28];

    float Loss;

    int numOfEpoch=5;
    float[] CSBin_data=new float[numOfEpoch];

    @Test
    @Override
    public void prepare() {
        tools.prepareDataAsFlatArray(1 );

        testX = tools.getTestAryX();
        testY = tools.getTestY();
        trainX = tools.getTrainAryX();
        trainY = tools.getTrainY();

        // System.out.println( Tools.AryToString( trainX[0] ));
        // layer 1 CONV
        //layer1Conv = new LayerConv( 5 , 2 , null, null ); //int filterSize, Integer filterForChannel, Integer padding, Integer stride

            //float[][][] oneX = new float[1][][];
            oneX[0] = trainX[0]; // extract One X
            layer1Conv.setUpByX( oneX );
            layer1Conv.setX( oneX );
            float[][][] layer2X = layer1Conv.Forward();
            // System.out.println( Tools.AryToString( oneX ) );


        // layer 2 ReLU
        //layer2ReLU = new LayerReLU();
            layer2ReLU.setX( layer2X );
            float[][][] layer3X = layer2ReLU.Forward();

        // layer 3 poolMax
        //layer3PoolingMax = new LayerPoolingMax(2, 2);
            layer3PoolingMax.setX( layer3X );
            float[][][] layer4X = layer3PoolingMax.Forward();

        //LayerFlatten layer4Flatten = new LayerFlatten( );
        float[] layer5X = layer4Flatten.Forward(layer4X);

        //System.out.println( layer1Conv );
        //System.out.println( layer2ReLU );
        //System.out.println( layer3PoolingMax );
        //System.out.println( layer4Flatten );
        //System.out.println(Arrays.toString( layer5X ));
        //System.out.println( layer5X.length );

        layer10=new Layer( LType.sigmod , 64 ,288 ); layer10.setName("Layer10"); // n neurons
        layer10.rnd();

        layer11=new Layer( LType.sigmod , 64 ,64 ); layer11.setName("Layer11"); // n neurons
        layer11.rnd();

        layer12=new Layer( LType.softmaxMultiClass , 10 ,64 ); layer12.setName("Layer12"); // n neurons
        layer12.rnd();

    }


    private forwardAndLearn(  )



    @Test
    @Override
    public void run() {
        prepare();




        // FORWARD
        int i=5;

        oneX[0] = trainX[i];
        layer1Conv.setX( oneX );
        layer2ReLU.setX( layer1Conv.Forward() );
        layer3PoolingMax.setX( layer2ReLU.Forward() );
        layer10.setX( layer4Flatten.Forward( layer3PoolingMax.Forward() ) );
        layer10.nForward();
        layer11.setX( layer10.getZ() );
        layer11.nForward();
        layer12.setX( layer11.getZ() );
        layer12.nForward();

        float[] Z = layer12.getZ();
        float[] S_Z = tools.vectorSubstSsubZ( trainY[ i ], Z );
            // System.out.println( Arrays.toString( trainY[ i ] ));
            // System.out.println( Arrays.toString( Z ));
            // System.out.println( Arrays.toString( S_Z ));

        layer12.nBackward( S_Z );
        Loss += Tools.crossEntropyMulticlassError( layer12.getZ() );
        layer11.nBackward( layer12.getEout() );
        layer10.nBackward( layer11.getEout() );
        layer1Conv.Backward(layer2ReLU.Backward(layer3PoolingMax.Backward(layer4Flatten.Backward(layer10.getEout()))));
        // System.out.println( Tools.AryToString( backward ));

        /*
        layer3.nBackward( S_Z );
        Loss += Tools.crossEntropyMulticlassError( layer3.getZ() );
        layer2.nBackward( layer3.getEout() );
        layer1.nBackward( layer2.getEout() );
        */


        /*
        for (int cycle=0;cycle<1;cycle++) {

            float Loss = 0.0f;
            int step=1;
            for (int epoch = 0; epoch < numOfEpoch; epoch++) {
                step++;
                for ( int index = 0; index < trainX.length; index++ ) {

                    // ONE CYCLE
                    int ind_ex =  (index*step) % trainX.length;


                    layer1.setX( trainX[ ind_ex ] );
                    layer1.nForward();
                    layer2.setX( layer1.getZ() );
                    layer2.nForward();
                    layer3.setX( layer2.getZ() );
                    layer3.nForward();

                    float[] S_Z = tools.vectorSubstSsubZ( trainY[ ind_ex ], layer3.getZ() );
                    layer3.nBackward( S_Z );
                    Loss += Tools.crossEntropyMulticlassError( layer3.getZ() );
                    layer2.nBackward( layer3.getEout() );
                    layer1.nBackward( layer2.getEout() );
                }
                CSBin_data[epoch]=Loss/trainX.length;

            }
            System.out.println( Arrays.toString( layer1.getNeuronWeight(0)));
            System.out.println( Arrays.toString( layer3.getX()));
            System.out.println( Arrays.toString( layer3.getZ()));

            // check accuracy
            int len = testX.length;
            int accuracy = 0;
            for (int i = 0; i < len; i++) {
                layer1.setX( testX[i] );
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
        */
    }
}
