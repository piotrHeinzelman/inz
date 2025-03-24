package pl.heinzelman.tools;

import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;
import pl.heinzelman.LayerDeep.LayerConvRGB;

//https://www.youtube.com/watch?v=Lakz2MoHy6o
class ToolsTest {

    @Disabled
    @Test
    void convRGB() {
        float[][][] input = new float[3][3][3];

        //R
        input[0][0] = new float[]{1.0f,2.0f,3.0f};
        input[0][1] = new float[]{4.0f,5.0f,6.0f};
        input[0][2] = new float[]{7.0f,8.0f,8.0f};
        //G
        input[1][0] = new float[]{10.0f,11.0f,12.0f};
        input[1][1] = new float[]{13.0f,14.0f,15.0f};
        input[1][2] = new float[]{16.0f,17.0f,18.0f};
        //B
        input[2][0] = new float[]{19.0f,20.0f,21.0f};
        input[2][1] = new float[]{22.0f,23.0f,24.0f};
        input[2][2] = new float[]{25.0f,26.0f,27.0f};


        LayerConvRGB layerConvRGB = new LayerConvRGB(2, 2, null, null);
        layerConvRGB.setName("convRGB");

        float[][][] biases = new float[2][2][2];// layerConvRGB.getBiases();
            biases[0][0] = new float[]{0.1f,-.1f};
            biases[0][1] = new float[]{0.2f,-.2f};

            biases[1][0] = new float[]{0.3f,-.3f};
            biases[1][1] = new float[]{0.4f,-.4f};
        // R
        float[][] myWeight = new float[2][2]; // layerConvRGB.getRNeuron(0).getMyWeight();
        myWeight[0] = new float[]{0.1f,-.1f};
        myWeight[1] = new float[]{0.2f,-.2f};

                //myWeight = new float[][]layerConvRGB.getRNeuron(1).getMyWeight();
        myWeight[0] = new float[]{0.3f,-.3f};
        myWeight[1] = new float[]{0.4f,-.4f};

        // G
               //myWeight = layerConvRGB.getGNeuron(0).getMyWeight();
        myWeight[0] = new float[]{0.5f,-.5f};
        myWeight[1] = new float[]{0.6f,-.6f};

              myWeight = layerConvRGB.getGNeuron(1).getMyWeight();
        myWeight[0] = new float[]{0.7f,-.7f};
        myWeight[1] = new float[]{0.8f,-.8f};

        // B
               myWeight = layerConvRGB.getBNeuron(0).getMyWeight();
        myWeight[0] = new float[]{0.9f,-.9f};
        myWeight[1] = new float[]{1.f,-1.f};

              myWeight = layerConvRGB.getBNeuron(1).getMyWeight();
        myWeight[0] = new float[]{1.2f,-1.2f};
        myWeight[1] = new float[]{1.5f,-1.5f};


        //layerConvRGB.rnd();
        System.out.println( layerConvRGB.toString() );

        float[][][] forward = layerConvRGB.forward(input);

        System.out.println( Tools.AryToString( forward ) );
    }

    @Test
    void conv() {

        float[][] input = new float[3][3];
        float[][] kernel = new float[2][2];

        input[0] = new float[]{1.0f,6.0f,2.0f};
        input[1] = new float[]{5.0f,3.0f,1.0f};
        input[2] = new float[]{7.0f,0.0f,4.0f};

        kernel[0] = new float[]{1.0f,2.0f};
        kernel[1] = new float[]{-1.0f,0.0f};

        System.out.println(Tools.AryToString( input ));
        System.out.println(Tools.AryToString( kernel ));
        System.out.println(Tools.AryToString( Conv.conv( input, kernel, 0 ) ));

        float[][] Rot_kernel = Conv.getRot180( kernel );

        System.out.println(Tools.AryToString( Rot_kernel ));
        System.out.println(Tools.AryToString( Conv.conv( input, Rot_kernel, 0 ) ));


        System.out.println( "\n\n*******************\n\n"  );

        int padd = (int)((3.0f-1.0f)/2.0f);
        System.out.println( padd );
        float[][] extInput = Conv.extendAry(input, padd);
        System.out.println(Tools.AryToString( extInput ));

        System.out.println(Tools.AryToString( Conv.conv( extInput, kernel, 0 ) ));
    }
}