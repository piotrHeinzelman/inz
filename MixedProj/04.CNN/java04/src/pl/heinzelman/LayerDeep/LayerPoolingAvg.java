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

    @Override
    protected float[][] flatForward( int fnum, int channel, float[][] Y ) {
        float[][] x = X[channel];
        for (int i=0;i<ysize;i++){
            for (int j=0;j<ysize;j++) {
                // sum 1 block
                float sum=0.0f;
                for (int m=0;m<filterSize;m++){
                    for (int n=0;n<filterSize;n++) {
                        sum+=x[i*filterSize+m][j*filterSize+n];
                        dX[channel][i*filterSize+m][j*filterSize+n]=DX;
                    }
                }
                Y[i][j] += (sum*DX);
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
