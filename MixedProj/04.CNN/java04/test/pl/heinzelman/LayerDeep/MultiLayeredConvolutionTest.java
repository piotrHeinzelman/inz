package pl.heinzelman.LayerDeep;

import org.junit.Test;
import pl.heinzelman.tools.Conv;
import pl.heinzelman.tools.Tools;

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


    @Test
    public void show(){
        System.out.println(Tools.AryToString( createInputData() ));
    }

}
