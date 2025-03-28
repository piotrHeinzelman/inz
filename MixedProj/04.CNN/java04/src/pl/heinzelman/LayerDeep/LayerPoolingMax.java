package pl.heinzelman.LayerDeep;

public class LayerPoolingMax extends LayerDeep{


    public LayerPoolingMax(int filterSize, Integer stride ) {
        super(filterSize, 1, 0, stride);
    }

    @Override
    protected float[][] flatForward( int fnum, int channel, float [][] Y  ) {
        for (int i=0;i<ysize;i++){
            for (int j=0;j<ysize;j++) {
                // MAX
                // --- max --- X[i][j] : X[i+size][j+size]
                float max=X[channel][i*filterSize][j*filterSize];
                int maxx = 0;
                int maxy = 0;
                for (int x=0;x<filterSize;x++){
                    for (int y=0;y<filterSize;y++) {
                        dX[channel][i*filterSize][j*filterSize]=0.0f;
                        if ( max<X[channel][i*filterSize+x][j*filterSize+y] ) { max=X[channel][i*filterSize+x][j*filterSize+y]; maxx=x; maxy=y; }
                    }
                }
                dX[channel][i*filterSize+maxx][j*filterSize+maxy]=1.0f;
                Y[i][j]=max;
                // ***  ENC
            }
        }
        return Y;
    }

    @Override
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

}
