package pl.heinzelman.neu;

import pl.heinzelman.tools.Tools;

import java.util.Random;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

// X [num][i][j]
// F [num][m][n]
// D [num][x][y]


public class LayerConvRGB extends LayerConv {

    private String name;
    int filterNum;
    int filterSize;
    private Neuron2D[] Rfilters;
    private Neuron2D[] Gfilters;
    private Neuron2D[] Bfilters;
    private float[][][] Bias;
    private float Y[][][];
    private float Z[][][];

    private float [][][] dLdX;

    public LayerConvRGB(int filterSize, int filterNum) {
        super( filterSize,  filterNum );
        this.filterNum = filterNum;
        this.filterSize = filterSize;
        this.Rfilters = new Neuron2D[filterNum];
        for (int i = 0; i < filterNum; i++) {
            this.Rfilters[i] = new Neuron2D(filterSize, this);
        }
        this.Gfilters = new Neuron2D[filterNum];
        for (int i = 0; i < filterNum; i++) {
            this.Gfilters[i] = new Neuron2D(filterSize, this);
        }
        this.Bfilters = new Neuron2D[filterNum];
        for (int i = 0; i < filterNum; i++) {
            this.Bfilters[i] = new Neuron2D(filterSize, this);
        }
        this.Bias = new float[filterNum][filterSize][filterSize];
    }

    public void rnd() {
        Random rand = new Random();
        for (int i = 0; i < Rfilters.length; i++) { Rfilters[i].rnd(rand); }
        for (int i = 0; i < Gfilters.length; i++) { Gfilters[i].rnd(rand); }
        for (int i = 0; i < Bfilters.length; i++) { Bfilters[i].rnd(rand); }

        for ( int i=0;i<filterNum;i++) {
            for (int j=0;j<filterSize;j++) {
                for ( int k=0;k<filterSize;k++) {
                    Bias[i][j][k] = rand.nextFloat();
                }
            }
        }
    }

    public void setName( String _name ) {
        this.name = _name;
    }

    public String toString() {
        StringBuffer out = new StringBuffer("\n" + name + "\n");
        for (int i = 0; i < Rfilters.length; i++) { out.append( Tools.AryToString(Rfilters[i].getMyWeight()) ); }
        for (int i = 0; i < Gfilters.length; i++) { out.append( Tools.AryToString(Gfilters[i].getMyWeight()) ); }
        for (int i = 0; i < Bfilters.length; i++) { out.append( Tools.AryToString(Bfilters[i].getMyWeight()) ); }
        for (int i = 0; i < Bias.length; i++) { out.append( Tools.AryToString(Bias[i]) ); }
        return out.toString();
    }


    public float[][][] forward ( float[][][] RGB ) { // Yi = Bi +Sum( Xj*Kij ) i=1...filterNum, j=channels
        this.Y = new float[filterNum][filterSize][filterSize];
        for (int n = 0; n < filterNum; n++) {
                    Y[n] = Tools.aryAdd( Bias[n] , Rfilters[n].Forward(  RGB[0] ) , Gfilters[n].Forward(  RGB[1] ) , Bfilters[n].Forward(  RGB[2] ) );
        }
        return Y;
    }





    public void nBackward( float[][][] _dLdO ){ // delta [--x-- ][][]
                                                //       [f0f1f2][][]
                                                // !!!! _dLdO is size of nForward out. !!!!
        int padd = (int)(_dLdO[0].length-1.0f/2.0f);
/*
        this.dLdX = new float[ _dLdO.length ][][];
        for ( int flen=0; flen< filters.length; flen++ ){
            for ( int xlen=0;xlen<X.length; xlen++ ){
                float[][] _dLdO_ =  _dLdO[flen*X.length + xlen];

                float[][] dLdF = Tools.conv( X[xlen], _dLdO_, 0);
                filters[flen].trainW( dLdF ); // update Weigth

                float [][] _dLdX_ = Tools.conv( Tools.extendAry( filters[flen].getRot180() , padd )  , _dLdO_ , 0);
                this.dLdX[ flen*X.length + xlen ] = _dLdX_;
            }
        }  */
    }

    public float[][][] getEout() { return dLdX; }

    Neuron2D getNeuron(int i){
        return Rfilters[i];
    }




}
