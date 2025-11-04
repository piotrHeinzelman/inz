package pl.heinzelman.neu;


import org.junit.Test;
import pl.heinzelman.tools.Tools;

import java.awt.image.BufferedImage;

public class LayerTest8_CrossEntropy_Multiclass_test {
    @Test
    public void forwardTest(){

        Tools tools = new Tools();

        Layer L1 = new Layer(LType.softmaxMultiClass, 4,3); // 4 neurons, 3 inputs
        L1.setName("Layer1");

        float[][] X = new float[4][]; // x1, x2, x3, x4, x[0] = {1,2}
            X[0] = new float[]{1,2,3,4};
            X[1] = new float[]{3,2,1,0};
            X[2] = new float[]{1,2,2,1};
            X[3] = new float[]{2,1,1,2};

        float[][] S = new float[4][];
            S[0] = new float[]{1,0,0,0};
            S[1] = new float[]{0,1,0,0};
            S[2] = new float[]{0,0,1,0};
            S[3] = new float[]{0,0,0,1};


        int numOfEpoch=1000;
        float[] CSBin_data=new float[numOfEpoch];
        for (int epoch=0;epoch<numOfEpoch; epoch++) {

            float MSE = 0.0f;
            for (int i = 0; i < X.length; i++) {
                L1.setX(X[i]);
                L1.nForward();

                //System.out.println("Y: " + Arrays.toString( L1.getY() ) +", Z: "+ Arrays.toString( L1.getZ() ));
                MSE += Tools.meanSquareError(S[i], L1.getZ());
                float[] S_Z = Tools.vectorSubstZsubS(S[i], L1.getZ());
                L1.nBackward(S_Z) ;
                //System.out.println( "x: " + Arrays.toString( L1.getX())  +", y: " + Arrays.toString( L1.getY())  + " : z:" + Arrays.toString( L1.getZ() ) );
            }
            CSBin_data[epoch]=MSE/X.length;
        }

        BufferedImage image = Tools.arrayOfFloatToImage( CSBin_data, 1 );
        Tools.saveImg( image , " CrossEntropy_Multiclass_by_Epoch ");
    }
}