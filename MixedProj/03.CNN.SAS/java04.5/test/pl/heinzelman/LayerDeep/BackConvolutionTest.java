package pl.heinzelman.LayerDeep;

import org.junit.Test;
import org.junit.jupiter.api.Assertions;
import pl.heinzelman.tools.Tools;

public class BackConvolutionTest {

    @Test
    public void BackConvolutionTest(){
        float[][][] X = new float[1][3][];
        X[0][0] = new float[]{1f,2f,3f};
        X[0][1] = new float[]{4f,5f,6f};
        X[0][2] = new float[]{7f,8f,9f};

        float[][][] delta = new float[1][2][];
        delta[0][0] = new float[]{.1f,.2f};
        delta[0][1] = new float[]{.3f,.8f};

        Neuron2D filterW11 = new Neuron2D(2, null );
        filterW11.setWm(0,0,1); //y,x
        filterW11.setWm(0,1, 2);

        filterW11.setWm(1,0, 3); //y,x
        filterW11.setWm(1,1, 4);

        //filterW11.setBias( 0f );

        LayerConv layerConv= new LayerConv(2,1,null,null);
        layerConv.setUpByX( X );
        layerConv.filters[0]=filterW11;

        float[][][] Z = layerConv.Forward(X);
        float[][][] OUTPUT_DELTA = layerConv.Backward(delta);

        System.out.println( "Z:\n"+Tools.AryToString( Z ) );
        System.out.println( "OutputDelta:\n"+ Tools.AryToString( OUTPUT_DELTA ) );

        //if (true) return;
        /*
            System.out.println( Tools.AryToString( Z ) );
            [ 37.0, 47.0,]
            [ 67.0, 77.0,]
         */
        Assertions.assertTrue( Math.pow(( Z[0][0][0] - 37f ), 2 ) < 0.0001f );
        Assertions.assertTrue( Math.pow(( Z[0][0][1] - 47f ), 2 ) < 0.0001f );
        Assertions.assertTrue( Math.pow(( Z[0][1][0] - 67f ), 2 ) < 0.0001f );
        Assertions.assertTrue( Math.pow(( Z[0][1][1] - 77f ), 2 ) < 0.0001f );


        //  UPDATE WEIGHT :- ) !!!
        /*
          [ 5.7,  7.1 ]
          [ 9.9, 11.3 ]
        */


        //  UPDATE BIAS = delta
        /*
          [ 0.1, 0.2 ]
          [ 0.3, 0.8 ]
        */

        //  OUTPUT_DELTA :-) !!!
        /*
        [ 0.1, 0.4, 0.4 ]
        [ 0.6, 2.4, 2.4 ]
        [ 0.9, 3.6, 3.2 ]
         */


        /*
        [ 0.1, 0.4, 0.4 ]
        [ 0.6, 2.4, 2.4 ]
        [ 0.9, 3.6, 3.2 ]
         */
        Assertions.assertTrue( OUTPUT_DELTA[0][0][0] - .1f < 0.0001f );
        Assertions.assertTrue( OUTPUT_DELTA[0][0][1] - .4f < 0.0001f );
        Assertions.assertTrue( OUTPUT_DELTA[0][0][2] - .4f < 0.0001f );
        Assertions.assertTrue( OUTPUT_DELTA[0][2][2] - 3.2f < 0.0001f );

        System.out.println( layerConv );
    }


}
