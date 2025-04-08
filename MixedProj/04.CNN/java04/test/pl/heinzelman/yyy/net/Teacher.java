package pl.heinzelman.yyy.net;

import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.LayerDeep.LayerPoolingMax;
import pl.heinzelman.LayerDeep.LayerReLU;
import pl.heinzelman.neu.LayerSigmoidFullConn;
import pl.heinzelman.neu.LayerSoftmaxMultiClass;
import pl.heinzelman.tools.Tools;

import java.util.Arrays;

public class Teacher   {

    private final static FileReadr fileReadr = new FileReadr();

    //initialize layers
    private static final Convolution conv=new Convolution();
    private static final MaxPool pool=new MaxPool();
    private static SoftMax softmax;
    private static int filterNum;
    private static float[][][] filters;

    private static float[][] testX;
    private static float[][] testY;
    private static float[][] trainX;
    private static float[][] trainY;


    private static float[][][] testXX;
    private static float[][][] trainXX;
    private Tools tools = new Tools();

    private static boolean newImplementation = true;


    private static LayerSigmoidFullConn   mySigm = new LayerSigmoidFullConn( 13*13*8 , 10 );
    private static LayerSoftmaxMultiClass mySoftmax = new LayerSoftmaxMultiClass(10 );
    private static LayerConv myConv = new LayerConv( 3, 8, null, null );
    private static LayerReLU myReLU = new LayerReLU();
    private static LayerPoolingMax myMax = new LayerPoolingMax(2, 2);
    private static LayerFlatten myFlatten = new LayerFlatten();



    public static float[][][] init_filters(int size) {
        float[][][] result = new float[size][3][3];
        for (int k = 0; k < size; k++) {
            result[k] = Mat.m_random(3, 3);
        }
        return result;
    }


    public static void prepare( int filterNum_ ){
        filterNum = filterNum_;
        softmax=new SoftMax(13*13*filterNum,10, filterNum );
        // LayerSigmoidFullConn   mySigm = new LayerSigmoidFullConn( 13*13*8 , 10 );
        // LayerSoftmaxMultiClass mySoftmax = new LayerSoftmaxMultiClass(10 );
        filters = init_filters( filterNum_ );

    }

    public static void train(int training_size  )   {

        Tools tools = new Tools();
        int dataSize = 100;
        tools.prepareDataAsFlatArray( dataSize );

        testXX = tools.getTestAryX();
        trainXX = tools.getTrainAryX();

        tools.prepareData( dataSize );

        testX = tools.getTestX();
        testY = tools.getTestY();
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();


        float[][][] oneX = new float[1][][];
        oneX[0]=trainXX[0]; // one channel;
        myConv.setUpByX( oneX );

        int label_counter = 0;
        float ce_loss=0;
        int accuracy=0;
        float acc_sum=0.0f;
        float learn_rate=0.005f;



        float[][] out_l = new float[1][10];
        for (int i = 0; i < training_size; i++) {

            label_counter++;
			
            //FORWARD PROPAGATION

            // importImage
            int[][] X = fileReadr.getNextTrainX();
            int correct_label=X[0][0];
            float[][] pxl =  TT.squareIntToSquareFLoat( X );

            correct_label = tools.getIndexMaxFloat( trainY[i] );
            pxl = trainXX[i];

            out_l = forward_ ( pxl );

            // compute cross-entropy loss
            ce_loss += (float) -Math.log(out_l[0][correct_label]);
            accuracy += correct_label == Mat.v_argmax(out_l) ? 1 : 0;

            //BACKWARD PROPAGATION --- STOCHASTIC GRADIENT DESCENT
            //gradient of the cross entropy loss

            float[][] gradient=Mat.v_zeros(10);
            gradient[0][correct_label]=-1/out_l[0][correct_label];

            backward_( gradient );

            //float[][][] sm_gradient=softmax.backprop(gradient,learn_rate);
            //float[][][] mp_gradient=pool.backprop(sm_gradient);
            //conv.backprop(mp_gradient, learn_rate);

            if(  i % 100 == 99){
                ce_loss=0;
                acc_sum+=accuracy;
                accuracy=0;
            }
        }
        System.out.println("filters: "+ filterNum +", average accuracy:- "+acc_sum/training_size+"%\n\n");
    }


