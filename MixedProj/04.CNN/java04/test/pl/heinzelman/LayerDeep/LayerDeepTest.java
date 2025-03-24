package pl.heinzelman.LayerDeep;

import org.junit.jupiter.api.Test;
import pl.heinzelman.tools.Conv;
import pl.heinzelman.tools.Tools;

import javax.tools.Tool;

import static org.junit.jupiter.api.Assertions.*;

class LayerDeepTest {
    @Test
    public void creationConvolutionTest2() {
        float[][][] input = new float[1][4][4];

        //R
        input[0][0] = new float[]{1.0f,6.0f,2.0f,2.0f};
        input[0][1] = new float[]{5.0f,3.0f,1.0f,1.0f};
        input[0][2] = new float[]{7.0f,0.0f,4.0f,1.0f};
        input[0][3] = new float[]{2.0f,1.0f,4.0f,8.0f};


        LayerDeep layer = new LayerPoolingAvg( 2, 2 );
        layer.setName( "layer1" );
        layer.setX( input );

        float[][][] Y = layer.Forward();

        System.out.println( Tools.AryToString( input ) );
        System.out.println( Tools.AryToString( Y ) );
        System.out.println( layer );

    }

    @Test
    public void creationConvolutionTest() {
        LayerDeep layer = new LayerConv( 2, 1, null, null );
        layer.setName( "layer1" );

        float[][][] input = new float[3][3][3];

        //R
        input[0][0] = new float[]{1.0f,6.0f,2.0f};
        input[0][1] = new float[]{5.0f,3.0f,1.0f};
        input[0][2] = new float[]{7.0f,0.0f,4.0f};
        //G
        input[1][0] = new float[]{10.0f,11.0f,12.0f};
        input[1][1] = new float[]{13.0f,14.0f,15.0f};
        input[1][2] = new float[]{16.0f,17.0f,18.0f};
        //B
        input[2][0] = new float[]{19.0f,20.0f,21.0f};
        input[2][1] = new float[]{22.0f,23.0f,24.0f};
        input[2][2] = new float[]{25.0f,26.0f,27.0f};

        //Neuron2D neuron = layer.getNeuron(0);

        //float [][] B = new float[2][];
        //B[0] = new float[]{.1f, .2f};
        //B[1] = new float[]{.4f, .3f};



        System.out.println( layer );
        layer.setX( input );
        layer.initBiases();
        System.out.println( layer );

        float[][][] Y = layer.Forward();
        float[][][] delta = layer.Backward(Y);

        System.out.println(Tools.AryToString( input ));
        System.out.println(Tools.AryToString( Y ));
        System.out.println(Tools.AryToString( delta ));

        float [][] F = new float[2][];
        F[0] = new float[]{1f, 2f};
        F[1] = new float[]{-1f, 0f};

        float[][] C = Conv.conv(input[0], F, layer.getBiases());
        System.out.println( Tools.AryToString( C ) );

        float[][] FullC = Conv.fullConv( input[0], F );
        System.out.println( Tools.AryToString( FullC ) );

    }

}