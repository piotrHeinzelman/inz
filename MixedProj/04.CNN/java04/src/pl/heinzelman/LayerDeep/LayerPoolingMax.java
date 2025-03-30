package pl.heinzelman.LayerDeep;

import java.util.Random;

public class LayerPoolingMax {

    protected String name;

    protected float[][][] X;
    protected float[][][] dX;
    protected float[][][] Y;
    protected int filterSize;
    protected int stride;

    protected int channels;
    protected int xsize;
    protected int ysize;



    public LayerPoolingMax(int filterSize, Integer stride ) {
        this.filterSize = filterSize;
        this.stride = (stride==null) ? 1 : stride;
    }

    public int getYSize(){
        return 1+(( xsize-filterSize )/stride);
    }

    protected void initAry(){
        X  = new float[ channels ][ xsize ][ xsize ];
        dX = new float[ channels ][ xsize ][ xsize ];
    }

    public void setX(float[][][] _x ) {
        this.channels= _x.length;
        this.xsize=_x[0].length;
        this.ysize = getYSize();
        initAry();

        for (int n = 0; n < channels; n++) {
            for (int i = 0; i < xsize; i++) {
                for (int j = 0; j < xsize; j++) {
                    X[n][i][j] = _x[n][i][j];
                }
            }
        }
    }

    public void setName( String name ) { this.name = name; }

    public float[][][] Forward () {
        float[][][] Z = new float[channels][ysize][ysize];
            for (int c=0;c<channels;c++){
                Z[c] = forwardChannel( c );
            }
        return Z;
    }

    public float[][] forwardChannel ( int channel ) {
        float[][] Z = new float[ysize][ysize];
            for (int i=0;i<ysize;i++){
                for (int j=0;j<ysize;j++) {

                    // MAX
                    // --- max --- X[i][j] : X[i+size][j+size]
                    float max = X[channel][i*stride][j*stride];
                    int maxx = 0;
                    int maxy = 0;
                    for (int x=0;x<filterSize;x++){
                        for (int y=0;y<filterSize;y++) {
                            dX[channel][i*stride][j*stride]=0.0f;
                            if ( max<X[channel][i*stride+x][j*stride+y] ) { max=X[channel][i*stride+x][j*stride+y]; maxx=x; maxy=y; }
                        }
                    }
                    dX[channel][i*stride+maxx][j*stride+maxy]=1.0f;
                    Z[i][j]=max;
                    // ***  ENC
                }
            }
        return Z;
    }




    /*

    protected float[][] flatBackward(float[][] dLdO, int fnum, int channel) {
            int dlSize = dLdO.length;
            float[][] delta_i = new float[dlSize*filterSize][dlSize*filterSize];
            for (int i=0;i<dlSize;i++){
                for (int j=0;j<dlSize;j++) {

                    // sum 1 block
                    for (int m=0;m<filterSize;m++){
                        for (int n=0;n<filterSize;n++) {
                            delta_i[i*filterSize+m][j*filterSize+n] = dLdO[i][j] * dX[channel][i*filterSize+m][j*filterSize+n] ;
                        }
                    }
                }
            }
            return delta_i;
    }

    */

}
