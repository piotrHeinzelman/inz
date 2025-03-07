package pl.heinzelman.tasks;

import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;
import pl.heinzelman.tools.Tools;

import java.awt.image.BufferedImage;

public class Task_64_64_simple_backward3 implements Task{


    float[][] testX = null;
    float[][] testY = null;
    float[][] trainX = null;
    float[][] trainY = null;

    @Override
    public void prepare() {
        // NOP
    }

    @Override
    public void run() {


        Tools tools = new Tools();
        tools.prepareData( 1 );

        testX = tools.getTestX();
        testY = tools.getTestY();
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();



        Layer layer1=new Layer( LType.softmaxMultiClass , 10 ,784 ); layer1.setName("Layer1"); // n neurons
        layer1.rnd();

        if ( false ) {
            int i = 1;
            System.out.println(tools.toStr(testY[i]));
            tools.saveVectorAsImg(testX[i], "_test_");
            System.out.println(tools.getIndexMaxFloat(testY[i]));
        }

        int numOfEpoch=500;
        float[] CSBin_data=new float[numOfEpoch];
        int goals0;

        for (int cycle=0;cycle<1;cycle++) {
            int step=1;

            float Loss = 0.0f;
            for (int epoch = 0; epoch < numOfEpoch; epoch++) {
                for ( int index = 0; index < trainX.length; index++ ) {

                    // ONE CYCLE
                       int ind_ex=index; //(index*step) % trainX.length;

                    float[] firstX = trainX[ ind_ex ];
                    //System.out.println( (index*step) % trainX.length );

                    layer1.setX( firstX );
                    layer1.nForward();

                    float[] S_Z = tools.vectorSubstSsubZ( trainY[ ind_ex ], layer1.getZ());
                    //System.out.println(  Arrays.toString( trainY[ ind_ex ] ) + " : " + Arrays.toString( layer1.getZ() ));

                    layer1.nBackward( S_Z );
                    Loss += Tools.crossEntropyMulticlassError( layer1.getZ() );
                }
                CSBin_data[epoch]=Loss/trainX.length;
                step++;


            }


            // check accuracy
            int len = testX.length;
            int accuracy = 0;
            for (int i = 0; i < len; i++) {
                layer1.setX( testX[i] );
                layer1.nForward();


                int netClassId = tools.getIndexMaxFloat( layer1.getZ() );
                int fileClassId = tools.getIndexMaxFloat( testY[i] );
                //System.out.println( netClassId + " : " + fileClassId );
                if (fileClassId == netClassId) {
                    accuracy++;
                }


            }
            System.out.println(100.0f * accuracy / len + "%");

        }
        BufferedImage image = Tools.arrayOfFloatToImage( CSBin_data, 10 );
        Tools.saveImg( image , " CrossEntropy_Multiclass ");

        if ( true ) { /*System.out.println( layer1.toString() ); */ return; }

    }
}
