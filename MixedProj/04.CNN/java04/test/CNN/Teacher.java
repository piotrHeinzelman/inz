package CNN;

import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.LayerDeep.LayerPoolingMax;
import pl.heinzelman.neu.LayerSoftmaxMultiClass;
import pl.heinzelman.neu.LayerSoftmaxMultiClassONLYFORWARD;
import pl.heinzelman.tools.Tools2;

public class Teacher   {

    private Tools2 tools = new Tools2();
    private float[][] trainX;
    private float[][] trainY;
    private float[][] testX;
    private float[][] testY;


    //initialize layers
    private final LayerConv myConv = new LayerConv( 3, 8, null, null );
    //private final LayerSoftmaxMultiClassONLYFORWARD myLayerSoftmax = new LayerSoftmaxMultiClassONLYFORWARD( 10 );
    private final LayerSoftmaxMultiClass myLayerSoftmax = new LayerSoftmaxMultiClass( 13*13*8, 10 );
    private final LayerFlatten myFlatten = new LayerFlatten();
    private final LayerPoolingMax myPoolMax = new LayerPoolingMax(2,2);
    private  final Convolution conv=new Convolution();
    private  final MaxPool pool=new MaxPool();
    private  SoftMax softmax;
    private  int filterNum;
    private  float[][][] filters;


    public  float[][][] init_filters( int size ) {
        float[][][] result = new float[size][3][3];
        for (int k = 0; k < size; k++) {
            result[k] = Mat.m_random(3, 3);
        }
        return result;
    }


    public void prepare( int filterNum_ ){
        tools.prepareData(100);
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();
        testX = tools.getTestX();
        testY = tools.getTestY();

        filterNum = filterNum_;
        softmax=new SoftMax( 13*13*filterNum, 10, filterNum );
        filters = init_filters( filterNum_ );

        float[][][] oneX = new float[1][][];
        oneX[0] = tools.convertToSquare28x28( trainX[0] );
        myConv.setUpByX( oneX );

    }


    public float[][] forward( float[][] pxl ){
        float[][][] out ;

        // myForward !
        float[][][] oneX = new float[1][][];
        oneX[0]=pxl;
        myConv.setX( oneX );
        out = myConv.Forward();

              myPoolMax.setX(out);
        out = myPoolMax.Forward();


        float[][] out_l = new float[1][];
        float[] flat = myFlatten.Forward( out );
        out_l[0] = myLayerSoftmax.nForward( flat );
        return out_l;
    }


    public void backward( float[] gradient, float learn_rate ){
        float[] floats = myLayerSoftmax.nBackward(gradient);
        float[][][] sm_gradient = myFlatten.Backward(floats);
        myConv.Backward( myPoolMax.Backward( sm_gradient ) );
    }


    public void train(int training_size  )   {
        int label_counter = 0;
        float ce_loss=0;
        int accuracy=0;
        float acc_sum=0.0f;
        float learn_rate=0.01f;

        float[][] out_l = new float[1][10];
        for (int i = 0; i < training_size; i++) {

            label_counter++;
			
            //FORWARD PROPAGATION

            // importImage
            int correct_label=tools.getIndexMaxFloat( trainY[i] );
            float[][] pxl = tools.convertToSquare28x28( trainX[i] );

            out_l = forward( pxl );

            // compute cross-entropy loss
            ce_loss += tools.getCeLoss_CNN( out_l, correct_label );
            accuracy += correct_label == tools.getIndexMaxFloat(out_l[0]) ? 1:0;
            float[] gradient = myLayerSoftmax.gradientCNN( out_l, correct_label );
            backward( gradient, learn_rate );
        }
        System.out.println( ce_loss );
        ce_loss=0.0f;
    }



    public  void test (int test_size  )   {

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
            int correct_label=tools.getIndexMaxFloat( testY[i] );
            float[][] pxl = tools.convertToSquare28x28( testX[i] );

            // perform convolution 28*28 --> 8x26x26
            out_l = forward( pxl );

            // compute cross-entropy loss
            int findClass = (int) Mat.v_argmax(out_l);
            if ( correct_label!=findClass ){
                errors[correct_label][findClass]++;
                error++;
            } else { accuracy++;  }
            //accuracy += correct_label == Mat.v_argmax(out_l) ? 1 : 0;
            sum ++;
        }
        System.out.println("\n***************************************\n** TEST ** errors "+ ( sum-accuracy ) + " .. " + ( 100 * accuracy / sum ) + "%\n" );
        Tools.printTable2( errors );
    }



}
