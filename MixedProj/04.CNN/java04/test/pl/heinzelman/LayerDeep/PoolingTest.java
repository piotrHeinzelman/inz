package pl.heinzelman.LayerDeep;

import org.junit.Test;
import org.junit.jupiter.api.Assertions;
import pl.heinzelman.tools.Tools;

import javax.tools.Tool;

public class PoolingTest {

    @Test
    public void MaxPoolingTes(){
        float[][] X = new float[6][];
        X[0] = new float[]{-19f, 22f,-20f,-12f,-17f, 11f};
        X[1] = new float[]{ 16f,-30f, -1f, 23f, -7f,-14f};
        X[2] = new float[]{-14f,24f,7f,-2f,1f,-7f};
        X[3] = new float[]{-15f,-10f,-1f,-1f,-15f,1f};
        X[4] = new float[]{-13f,13f,-11f,-5f,13f,-7f};
        X[5] = new float[]{-18f,9f,-18f,13f,-3f,4f};

        float[][][] x0 = new float[1][][];
        x0[0]=X;

        float[][] Z = new float[3][];
        Z[0] = new float[]{22f,23f,11f};
        Z[1] = new float[]{24f,7f,1f};
        Z[2] = new float[]{13f,13f,13f};
        float[][][] z0 = new float[1][][];
        z0[0] = Z;
        //System.out.println(Tools.AryToString( X ));

        LayerPoolingMax layerPoolingMax = new LayerPoolingMax(2, 2);


        layerPoolingMax.setX( x0 );
        float[][][] OUT = layerPoolingMax.Forward();


        Assertions.assertTrue( OUT[0][0][0] - 22f < 0.0001f );
        Assertions.assertTrue( OUT[0][2][2] - 13f < 0.0001f );
        Assertions.assertTrue( OUT[0][0][1] - 23f < 0.0001f );
        Assertions.assertTrue( OUT[0][0][2] - 11f < 0.0001f );

        System.out.println(Tools.AryToString( OUT ));
    }
}
