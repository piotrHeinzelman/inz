package pl.heinzelman.LayerDeep;

import org.junit.Assert;
import org.junit.Test;
import pl.heinzelman.tools.Conv;
import pl.heinzelman.tools.Tools;

import javax.tools.Tool;

public class MultiLayeredConvolutionTest {


    public float[][][] createInputData() {
        float[][][] input = new float[3][][]; // 3 channel

        float[][] inputCh1 = new float[5][];
        inputCh1[0] = new float[]{0.f, 0.f, 1.f, 0.f, 2.f}; // size 5.5
        inputCh1[1] = new float[]{1.f, 0.f, 2.f, 0.f, 1.f}; // size 5.5
        inputCh1[2] = new float[]{1.f, 0.f, 2.f, 2.f, 0.f}; // size 5.5
        inputCh1[3] = new float[]{2.f, 0.f, 0.f, 2.f, 0.f}; // size 5.5
        inputCh1[4] = new float[]{2.f, 1.f, 2.f, 2.f, 0.f}; // size 5.5

        float[][] inputCh2 = new float[5][];
        inputCh2[0] = new float[]{2.f, 1.f, 2.f, 1.f, 1.f}; // size 5.5
        inputCh2[1] = new float[]{2.f, 1.f, 2.f, 0.f, 1.f}; // size 5.5
        inputCh2[2] = new float[]{0.f, 2.f, 1.f, 0.f, 1.f}; // size 5.5
        inputCh2[3] = new float[]{1.f, 2.f, 2.f, 2.f, 2.f}; // size 5.5
        inputCh2[4] = new float[]{0.f, 1.f, 2.f, 0.f, 1.f}; // size 5.5

        float[][] inputCh3 = new float[5][];
        inputCh3[0] = new float[]{2.f, 1.f, 1.f, 2.f, 0.f}; // size 5.5
        inputCh3[1] = new float[]{1.f, 0.f, 0.f, 1.f, 0.f}; // size 5.5
        inputCh3[2] = new float[]{0.f, 1.f, 0.f, 0.f, 0.f}; // size 5.5
        inputCh3[3] = new float[]{1.f, 0.f, 2.f, 1.f, 0.f}; // size 5.5
        inputCh3[4] = new float[]{2.f, 2.f, 1.f, 1.f, 1.f}; // size 5.5

        input[0] = Conv.extendAry( inputCh1, 1 );
        input[1] = Conv.extendAry( inputCh2, 1 );
        input[2] = Conv.extendAry( inputCh3, 1 );
        return input;
    }


    public Neuron2D[] createFilters() {
        Neuron2D filterW11 = new Neuron2D(3, null );
        filterW11.setWm(0,0,-1); //y,x
        filterW11.setWm(0,1,0);
        filterW11.setWm(0,2,1);

        filterW11.setWm(1,0,0); //y,x
        filterW11.setWm(1,1,0);
        filterW11.setWm(1,2,1);

        filterW11.setWm(2,0,1); //y,x
        filterW11.setWm(2,1,-1);
        filterW11.setWm(2,2,1);

        filterW11.setBias( 1f );


        Neuron2D filterW12 = new Neuron2D(3, null );  // 1 filter, 2 channel
        filterW12.setWm(0,0,-1); //y,x
        filterW12.setWm(0,1,0);
        filterW12.setWm(0,2,1);

        filterW12.setWm(1,0,1); //y,x
        filterW12.setWm(1,1,-1);
        filterW12.setWm(1,2,1);

        filterW12.setWm(2,0,0); //y,x
        filterW12.setWm(2,1,1);
        filterW12.setWm(2,2,0);


        Neuron2D filterW13 = new Neuron2D(3, null );  // 1 filter, 2 channel
        filterW13.setWm(0,0,-1); //y,x
        filterW13.setWm(0,1,1);
        filterW13.setWm(0,2,1);

        filterW13.setWm(1,0,1); //y,x
        filterW13.setWm(1,1,1);
        filterW13.setWm(1,2,0);

        filterW13.setWm(2,0,0); //y,x
        filterW13.setWm(2,1,-1);
        filterW13.setWm(2,2,0);

// *********** 2

        Neuron2D filterW21 = new Neuron2D(3, null );
        filterW21.setWm(0,0,0); //y,x
        filterW21.setWm(0,1,1);
        filterW21.setWm(0,2,-1);

        filterW21.setWm(1,0,0); //y,x
        filterW21.setWm(1,1,-1);
        filterW21.setWm(1,2,0);

        filterW21.setWm(2,0,0); //y,x
        filterW21.setWm(2,1,-1);
        filterW21.setWm(2,2,1);

        filterW21.setBias( 0f );


        Neuron2D filterW22 = new Neuron2D(3, null );  // 1 filter, 2 channel
        filterW22.setWm(0,0,-1); //y,x
        filterW22.setWm(0,1,0);
        filterW22.setWm(0,2,0);

        filterW22.setWm(1,0,1); //y,x
        filterW22.setWm(1,1,-1);
        filterW22.setWm(1,2,0);

        filterW22.setWm(2,0,1); //y,x
        filterW22.setWm(2,1,-1);
        filterW22.setWm(2,2,0);


        Neuron2D filterW23 = new Neuron2D(3, null );  // 1 filter, 2 channel
        filterW23.setWm(0,0,-1); //y,x
        filterW23.setWm(0,1,1);
        filterW23.setWm(0,2,-1);

        filterW23.setWm(1,0,0); //y,x
        filterW23.setWm(1,1,-1);
        filterW23.setWm(1,2,-1);

        filterW23.setWm(2,0,1); //y,x
        filterW23.setWm(2,1,0);
        filterW23.setWm(2,2,0);

// ************



        Neuron2D[]filters = new Neuron2D[ 2*3 ]; // filterNum, * channelNum
        filters[0*3 + 0]=filterW11;
        filters[0*3 + 1]=filterW12;
        filters[0*3 + 2]=filterW13;
        filters[1*3 + 0]=filterW21;
        filters[1*3 + 1]=filterW22;
        filters[1*3 + 2]=filterW23;
        return filters;
    }

    @Test
    public void show(){

        float[][][] X = createInputData();
        Neuron2D[] filters = createFilters();

        //System.out.println( filters[ filterNum * channels + channelNum ] ); ;

        //System.out.println( filters[ 1*3 + 0 ] );
        //System.out.println( filters[ 1*3 + 1 ] );
        //System.out.println( filters[ 1*3 + 2 ] );

        LayerConv layerConv = new LayerConv(3, 2, null, null);

        layerConv.filters = filters;
        //System.out.println( Tools.AryToString(  layerConv.getNeuron(0).getMyWeight() ));
        layerConv.setX( X );
        float[][][] forward = layerConv.Forward();
        System.out.println( Tools.AryToString( forward ) );

        Assert.assertEquals( forward[0][0][0], 2f );
        Assert.assertEquals( forward[1][0][0], -8f );


    }

}
