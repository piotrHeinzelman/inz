package pl.heinzelman.LayerDeep;

import pl.heinzelman.tools.Conv;
import pl.heinzelman.tools.Tools;

import java.util.Arrays;
import java.util.Random;

// https://pavisj.medium.com/convolutions-and-backpropagations-46026a8f5d2c
//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

public class Neuron2D {
private int m;
private float bias=0f;
private float[][] W;
private final LayerDeep parent;
private final static float mu=0.01f;

public void setBias( float b ) { this.bias=b; }
public float getBias(){ return bias; }

public Neuron2D( int m, LayerDeep parent ) {
        this.parent=parent;
        this.m=m;
        this.W = new float[m][m];
        for ( int i=0; i<m ; i++ ) {
            this.W[i] = new float[m];
        }
    }


    public void setWm( int i, int j, float wij ){
        W[i][j] = wij;
    }

    public float[][] Forward( float[][] X ) {
        //convolution
        return Conv.conv( X, W, bias, 1 );
    }


    @Override
    public String toString() {
        return "N{ W=" + Tools.AryToString(W) + '}';
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

    public void trainW(float [][] dLdF ){
        int m=W.length;
        for ( int i=0;i<m; i++ ){
            for ( int j=0;j<m; j++ ){
                W[i][j]= W[i][j] - (mu * dLdF[i][j]);
            }
        }
    }

    public void trainB(float dB ){
        bias = bias - (mu * dB);
    }

    public float[][] getRot180(){
        float[][] Rot180 = new float[ m ][ m ];
            for (int i=0;i<m;i++){
                for (int j=0;j<m;j++){
                    Rot180[m-i-1][m-j-1] = W[i][j];
            }
        }
    return Rot180;
    }

}
