package CNN;

import pl.heinzelman.tools.Tools2;

public class SoftMax {
    

        public float[][] weights;
        public float[][] input;
   
        public float[][] bias;
    


        public float[][] output;
        public int filterNum;


    public SoftMax(int input, int output, int filterNum) {
        this.filterNum=filterNum;
        weights = Mat.m_scale(Mat.m_random(input, output), 1.0f / input);
        bias = Mat.v_zeros(10);
    }


    public float[][] forward(float[][][] input) {
        //flattens the input to [8] X [13] X [13] to a [1] X [8*13*13] vector.
        float[][] in = Mat.m_flatten( input );  //1X1342
        output = new float[1][bias.length];    //1X10
// equal System.out.println( "\n\nin: \n" + Tools.AryToString( in ) );
     // evaluate the total activation value --> t=[i][w]+[b] and cache the totals for backprop
     // [1] X [10] =  [1] X [1342]  * [1342] X [10] + [1] X [10]
        output = Mat.mm_add(Mat.mm_mult(in, weights), bias);
        //compute softmax probabilities.
        float[][] totals = Mat.v_exp(output);
        float inv_activation_sum = 1 / Mat.v_sum(totals);
        //cache input
        this.input = in;
        return Mat.v_scale(totals, inv_activation_sum);
    }

    public float[][][] backprop(float[] Ein, float learning_rate) {
        //gradient of loss w.r.t. the total probabilites of the softmax layer.
        float[][] dFofZ_x_EinI_True_I = new float[1][Ein.length];
        //repeat softmax probability computations (caching can be used to avoid this.)
        float[][] Y = Mat.v_exp(output);
        float sum = Mat.v_sum(Y);
        float[][] Eout=null;

        //System.out.println( " d_L_d_out: " + Tools.AryToString( d_L_d_out ) );
        for (int i = 0; i < Ein.length; i++) {
            float grad = Ein[i];
            if (grad == 0) {
                continue;
            }

            //gradient of the output layer w.r.t. the totals [1] X [10]
            float[][] dFofZ = Mat.v_scale(Y, -Y[0][i] / (sum * sum));
            dFofZ[0][i] = Y[0][i] * (sum - Y[0][i]) / (sum * sum);

            dFofZ_x_EinI_True_I = Mat.m_scale(dFofZ, grad);

//Tools2 t = new Tools2(); t.echo( "dFofZ_x_EinI_True_I:" , dFofZ_x_EinI_True_I );


            //gradient of totals w.r.t weights -- [1342] X [1]
            float[][] X = Mat.m_transpose(input);
            //gradient of totals w.r.t inputs -- [1342] X [10] 
            float[][] W = weights;
            //gradient of Loss w.r.t. weights ---> chain rule 
            //        [1342] X [10] = [1342] X [1] * [1] X [10]
            float[][] d_L_d_w = Mat.mm_mult(X, dFofZ_x_EinI_True_I);
            //gradient of Loss w.r.t. inputs ---> chain rule
            // [1342] X [1]      [1342] X [10]    *   [10] X [1](transposed)
            Eout = Mat.mm_mult(W, Mat.m_transpose(dFofZ_x_EinI_True_I));
            //gradient of loss w.r.t. bias
            float[][] d_L_d_b = dFofZ_x_EinI_True_I;
            //update the weight and bias matrices.
            weights = Mat.mm_add(Mat.m_scale(d_L_d_w, -learning_rate), weights);
            bias = Mat.mm_add(Mat.m_scale(d_L_d_b, -learning_rate), bias);
        }
        // reshape the final gradient matrix to the input shape of the maxpooling layer.
        // [1] X [1342](transposed) ----> [8] X [13] X [13]

        return Mat.reshape(Mat.m_transpose( Eout ),filterNum,13,13);
    }
}
