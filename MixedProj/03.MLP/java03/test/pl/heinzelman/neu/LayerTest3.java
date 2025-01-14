package pl.heinzelman.neu;


import org.junit.Test;
import pl.heinzelman.tools.Tools;

public class LayerTest3 {
    @Test
    public void forwardTest(){

        Tools tools = new Tools();

        Layer L1 = new Layer(LType.sigmod, 3,2); // 3 neurons, 2 inputs
        float[] X = new float[]{1,2};
        float[] S = new float[]{1,0};


        L1.setWmn(0,0,1.0f ); // neu 0 , inp 0
        L1.setWmn(0,1,-1.0f ); // neu 0 , inp 1

        L1.setWmn(1,0,1.0f ); // neu 1 , inp 0
        L1.setWmn(1,1,1.0f ); // neu 1 , inp 1

        L1.setWmn(2,0,-1.0f ); // neu 2 , inp 0
        L1.setWmn(2,1,1.0f ); // neu 2 , inp 1

        L1.setName("Layer1");
        L1.setX( X );

        L1.nForward();
        System.out.println( L1 );

        float[] Z1=L1.getZ();
        System.out.println( "Z1: "+ tools.toStr( Z1 ));

        Layer L2 = new Layer(LType.softmax , 2, 3 ); // 2 neurons, 3 inputs
        L2.setWmn( 0,0, 1.0f);
        L2.setWmn( 0,1, -1.0f);
        L2.setWmn( 0,2, 1.0f);

        L2.setWmn( 1,0, -1.0f);
        L2.setWmn( 1,1, 1.0f);
        L2.setWmn( 1,2, -1.0f);

        L2.setName("Layer2");
        L2.setX( Z1 );
        L2.nForward();
        float[] Z2 =  L2.getZ();


        System.out.println( "Z: " + tools.toStr( Z2 ) );
        System.out.println( "S: " + tools.toStr( S ) );

        float[] S_Z = tools.vectorSubstSsubZ( S , Z2 );
        System.out.println( "S-Z: " + tools.toStr( S_Z ) );
        L2.nBackward( S_Z  );
        float[] eout = L2.getEout();
        System.out.println( "eout: " + tools.toStr( eout ) );
        System.out.println( L2 );

        L1.nBackward( eout );
        System.out.println( L1 );

    }
}