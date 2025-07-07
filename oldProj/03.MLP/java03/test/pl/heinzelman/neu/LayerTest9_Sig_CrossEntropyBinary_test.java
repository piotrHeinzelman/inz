package pl.heinzelman.neu;


import org.junit.Test;
import pl.heinzelman.tools.Tools;

import java.awt.image.BufferedImage;
import java.util.Arrays;

public class LayerTest9_Sig_CrossEntropyBinary_test {
    @Test
    public void forwardTest(){

        Tools tools = new Tools();

        Layer L1 = new Layer(LType.sigmod, 3,4); // 3 neurons, 4 inputs
        L1.rnd();
        L1.setName("Layer1");

        Layer L2 = new Layer(LType.softmaxMultiClass, 3,3); // 2 neurons, 3 inputs
        L2.rnd();
        L2.setName("Layer2");

        float[][] X = new float[3][]; // x1, x2, x3, x4, x[0] = {1,2}
            X[0] = new float[]{1,2,3,4};
            X[1] = new float[]{3,2,1,0};
            X[2] = new float[]{1,2,0,1};


        float[][] S = new float[3][];
            S[0] = new float[]{1,0,0};
            S[1] = new float[]{0,1,0};
            S[2] = new float[]{0,0,1};



        int numOfEpoch=10000;
        float[] CSBin_data=new float[numOfEpoch];
        float[] CSBin_data2=new float[numOfEpoch];
        for (int epoch=0;epoch<numOfEpoch; epoch++) {

            float MSE2 = 0.0f;
            float MSE1 = 0.0f;
            for (int i = 0; i < X.length; i++) {
                L1.setX( X[i] );
                L1.nForward();

                L2.setX( L1.getZ() );
                L2.nForward();

                MSE2 += Tools.crossEntropyBinaryError2input( S[i], L2.getZ() );
                float[] S_Z = Tools.vectorSubstSsubZ(S[i], L2.getZ());
                L2.nBackward( S_Z ) ;
                //float[] SZ_lev1 = L2.getEout();
                //MSE1 += Tools.crossEntropyBinaryError2input( L2.getEout(), L1.getZ());
                //System.out.println(Arrays.toString( S_Z ) + " : " +   Arrays.toString( L2.getEout() ));
                MSE1 += Tools.meanSquareError( L2.getEout(), L1.getZ() );
                L1.nBackward( L2.getEout() );
            }
            CSBin_data2[epoch]=MSE2/X.length;
            CSBin_data[epoch]=MSE1/X.length;
        }

        BufferedImage image2 = Tools.arrayOfFloatToImage( CSBin_data2, 10 );
        BufferedImage image = Tools.arrayOfFloatToImage( CSBin_data, 10 );
        Tools.saveImg( image2 , " 2level2");
        Tools.saveImg( image , " 2level");


        for (int i=0;i<3;i++) {
            L1.setX(X[ i ]);
            L1.nForward();
            L2.setX(L1.getZ());
            L2.nForward();
            System.out.println(tools.getIndexMaxFloat(L2.getZ()) + " : " + tools.getIndexMaxFloat(S[ i ]));
        }
    }
}