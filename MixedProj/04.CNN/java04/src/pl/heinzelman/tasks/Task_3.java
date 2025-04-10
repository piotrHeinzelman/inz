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

    private LayerSigmoidFullConn layer1FC;
    private LayerSoftmaxMultiClass layer2SoftmaxMulticlass;

    private LayerFlatten layerFlatten = new LayerFlatten();
    private LayerConv layerConv = new LayerConv( 3 , 8, null, null  );
    private Tools tools = new Tools();

    int numOfEpoch=50;
    int cyclesOfEpoch=20;
    float[] CSBin_data=new float[numOfEpoch*cyclesOfEpoch];

    /// old
    private static final _Convolution conv=new _Convolution();
    private static final _MaxPool pool=new _MaxPool();
    private static _SoftMax softmax;
    private static int filterNum;

    private float[][][] filters;
    private float ce_loss;
    private float accuracy;
    private float[][] out_l = new float[1][10];

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

        layer1FC = new LayerSigmoidFullConn( 26*26*8, 10 ); layer1FC.setName("Layer1"); // n neurons
        layer2SoftmaxMulticlass = new LayerSoftmaxMultiClass( 10 ); layer2SoftmaxMulticlass.setName("Layer2Softmax"); // n neurons

        // ****************************

/* */   int filterNum = 8;
        softmax=new _SoftMax(13*13*filterNum,10, filterNum );
        filters = new float[ filterNum ][3][3];
        for (int k = 0; k < filterNum; k++) {
            filters[k] = _Mat.m_random(3, 3);
        }
    }

    public float[] forward_( float[][] X ){
        float[][][] oneX = new float[1][28][28];
        oneX[0] = X;
        layerConv.setX( oneX );
        float[][][] Zconv = layerConv.Forward();

        // System.out.println( Zconv.length + " : " + Zconv[0].length + " ! " + Zconv[0][0].length );

        float[] Xf = layerFlatten.Forward(Zconv);
        float[] Z1 = layer1FC.nForward( Xf );
        float[] Z2 = layer2SoftmaxMulticlass.nForward( Z1 );
        return Z2;
    }

    public float[] backward_( float[] eIN ){
        float[] L2eOUT = layer2SoftmaxMulticlass.nBackward( eIN );
        float[] eOUT = layer1FC.nBackward( L2eOUT );
        float[][][] eOUTF    = layerFlatten.Backward( eOUT );
                               layerConv.Backward( eOUTF );

        //System.out.println( eOUTF.length + " : "+ eOUTF[0].length + " : "+ eOUTF[0][0].length );
        return null;
    }

    public float[][] _calculateZ_S( float[][] outZ, float[] correctZ ){
        float learn_rate = .01f;
        int correct_label =  tools.getIndexMaxFloat( correctZ );
        ce_loss += (float) -Math.log( out_l[0][correct_label] );
        if ( correct_label == tools.getIndexMaxFloat( outZ[0] )) { accuracy++; }

        //BACKWARD PROPAGATION --- STOCHASTIC GRADIENT DESCENT
        //gradient of the cross entropy loss
        float[][] gradient=_Mat.v_zeros(10);
        gradient[0][correct_label]=-1/outZ[0][correct_label];
        return gradient;
    }
    public float[] calculateZ_S( float[] outZ, float[] trueZ ){
        int trueIndexZ = tools.getIndexMaxFloat( trueZ );
        float[]Z_S = new float[10];
        for ( int i=0;i<10;i++ ){ Z_S[i]=0.0f; }
        Z_S[ trueIndexZ ]=-1.0f/outZ[trueIndexZ];
        return Z_S;
    }

// ****************************

    public float[][] _forward_( float[][] X ){
        // perform convolution 28*28 --> 8x26x26
        float[][][] out = conv.forward( X, filters, 8 );

        // perform maximum pooling  8x26x26 --> 8x13x13
        out = pool.forward( out );

        // perform softmax operation  8*13*13 --> 10
        float[][] out_l = softmax.forward( out );
        // System.out.println( "OUT_L: " + Arrays.toString( out_l[0] ));
        // System.out.println( "OUT_L: " + Tools.AryToString( out_l ));
        // System.out.println( "outF[0]: " + Arrays.toString(  out_l[0] ));
        return out_l;
    }

    public float[] _backward_( float[][] gradient ){
        float learn_rate=0.005f;
        float[][][] sm_gradient=softmax.backprop(gradient,learn_rate);
        float[][][] mp_gradient=pool.backprop(sm_gradient);
        conv.backprop(mp_gradient, learn_rate);
        return null;
    }

// *********************

    @Override
    public void run() {
        prepare();

        int epochNum=0;
        for (int cycle=0;cycle<cyclesOfEpoch;cycle++) {
            float Loss=0.0f;
            int step=1;

            ce_loss=0.0f;
            accuracy=0.0f;
            for (int epoch = 0; epoch < numOfEpoch; epoch++) {
                step++; epochNum++; Loss=0.0f;
                for ( int index = 0; index < trainX.length; index++ ) {

                    // ONE CYCLE
                    int ind_ex = /*index; //*/ (index * step) % trainX.length;

                    float[][] X = trainXX[ind_ex];
                    float[] trueZ = trainY[ind_ex];
                    int trueIndexZ = tools.getIndexMaxFloat( trueZ );

                    float[][] out_l = _forward_( X );

                    float[][] Z_S = _calculateZ_S( out_l, trueZ ); //= tools.vectorSubstZsubS( outZ, trueZ );

                            _backward_(Z_S);
                    //Loss += Tools.meanSquareError( outZ, trueZ );
                    Loss += Tools.crossEntropyMulticlassError( out_l[0] );
                }
                CSBin_data[epoch]=Loss/trainX.length;
            }
            System.out.println("Loss: " + Loss );

            int acc = 0;
            int sam = 0;
            for (int i=0;i<testX.length;i++){
                float[] Z = _forward_(testXX[i])[0];
                float[] trueZ = testY[i];
                if ( tools.getIndexMaxFloat( Z ) == tools.getIndexMaxFloat( trueZ ) ) { acc++; }
                sam++;
            }
            System.out.println("test accuracy: " + 100.0f * acc / sam + "%     ("+epochNum+")");
        }
    }
}


