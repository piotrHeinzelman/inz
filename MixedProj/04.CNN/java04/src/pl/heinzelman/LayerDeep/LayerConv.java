package pl.heinzelman.LayerDeep;

import pl.heinzelman.tools.Conv;
import pl.heinzelman.tools.Tools;

import java.util.Random;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

// X [num][i][j]
// F [num][m][n]
// D [num][x][y]


public class LayerConv extends LayerDeep {

    public LayerConv( int filterSize, Integer filterNum, Integer padding, Integer stride ) {
        super( filterSize, filterNum, padding, stride );
    }

    @Override
    protected float[][] flatForward( int fnum, int channel){
        return filters[fnum].Forward( X[channel] );
    }

    /*
    @Override
    public float[][][] Backward( float[][][] _dLdO ){ // delta [--x-- ][][]
                                                //       [f0f1f2][][]
                                                // !!!! _dLdO is size of nForward out. !!!!
        int padd = (int)(_dLdO[0].length-1.0f/2.0f);

        float[][][] dOUT = new float[ _dLdO.length ][][];
        for ( int fnum=0; fnum< filterNum; fnum++ ){
            for ( int channel=0;channel<channels; channel++ ){

                float[][] _dLdO_ =  _dLdO[fnum*channels + channel];

                System.out.println( _dLdO_ );
                float[][] dLdF = Conv.conv( X[channel], _dLdO_, 0);
                filters[fnum].trainW( dLdF ); // update Weigth

                float [][] _dLdX_ = Conv.conv( Conv.extendAry( filters[fnum].getRot180() , padd )  , _dLdO_ , 0);
                dOUT[ fnum*channels + channel ] = _dLdX_;
            }
        }
        return dOUT;
    }
    */

    @Override
    protected float[][] flatBackward( float[][] dLdO, int fnum, int channel ){
        int padd = (int)(dLdO.length-1.0f/2.0f);

        // train W
        float[][] dLdF = Conv.conv( X[channel], dLdO, 0);
        filters[fnum].trainW( dLdF ); // update Weigth

        // out
        float [][] _dLdX_ = Conv.conv( Conv.extendAry( filters[fnum].getRot180() , padd )  , dLdO , 0);
        return _dLdX_;
    }

}
