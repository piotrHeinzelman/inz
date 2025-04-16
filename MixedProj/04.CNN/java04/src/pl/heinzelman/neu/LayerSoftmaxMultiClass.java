package pl.heinzelman.neu;

import pl.heinzelman.LayerDeep._Mat;

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

public class LayerSoftmaxMultiClass implements LayerParent {
    private String name;
    private  Neuron[] neurons;
    private  float X[];
    private  float Y[];
    private  float Z[];
    private  float dFofZ[][];
    private  float Eout[]; // S-Z for last

    public LayerSoftmaxMultiClass( int m, int n ) { // m - number of inputs  = input  size X[m]
                                                    // n - number of neurons & output size Y[n], Z[n]
        this.neurons = new Neuron[n];
        for (int i=0; i<n; i++){
            this.neurons[i]=new Neuron( m, this );
        }
        X = new float[m];
        Y = new float[n];
        Z = new float[n];
        dFofZ = new float[n][m];
        Eout = new float[m];
        rnd();
    }


    private void rnd(){
        Random random=new Random();
        float normalization=X.length;
        for ( Neuron neu : neurons ) {
            for ( int m=0; m<X.length; m++ ) {
                neu.setWm( m , random.nextFloat() / normalization );
            }
        }
    }


    public float[] nForward( float[] _x ) {
        for (int m=0;m<X.length;m++){ X[m]=_x[m]; Eout[m]=0; }
        for (int n = 0; n < neurons.length; n++) {
            Y[n] = neurons[n].Forward( X );
        }
        // Softmax
        int len=Y.length;
        float sum = 0.0f;
        float max = 0.0f;
        for ( int i=0;i<len;i++ ){ // find MAX
            if (Y[i]>max) { max=Y[i]; }
        }
        for ( int i=0; i<len; i++ ) {  // Zi = e^Xi
            Z[i] = (float) Math.exp( Y[i]-max );
            sum += Z[i];
        }
        for ( int i = 0; i < len; i++ ) { // Yi = Yi/sum
            Z[i] = Z[i] / sum;
        }
        return Z;
    }

    public float[] nBackward( float[] Ein ){ // S-Z or Ein
        for ( int m=0;m<Eout.length;m++ ){ Eout[m]=0.0f;}
        for ( int n=0; n<neurons.length; n++ ){
            neurons[n].Backward( Ein[n]  /*  * dFofZ[n] */, Ein[n] );
        }
        if ( true )return Eout;



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


        // !!!!!!!!!!!!!!!!!
        int len=X.length;
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

    // getters / setters
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
    public void setWmn( int n, int m, float wji ){
        neurons[n].setWm( m, wji );
    }


    //@Deprecated
    public float[] getY() { return Y; }

    //@Deprecated
    public float[] getNeuronWeight( int i ){
        return neurons[i].getMyWeight();
    }

    public Neuron getNeuron(int i) {
        return neurons[i];
    }
    public void setAllWeight( float[][] w ){
        for (int i=0;i<neurons.length;i++){
            neurons[i].setWeights( w[i] );
        }
    }

    public float[] getdZ(  float [] target ){
        // https://www.youtube.com/watch?v=vbUozbkMhI0
        // dZ3 = (A3-Y)
        //
        float[] dZ = new float[Z.length];
        for ( int i=0; i<Z.length; i++ ){
            dZ[i] = ( Z[i] - target[i] );
        }
        return dZ;
    }

    public float[] getdZ(  int targetClass ){
        float[] Vtarget = new float[Z.length];
        for (int i=0;i<Z.length; i++){
            Vtarget[i]=0.0f;
        }
        Vtarget[targetClass]=1.0f;
        return getdZ( Vtarget );
    }








    // cost   _  m
    // -1/m * \  [ yi *log (ai) + (1-yi)* log(1-ai) ]
    //        /
    //        - i=1         [] = LOSS,   -1/m SUM [] = COST

    public float[][] compute_gradient( float[][] Z, int correct_label ){
        //BACKWARD PROPAGATION --- STOCHASTIC GRADIENT DESCENT
        //gradient of the cross entropy loss

        //public static float[] vectorSubstZsubS(float[] z, float[] s){
        float[][] out = new float[1][ Z[0].length];
        for ( int i=0;i<Z[0].length; i++ ){
            if ( i==correct_label ) { out[0][i] = Z[0][i]-1.0f; }
            else           { out[0][i] = Z[0][i]; }
            //out[0][i] = ( Z[i] ) ; if ( i==correct_label ) { Z[i]=Z[i]-1.0f; } //- S[i] );
        }
        if (true)    return out;
        //}

        //public static float[] gradientSoftMax( float[] S, float[] Z ){
        //    float[][] out = new float[1][ Z[0].length];
        //    for ( int i=0;i<Z[0].length; i++ ){
        //        if ( S[i]==0 ) { out [i]=0; }
        //        else { out[i] = ( -1 / S[i] ); }
        //    }
        //    return out;
        //}


        float[][] gradient = _Mat.v_zeros(10);
        gradient[0][correct_label] = -1.0f / (float) Math.log( Z[0][correct_label] );
        return gradient;
    }

    public float delta_Loss( int correct_label ) {
        // compute cross-entropy loss
        // not used
        float value_correctLabel = Z[correct_label];
        return  (float) -Math.log( value_correctLabel );
    }

    public float[] gradientCNN( float[][] out_l, int correct_label ){

        //BACKWARD PROPAGATION --- STOCHASTIC GRADIENT DESCENT
        //gradient of the cross entropy loss

        float[] gradient=new float[10]; //Mat.v_zeros(10);
        for (int i=0;i<10;i++){ gradient[i]=0.0f; }
        gradient[correct_label]=-1/out_l[0][correct_label];
        return gradient;

        // grad straty = (si-ki)
        //
        // dL/dwij = (si-ki) * xj : gdzie si = out_l[0][i],     if i==correctLabel k=1 else k=0
        //           j=1
        // ???????????????????????????
        //for (int i=0;i<10;i++){ gradient[0][i]=Z[i]; }
        //        gradient[0][correct_label]=(Z[correct_label]-1);
        //return gradient;
    }




}
