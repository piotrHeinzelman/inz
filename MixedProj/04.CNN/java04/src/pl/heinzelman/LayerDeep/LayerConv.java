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

//                        F11  F1c1    Fnc*Xc
//  Xc1 [ ]---------+----> [ ] -----     b1
//                 |                \   |
//                 |      F12  F1c2  ( + ) ----->
//  Xc2 [ ]---+--- | ---> [ ] ----- /
//           |     |
//           |     |
//           |     |      F21  F2channel1
//           |     +----> [ ] ------    b2
//           |     |                \   |
//           |            F22  F2c2   ( + ) ----->
//           +----------> [ ] ------/
//           |
//           |     |      F31  F3c1     b3
//           |     ---->  [ ] ----- \   |
//           |                       ( + ) ------>
//           |            F32  F3c2 /
//           ---------->  [ ] -----
//
//
//           Filter ( FilterNum*Channels + Channel )
//
//           out[n][c] = out[ n*c ] = Fnc * Xc                       separated multiply X & filter
//                       out[n]     = SUM by c ( out[n][c] )  +bn    mass add filter outputs


public class LayerConv {
    protected String name;
    protected Neuron2D[] filters;

    protected float[][][] X;
    protected float[][][] dX;
    protected float[][][] Y;
    protected int filterNum; // 6  ( input channel * filterForChannel )  for (n) for (c) filters(  n*channels + c ) // n: filterForChannel = output size // c: channel = input size
    protected int filterForChannel; // output channel
    protected int filterSize;
    protected int padding=0;
    protected int stride;

    protected int channels; // input channel
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
        if ( padding!=0 ) { _x = Conv.extendAry( _x, padding ); }
        this.channels= _x.length;
        this.filterNum=filterForChannel*channels;
        this.xsize=_x[0].length;
        this.ysize = getYSize();
        initAry();
        initFilters();

        for (int n = 0; n < channels; n++) {
            for (int x = 0; x < xsize; x++) {
                for (int y = 0; y < xsize; y++) {
                    X[n][y][x] = _x[n][y][x];
                }
            }
        }
    }




    public float[][][] Forward() {
        Y = new float[ filterForChannel ][ ysize ][ ysize ];
        float[][][] FtmpOUT = new float[filterNum][][];

       // MASS multiply Fnc * Xc
       for ( int fnum=0;fnum<filterNum; fnum++ ){   //System.out.println( "filternum: " + fnum + ", channelNum:" + fnum%filterForChannel + ", filterClass: " + fnum/filterForChannel );
            FtmpOUT[ fnum ] = ConvolutionFilterTimesXc( filters[fnum], X[ fnum%channels ] );
        }

       // by set of filter ( output channel )
        for ( int f=0;f<filterForChannel;f++ ) {
            // init bias
            float b = filters[f*channels].getBias();

            for (int x = 0; x < ysize; x++) {
                for (int y = 0; y < ysize; y++) {
                    Y[f][x][y]=b;
                }
            }

            // sum FOUT
            for ( int c=0; c<channels; c++ ){
                for (int x = 0; x < ysize; x++) {
                    for (int y = 0; y < ysize; y++) {
                        Y[f][x][y] += FtmpOUT[ f*channels +c ][x][y];
                    }
                }
            }
        }
        return Y;
    }



    public float[][] ConvolutionFilterTimesXc(Neuron2D filter, float[][] Xc ) {
        float[][] W = filter.getMyWeight();
        float[][] OUT = new float[ysize][ysize];

        for ( int i=0;i<ysize;i++){
            for ( int j=0;j<ysize;j++) {

                for (int x=0;x<filterSize;x++){
                    for (int y=0;y<filterSize;y++) {
                        // every channel (c)
                        // target output[i][j]
                        OUT[i][j] += ((Xc[ i*stride + x ][ j*stride + y ]) * (W[x][y]));
                    }
                }
            }
        }
        return OUT;
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


