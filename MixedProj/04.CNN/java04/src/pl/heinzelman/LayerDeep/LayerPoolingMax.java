package pl.heinzelman.LayerDeep;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

public class LayerPoolingMax {

    private String name;

    private int size;
    private float X[][][];

    private float [][][] dLdX; // outout dL/dx * dx

    private float [][][] dX; // inner derivate...

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
        int s = (int) Math.floor( X[0].length / size );
        float Y[][][] = new float[ X.length ][ s ][ s ];
            for ( int xlen=0;xlen<X.length; xlen++ ){
                for ( int i=0;i<s;i++ ) {
                    for ( int j=0;j<s;j++ ) {

                        // --- max --- X[i][j] : X[i+size][j+size]
                        float max=X[xlen][i*size][j*size];
                        int maxx = 0;
                        int maxy = 0;
                        for (int x=0;x<size;x++){
                            for (int y=0;y<size;y++) {
                                dX[xlen][i*size][j*size]=0.0f;
                                if ( max<X[xlen][i*size+x][j*size+y] ) { max=X[xlen][i*size+x][j*size+y]; maxx=x; maxy=y; }
                            }
                        }
                        dX[xlen][i*size+maxx][j*size+maxy]=1.0f;
                        Y[xlen][i][j]=max;
                        // --- end of max
                    }
                }
            }
        return Y;
    }




    public void nBackward( float[][][] _dLdO ){ // delta [--x-- ][][]
        dLdX = new float[dX.length][ dX[0].length][dX[0].length];
        int s=dX[0].length/size;

        for (int num=0;num< dX.length;num++){
            for ( int i=0;i<s; i++ ) {
                for ( int j=0;j<s; j++){

                    for (int x=0;x<size;x++) {
                        for (int y=0;y<size;y++) {
                            //System.out.println( "[x + i*size][y +j*size] [" + x +"+"+ i + "*" +size+"]["+y+"+"+j+"*"+size+"]");
                            dLdX[num][x + i*size][y +j*size] = dX[num][x + i*size][y + j*size] * _dLdO[num][i][j];
                        }
                    }
                }
            }
        }
    }


    public float[][][] getEout() { return dLdX; }


}
