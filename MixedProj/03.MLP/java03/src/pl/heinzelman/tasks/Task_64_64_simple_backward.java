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

        // show data
        if ( true ) {
                System.out.println( tools.toStr(  testY[0] ) );
                tools.saveVectorAsImg( testX[0] ,  "_test_" );
                System.out.println( tools.getIndexMaxFloat( testY[0] ) );
        return; }


        Layer layer1=new Layer( LType.sigmod , 64 ,784 ); layer1.setName("Layer1"); // n neurons
        layer1.rnd();

        Layer layer2=new Layer( LType.sigmod , 64 ,64 ); layer2.setName("Layer2"); // n neurons
        layer2.rnd();

        Layer layer3=new Layer( LType.sigmod , 10 ,64 ); layer3.setName("Layer3"); // n neurons
        layer3.rnd();

        int goals0;
        for ( int index=0; index<1/*trainX.length*/; index++ ) {
            // ONE CYCLE


            float[] firstX = trainX[index];
            layer1.setX( firstX );
            layer1.nForward();

            float[] XforL2 = layer1.getZ();

            layer2.setX(XforL2);
            layer2.nForward();
            float[] XforL3 = layer2.getZ();

            layer3.setX(XforL3);
            layer3.nForward();

            System.out.println( tools.toStr(  XforL2 ) );
            //System.out.println( tools.getIndexMaxFloat( trainY[index] ) );

            //System.out.println( trainY[index][9] );

            layer3.nBackward( trainY[index], LossType.squareError );
            float[] eout3 = layer3.getEout();

            layer2.nBackward(eout3);
            float[] eout2 = layer2.getEout();

            layer1.nBackward(eout2);

        }





        if ( true ) { /*System.out.println( layer1.toString() ); */ return; }

    }
}
