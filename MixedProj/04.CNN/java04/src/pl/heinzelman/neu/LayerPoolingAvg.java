package pl.heinzelman.neu;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

public class LayerPoolingAvg {

    private String name;

    private int size;
    private float X[][][];

    private float [][][] dLdX; // outout dL/dx * dx

    private float dX; // inner derivate...

    public LayerPoolingAvg(int size ) {
        this.size = size;
        this.dX = 1.0f/(size*size);
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
        dLdX = new float[_x.length ][_x[0].length][_x[0].length];
    }


    public float[][][] nForward() {
        int s = (int) Math.floor( X[0].length / size );
        float Y[][][] = new float[ X.length ][ s ][ s ];
            for ( int xlen=0;xlen<X.length; xlen++ ){
                for ( int i=0;i<s;i++ ) {
                    for ( int j=0;j<s;j++ ) {

                        // --- max --- X[i][j] : X[i+size][j+size]
                        float sum=0.0f;
                        for (int x=0;x<size;x++){
                            for (int y=0;y<size;y++) {
                                sum+=X[xlen][i*size+x][j*size+y];
                            }
                        }
                        Y[xlen][i][j]=sum*dX;
                        // --- end of sum (AVG)
                    }
                }
            }
        return Y;
    }


    public void nBackward( float[][][] _dLdO ){ // delta [--x-- ][][]
        dLdX = new float[_dLdO.length][ _dLdO[0].length*size][_dLdO[0].length*size];
        int s=_dLdO[0].length;

        for (int num=0;num<_dLdO.length;num++){
            for ( int i=0;i<s; i++ ) {
                for ( int j=0;j<s; j++){

                    for (int x=0;x<size;x++) {
                        for (int y=0;y<size;y++) {
                            dLdX[num][x + i*size][y +j*size] = dX * _dLdO[num][i][j];
                        }
                    }
                }
            }
        }
    }


    public float[][][] getEout() { return dLdX; }


}
