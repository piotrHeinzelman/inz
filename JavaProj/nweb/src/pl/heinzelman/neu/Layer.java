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
    private String name;
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



    public void nBackward( float[] S , LossType lossFunction ){
        // poprawić w zaleznosci od warstwy dodac mnozenie o dL
        float[] e = new float[Z.length];
        //for ( int i=0;i<Z.length;i++ ){
        //    e[i]=S[i]-Z[i];
        //}
        float k=1;
        for (int i=0;i<Z.length;i++) {
            switch ( lossFunction ) {
                case squareError: { e[i]=0.5f*2*(S[i]-Z[i]); break; }
                case crossEntropy: { e[i]=(S[i]-Z[i]); break; }
                case softmax:     { e[i]=(S[i]-Z[i]); break; }
                case notOutLayer: { e[i]=1; break; }
            }
            e[i]=e[i]*k;
        }

        nBackward( e );
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
            case sigmod: { z = (float) ( 1/(1 + Math.exp( -y ))); break; }
            case crossentropy: { z = (float) ( 1/(1 + Math.exp( -y ))); break; }
                        // Activation fun = sigmod,
                        // S=[s,1-s] // Z=[z,1-z]
                        // Loss fun : L(S,Z)=-Sum(si*ln zi) = -(s*ln(z) +(1-s)*ln(1-z) )
                        //
            case softmax: {
                    if (Z[0]==0.0) {
                        float ymax=0.0f;
                              for ( float y_ : Y ){ if ( y_ > ymax ) { ymax=y_; }}
                        float sumexpy=0.0f;
                              for ( int i=0; i<Z.length; i++ ){ Z[i] = (float) Math.exp( Y[i]-ymax ); }
                        float maxZ=0.0f;
                              for ( float z_ : Z){ maxZ = maxZ + z_; }
                        for ( int i=0; i<Z.length; i++ ){ Z[i] = Z[i]/maxZ; }
                    }
                    z=0;
                    for ( int i=0; i<Z.length; i++ ){ if (Y[i] == y){ z=Z[i]; }}
                    break; }
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
            case softmax: { df = 1; break; }
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
        return "\nLayer{" + name + " : "+
                "\nneurons=" + Arrays.toString(neurons) +
                "\nX=" + Arrays.toString(X) +
                "\nY=" + Arrays.toString(Y) +
                "\nZ=" + Arrays.toString(Z) +
                "\ndZ=" + Arrays.toString(dFofZ) +
                '}';
    }

    public void setName(String name) { this.name = name; }
}
