package pl.heinzelman.tasks;

import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;
import pl.heinzelman.neu.LossType;

import java.util.Arrays;

public class Task2x3_simple_backward implements Task{


    @Override
    public void prepare() {
        // NOP
    }

    @Override
    public void run() {


        Layer layer1=new Layer( LType.sigmod , 3 ,2 ); layer1.setName("Layer1");

        // first neu
        layer1.setWmn( 0, 0, 1 );
        layer1.setWmn( 0, 1, -1 );

        // secont neu
        layer1.setWmn( 1, 0, 1 );
        layer1.setWmn( 1, 1, 1 );

        // third neu
        layer1.setWmn( 2, 0, -1 );
        layer1.setWmn( 2, 1, 1 );

        float[] firstX = new float[]{1,2};
        layer1.setX( firstX );
        layer1.nForward();

        float[] XforL2 = layer1.getZ();


        // 3*neu / 2*weight
        Layer layer2 = new Layer( LType.sigmod , 2 ,3  );  layer2.setName("Layer2");
        // first neu
        layer2.setWmn( 0, 0,  1 );
        layer2.setWmn( 0, 1, -1 );
        layer2.setWmn( 0, 2,  1 );

        // secont neu
        layer2.setWmn( 1, 0, -1 );
        layer2.setWmn( 1, 1,  1 );
        layer2.setWmn( 1, 2, -1 );

        layer2.setX( XforL2 );
        System.out.println( "XforL2"+XforL2 );
        layer2.nForward();

        float[] s = new float[]{1,0};
        layer2.nBackward( s , LossType.squareError );
        System.out.println( "s: " + Arrays.toString( s ) );

        float[] eOut=layer2.getEout();
        layer1.nBackward( eOut );
        System.out.println( layer1 );
        System.out.println(layer2);
    }
}
