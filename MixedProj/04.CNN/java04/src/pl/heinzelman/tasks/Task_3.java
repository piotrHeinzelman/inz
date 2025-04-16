package pl.heinzelman.tasks;

import pl.heinzelman.LayerDeep.*;
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
    private LayerSoftmaxMultiClass layer1SoftmaxMultiClass = new LayerSoftmaxMultiClass( 26*26*8, 10 );

    float[][][] oneX = new float[1][28][28];
    float[][] out1x10 = new float[1][10];

    private Tools tools = new Tools();

    private float ce_loss=0.0f;
    private int accuracy=0;


    public void prepare() {
        int filterNum=8;
        int dataSize =2;
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
        float[] Z1 = layer1SoftmaxMultiClass.nForward( Xf );

        // convert out to [1][10]
        out1x10[0]=Z1;
        return out1x10;
    }

    public float[][][] backward_( float[] gradient ){
        float[] eOUT = layer1SoftmaxMultiClass.nBackward( gradient );
        float[][][] eOUTF    = layerFlatten.Backward( eOUT );
        return layerConv.Backward( eOUTF );
    }


// *********************

    @Override
    public void run() {

        for (int j=0;j<25;j++) {
            for (int i = 0; i < 10; i++) train();
            test();
        }

    }

    public void train(){

        int label_counter = 0;
        int accuracy=0;
        float acc_sum=0.0f;
        float learn_rate=0.01f;
        float loss = 0.0f;
        int sum=0;

        float[][] Z = new float[1][10];
        for (int i = 0; i < trainXX.length; i++) {

            label_counter++;

            //FORWARD PROPAGATION
            int ind_ex = i;

            float[][] X = trainXX[ind_ex];
            float[] trueZ = trainY[ind_ex];
            int correct_label = tools.getIndexMaxFloat(trueZ);

            Z = forward_(X);
            // float[][] gradient = layer2SoftmaxMulticlass.compute_gradient( Z, correct_label );
            float[] gradient = layer1SoftmaxMultiClass.gradientCNN( Z, correct_label );
// System.out.println( Tools.AryToString( gradient ) );
            loss += layer1SoftmaxMultiClass.delta_Loss( correct_label );
            backward_( gradient );

            sum++;
            if ( correct_label==tools.getIndexMaxFloat( Z[0] )){ accuracy++; }
            //if(  i % 100 == 99){
                // System.out.println( "I: " + i + ", ce_loss: " + ce_loss );
            //    ce_loss=0;
            //    acc_sum+=accuracy;
            //    accuracy=0;
            //}
        }
        System.out.println( "Loss: " + loss + ", accuracy: " + ( 100f*accuracy )/sum + "%         \tsize: " + trainXX.length );
        accuracy=0; sum=0;
        // System.out.println("Average accuracy:- "+acc_sum/training_size+"%\n\n");
    }




    public void test(){
        int filterNum = 8;
        int[][] errors = new int[10][10];
        int error = 0;

        int label_counter = 0;
        int accuracy=0;
        int sum=0;

        float[][] out_l;
        for (int i = 0; i < trainXX.length; i++) {

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


