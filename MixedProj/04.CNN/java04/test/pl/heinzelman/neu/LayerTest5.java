package pl.heinzelman.neu;


import org.junit.Test;
import pl.heinzelman.tools.Tools;

import java.util.Arrays;

public class LayerTest5 {
    @Test
    public void forwardTest(){

        Tools tools = new Tools();

        Layer L1 = new Layer(LType.sigmod_CrossEntropy_Binary, 3,2); // 3 neurons, 2 inputs
        float[] X = new float[]{1,2};
        float[] S = new float[]{1,0,0};

        L1.setName("Layer1");


        for (int i=0;i<1000;i++) {
            L1.setX(X);
            L1.nForward();
            //System.out.println(L1);

            //System.out.println("Y: " + Arrays.toString( L1.getY() ) +", Z: "+ Arrays.toString( L1.getZ() ));
            float[] S_Z = Tools.vectorSubstSsubZ(S, L1.getZ());
            //System.out.println(tools.toStr(S_Z));
            L1.nBackward(S_Z);
        }
        L1.setX( X );
        L1.nForward();
        //System.out.println( tools.toStr( L1.getZ()));

        /*
        Binary Cross-Entropy


         */
    }
}