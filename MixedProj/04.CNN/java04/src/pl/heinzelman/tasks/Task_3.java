package pl.heinzelman.tasks;

import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.neu.LayerSigmoidFullConn;
import pl.heinzelman.neu.LayerSoftmaxMultiClass;
import pl.heinzelman.tools.Tools;

public class  Task_3 implements Task{

    private float[][] testX;
    private float[][] testY;
    private float[][] trainX;
    private float[][] trainY;


    private float[][][] testXX;
    private float[][][] trainXX;


    private LayerSigmoidFullConn layer1FC;
    private LayerSigmoidFullConn layer2FC;
    private LayerSoftmaxMultiClass layer3SoftmaxMulticlass;

    private LayerFlatten layerFlatten = new LayerFlatten();
    private LayerConv layerConv = new LayerConv( 3 , 8, null, null  );
    private Tools tools = new Tools();

    int numOfEpoch=50;
    int cyclesOfEpoch=20;
    float[] CSBin_data=new float[numOfEpoch*cyclesOfEpoch];


    @Override
    public void prepare() {

        int dataSize = 10;
        tools.prepareData( dataSize );

        testX = tools.getTestX();
        testY = tools.getTestY();
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();

        tools.prepareDataAsFlatArray( dataSize );
        trainXX = tools.getTrainAryX();
        testXX  = tools.getTestAryX();


        //System.out.println( testX[0].length );


        float[][][] oneX = new float[1][28][28];
        oneX[0] = trainXX[0];
        layerConv.setUpByX( oneX );

        layer1FC = new LayerSigmoidFullConn( 26*26*8, 64 ); layer1FC.setName("Layer1"); // n neurons
        layer2FC = new LayerSigmoidFullConn( 64, 10 ); layer2FC.setName("Layer2"); // n neurons
        layer3SoftmaxMulticlass = new LayerSoftmaxMultiClass( 10 ); layer3SoftmaxMulticlass.setName("Layer3"); // n neurons

        // ****************************


    }

    public float[] forward_( float[][] X ){

        float[][][] oneX = new float[1][28][28];
        oneX[0] = X;
        layerConv.setX( oneX );
        float[][][] Zconv = layerConv.Forward();

        // System.out.println( Zconv.length + " : " + Zconv[0].length + " ! " + Zconv[0][0].length );

        float[] Xf = layerFlatten.Forward(Zconv);
        float[] Z1 = layer1FC.nForward( Xf );
        float[] Z2 = layer2FC.nForward( Z1 );
        float[] Z3 = layer3SoftmaxMulticlass.nForward( Z2 );
        return Z3;

    }

    public float[] backward_( float[] eIN ){
        float[] L3eOUT = layer3SoftmaxMulticlass.nBackward( eIN );
        float[] L2eOUT = layer2FC.nBackward( L3eOUT );
        float[] eOUT = layer1FC.nBackward( L2eOUT );
        float[][][] eOUTF    = layerFlatten.Backward( eOUT );
                               layerConv.Backward( eOUTF );

        //System.out.println( eOUTF.length + " : "+ eOUTF[0].length + " : "+ eOUTF[0][0].length );

        return null;
    }


    @Override
    public void run() {
        prepare();

        int epochNum=0;
        for (int cycle=0;cycle<cyclesOfEpoch;cycle++) {
            float Loss=0.0f;
            int step=1;

            for (int epoch = 0; epoch < numOfEpoch; epoch++) {
                step++; epochNum++; Loss=0.0f;
                for ( int index = 0; index < trainX.length; index++ ) {

                    // ONE CYCLE
                    int ind_ex = /*index; //*/ (index * step) % trainX.length;

                    float[][] X = trainXX[ind_ex];
                    float[] trueZ = trainY[ind_ex];

                    float[] outZ = forward_( X );

                    float[] Z_S = tools.vectorSubstZsubS( outZ, trueZ );

                                   backward_(Z_S);
                    //Loss += Tools.meanSquareError( outZ, trueZ );
                    Loss += Tools.crossEntropyMulticlassError( outZ );

                }
                CSBin_data[epoch]=Loss/trainX.length;
            }
            System.out.println("Loss: " + Loss );

            int acc = 0;
            int sam = 0;
            for (int i=0;i<testX.length;i++){
                float[] Z = forward_(testXX[i]);
                float[] trueZ = testY[i];
                if ( tools.getIndexMaxFloat( Z ) == tools.getIndexMaxFloat( trueZ ) ) { acc++; }
                sam++;
            }
            System.out.println("test accuracy: " + 100.0f * acc / sam + "%     ("+epochNum+")");
        }
    }
}


