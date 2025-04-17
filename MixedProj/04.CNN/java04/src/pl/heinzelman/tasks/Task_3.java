package pl.heinzelman.tasks;

import pl.heinzelman.LayerDeep.*;
import pl.heinzelman.neu.LayerSoftmaxMultiClass;
import pl.heinzelman.tools.Tools2;

public class  Task_3 implements Task{

    private Tools2 tools = new Tools2();
    private float[][] testX;
    private float[][] testY;
    private float[][] trainX;
    private float[][] trainY;
    private int[][] errors = new int [10][10];


    private LayerConv conv = new LayerConv( 3 , 8, null, null  );
    private LayerPoolingMax poolMax = new LayerPoolingMax(2,2);
    private LayerFlatten flatten = new LayerFlatten();
    private LayerSoftmaxMultiClass softmax = new LayerSoftmaxMultiClass( 13*13*8, 10 );


    public void prepare() {
        int dataSize=100;
        tools.prepareData( dataSize );

        testX = tools.getTestX();
        testY = tools.getTestY();
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();

        float[][][] oneX = new float[1][28][28];
        oneX[0] = tools.convertToSquare28x28( trainX[0] );
        conv.setUpByX( oneX );
    }


    public float[] forward_( float[][] X ){
        float[][][] oneX = new float[1][][];
        oneX[0]=X;
        return softmax.nForward( flatten.Forward( poolMax.Forward( conv.Forward( oneX ))));
    }

    public float[][][] backward_( float[] gradient ){
        return conv.Backward(  poolMax.Backward( flatten.Backward(  softmax.nBackward( gradient ))));
    }


// *********************

    @Override
    public void run() {
        prepare();

        train( 6000 );
        train( 6000 );
        train( 6000 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );
        train( 128 );

        test( 10000 );

    }

    public void train( int test_size ){
        int accuracy=0;
        float loss = 0.0f;
        float ce_loss = 0.0f;
        int sum=0;

        for (int i = 0; i < test_size; i++) {
            //FORWARD PROPAGATION
            int ind_ex = i;

            float[][] X = tools.convertToSquare28x28( trainX[ind_ex] );
            int correct_label = tools.getIndexMaxFloat(trainY[ind_ex]);

            float[] Z = forward_(X);
            loss += softmax.delta_Loss( correct_label );
            //System.out.println( "correct_label: " + correct_label + ", Z : " + tools.getIndexMaxFloat(Z) + " : " + tools.AryToString( Z ) );
            if ( correct_label==tools.getIndexMaxFloat( Z )){ accuracy++; }

            float[] gradient = softmax.gradientCNN( Z, correct_label );
            backward_( gradient );
        }
        System.out.println( "Acc: " + ((100.0f*accuracy)/ test_size) + ", Loss: " + loss  );
        loss=0.0f;
    }




    public  void test ( int test_size  )   {

        int[][] errors = new int[10][10];
        int error = 0;

        int label_counter = 0;
        int accuracy=0;
        int sum=0;

        float[] out_l = new float[10];
        for (int i = 0; i < test_size; i++) {

            label_counter++;
            //FORWARD PROPAGATION

            // importImage
            int correct_label=tools.getIndexMaxFloat( testY[i] );
            float[][] pxl = tools.convertToSquare28x28( testX[i] );

            // perform convolution 28*28 --> 8x26x26
            out_l = forward_( pxl );

            // compute cross-entropy loss
            int findClass = tools.getIndexMaxFloat(out_l);//  ()int) Mat.v_argmax(out_l);
            if ( correct_label!=findClass ){
                errors[correct_label][findClass]++;
                error++;
            } else { accuracy++;  }
            //accuracy += correct_label == Mat.v_argmax(out_l) ? 1 : 0;
            sum ++;
        }
        System.out.println("\n***************************************\n** TEST ** errors "+ ( error ) + " .. " + ( 100 * accuracy / test_size ) + "%\n" );
        Tools2.printTable2( errors );
    }

}


