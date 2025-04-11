package pl.heinzelman.tasks;

import pl.heinzelman.LayerDeep.*;
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

    private LayerConv layerConv = new LayerConv( 3 , 8, null, null  );
    private LayerFlatten layerFlatten = new LayerFlatten();
    private LayerPoolingMax layerPoolMAX = new LayerPoolingMax(1,1);
    private LayerSigmoidFullConn layer1FC = new LayerSigmoidFullConn( 26*26*8, 10 );
    private LayerSoftmaxMultiClass layer2SoftmaxMulticlass = new LayerSoftmaxMultiClass( 10 );

    float[][][] oneX = new float[1][28][28];
    float[][] out1x10 = new float[1][10];

    private Tools tools = new Tools();

    private float ce_loss=0.0f;
    private int accuracy=0;


    public void prepare() {
        int filterNum=8;
        int dataSize = 100;
        tools.prepareData( dataSize );

        testX = tools.getTestX();
        testY = tools.getTestY();
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();

        tools.prepareDataAsFlatArray( dataSize );
        trainXX = tools.getTrainAryX();
        testXX  = tools.getTestAryX();

        float[][][] oneX = new float[1][28][28];
        oneX[0] = trainXX[0];
        layerConv.setUpByX( oneX );

    }


    public float[][] forward_( float[][] X ){

        oneX[0] = X;
        layerConv.setX( oneX );
        float[][][] Zconv = layerConv.Forward();

        float[] Xf = layerFlatten.Forward(Zconv);
        float[] Z1 = layer1FC.nForward( Xf );
        float[] Z2 = layer2SoftmaxMulticlass.nForward( Z1 );

        // convert out to [1][10]
        out1x10[0]=Z2;
        return out1x10;
    }

    public float[] backward_( float[][] gradient ){
        float[] L2eOUT = layer2SoftmaxMulticlass.nBackward( gradient[0] );
        float[] eOUT = layer1FC.nBackward( L2eOUT );
        float[][][] eOUTF    = layerFlatten.Backward( eOUT );
                               layerConv.Backward( eOUTF );
        return null;
    }


// *********************

    @Override
    public void run() {

        train(60000);
        test(10000);

        train(60000);
        test(10000);

        train(60000);
        test(10000);

        train(5000);
        test(1000);

        train(5000);
        test(1000);

        train(5000);
        test(1000);

    }

    public void train( int training_size ){

        int label_counter = 0;
        int accuracy=0;
        float acc_sum=0.0f;
        float learn_rate=0.005f;

        float[][] out_l = new float[1][10];
        for (int i = 0; i < training_size; i++) {

            label_counter++;

            //FORWARD PROPAGATION
            int ind_ex = i;

            float[][] X = trainXX[ind_ex];
            float[] trueZ = trainY[ind_ex];
            int correct_label = tools.getIndexMaxFloat(trueZ);

            out_l = forward_(X);
            float[][] gradient = compute_gradient(out_l, correct_label);
            backward_( gradient );

            //if(  i % 100 == 99){
                // System.out.println( "I: " + i + ", ce_loss: " + ce_loss );
            //    ce_loss=0;
            //    acc_sum+=accuracy;
            //    accuracy=0;
            //}
        }
        // System.out.println("Average accuracy:- "+acc_sum/training_size+"%\n\n");
    }


    public float[][] compute_gradient( float[][] out_l, int correct_label){
        // compute cross-entropy loss
        // not used
        ce_loss += (float) -Math.log(out_l[0][correct_label]);
        // not used
        accuracy += correct_label == _Mat.v_argmax(out_l) ? 1 : 0;

        //BACKWARD PROPAGATION --- STOCHASTIC GRADIENT DESCENT
        //gradient of the cross entropy loss
        float[][] gradient = _Mat.v_zeros(10);
        gradient[0][correct_label] = -1 / out_l[0][correct_label];
        return gradient;
    }

    public void test( int test_size ){
        int filterNum = 8;
        int[][] errors = new int[10][10];
        int error = 0;

        int label_counter = 0;
        int accuracy=0;
        int sum=0;

        float[][] out_l;
        for (int i = 0; i < test_size; i++) {

            label_counter++;
            //FORWARD PROPAGATION

            int ind_ex = i;

            float[][] X = trainXX[ind_ex];
            float[] trueZ = trainY[ind_ex];
            int correct_label = tools.getIndexMaxFloat( trueZ );

            out_l = forward_(X);

            // compute cross-entropy loss
            int findClass = tools.getIndexMaxFloat( out_l[0] );
            if ( correct_label!=findClass ){
                errors[correct_label][findClass]++;
                error++;
            } else { accuracy++;  }
            sum ++;
        }
        System.out.println(" ** TEST ** "+ (100*accuracy)/sum + "%,  errors: "+ ( sum-accuracy ) + "\n" );
    }

}


