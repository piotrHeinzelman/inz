package pl.heinzelman.LayerDeep;

import org.junit.Test;
import org.junit.jupiter.api.Assertions;
import pl.heinzelman.tools.Tools;

public class ReLUTest {

    @Test
    public void ReLUTest(){
        float[][] X = new float[6][];
        X[0] = new float[]{-19f, 22f,-20f,-12f,-17f, 11f};
        X[1] = new float[]{ 16f,-30f, -1f, 23f, -7f,-14f};
        X[2] = new float[]{-14f,24f,7f,-2f,1f,-7f};
        X[3] = new float[]{-15f,-10f,-1f,-1f,-15f,1f};
        X[4] = new float[]{-13f,13f,-11f,-5f,13f,-7f};
        X[5] = new float[]{-18f,9f,-18f,13f,-3f,4f};

        float[][][] x0 = new float[1][][];
        x0[0]=X;

        LayerReLU layerReLU = new LayerReLU();

        layerReLU.setX( x0 );
        float[][][] Z = layerReLU.Forward();
        float[][][] OUT = layerReLU.Backward( Z );

        //Assertions.assertTrue( Z[0][0][0] - 22f < 0.0001f );
        //Assertions.assertTrue( Z[0][2][2] - 13f < 0.0001f );
        //Assertions.assertTrue( Z[0][0][1] - 23f < 0.0001f );
        //Assertions.assertTrue( Z[0][0][2] - 11f < 0.0001f );


        System.out.println(Tools.AryToString( X ));
        System.out.println(Tools.AryToString( layerReLU.dX ));
        System.out.println(Tools.AryToString( Z ));
        System.out.println(Tools.AryToString( OUT ));



    }




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

        LayerPoolingMax layerPoolingMax = new LayerPoolingMax(2, 2);

        float[][][] Z = layerPoolingMax.Forward( x0 );
        float[][][] OUT = layerPoolingMax.Backward( Z );

        Assertions.assertTrue( Z[0][0][0] - 22f < 0.0001f );
        Assertions.assertTrue( Z[0][2][2] - 13f < 0.0001f );
        Assertions.assertTrue( Z[0][0][1] - 23f < 0.0001f );
        Assertions.assertTrue( Z[0][0][2] - 11f < 0.0001f );

        //System.out.println(Tools.AryToString( OUT ));
        //System.out.println(Tools.AryToString( layerPoolingMax.dX ));
        //System.out.println(Tools.AryToString( Z ));
    }
}
