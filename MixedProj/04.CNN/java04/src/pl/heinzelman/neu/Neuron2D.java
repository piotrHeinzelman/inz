package pl.heinzelman.neu;

import pl.heinzelman.tools.Tools;

import java.util.Arrays;

public class Neuron2D {

private float bias=0f;
private float[][] W;
private final LayerConv parent;
private final static float mu=0.001f;

public void setBias( float b ) { this.bias=b; }
public float getBias(){ return bias; }

public Neuron2D( int m, LayerConv parent ) {
        this.parent=parent;
        for ( int i=0; i<m ; i++ ) {
            this.W[i] = new float[m];
        }
    }


    public void setWm( int i, int j, float wij ){
        W[i][j] = wij;
    }

    public float[][] Forward( float[][] X ) {
        float res=bias;

        //convolution
        return Tools.conv( X, W , bias, 1 );
    }

    public void Backward( float en_x_dFIznI ) {
        // weights
//        float[] X = parent.getX();
//        for ( int m=0; m<W.length; m++ ) {
//            parent.getEout()[m] += ( W[m] * en_x_dFIznI );
//            W[m] += mu * en_x_dFIznI * X[m];
//        }
    }


    @Override
    public String toString() {
        return "N{ W=" + Arrays.toString(W) + '}';
    }

    //@Deprecated
    public float[][] getMyWeight() { return W; }

}
