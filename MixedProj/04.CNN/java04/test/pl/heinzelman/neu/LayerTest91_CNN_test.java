package pl.heinzelman.neu;

import org.junit.Test;
import pl.heinzelman.tools.Tools;

import javax.tools.Tool;
import java.awt.image.BufferedImage;
import java.util.Arrays;

public class LayerTest91_CNN_test {
    @Test
    public void forwardTest(){

        Tools tools = new Tools();

        LayerConv LCNN1 = new LayerConv( 3, 1 ); // 3x3 1 filter
        LCNN1.rnd();
        LCNN1.setName( "CNN 01" );

        float[][][] X = new float[1][5][5]; // x1, x2, x3, x4, x[0] = {1,2}
        X[0][0] = new float[]{  1, 2, 3, 4, 5 };
        X[0][1] = new float[]{  6, 7, 8, 9,10 };
        X[0][2] = new float[]{ 11,12,13,14,15 };
        X[0][3] = new float[]{ 16,17,18,19,20 };
        X[0][4] = new float[]{ 21,22,23,24,25 };

        LCNN1.setX( X );

        float[][][] Z = LCNN1.nForward();

        LCNN1.nBackward( Z );
        System.out.println( Tools.AryToString( X ) );
        System.out.println( Tools.AryToString( Z ) );
        System.out.println( Tools.AryToString( LCNN1.getEout() ));

    }
}