package pl.heinzelman.neu;

import java.util.Arrays;

public class Neuron {
    private final float[] W;
    private final Layer parent;
    private final static float mu=0.1f;

    public Neuron( int m, Layer parent ) {
        this.parent=parent;
        this.W = new float[m];
    }

    public void setWm( int m, float wji ){
        W[m] = wji;         //
    }

    public float Forward( float[] X ) {
        float res=0;
        for ( int m=0; m<W.length; m++ ) {
            res+= X[m]*W[m];
        }
        return res;
    }

    public void Backward( float en_x_dFIznI ) {
        // weights
        for ( int m=0; m<W.length; m++ ) {
            W[m] += mu * en_x_dFIznI * parent.getX()[m];
            parent.getEout()[m] += ( W[m] * en_x_dFIznI );
        }
    }



    @Override
    public String toString() {
        return "N{ W=" + Arrays.toString(W) + '}';
    }
}
