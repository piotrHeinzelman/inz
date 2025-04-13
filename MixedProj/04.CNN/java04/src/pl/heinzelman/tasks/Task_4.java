package pl.heinzelman.tasks;

import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.LayerDeep.LayerPoolingMax;
import pl.heinzelman.neu.LayerSigmoidFullConn;
import pl.heinzelman.neu.LayerSoftmaxMultiClass;
import pl.heinzelman.tools.Tools;
import pl.heinzelman.tools.Tools2;

public class Task_4 implements Task{

    private float[][] testX;
    private float[][] testY;
    private float[][] trainX;
    private float[][] trainY;

    private float[][][] testXX;
    private float[][][] trainXX;

    //private LayerConv layerConv = new LayerConv( 3 , 8, null, null  );
    //private LayerFlatten layerFlatten = new LayerFlatten();
    //private LayerPoolingMax layerPoolMAX = new LayerPoolingMax(1,1);
    // private LayerSigmoidFullConn layer1FC = new LayerSigmoidFullConn( 26*26*8, 10 );
    private LayerSigmoidFullConn layer1FC = new LayerSigmoidFullConn( 7, 5 );

    private Tools2 tools = new Tools2();


    public void prepare() {
        int dataSize=100;
        tools.prepareData( dataSize );

        testX = tools.getTestX();
        testY = tools.getTestY();
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();

        // System.out.println( Tools.AryToString(  trainX[0] ));
        //System.out.println( Tools.AryToString( Tools.convertToSquare28x28( trainX[0] )));



    }


    public float[][] forward_( float[][] X ){

        return null;
    }

    public float[][][] backward_( float[][] gradient ){

        return null;
    }


// *********************

    @Override
    public void run() {

        train();

    }

    public void train(){
        int i=0;
        float[][] Xi = Tools.convertToSquare28x28( trainX[i] );
        float[] X = new float[]{ 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.4f, 0.3f };

        System.out.println( "X:" + Tools2.AryToString( X ) );
        float[] Z = layer1FC.nForward( X );
        System.out.println( "Z:" + Tools2.AryToString( Z ) );
        float[] dZ = layer1FC.getdZ(3);
        System.out.println( "dZ:" + Tools2.AryToString( dZ ) );  // 3 - target class

        for (int n=0;n<2000;n++){
            layer1FC.nBackward(dZ);
        }
        System.out.println( Tools2.AryToString( layer1FC.nForward( X )));

        for (int n=0;n<2000;n++){
            layer1FC.nBackward(dZ);
        }
        System.out.println( Tools2.AryToString( layer1FC.nForward( X )));

        for (int n=0;n<2000;n++){
            layer1FC.nBackward(dZ);
        }
        System.out.println( Tools2.AryToString( layer1FC.nForward( X )));

        for (int n=0;n<2000;n++){
            layer1FC.nBackward(dZ);
        }
        System.out.println( Tools2.AryToString( layer1FC.nForward( X )));


    }

    public void test(){

    }



}


