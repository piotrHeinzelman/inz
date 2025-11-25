package pl.heinzelman.LayerDeep;

import org.junit.Test;
import pl.heinzelman.tools.Tools;

public class CNN_3_class {

    @Test
    public void argmaxTest(){

            float[][] out_l = new float[1][10];
            out_l[0] = new float[]{-0.4f, -0.3f, -0.2f, -0.1f, 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.3f};


            // accuracy += correct_label == _Mat.v_argmax(out_l) ? 1 : 0;
            float IndexOfmMaxValue = _Mat.v_argmax( out_l );
            // 8.0
    }

    @Test
    public void gradientTest() {
        int correct_label=8;
        float[][] out_l = new float[1][10];
        out_l[0] = new float[]{-0.4f, -0.3f, -0.2f, -0.1f, 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.3f};

        float[][] gradient = _Mat.v_zeros(10);
        gradient[0][correct_label] = -1 / out_l[0][correct_label];

        System.out.println( Tools.AryToString( gradient ) );
        // [0][ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.5, 0.0,]
    }


    @Test
    public void LossTest() {
        int correct_label = 8;
        float[][] out_l = new float[1][10];
        out_l[0] = new float[]{-0.4f, -0.3f, -0.2f, -0.1f, 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.3f};

        // compute cross-entropy loss
        // not used
        //ce_loss += (float) -Math.log(out_l[0][correct_label]);
        float value_correctLabel = out_l[0][correct_label];
        float deltaLoss = (float) -Math.log(value_correctLabel);

        System.out.println(deltaLoss);
    }
}
