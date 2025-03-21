package pl.heinzelman.tools;

import org.junit.jupiter.api.Test;
import pl.heinzelman.neu.LayerConv;
import pl.heinzelman.neu.LayerConvRGB;
import pl.heinzelman.neu.Neuron2D;

import javax.tools.Tool;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;
//https://www.youtube.com/watch?v=Lakz2MoHy6o
class ToolsTest {

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


        LayerConvRGB layerConvRGB = new LayerConvRGB(2, 2);
        layerConvRGB.setName("convRGB");
        layerConvRGB.rnd();
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
        System.out.println(Tools.AryToString( Tools.conv( input, kernel, 0 ) ));

        float[][] Rot_kernel = Tools.getRot180( kernel );

        System.out.println(Tools.AryToString( Rot_kernel ));
        System.out.println(Tools.AryToString( Tools.conv( input, Rot_kernel, 0 ) ));


        System.out.println( "\n\n*******************\n\n"  );

        int padd = (int)((3.0f-1.0f)/2.0f);
        System.out.println( padd );
        float[][] extInput = Tools.extendAry(input, padd);
        System.out.println(Tools.AryToString( extInput ));

        System.out.println(Tools.AryToString( Tools.conv( extInput, kernel, 0 ) ));
    }
}