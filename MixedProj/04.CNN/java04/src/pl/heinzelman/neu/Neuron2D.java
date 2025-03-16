package pl.heinzelman.neu;

import pl.heinzelman.tools.Tools;

import java.util.Arrays;
import java.util.Random;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

public class Neuron2D {

private float bias=0f;
private float[][] W;
private final LayerConv parent;
private final static float mu=0.001f;

public void setBias( float b ) { this.bias=b; }
public float getBias(){ return bias; }

public Neuron2D( int m, LayerConv parent ) {
        this.parent=parent;
        this.W = new float[m][m];
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

    public void Backward( float[][][] dL_dO_delta ) { // dL/dO = delta


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


    public void rnd( Random rand ){
        this.bias = rand.nextFloat();
        for ( int i=0;i< W.length; i++){
            for (int j=0;j<W[0].length; j++){
                W[i][j]= rand.nextFloat();
            }
        }
    }

    public void fix( float [][] dLdF ){
        for ( int i=0;i< W.length; i++){
            for (int j=0;j<W[0].length; j++){
                W[i][j]= W[i][j] - (mu * dLdF[i][j]);
            }
        }
    }

    public float[][] getRot180(){
        float[][] Rot180 = new float[ W.length ][ W.length ];
        for (int i=0;i<W.length;i++){
            for (int j=0;j<W.length;j++){
                Rot180[W.length-i-1][W.length-j-1] = W[i][j];
            }
        }
        return Rot180;
    }

}
