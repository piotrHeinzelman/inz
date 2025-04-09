package pl.heinzelman.neu;


import org.junit.Assert;
import org.junit.Test;
import pl.heinzelman.tools.Tools;

import java.awt.image.BufferedImage;
import java.util.Arrays;

public class LayerTest6_MSE_test {
    @Test
    public void forwardTest(){

        Tools tools = new Tools();

        Layer L1 = new Layer(LType.sigmod, 3,2); // 3 neurons, 2 inputs
        L1.setName("Layer1");

        float[][] X = new float[4][]; // x1, x2, x3, x4, x[0] = {1,2}
            X[0] = new float[]{1,2};
            X[1] = new float[]{2,1};
            X[2] = new float[]{1,1};
            X[3] = new float[]{2,2};

        float[][] S = new float[4][];
            S[0] = new float[]{1,0,0};
            S[1] = new float[]{0,1,0};
            S[2] = new float[]{0,0,1};
            S[3] = new float[]{1,0,0};


        int numOfEpoch=100000;
        float[] MSEdata=new float[numOfEpoch];
        for (int epoch=0;epoch<numOfEpoch; epoch++) {

            float MSE = 0.0f;
            for (int i = 0; i < X.length; i++) {
                L1.setX(X[i]);
                L1.nForward();

                //System.out.println("Y: " + Arrays.toString( L1.getY() ) +", Z: "+ Arrays.toString( L1.getZ() ));
                MSE += Tools.meanSquareError(S[i], L1.getZ());
                float[] S_Z = Tools.vectorSubstZsubS(S[i], L1.getZ());

                System.out.println("Y: " + Arrays.toString( L1.getY() ) +", Z: "+ Arrays.toString( L1.getZ() ));
                System.out.println("S_Z: " +  Arrays.toString(  S_Z ));
                L1.nBackward(S_Z);
            }
            MSEdata[epoch]=MSE/X.length;
        }

        BufferedImage image = Tools.arrayOfFloatToImage( MSEdata, 100 );
        Tools.saveImg( image , " MSE_by_Epoch ");


        int i=1;
        L1.setX( X[i] );
        L1.nForward();
        float[] Z = L1.getZ();

        System.out.println( Arrays.toString(Z) + " : " + Arrays.toString( S[i]) + ", index: " + tools.getIndexMaxFloat( S[i] )  );
        Assert.assertEquals( tools.getIndexMaxFloat(Z),  tools.getIndexMaxFloat( S[i] ));
    }
}