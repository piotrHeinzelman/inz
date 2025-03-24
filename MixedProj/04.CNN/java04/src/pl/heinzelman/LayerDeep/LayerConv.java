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

    @Override
    protected float[][] flatBackward( float[][] dLdO, int fnum, int channel ){
        // train W
        float[][] dLdF = Conv.conv( X[channel], dLdO, biases);
        filters[fnum].trainW( dLdF ); // update Weigth

        // out
        float [][] _dLdX_ = Conv.fullConv( filters[fnum].getRot180(), dLdO );
        return _dLdX_;
    }

}
