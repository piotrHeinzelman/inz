package pl.heinzelman.neu;

import org.junit.jupiter.api.Test;
import pl.heinzelman.LayerDeep.Neuron2D;
import pl.heinzelman.tools.Conv;
import pl.heinzelman.tools.Tools;

public class convTest {

    private Tools tools;
    float bias=0.1f;

    @Test
    public void paddingTest (){
        float[][] X = new float[3][];
        X[0]=new float[]{0f,1f,2f};
        X[1]=new float[]{3f,4f,5f};
        X[2]=new float[]{6f,7f,8f};

        System.out.println( Tools.AryToString( X ) );

        for (int i=0;i<4;i++) {
            float[][] extendX = Conv.extendAry(X, i);
            System.out.println( "\n\nI="+i );
            System.out.println( Tools.AryToString( extendX ) );
        }

        float[][] F = new float[2][];
        F[0]=new float[]{1f,2f};
        F[1]=new float[]{3f,4f};

        System.out.println( "\nFilter:" + Tools.AryToString( F ) );

        float B = .1f;

        float [][] Y = Conv.conv( X, F, 0 );

        System.out.println( "\nConv:" + Tools.AryToString( Y ) );

    }




    @Test
    public void paddingTest2 (){
        float[][] X = new float[5][];
        X[0]=new float[]{00f,01f,02f,03f,04f};
        X[1]=new float[]{05f,06f,07f,08f,09f};
        X[2]=new float[]{10f,11f,12f,13f,14f};
        X[3]=new float[]{15f,16f,17f,18f,19f};
        X[4]=new float[]{20f,21f,22f,23f,24f};

        X=Conv.extendAry( X,1 );

        System.out.println( Tools.AryToString( X ) );


        float[][] F = new float[2][];
        F[0]=new float[]{1f,2f};
        F[1]=new float[]{3f,4f};

        System.out.println( "\nFilter:" + Tools.AryToString( F ) );

        float B =  .2f;

        float [][] Y = Conv.conv( X, F, B, 2 );

        System.out.println( "\nConv:" + Tools.AryToString( Y ) );

    }


    @Test
    public void paddingTest3 (){

        Neuron2D neu =  new Neuron2D( 3 , null );
        neu.setWm(0,0, 1);
        neu.setWm(0,1, 2);
        neu.setWm(0,2, 3);

        neu.setWm(1,0, 4);
        neu.setWm(1,1, 5);
        neu.setWm(1,2, 6);

        neu.setWm(2,0, 7);
        neu.setWm(2,1, 8);
        neu.setWm(2,2, 9);

        System.out.println( Tools.AryToString(  neu.getMyWeight() ));

        System.out.println( Tools.AryToString(  neu.getRot180() ));

        //public float[][] getRot180();
    }

}
