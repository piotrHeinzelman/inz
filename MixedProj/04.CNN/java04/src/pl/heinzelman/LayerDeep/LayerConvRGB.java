package pl.heinzelman.LayerDeep;

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


    private Neuron2D[] Gfilters;
    private Neuron2D[] Bfilters;


    public LayerConvRGB( int filterSize, Integer filterNum, Integer padding, Integer stride ) {
        super( filterSize, filterNum, padding, stride );

        this.Gfilters = new Neuron2D[filterNum];
        for (int i = 0; i < filterNum; i++) {
            this.Gfilters[i] = new Neuron2D(filterSize, this);
        }
        this.Bfilters = new Neuron2D[filterNum];
        for (int i = 0; i < filterNum; i++) {
            this.Bfilters[i] = new Neuron2D(filterSize, this);
        }
    }

    public void rnd() {
        Random rand = new Random();
        for (int i = 0; i < Gfilters.length; i++) { Gfilters[i].rnd(rand, getMaxRand()); }
        for (int i = 0; i < Bfilters.length; i++) { Bfilters[i].rnd(rand, getMaxRand()); }

        for ( int i=0;i<filterNum;i++) {
            for (int j=0;j<filterSize;j++) {
                for ( int k=0;k<filterSize;k++) {
                   // Bias[i][j][k] = rand.nextFloat();
                }
            }
        }
    }



    public String toString() {
        StringBuffer out = new StringBuffer("\n" + name + "\n");
        for (int i = 0; i < Gfilters.length; i++) { out.append( Tools.AryToString(Gfilters[i].getMyWeight()) ); }
        for (int i = 0; i < Bfilters.length; i++) { out.append( Tools.AryToString(Bfilters[i].getMyWeight()) ); }
        return out.toString();
    }


    public float[][][] forward ( float[][][] RGB ) { // Yi = Bi +Sum( Xj*Kij ) i=1...filterNum, j=channels
        this.Y = new float[filterNum][filterSize][filterSize];
        for (int n = 0; n < filterNum; n++) {
               //     Y[n] = Tools.aryAdd( Bias[n] , Rfilters[n].Forward(  RGB[0] ) , Gfilters[n].Forward(  RGB[1] ) , Bfilters[n].Forward(  RGB[2] ) );
        }
        return Y;
    }





    public float[][][] nBackward( float[][][] _dLdO ){ // delta [--x-- ][][]
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
        return null;
    }


    public Neuron2D getNeuron(int i){ return null; }
    public Neuron2D getGNeuron(int i){ return  Gfilters[i]; }
    public Neuron2D getBNeuron(int i){ return  Bfilters[i]; }




}
