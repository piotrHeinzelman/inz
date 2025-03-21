package pl.heinzelman.neu;

import pl.heinzelman.tools.Tools;

import java.util.Arrays;
import java.util.Random;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

// X [num][i][j]
// F [num][m][n]
// D [num][x][y]


public class LayerConv {

    private String name;
    private Neuron2D[] filters;
    private float X[][][];

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
                    //System.out.println( "X[n][i][j] = _x["+n+"]["+i+"]["+j+"]" );
                }
            }
        }
    }


    public float[][][] nForward() {
        float Y[][][] = new float[ filters.length * X.length ][ X[0].length ][ X[0].length ];
        for ( int flen=0; flen< filters.length; flen++ ){
            for ( int xlen=0;xlen<X.length; xlen++ ){
                Y[ flen*X.length + xlen ] = filters[flen].Forward( X[xlen] );
            }
        }
        return Y;
    }


    public void nBackward( float[][][] _dLdO ){ // delta [--x-- ][][]
                                                //       [f0f1f2][][]
                                                // !!!! _dLdO is size of nForward out. !!!!
        int padd = (int)(_dLdO[0].length-1.0f/2.0f);

        this.dLdX = new float[ _dLdO.length ][][];
        for ( int flen=0; flen< filters.length; flen++ ){
            for ( int xlen=0;xlen<X.length; xlen++ ){
                float[][] _dLdO_ =  _dLdO[flen*X.length + xlen];

                float[][] dLdF = Tools.conv( X[xlen], _dLdO_, 0);
                filters[flen].trainW( dLdF ); // update Weigth

                float [][] _dLdX_ = Tools.conv( Tools.extendAry( filters[flen].getRot180() , padd )  , _dLdO_ , 0);
                this.dLdX[ flen*X.length + xlen ] = _dLdX_;
            }
        }
    }

    public float[][][] getEout() { return dLdX; }

    Neuron2D getNeuron(int i){
        return filters[i];
    }




}
