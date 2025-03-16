package pl.heinzelman.neu;

import pl.heinzelman.tools.Tools;

import javax.tools.Tool;
import java.util.Random;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

public class LayerConv {

    private String name;
    private Neuron2D[] filters;
    private float X[][][];
    private float Y[][][];
    private float Z[][];

    private float [][][] dLdX;

    public LayerConv(int filterSize, int filterNum) {
        this.filters = new Neuron2D[filterNum];
        for (int i = 0; i < filterNum; i++) {
            this.filters[i] = new Neuron2D(filterSize, this);
        }
    }

    public void rnd() {
        Random rand = new Random();
        for (int i = 0; i < filters.length; i++) {
            filters[i].rnd(rand);
        }
    }

    public void setName( String _name ) {
        this.name = _name;
    }

    public String toString() {
        StringBuffer out = new StringBuffer("\n" + name + "\n");
        for (int i = 0; i < filters.length; i++) {
            out.append( Tools.AryToString(filters[i].getMyWeight()) );
        }
        return out.toString();
    }


    public void setX(float[][][] _x) {
        this.X = new float[_x.length][_x[0].length][_x[0].length];
        for (int n = 0; n < _x.length; n++) {
            for (int i = 0; i < _x[0].length; i++) {
                for (int j = 0; j < _x[0].length; j++) {
                    X[n][i][j] = _x[n][i][j];
                }
            }
        }
    }


    public float[][][] nForward() {
        float Y[][][] = new float[ filters.length * X.length ][ X[0].length ][ X[0].length ];
        for ( int xlen=0;xlen<X.length; xlen++ ){
            for ( int flen=0; flen< filters.length; flen++ ){
                Y[ xlen*filters.length + flen ] = filters[flen].Forward( X[xlen] );
            }
        }
        return Y;
    }


    public void nBackward( float[][][] _dLdO ){ // delta [--x-- ][][]
                                                //       [f0f1f2][][]
                                                // !!!! _dLdO is size of nForward out. !!!!
        int padd = (_dLdO[0].length-1)/2;

        this.dLdX = new float[ _dLdO.length ][][];
        for ( int xlen=0;xlen<X.length; xlen++ ){
            for ( int flen=0; flen< filters.length; flen++ ){

                float[][] _dLdO_ =  _dLdO[xlen * filters.length + flen];


                float[][] dLdF = Tools.conv(X[xlen], _dLdO_, 0);
                filters[flen].fix( dLdF ); // update Weigth

                float [][] _dLdX_ = Tools.conv( Tools.extendAry( filters[flen].getRot180() , padd )  , _dLdO_ , 0);
                this.dLdX[ xlen * filters.length + flen ] = _dLdX_;
            }
        }
    }

    public float[][][] getEout() { return dLdX; }

}
