package pl.heinzelman.LayerDeep;

import org.junit.Test;
import pl.heinzelman.tools.Tools;

import java.util.Arrays;

public class CNN_test {


    @Test
    public void BackConvolutionTest2() {
        Tools tools = new Tools();
        tools.prepareDataAsFlatArray( 1 );

        float[][][] testX = tools.getTestAryX();
        float[][] testY = tools.getTestY();
        float[][][] trainX = tools.getTrainAryX();
        float[][] trainY = tools.getTrainY();

        /*
    private LayerConv layer1Conv = new LayerConv( 5 , 20 , null, null );
    private LayerReLU layer2ReLU = new LayerReLU();
    private LayerPoolingMax layer3PoolingMax = new LayerPoolingMax(2, 2);
    private LayerFlatten layer4Flatten = new LayerFlatten();
         */

        float[][][] oneX = new float[1][][];
        oneX[0] = trainX[0]; // extract One X
        LayerConv layer1Conv = new LayerConv( 5 , 1 , null, null );
        layer1Conv.setUpByX( oneX );
        layer1Conv.setX( oneX );
        float[][][] layer2X = layer1Conv.Forward();

//        tools.saveVectorAsImg( layer2X[0], "C:\\Users\\PiotrH\\Desktop\\pict\\X" );
//        tools.saveVectorAsImg( layer1Conv.getNeuron(0).getMyWeight(), "C:\\Users\\PiotrH\\Desktop\\pict\\F" );

        //System.out.println( Tools.AryToString(  layer2X ) );

        LayerReLU layer2ReLU = new LayerReLU();
                  layer2ReLU.setX( layer2X );
        float[][][] layer3x = layer2ReLU.Forward();
//        tools.saveVectorAsImg( layer3x[0], "C:\\Users\\PiotrH\\Desktop\\pict\\Y01" );


        LayerPoolingMax layer3PoolingMax = new LayerPoolingMax(2,2);
        layer3PoolingMax.setX( layer3x );
        float[][][] layer4x = layer3PoolingMax.Forward();

//        tools.saveVectorAsImg( layer4x[0], "C:\\Users\\PiotrH\\Desktop\\pict\\Y02" );

        LayerFlatten layer4Flatten = new LayerFlatten();
        float[] layer5x = layer4Flatten.Forward(layer4x);

        System.out.println(Arrays.toString( layer5x ));
        System.out.println(layer5x.length);

        float[][] flat5X=new float [4][layer5x.length];
        flat5X[0]=layer5x;
        tools.saveVectorAsImg( flat5X, "C:\\Users\\PiotrH\\Desktop\\pict\\Y03" );

        /*
        float[] FLAT = layer4Flatten.Forward(layer3PoolingMax.Forward());
        //System.out.println( FLAT.length);
        layer10.setX( FLAT );
        layer10.nForward();
        layer11.setX( layer10.getZ() );
        layer11.nForward();
        layer12.setX( layer11.getZ() );
        layer12.nForward();
        return layer12.getZ();
        */



    }
}
