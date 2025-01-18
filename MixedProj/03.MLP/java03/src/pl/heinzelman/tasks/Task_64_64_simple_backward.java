package pl.heinzelman.tasks;

import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;
import pl.heinzelman.tools.Tools;

import java.awt.image.BufferedImage;

public class Task_64_64_simple_backward implements Task{

    private float[][] testX;
    private float[][] testY;
    private float[][] trainX;
    private float[][] trainY;

    private Layer layer1;
    private Layer layer2;
    private Layer layer3;

    private Tools tools = new Tools();

    int numOfEpoch=50;
    float[] CSBin_data=new float[numOfEpoch];

    @Override
    public void prepare() {
        tools.prepareData( 1 );

        testX = tools.getTestX();
        testY = tools.getTestY();
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();

        layer1=new Layer( LType.sigmod , 64 ,784 ); layer1.setName("Layer1"); // n neurons
        layer1.rnd();

        layer2=new Layer( LType.sigmod , 64 ,64 ); layer2.setName("Layer2"); // n neurons
        layer2.rnd();

        layer3=new Layer( LType.softmaxMultiClass , 10 ,64 ); layer3.setName("Layer3"); // n neurons
        layer3.rnd();


        if ( false ) {
            int i = 1;
            System.out.println(tools.toStr( testY[i] ));
            tools.saveVectorAsImg( testX[i], "_test_");
            System.out.println( tools.getIndexMaxFloat(testY[i] ));
        }
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
                    int ind_ex = /*index; //*/ (index*step) % trainX.length;

                    float[] firstX = trainX[ ind_ex ];

                    layer1.setX( firstX );
                    layer1.nForward();
                    layer2.setX( layer2.getZ() );
                    layer2.nForward();
                    layer3.setX( layer2.getZ() );
                    layer3.nForward();

                    float[] S_Z = tools.vectorSubstSsubZ( trainY[ ind_ex ], layer3.getZ());

                    layer3.nBackward( S_Z );
                    Loss += Tools.crossEntropyMulticlassError( layer3.getZ() );
                }
                CSBin_data[epoch]=Loss/trainX.length;
            }


            // check accuracy
            int len = testX.length;
            int accuracy = 0;
            for (int i = 0; i < len; i++) {
                layer1.setX( testX[i] );
                layer1.nForward();
                layer2.setX( layer2.getZ() );
                layer2.nForward();
                layer3.setX( layer2.getZ() );
                layer3.nForward();



                int netClassId = tools.getIndexMaxFloat( layer3.getZ() );
                int fileClassId = tools.getIndexMaxFloat( testY[i] );
                //System.out.println( netClassId + " : " + fileClassId );
                if (fileClassId == netClassId) {
                    accuracy++;
                }


            }
            System.out.println(100.0f * accuracy / len + "%");

            BufferedImage image = Tools.arrayOfFloatToImage( CSBin_data, 10 );
            Tools.saveImg( image , " CrossEntropy_Multiclass "+cycle);
        }


        if ( true ) { /*System.out.println( layer1.toString() ); */ return; }

    }
}
