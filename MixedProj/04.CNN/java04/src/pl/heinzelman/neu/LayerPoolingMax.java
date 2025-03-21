package pl.heinzelman.neu;

import pl.heinzelman.tools.Tools;

import java.util.Random;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

public class LayerPoolingMax {

    private String name;

    private int size;
    private float X[][][];
    private float Y[][][];
    private float Z[][];

    private float [][][] dLdX;

    private float [][][] dX;

    public LayerPoolingMax( int size ) {
        this.size = size;
    }

    public void setName( String _name ) {
        this.name = _name;
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
        dX = new float[_x.length ][_x[0].length][_x[0].length];
        dLdX = new float[_x.length ][_x[0].length][_x[0].length];
    }


    public float[][][] nForward() {
        int s= (int)Math.floor( X[0].length / size );
        float Y[][][] = new float[ X.length ][ s ][ s ];
            for ( int xlen=0;xlen<X.length; xlen++ ){
                for ( int i=0;i<s;i++ ) {
                    for ( int j=0;j<s;j++ ) {
                        Y[xlen][i][j]=max( X[xlen], i*s, j*s,  xlen  );
                    }
                }
            }
        return Y;
    }


    private float max( float[][]X, int start_i, int start_j,  int xlen  ){
        int maxi=0;
        int maxj=0;
        float max=X[start_i][start_j];
        for ( int i=start_i; i <start_i+size; i++ ){
            for ( int j=start_j; j<start_j+size; j++ ){
                if ( max<X[i][j] ) { max=X[i][j]; maxi=i; maxj=j; }
                dLdX[xlen][i][j]=0;
            }
        }
        dLdX[xlen][maxi][maxj]=1;
        return max;
    }


    public void nBackward( float[][][] _dLdO ){ // delta [--x-- ][][]
        float[][][] dLdX = new float[dX.length][ dX[0].length][dX[0].length];
        for (int num=0;num< dX.length;num++){
            for ( int i=0;i<dX[0].length; i++ ) {
                for ( int j=0;j<dX[0].length; j++){
                    dLdX[num][i][j] = dX[num][i][j] * _dLdO[num][ (int)Math.floor(i/size) ][ (int)Math.floor( j/size ) ];
                }
            }
        }
    }

    public float[][][] getEout() { return dLdX; }

}
