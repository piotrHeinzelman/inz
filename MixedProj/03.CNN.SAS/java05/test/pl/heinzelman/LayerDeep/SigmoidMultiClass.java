package pl.heinzelman.LayerDeep;

import org.junit.jupiter.api.Test;
import pl.heinzelman.neu.LayerSoftmaxMultiClassONLYFORWARD;

import java.util.Arrays;

public class SigmoidMultiClass {

    @Test
    public void Sigmoid_multiclass_test(){
        float [] X = new float[]{.1f,.2f,.3f,.4f};
        System.out.println("X: "+Arrays.toString( X ));

        float[] output_gradient = new float[]{ 0.5f, 0.6f, 0.7f, 0.8f };

        LayerSoftmaxMultiClassONLYFORWARD layer = new LayerSoftmaxMultiClassONLYFORWARD( 4 );
        float[] Y = layer.nForward( X );
        //System.out.println( "Y: "+Arrays.toString( Y ) );

        float[] EOut = layer.nBackward( output_gradient );
        System.out.println(Arrays.toString( EOut ));
    }
}
