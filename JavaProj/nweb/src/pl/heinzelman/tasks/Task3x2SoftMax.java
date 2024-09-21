package pl.heinzelman.tasks;

import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;

import java.util.Arrays;

public class Task3x2SoftMax implements Task{


    @Override
    public void prepare() {
        // NOP
    }

    @Override
    public void run() {

        Layer layer1=new Layer( LType.sigmod , 3 ,2 );
        layer1.setName( "Layer: 1" );

        // first neu
        layer1.setWmn( 0, 0, 1 );
        layer1.setWmn( 0, 1, -1 );

        // secont neu
        layer1.setWmn( 1, 0, 1 );
        layer1.setWmn( 1, 1, 1 );

        // third neu
        layer1.setWmn( 2, 0, -1 );
        layer1.setWmn( 2, 1, 1 );

//System.out.println( layer1 );


        float[] firstX = new float[]{1,2};
//System.out.println( firstX[0] + ","+firstX[1] );

        layer1.setX( firstX );
//System.out.println( layer1 );

        layer1.nForward();
//System.out.println( layer1 );

        float[] XforL2 = layer1.getZ();
//System.out.println(  Arrays.toString( XforL2 ) );

//System.out.println(  "Lay1 : Z = " + Arrays.toString( layer1.getZ() ) );





        // 3*neu / 2*weight
        Layer layer2 = new Layer( LType.softmax , 2 ,3  );
        layer2.setName( "Layer: 2" );
        // first neu
        layer2.setWmn( 0, 0,  1 );
        layer2.setWmn( 0, 1, -1 );
        layer2.setWmn( 0, 2,  1 );

        layer2.setWmn( 1, 0,  -1 );
        layer2.setWmn( 1, 1,   1 );
        layer2.setWmn( 1, 2,  -1 );


        layer2.setX( XforL2 );
System.out.println( "XforL2"+XforL2 );
        layer2.nForward();


//System.out.println( layer2 );





        float[] z = layer2.getZ();
        float[] s = new float[]{1,0};

System.out.println( "z:" + Arrays.toString( z ));
System.out.println( "s:" + Arrays.toString( s ));

        float[] e = new float[z.length];
        for ( int i=0;i<z.length;i++ ){
            e[i]=s[i]-z[i];
        }
        //System.out.println( "e: " + Arrays.toString( e ) );
        layer2.nBackward( e );
        //if (true) return;
        // E ok e *. (1-z) * z

        //System.out.println(layer2);

        float[] eOut=layer2.getEout();
        layer1.nBackward( eOut );
System.out.println( "eOut (L2):" + Arrays.toString( eOut ));
System.out.println( layer1 );
System.out.println( layer2 );
    }
}
