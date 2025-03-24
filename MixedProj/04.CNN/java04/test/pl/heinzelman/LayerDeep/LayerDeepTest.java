package pl.heinzelman.LayerDeep;

import org.junit.jupiter.api.Test;
import pl.heinzelman.tools.Tools;

import static org.junit.jupiter.api.Assertions.*;

class LayerDeepTest {
    @Test
    public void creationTest() {
        LayerDeep layer = new LayerConv( 2, 1, null, null );
        layer.setName( "layer1" );

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

        layer.setX( input );

        float[][][] Y = layer.Forward();
        float[][][] delta = layer.Backward(Y);

        System.out.println(Tools.AryToString( input ));
        System.out.println(Tools.AryToString( Y ));
        System.out.println(Tools.AryToString( delta ));

    }

}