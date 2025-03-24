package pl.heinzelman.LayerDeep;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

import pl.heinzelman.tools.Tools;

public class LayerPoolingAvg extends LayerDeep{

    private float DX;

    public LayerPoolingAvg( int filterSize, Integer stride ) {
        super(filterSize, 1, 0, stride);
        DX = 1.0f/(filterSize*filterSize);
    }

    //public LayerPoolingAvg(int filterSize, Integer filterNum, Integer padding, Integer stride) {
    //    super(filterSize, 1, padding, stride);
    //    DX = 1.0f/(filterSize*filterSize);
    //}

    private float [][][] dLdX; // outout dL/dx * dx

    private float dX; // inner derivate...

    public void calcLayerPoolingAvg( int size ) {
        this.filterSize = size;
    }

    @Override
    protected float[][] flatForward( int fnum, int channel ) {
        System.out.println( DX );
        float[][] x = X[channel];
        int ySize = getYSize();
        float[][] Y = new float[ySize][ySize];
        for (int i=0;i<ySize;i++){
            for (int j=0;j<ySize;j++) {
                // sum 1 block
                float sum=0.0f;
                for (int m=0;m<filterSize;m++){
                    for (int n=0;n<filterSize;n++) {
                        sum+=x[i*filterSize+m][j*filterSize+n];
                    }
                }
                Y[i][j] = (sum*DX);
            }
        }
        return Y;
    }

    @Override
    protected float[][] flatBackward(float[][] dLdO, int fnum, int channel) {
        return new float[0][];
    }

    /*
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
    */


    /*
    public float[][][] nBackward( float[][][] _dLdO ){ // delta [--x-- ][][]
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
        return dLdX;
    }
    */


}