    public static void backward_( float [][] gradient ){
        // System.out.println( "gradient: " + Tools.AryToString( gradient ));
        // System.out.println( "Arrays.toString gradient[0]: " + Arrays.toString( gradient[0] ));
        if ( newImplementation ){
            float[][][] oneX = new float[1][][];
            // !!! ONLY ONE CHANNEL !!!
            float[] eOut = mySoftmax.nBackward( gradient[0] );
            mySigm.nBackward( eOut );
            float[] eOut2 = mySigm.getEout();
            float[][][] eOutTensor = myFlatten.Backward( eOut2 );
            float[][][] eOutTensor2 = myMax.Backward( eOutTensor );
            float[][][] eOutTensor3 = myReLU.Backward( eOutTensor2 );
            float[][][] eOutTensor4 = myConv.Backward( eOutTensor3 );
            return;
        }

        float learn_rate=0.005f;
        float[][][] sm_gradient=softmax.backprop(gradient,learn_rate);
        float[][][] mp_gradient=pool.backprop(sm_gradient);
        conv.backprop(mp_gradient, learn_rate);
    }

    public static float[][] forward_( float[][] pxl ){
        if ( newImplementation ){
            float[][][] oneX = new float[1][][];
            oneX[0]=pxl; // one channel;
            myConv.setX( oneX );
            float[][][] outTensor = myConv.Forward();

            myReLU.setX( outTensor );
            float[][][] outTensor2 = myReLU.Forward();

            myMax.setX( outTensor2 );
            float[][][] outTensor3 = myMax.Forward();

            float[] flatX = myFlatten.Forward( outTensor3 );

            float[] CxX = mySigm.nForward( flatX );
            float[] out_l = mySoftmax.nForward( CxX );

            float[][] outF = new float[1][];
            outF[0]=out_l;

            return outF;
        }


        // perform convolution 28*28 --> 8x26x26
        float[][][] out = conv.forward( pxl, filters, filterNum );

        // perform maximum pooling  8x26x26 --> 8x13x13
        out = pool.forward( out );

        // perform softmax operation  8*13*13 --> 10
        float[][] out_l = softmax.forward( out );
        // System.out.println( "OUT_L: " + Arrays.toString( out_l[0] ));
        // System.out.println( "OUT_L: " + Tools.AryToString( out_l ));
        // System.out.println( "outF[0]: " + Arrays.toString(  out_l[0] ));
        return out_l;
    }

    public static void test (int test_size  )   {

        int[][] errors = new int[10][10];
        int error = 0;

        int label_counter = 0;
        int accuracy=0;
        int sum=0;

        float[][] out_l = new float[1][10];
        for (int i = 0; i < test_size; i++) {

            label_counter++;
            //FORWARD PROPAGATION

            // importImage
            int[][] X = fileReadr.getNextTrainX();
            int correct_label = X[0][0];
            float[][] pxl = TT.squareIntToSquareFLoat(X);

            // perform convolution 28*28 --> 8x26x26
            float[][][] out = conv.forward(pxl, filters, filterNum);

            // perform maximum pooling  8x26x26 --> 8x13x13
            out = pool.forward(out);

            // perform softmax operation  8*13*13 --> 10
            out_l = softmax.forward(out);

            // compute cross-entropy loss
            int findClass = (int) Mat.v_argmax(out_l);
            if ( correct_label!=findClass ){
                errors[correct_label][findClass]++;
                error++;
            } else { accuracy++;  }
            //accuracy += correct_label == Mat.v_argmax(out_l) ? 1 : 0;
            sum ++;
        }
        System.out.println("\n***************************************\n** TEST ** errors "+ ( sum-accuracy ) + "\n" );
        TT.printTable2( errors );
    }

}
