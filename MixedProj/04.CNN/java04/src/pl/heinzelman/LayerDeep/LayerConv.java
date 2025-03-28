package pl.heinzelman.LayerDeep;

import pl.heinzelman.tools.Conv;

import java.util.Random;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

// X [num][i][j]
// F [num][m][n]
// D [num][x][y]


public class LayerConv {
    protected String name;
    protected Neuron2D[] filters;

    protected float[][][] X;
    protected float[][][] dX;
    protected float[][][] Y;
    protected int filterNum; // 6 for (n) for (c) filters( c + n*channels ) // n: filterForChannel = output size // c: channel = input size
    protected int filterForChannel; // 2
    protected int filterSize;
    protected int padding;
    protected int stride;

    protected int channels;
    protected int xsize;
    protected int ysize;

    public LayerConv( int filterSize, Integer filterForChannel, Integer padding, Integer stride ) {
        this.filterSize = filterSize;
        this.filterForChannel = filterForChannel;
        this.padding = ( padding==null ) ? 0 : padding;
        this.stride = (stride==null) ? 1 : stride;
    }
    private void initFilters(){
        this.filters = new Neuron2D[ filterNum ];
        Random rand = new Random();
        float max=getMaxRand();
        for ( int i=0;i<filterNum;i++ ){
            filters[i] = new Neuron2D( filterSize, this );
            filters[i].rnd(rand, max);
        }
    }
    protected void initAry(){
        X  = new float[ channels ][ xsize ][ xsize ];
        dX = new float[ channels ][ xsize ][ xsize ];
    }

    public void setX(float[][][] _x ) {
        this.channels= _x.length;
        this.filterNum=filterForChannel*channels;
        this.xsize=_x[0].length;
        this.ysize = getYSize();
        initAry();
        initFilters();

        for (int n = 0; n < channels; n++) {
            for (int i = 0; i < xsize; i++) {
                for (int j = 0; j < xsize; j++) {
                    X[n][i][j] = _x[n][i][j];
                }
            }
        }
    }



    public float[][][] Forward() {
        Y = new float[ filterForChannel ][ ysize ][ ysize ];

        for ( int fnum=0;fnum<filterNum; fnum++ ){
            System.out.println( "filternum: " + fnum + ", channelNum:" + fnum%filterForChannel + ", filterClass: " + fnum/filterForChannel );
        }
        /*



        for (int n=0;n<filterForChannel;n++ ){ // 3 ways
            for (int x=0;x<ysize;x++) {
                for (int y = 0; y < ysize; y++) {
                    float sum=0f;

                    for ( int c=0;c<channels;c++ ) {   // channels
                        Neuron2D filter = filters[c + n*channels];
                        sum += filter.getBias();
                        float[][] W = filter.getMyWeight();

                        for (int i = 0; i < filterSize; i++) {
                            for (int j = 0; j < filterSize; j++) {
                                sum += ( W[i][j] * X[c][i+x][j+y] );
                            }
                        }

                    }
                    //Y[n][x][y] = relu( sum );
                    Y[n][x][y] = sum ;
                }
            }
        }
        return Y;
        */
        return null;
    }






    public float[][][] Backward( float[][][] dLdO ) {
        float[][][] dOUT = new float[ filterForChannel ][ ysize ][ ysize ];
        System.out.println( dLdO );
        /*
        float[][][] _dLdX_ = new float[channels][xsize][xsize];
        for ( int fnum=0; fnum< filterNum; fnum++ ){
            for ( int channel=0;channel<channels; channel++ ) {

                    //float[][] dLdF = Conv.conv( X[channel], dLdO[fnum*channels + channel], filters[fnum].getBias() );
                    //filters[fnum].trainW( dLdF ); // update Weigth

                    // out
                    //_dLdX_[fnum] = Conv.fullConv( filters[fnum].getRot180(), dLdO[fnum*channels + channel] );
                }
                // ********************
            }*/
        return dOUT;
    }

    // ****************

    public String toString(){ if ( filters==null) { return ""; } StringBuffer out = new StringBuffer(); for ( int i=0;i<filterNum;i++){ out.append( "\n" ); out.append( filters[i].toString() ); } return out.toString(); }
    public void setName( String name ) { this.name = name; }
    public Neuron2D getNeuron(int i){ return filters[i]; }
    private float relu(float x){
        return (x>0)? x : 0;
    }
    public int getYSize(){
        return 1+(( xsize+padding+padding-filterSize )/stride);
    }
    protected float getMaxRand(){
        float inputChannelNum = 6; // inputs
        float outputChannelNum = filterNum; //
        return (float)Math.pow((filterNum / ((inputChannelNum + outputChannelNum) * (filterSize * filterSize))), .5f);
    }

}


