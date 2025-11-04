package pl.heinzelman.tools;

import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;

//https://www.youtube.com/watch?v=Lakz2MoHy6o
class ToolsTwoTest {

    @Test
    void conv() {

        float[][] input = new float[3][3];
        float[][] kernel = new float[2][2];

        input[0] = new float[]{1.0f,6.0f,2.0f};
        input[1] = new float[]{5.0f,3.0f,1.0f};
        input[2] = new float[]{7.0f,0.0f,4.0f};

        kernel[0] = new float[]{1.0f,2.0f};
        kernel[1] = new float[]{-1.0f,0.0f};

        float B = .3f;


        System.out.println(Tools.AryToString( input ));
        System.out.println(Tools.AryToString( kernel ));
        System.out.println(Tools.AryToString( Conv.conv( input, kernel, B ) ));

        float[][] Rot_kernel = Conv.getRot180( kernel );

        System.out.println(Tools.AryToString( Rot_kernel ));
        System.out.println(Tools.AryToString( Conv.conv( input, Rot_kernel, B ) ));


        System.out.println( "\n\n*******************\n\n"  );

        int padd = (int)((3.0f-1.0f)/2.0f);
        System.out.println( padd );
        float[][] extInput = Conv.extendAry(input, padd);
        System.out.println(Tools.AryToString( extInput ));

        System.out.println(Tools.AryToString( Conv.conv( extInput, kernel, B ) ));
    }
}