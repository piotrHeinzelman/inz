package pl.heinzelman.tasks;

import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;
import pl.heinzelman.neu.LossType;
import pl.heinzelman.tools.Tools;

import java.util.Arrays;

public class Task_64_64_simple_backward implements Task{


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

        /*

        Layer layerx=new Layer( LType.sigmod , 3 ,5 ); layerx.setName("Layer1"); // n neurons
        layerx.rnd();
        float[] myX=new float[]{ 0.2f, 0.3f, 0.4f, 0.5f, 0.6f };
        float[] mySOczekiwany =new float[]{ 0.0f, 1.0f, 0.0f };
        layerx.setX( myX );
        layerx.nForward();
        float[] myz = layerx.getZ();

        System.out.println( layerx );
        for (int i=0;i<200;i++) {
            layerx.nBackward( tools.vectorSubstSsubZ(  mySOczekiwany, layerx.getZ() ) );
        }
        System.out.println( layerx );




        if ( true ) { return; }

        // show data
        if ( true ) {
                System.out.println( tools.toStr(  testY[0] ) );
                tools.saveVectorAsImg( testX[0] ,  "_test_" );
                System.out.println( tools.getIndexMaxFloat( testY[0] ) );
        return; }
         */

        Layer layer1=new Layer( LType.sigmod , 64 ,784 ); layer1.setName("Layer1"); // n neurons
        layer1.rnd();

        Layer layer2=new Layer( LType.sigmod , 64 ,64 ); layer2.setName("Layer2"); // n neurons
        layer2.rnd();

        Layer layer3=new Layer( LType.sigmod , 10 ,64 ); layer3.setName("Layer3"); // n neurons
        layer3.rnd();

        int goals0;
        for ( int index=0; index<trainX.length; index++ ) {
            // ONE CYCLE


            float[] firstX = trainX[index];

            layer1.setX( firstX );
            layer1.nForward();
//System.out.println( tools.toStr( layer1.getY() ));
//System.out.println( tools.toStr( layer1.getZ() ));
//System.out.println( layer1 );
            // >>
            layer2.setX( layer1.getZ() );
            layer2.nForward();
//System.out.println( tools.toStr( layer2.getZ() ));
            // >>
            layer3.setX( layer2.getZ() );
            layer3.nForward();
//System.out.println( tools.toStr( layer3.getZ() ));
            //System.out.println( layer3 );
            //System.out.println( tools.toStr( trainY[index] ));


//System.out.println( tools.toStr( layer3.getZ() ));
//System.out.println( tools.toStr( trainY[index] ));
            float[] S_Z = tools.vectorSubstSsubZ(trainY[index], layer3.getZ());
//System.out.println( tools.toStr( S_Z ));

//System.out.println( layer3 );

            layer3.nBackward( S_Z, LossType.squareError );

//System.out.println( layer3 );

            float[] eout3 = layer3.getEout();
//System.out.println( tools.toStr( eout3 ) );

            layer2.nBackward( eout3 );
            float[] eout2 = layer2.getEout();

            layer1.nBackward( eout2 );

//System.out.println( layer1 );
           // layer1.saveAllWeightAsImg("_layer1_" +index );



        }





        if ( true ) { /*System.out.println( layer1.toString() ); */ return; }

    }
}
