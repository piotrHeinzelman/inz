package pl.heinzelman.neu;

import java.util.Arrays;

public class Neuron {
    private float bias=0;
    private final float[] W;
    private final Layer parent;
    private final static float mu=0.001f;

    public void setBias( float b ) { this.bias=b; }
    public float getBias(){ return bias; }

    public Neuron( int m, Layer parent ) {
        this.parent=parent;
        this.W = new float[m];
    }


    public void setWm( int m, float wji ){
        W[m] = wji;         //
    }

    public float Forward( float[] X ) {
        float res=bias;
        for ( int m=0; m<W.length; m++ ) {
            res+= X[m]*W[m];
        }
        return res;
    }

    public void Backward( float en_x_dFIznI ) {
        // weights
        float[] X = parent.getX();
        for ( int m=0; m<W.length; m++ ) {
            parent.getEout()[m] += ( W[m] * en_x_dFIznI );
            W[m] += mu * en_x_dFIznI * X[m];
        }
    }



    @Override
    public String toString() {
        return "N{ W=" + Arrays.toString(W) + '}';
    }

    //@Deprecated
    public float[] getMyWeight() { return W; }


}
