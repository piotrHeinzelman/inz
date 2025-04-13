package pl.heinzelman.tasks;

import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.LayerDeep.LayerPoolingMax;
import pl.heinzelman.LayerDeep.LayerReLU;
import pl.heinzelman.neu.LayerSigmoidFullConn;
import pl.heinzelman.neu.LayerSoftmaxMultiClass;
import pl.heinzelman.tools.Tools;

public class Task_CNN implements Task{

    private float[][] testY;
    private float[][] trainY;

    private float[][][] testXX;
    private float[][][] trainXX;

    private LayerConv layer1Conv = new LayerConv( 5 , 20 , null, null );
    private LayerReLU layer2ReLU = new LayerReLU();
    private LayerPoolingMax layer3PoolingMax = new LayerPoolingMax(2, 2);
    private LayerFlatten layer4Flatten = new LayerFlatten();

    private LayerSigmoidFullConn layer5FC = new LayerSigmoidFullConn( 20*12*12, 10 ); //13*13*8 //1152 //26*26*8
    private LayerSoftmaxMultiClass layer6SoftmaxMulticlass = new LayerSoftmaxMultiClass( 10 );

    private Tools tools = new Tools();
    float[][][] oneX = new float[1][][];
    float[][] out1x10 = new float[1][10];

    int numOfEpoch=5;
    float[] CSBin_data=new float[numOfEpoch];

    private float ce_loss=0.0f;
    private int accuracy=0;

    public void prepare() {

        int dataSize = 100;
        tools.prepareData( dataSize );
        testY = tools.getTestY();
        trainY = tools.getTrainY();

        tools.prepareDataAsFlatArray( dataSize );
        testXX = tools.getTestAryX();
        trainXX = tools.getTrainAryX();

        // ****************************

        oneX[0] = trainXX[0]; // extract One X
        // System.out.println( Tools.AryToString( oneX ) );
        layer1Conv.setUpByX( oneX );
    }


    private float[][] _forward( float[][][] oneX ){

        layer1Conv.setX(oneX);
        float[][][] Z1 = layer1Conv.Forward();
        //System.out.println( Z1.length + " : " + Z1[0].length + " : " + Z1[0][0].length );
                         layer2ReLU.setX( Z1 );
        float[][][] Z2 = layer2ReLU.Forward();
                         layer3PoolingMax.setX( Z2 );
        float[][][] Z3 = layer3PoolingMax.Forward();
        // System.out.println( Z3.length + " : " + Z3[0].length + " : " + Z3[0][0].length );
        System.out.println( Tools.AryToString( Z1 ));
        //float[][][] Z3 = Z1;

        float[] CX = layer4Flatten.Forward( Z3 );
        float[] CxX = layer5FC.nForward( CX );
        float[] Z = layer6SoftmaxMulticlass.nForward( CxX );

        // System.out.println( Tools.AryToString( Z1 ));
        // System.out.println( Tools.AryToString( Z ));
        // System.out.println( Tools.AryToString( Z3[0] ));
        // System.out.println( Tools.AryToString( oneX ));
        // if ( true ) throw new RuntimeException( "?" );

        // convert out to [1][10]
        out1x10[0]=Z;
        return out1x10;
    }

    private float[][][] _backward( float[][] gradient ){
        float[] Z_S = layer6SoftmaxMulticlass.nBackward( gradient[0] );
        float[] Z_S1 = layer5FC.nBackward(Z_S);
        float[][][] Z_S2 = layer4Flatten.Backward(Z_S1);
        float[][][] Z_S3 = layer3PoolingMax.Backward(Z_S2);
        float[][][] Z_S4 = layer2ReLU.Backward(Z_S3);
        //float[][][] Z_S4 = Z_S2;
        return             layer1Conv.Backward( Z_S4 ) ;
    }



    public void run() {
        for (int cycle=0;cycle<20;cycle++) {

            float Loss = 0.0f;
            float Loss2 = 0.0f;
            int step=1;
            for (int epoch = 0; epoch < numOfEpoch; epoch++) {
                step++;
                for ( int index = 0; index < trainY.length; index++ ) {

                    // ONE CYCLE
                    //int ind_ex = (index * step) % trainXX.length;
                    int ind_ex = index;
                    oneX[0] = trainXX[ind_ex];
                    int correct_label = tools.getIndexMaxFloat( trainY[ind_ex] );

                    // System.out.println( ind_ex + " : " + Tools.AryToString( trainXX[ind_ex] ) );

                    float[][] Z = _forward( oneX );
                    float[][] gradient = layer6SoftmaxMulticlass.compute_gradient( Z, correct_label );
                    //       gradient[0] = Tools.vectorSubstZsubS( Z[0], trainY[ind_ex] );
                           gradient[0] = Tools.gradientSoftMax( Z[0], trainY[ind_ex] );
                   Loss  += layer6SoftmaxMulticlass.delta_Loss( correct_label );
                   Loss2 += Tools.crossEntropyMulticlassError( Z[0] );

                    _backward( gradient );
                }
                //System.out.println( "Loss2:" + Loss2 ); Loss2=0f;
                //System.out.println( "Loss: " + Loss );  Loss=0f;
                CSBin_data[epoch]=Loss/trainXX.length;
            }


            float[][][] oneX = new float[1][][];
            // check accuracy
            int len = testXX.length;
            int accuracy = 0;
            for (int i = 0; i < len; i++) {
                oneX[0]=testXX[i];
// ----------->
                float[][] Z = _forward(oneX);

                int netClassId = tools.getIndexMaxFloat( Z[0] );
                int fileClassId = tools.getIndexMaxFloat( testY[i] );
                if (fileClassId == netClassId) {
                    accuracy++;
                }
            }
            System.out.println(100.0f * accuracy / len + "%");
        }
    }
}
