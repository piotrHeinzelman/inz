package pl.heinzelman.neu;

import org.junit.Test;
import org.junit.jupiter.api.Disabled;
import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerPoolingAvg;
import pl.heinzelman.tools.Tools;

public class LayerTest91_CNN_test {
    @Test
    public void forwardTest(){

        Tools tools = new Tools();

        LayerConv LCNN1 = new LayerConv( 2, 1, null, null ); // 3x3 1 filter
        LCNN1.setName( "CNN 01" );

        float[][][] X = new float[1][5][5]; // x1, x2, x3, x4, x[0] = {1,2}
        X[0][0] = new float[]{  1, 2, 3, 4, 5 };
        X[0][1] = new float[]{  6, 7, 8, 9,10 };
        X[0][2] = new float[]{ 11,12,13,14,15 };
        X[0][3] = new float[]{ 16,17,18,19,20 };
        X[0][4] = new float[]{ 21,22,23,24,25 };

        LCNN1.setX( X );

        float[][][] Z = LCNN1.Forward();
        System.out.println(  LCNN1 );

        float[][][] eOUT = LCNN1.Backward(Z);
        System.out.println( Tools.AryToString( X ) );
        System.out.println( Tools.AryToString( Z ) );
        System.out.println( Tools.AryToString( eOUT ));
        System.out.println( LCNN1  );
    }


    @Test
    public void X3_F3_forward_conv(){
        float[][] x0= new float[1][1];
                  x0[0][0] = 1;

        float[][] x1= new float[1][1];
        x1[0][0] = 2;

        float[][] x2= new float[1][1];
        x2[0][0] = 3;

        float[][][]allX = new float[3][1][1]; // numbers, size, size
        allX[0]=x0;
        allX[1]=x1;
        allX[2]=x2;

        LayerConv layerConv = new LayerConv( 1, 3, null, null );
                  layerConv.setX( allX );

        //          layerConv.getNeuron(0 ).setWm(0,0,5.0f );
        //          layerConv.getNeuron(1 ).setWm(0,0,10.0f );
        //          layerConv.getNeuron(2 ).setWm(0,0,20.0f );

        float[][][] out = layerConv.Forward();

        System.out.println( layerConv.toString() );
        System.out.println(  Tools.AryToString( out ));

        System.out.println( layerConv.toString() );

    }

    @Test
    public void X3_F3_forward_maxPool(){
        float[][][] X = new float[3][4][4]; // x1, x2, x3, x4, x[0] = {1,2}
        X[0][0] = new float[]{  1, 2, 3, 4 };
        X[0][1] = new float[]{  5, 6, 7, 8 };
        X[0][2] = new float[]{  9,10,11,12 };
        X[0][3] = new float[]{ 13,14,15,16 };

        X[1][0] = new float[]{  21,22,23,24 };
        X[1][1] = new float[]{  25,26,27,28 };
        X[1][2] = new float[]{  29,20,21,22 };
        X[1][3] = new float[]{  23,24,25,26 };

        X[2][0] = new float[]{  51,52,53,54 };
        X[2][1] = new float[]{  55,56,57,58 };
        X[2][2] = new float[]{  59,50,51,52 };
        X[2][3] = new float[]{  53,54,55,56 };


        LayerPoolingAvg poolingMax = new LayerPoolingAvg( 2, 2 );
        poolingMax.setX( X );
        System.out.println( "X: " + Tools.AryToString( X ));

        float[][][] out = poolingMax.Forward();
        System.out.println( "Y: " + Tools.AryToString( out ));

        float[][][] eOUT = poolingMax.Backward(out);

        System.out.println( "E out:" + Tools.AryToString( eOUT ));

    }


}