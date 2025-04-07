package pl.heinzelman.neu;

import pl.heinzelman.tools.Tools;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.Random;

import static java.awt.image.BufferedImage.TYPE_INT_RGB;

// Forward
// y = Neu[n]*X[]; /y is scalar, a number !
// z = F( y ) ;    /z is scalar, a number !

// Backward
// eIn = s-z; // last layer
// Eout[i]  = Ein * dF(Z) * [W^T]
// <- Sum(Eout)

//Weight
//dF(Z)*E

public class LayerSoftmaxMultiClass {
    private String name;
    private  float X[];
    private  float Y[];
    private  float Z[];
    private  float dFofZ[][];
    private  float Eout[]; // S-Z for last
    private  float tmp[][];

    public LayerSoftmaxMultiClass() {}
    public LayerSoftmaxMultiClass( int n ) { // n - number of inputs  = input  size X[m]
                                             // n - number of neurons & output size Y[n], Z[n]
        X = new float[n];
        Y = new float[n];
        Z = new float[n];
        dFofZ= new float[n][n];
        Eout = new float[n];
        tmp  = new float[n][n];
    }


    public float[] nForward( float[] X ) {
        // OK !
        int len=X.length;
        float sum = 0.0f;
        float max = 0.0f;
        for ( int i=0;i<len;i++ ){ // find MAX
            if (X[i]>max) { max=X[i]; }
        }
        for ( int i=0; i<len; i++ ) {  // Yi = e^Xi
            Y[i] = (float) Math.exp( X[i]-max );
            sum += Y[i];
        }
        for ( int i = 0; i < len; i++ ) { // Yi = Yi/sum
            Z[i] = Y[i] / sum;
        }
        return Z;
    }


    public float[] nBackward( float[] Ein ){ // S-Z or Ein
        for ( int m=0;m<Eout.length;m++ ){ Eout[m]=0.0f; } // reset EOUT
        for ( int i=0;i<dFofZ.length;i++){
            for ( int j=0;j<dFofZ.length;j++) {
                dFofZ[i][j]=0.0f;
            }
        }

        // https://www.youtube.com/watch?v=AbLvJVwySEo
        // backward of softmaxMulticlass
        // if i=k  dx/de    = yi(1-yi)
        // else             = -yi*yk
        //
        // py:
        // n = np.size (output)
        // tmp = np.tile ( output, n )
        // return np.dot( tmp * (np.identity(n) - np.transpose(tmp)), output )

	    // https://www.youtube.com/watch?v=pauPCy_s0Ok

        int len=tmp.length;
        for ( int i=0;i<len;i++ ){
            for ( int j=0;j<len;j++ ){
               dFofZ[i][j] = -1.0f*(Z[i]*Z[j]);
            }
        }
        for ( int i=0;i<len;i++ ){
              dFofZ[i][i] = Z[i]*(1.0f-Z[i]);
        }
        //System.out.println( Tools.AryToString( dFofZ ));
        for ( int i=0;i<len;i++ ){
            for (int j=0;j<len;j++) {
                Eout[i] += Ein[j] * dFofZ[i][j]; // sum= sum ( dFofZ[i][..] )
            }
        }
        return Eout;
    }


    // getters / setters // dummy class ---------------------------------

    public float[] getX() { return X; }
    public float[] getY() { return Y; }
    public float[] getZ() { return Z; }
    public float[] getEout() { return Eout; }


    @Override
    public String toString() {
        return "\nLayer{" + name + " : "+
                "\nX=" + Arrays.toString(X) +
                "\nY=" + Arrays.toString(Y) +
                "\nZ=" + Arrays.toString(Z) +
                "\ndZ=" + Arrays.toString(dFofZ) +
                '}';
    }

    public void setName(String name) { this.name = name; }
}
