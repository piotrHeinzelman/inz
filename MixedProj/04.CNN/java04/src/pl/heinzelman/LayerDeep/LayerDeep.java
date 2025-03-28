package pl.heinzelman.LayerDeep;

import java.util.Random;

public abstract class LayerDeep {
    protected String name;
    protected Neuron2D[] filters;

    protected float[][][] X;
    protected float[][][] dX;
    protected float[][][] Y;
    protected int filterNum;
    protected int filterSize;
    protected int padding;
    protected int stride;

    protected int channels;
    protected int xsize;
    protected int ysize;

    public LayerDeep( int filterSize, Integer filterNum, Integer padding, Integer stride ) {
        this.filterSize = filterSize;
        this.filterNum = (filterNum==null) ? 0 : (int)filterNum;
        this.padding = ( padding==null ) ? 0 : (int)padding;
        this.stride = (stride==null) ? 1 : (int)stride;
    }


    protected void initFilters(){
        this.filters = new Neuron2D[ filterNum ];
        Random rand = new Random();
        float max=getMaxRand();
        for ( int i=0;i<filterNum;i++ ){
          //  filters[i] = new Neuron2D( filterSize, this );
           // filters[i].rnd(rand, max);
        }
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
        if ( filterNum>0 ) { initFilters(); }

        for (int n = 0; n < channels; n++) {
            for (int i = 0; i < xsize; i++) {
                for (int j = 0; j < xsize; j++) {
                    X[n][i][j] = _x[n][i][j];
                }
            }
        }
    }

    public float[][][] ConvForward() {
        Y = new float[ filterNum ][ ysize ][ ysize ];
        for ( int fnum=0; fnum< filterNum; fnum++ ){
            for ( int channel=0;channel<channels; channel++ ){
                flatForward( fnum, channel, Y[ fnum ] );
            }
        }
        return Y;
    }


    protected abstract float[][] flatForward( int fnum, int channel, float[][] Y );
    protected abstract float[][] flatBackward( float[][] dLdO, int fnum, int channel );



    public float[][][] Backward( float[][][] dLdO ) {
        float[][][] dOUT = new float[ dLdO.length ][][];
        for ( int fnum=0; fnum< filterNum; fnum++ ){
            for ( int channel=0;channel<channels; channel++ ) {
                dOUT[ fnum*channels + channel ] = flatBackward( dLdO[fnum*channels + channel], fnum, channel );
            }

        }
        return dOUT;
    }

    // ****************

    public String toString(){ StringBuffer out = new StringBuffer(); for ( int i=0;i<filterNum;i++){ out.append( "\n" ); out.append( filters[i].toString() ); } return out.toString(); }
    public void setName( String name ) { this.name = name; }
    public Neuron2D getNeuron(int i){ return filters[i]; }

    public int getYSize(){
        return 1+(( xsize+padding+padding-filterSize )/stride);
    }
    protected float getMaxRand(){
        float inputChannelNum = 6; // inputs
        float outputChannelNum = filterNum; //
        return (float)Math.pow((filterNum / ((inputChannelNum + outputChannelNum) * (filterSize * filterSize))), .5f);
    }

}
