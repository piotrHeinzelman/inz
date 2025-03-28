package pl.heinzelman.LayerDeep;

import org.junit.jupiter.api.Test;
import pl.heinzelman.tools.Conv;
import pl.heinzelman.tools.Tools;

class LayerDeepTest {
    @Test
    public void creationConvolutionTest2() {
        float[][][] input = new float[2][4][4];

        //R
        input[0][0] = new float[]{1.0f,6.0f,2.0f,2.0f};
        input[0][1] = new float[]{5.0f,3.0f,1.0f,1.0f};
        input[0][2] = new float[]{7.0f,0.0f,4.0f,1.0f};
        input[0][3] = new float[]{2.0f,1.0f,4.0f,8.0f};

        input[1][0] = new float[]{1.0f,6.0f,2.0f,2.0f};
        input[1][1] = new float[]{5.0f,3.0f,1.0f,1.0f};
        input[1][2] = new float[]{7.0f,0.0f,4.0f,1.0f};
        input[1][3] = new float[]{2.0f,1.0f,4.0f,8.0f};


        //LayerDeep layer = new LayerConv( 2, 1 , 0 , 1);
        //LayerDeep layer = new LayerPoolingAvg( 2, 2 );
        LayerDeep layer = new LayerPoolingMax( 2, 2 );
        layer.setName( "layer1" );
        layer.setX( input );

        float[][][] Y = layer.ConvForward();

        float[][][] deltaIn = new float[2][2][2];

        //R
        deltaIn[0][0] = new float[]{ 1.0f,6.0f };
        deltaIn[0][0] = new float[]{ 5.0f,3.0f };
        deltaIn[0][1] = new float[]{ 7.0f,4.0f };
        deltaIn[0][1] = new float[]{ 7.0f,2.0f };
        deltaIn[1][0] = new float[]{ 1.0f,6.0f };
        deltaIn[1][0] = new float[]{ 5.0f,3.0f };
        deltaIn[1][1] = new float[]{ 7.0f,4.0f };
        deltaIn[1][1] = new float[]{ 7.0f,2.0f };
/*
        float[][][] delta3 = new float[1][3][3];

        //R
        delta3[0][0] = new float[]{ 1.0f,6.0f,2.0f };
        delta3[0][0] = new float[]{ 5.0f,3.0f,1.0f };
        delta3[0][0] = new float[]{ 5.0f,3.0f,1.0f };
        delta3[0][1] = new float[]{ 7.0f,0.0f,0.0f };
        delta3[0][1] = new float[]{ 7.0f,0.0f,1.2f };
        delta3[0][1] = new float[]{ 7.0f,0.0f,1.2f };
        delta3[0][2] = new float[]{ 7.0f,0.0f,1.2f };
        delta3[0][2] = new float[]{ 7.0f,0.0f,1.2f };
        delta3[0][2] = new float[]{ 7.0f,0.0f,1.2f };
*/


        float[][][] delta = layer.Backward( deltaIn );

        System.out.println( "\nInput: " + Tools.AryToString( input ) );
        System.out.println( "\nY: " + Tools.AryToString( Y ) );
        System.out.println( "\ndeltaIn: " + Tools.AryToString( deltaIn ) );
        System.out.println( "\nDelta: " + Tools.AryToString( delta ) );

        System.out.println( "\nDx: " + Tools.AryToString( layer.dX ));

    }

    @Test
    public void creationConvolutionTest() {
        LayerConv layer = new LayerConv( 2, 2, null, null );
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



        layer.setX( input );
        System.out.println( layer );

        float[][][] Y = layer.Forward();
        float[][][] delta = layer.Backward(Y);

        //System.out.println("\n\nInput:" + Tools.AryToString( input ));
        System.out.println("\n\nY: "+Tools.AryToString( Y ));
        System.out.println("\n\nDelta: " + Tools.AryToString( delta ));
/*
        float [][] F = new float[2][];
        F[0] = new float[]{1f, 2f};
        F[1] = new float[]{-1f, 0f};

        float[][] C = Conv.conv(input[0], F, layer.getNeuron(0).getBias());
        System.out.println( Tools.AryToString( C ) );

        float[][] FullC = Conv.fullConv( input[0], F );
        System.out.println( Tools.AryToString( FullC ) );
*/
    }

}