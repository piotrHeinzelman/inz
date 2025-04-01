package pl.heinzelman.tasks;

import org.testng.annotations.Test;
import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;
import pl.heinzelman.tools.Tools;

import java.util.Arrays;

public class Task_CNN implements Task{

    private float[][][] testX;
    private float[][] testY;
    private float[][][] trainX;
    private float[][] trainY;

    private Layer layer1;
    private Layer layer2;
    private Layer layer3;

    private Tools tools = new Tools();

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

        System.out.println( Tools.AryToString( trainX[0] ));

        LayerConv layerConv1 = new LayerConv( 5 , 1 , null, null ); //int filterSize, Integer filterForChannel, Integer padding, Integer stride
        layerConv1.setX( trainX );
        layerConv1.initFilters();



        if (true) {return;}

        layer1=new Layer( LType.sigmod , 64 ,784 ); layer1.setName("Layer1"); // n neurons
        layer1.rnd();

        layer2=new Layer( LType.sigmod , 64 ,64 ); layer2.setName("Layer2"); // n neurons
        layer2.rnd();

        layer3=new Layer( LType.softmaxMultiClass , 10 ,64 ); layer3.setName("Layer3"); // n neurons
        layer3.rnd();

    }

    @Override
    public void run() {
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
