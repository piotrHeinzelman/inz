
package pl.heinzelman.yyy.net;


public class _MaxPool {


        public float[][][] input;  // [8] X [26] X [26]
        public float[][][] output;


    public float[][] max_pool(float[][] img) {
        //final array shape is half of the original input shape
        float[][] pool = new float[img.length / 2][img[0].length / 2];
        for (int i = 0; i < pool.length - 1; i++) {
            for (int j = 0; j < pool[0].length - 1; j++) {
                //get the maximum value from the (i,j)th 2X2 sub-region of the input.
                pool[i][j] = Mat.m_max(Mat.m_sub(img, i * 2, i * 2 + 1, j * 2, j * 2 + 1));
            }
        }
        return pool;
    }

    public float[][][] forward(float[][][] dta) {
        input = dta;
        float[][][] result = new float[dta.length][dta[0].length][dta[0][0].length];
        for (int k = 0; k < dta.length; k++) {
            float[][] res = max_pool(dta[k]);
            result[k] = res;
        }
        output = result;
        return result;
    }

    public float[][][] backprop(float[][][] d_L_d_out) {
        float[][][] d_L_d_input = new float[input.length][input[0].length][input[0][0].length];
        for (int i = 0; i < output.length; i++) { // filter index 0 - 12 [13 values]
            for (int j = 0; j < output[0].length; j++) { //pool row index 0 -12 [13 values]
                for (int k = 0; k < output[0][0].length; k++) { //pool column index
                    //get 2X2 image region.
                    float[][] region = Mat.m_sub(input[i], j * 2, j * 2 + 1, k * 2, k * 2 + 1);
                    //loop through image region to get row,column index of the maximum value.
                    for (int m = 0; m < region.length; m++) {
                        for (int n = 0; n < region[0].length; n++) {
                            //if the current value in the 2X2 region is the maximum 
                            //then assign the output gradient value to this index on the
                            // [8]X[26]X[26] output gradient matrix.
                            if (Math.abs(output[i][j][k] - region[m][n]) < 0.00000001) {
                                //the index should be translated from local 3X3 to global
                                //i.e. from [m][n] of the 3X3 matrix to [i*2+m][j*2+n] of the grad matrix
                                d_L_d_input[i][j * 2 + m][k * 2 + n] = d_L_d_out[i][j][k];
                            }
                        }
                    }
                }
            }
        }
        return d_L_d_input;
    }
}
