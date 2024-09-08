package pl.heinzelman.neu;

import java.util.Arrays;
import java.util.Random;

// Forward
// y = Neu[n]*X[]; /y is scalar, a number !
// z = F( y ) ;    /z is scalar, a number !

// Backward
// eIn = s-z; // last layer
// Eout[i]  = Ein * dF(Z) * [W^T]
// <- Sum(Eout)

//Weight
//dF(Z)*E

public class Layer {
    private  LType lType;
    private  Neuron[] neurons;
    private  float X[];
    private  float Y[];
    private  float Z[];
    private  float dFofZ[];
    //private  float Ein[]; // S-Z for last
    private  float Eout[]; // S-Z for last

    public Layer( LType lType, int n, int m ) { // n - number of neurons & output size Y[n], Z[n]
        this.lType=lType;                        // m - number of inputs  = input  size X[n]
        this.neurons = new Neuron[n];
        for (int i=0;i<n;i++){
            this.neurons[i]=new Neuron(m, this);
        }
        X = new float[m];
        Y = new float[n];
        Z = new float[n];
        dFofZ = new float[n];
        //Ein = new float[n];
        Eout = new float[m];
    }

    public void setWmn( int n, int m, float wji ){
        neurons[n].setWm( m, wji );
    }



    public void rnd(){
        Random random=new Random();
        for ( Neuron neu : neurons ) {
            for ( int m=0;m<neurons.length;m++ ) {
                neu.setWm( m , random.nextFloat());
            }
            System.out.println( neu );
        }
    }


    public void nForward(){
        for ( int n=0;n< neurons.length;n++) {
            Y[n] = neurons[n].Forward( X );
            Z[n] = F ( Y[n] );
            dFofZ[n] = dF( Z[n] );
        }
    }

    public void nBackward( float[] Ein ){
        for ( float f : Eout ){ f=0f; } // clear Eout
        for ( int n=0; n< neurons.length; n++ ){
            System.out.println( "Ein[n]:"+Ein[n]  + ", "+dFofZ[n]);
            neurons[n].Backward( Ein[n] * dFofZ[n] );
        }
    }




    // Math F(y) / dF(z)

    private float F ( float y ){
        float z;
        switch (this.lType) {
            case sigmod: { z = (float) ( 1/(1 + Math.exp( -y ))); break;}
            case crossentropy: { z = (float) ( 1/(1 + Math.exp( -y ))); break;}
                        // Activation fun = sigmod,
                        // S=[s,1-s] // Z=[z,1-z]
                        // Loss fun : L(S,Z)=-Sum(si*ln zi) = -(s*ln(z) +(1-s)*ln(1-z) )
                        //
            case linear:
                default: { z=y; break; }
        }
        return z;
    }

    private float dF (float z ){
        float df;
        switch (lType) {

            case sigmod: { df = z*(1-z); break; }
            case crossentropy: { df = 1; break; }
            case linear:
            default: { df=1; break; }
        }
        return df;
    }



    // getters / setters
    public void setX( float[] _x ) {
        for ( int m=0; m<X.length; m++ ){
            this.X[m] = _x[m];
        }
    }

    public float[] getZ() { return Z; }
    public float[] getX() { return X; }
    public float[] getEout() { return Eout; }


    @Override
    public String toString() {
        return "\nLayer{" +
                "\nneurons=" + Arrays.toString(neurons) +
                "\nX=" + Arrays.toString(X) +
                "\nY=" + Arrays.toString(Y) +
                "\nZ=" + Arrays.toString(Z) +
                "\ndZ=" + Arrays.toString(dFofZ) +
                '}';
    }
}
