package pl.heinzelman.LayerDeep;

import org.junit.jupiter.api.Test;
import pl.heinzelman.tools.Tools;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class LayerFlattenTest {

    private float[][][] X = new float[3][3][3];
    private void prepareX(){
        X[0][0] = new float[]{1f,2f,3f};
        X[0][1] = new float[]{4f,5f,6f};
        X[0][2] = new float[]{7f,8f,9f};

        X[1][0] = new float[]{10f,11f,12f};
        X[1][1] = new float[]{13f,14f,15f};
        X[1][2] = new float[]{16f,17f,18f};

        X[2][0] = new float[]{19f,20f,21f};
        X[2][1] = new float[]{22f,23f,24f};
        X[2][2] = new float[]{25f,26f,27f};
    }


    @Test
    void forward() {
        prepareX();
        System.out.println( "X: "+Tools.AryToString( X ) );
        LayerFlatten layerFlatten = new LayerFlatten();

        float[] Z = layerFlatten.Forward(X);
        System.out.println("Forward: "+Arrays.toString(Z));

        float[][][] backward = layerFlatten.Backward(Z);
        System.out.println( "Backward: "+Tools.AryToString(  backward ) );

    }

    @Test
    void backward() {
    }
}