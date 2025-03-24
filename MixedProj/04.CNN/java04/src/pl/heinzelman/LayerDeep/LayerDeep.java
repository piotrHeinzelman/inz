package pl.heinzelman.LayerDeep;

import java.util.Arrays;
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

    public LayerDeep( int filterSize, Integer filterNum, Integer padding, Integer stride ) {
        this.filterSize = (int)filterSize;
        this.filterNum = (filterNum==null) ? 0 : (int)filterNum;
        this.padding = ( padding==null ) ? 0 : (int)padding;
        this.stride = (stride==null) ? 1 : (int)stride;
        if ( filterNum>0 ) { initFilters(); }
    }

    protected void initFilters(){
        this.filters = new Neuron2D[ filterNum ];
        Random rand = new Random();
        for ( int i=0;i<filterNum;i++ ){
            filters[i] = new Neuron2D( filterSize, this );
            filters[i].rnd(rand);
        }
    }

    protected void initAry(){
        X  = new float[ channels ][ xsize ][ xsize ];
        //dX = new float[ channels ][ xsize ][ xsize ];
    }

    public void setName( String name ) { this.name = name; }
    public Neuron2D getNeuron(int i){ return filters[i]; }

    public void setX( float[][][] _x ) {
        this.channels= _x.length;
        this.xsize=_x[0].length;
        initAry();

        for (int n = 0; n < channels; n++) {
            for (int i = 0; i < xsize; i++) {
                for (int j = 0; j < xsize; j++) {
                    X[n][i][j] = _x[n][i][j];
                }
            }
        }
    }

    public float[][][] Forward() {
        int ySize=getYSize();
        Y = new float[ filterNum * channels ][ ySize ][ ySize ];
        for ( int fnum=0; fnum< filterNum; fnum++ ){
            for ( int channel=0;channel<channels; channel++ ){
                Y[ fnum*channels + channel ] = flatForward( fnum, channel);
            }
        }
        return Y;
    }


    protected abstract float[][] flatForward( int fnum, int channel );
    protected abstract float[][] flatBackward( float[][] dLdO, int fnum, int channel );

    public int getYSize(){
        return (( xsize+padding+padding )+1-filterSize)/stride;
    }

    public float[][][] Backward( float[][][] dLdO ) {
        float[][][] dOUT = new float[ dLdO.length ][][];
        for ( int fnum=0; fnum< filterNum; fnum++ ){
            for ( int channel=0;channel<channels; channel++ ) {
                dOUT[ fnum*channels + channel ] = flatBackward( dLdO[fnum*channels + channel], fnum, channel );
            }
        }
        return dOUT;
    }

    public String showWeight(){
        StringBuffer out = new StringBuffer();
        for ( int i=0;i<filterNum;i++){
            out.append( "\n" );
            out.append( filters[i].toString() );
        }
        return out.toString();
    }


}
