
package pl.heinzelman.LayerDeep;


import pl.heinzelman.tools.Tools;

public class _Convolution {


        public float[][] input; // shape --> [28] X [28]

        public float[][][] filters; // shape --> [8] X [3] X [3]


		public float[][] convolve3x3(float[][] image, float[][] filter) {
        input=image;
        float[][] result = new float[image.length - 2][image[0].length - 2];
        //loop through
        for (int i = 1; i < image.length - 2; i++) {
            for (int j = 1; j < image[0].length - 2; j++) {
                float[][] conv_region = _Mat.m_sub(image, i - 1, i + 1, j - 1, j + 1);
                result[i][j] = _Mat.mm_elsum(conv_region, filter);
            }
        }
        return result;
    }

    public float[][][] forward(float[][] image, float[][][] filter, int filterNum) {
        filters=filter; // 8 X 3 X 3
        float[][][] result = new float[filterNum][26][26];
        for (int k = 0; k < filters.length; k++) {
            float[][] res = convolve3x3(image, filters[k]);
            result[k] = res;
        }
        return result;
    }


    public void backprop(float[][][] d_L_d_out,float learning_rate){
        //the output gradient which is dL/dfilter= (dL/dout)*(dout/dfilter)
        float[][][] d_L_d_filters= new float[filters.length][filters[0].length][filters[0][0].length];
        //reverses the convolution phase by creating a 3X3 gradient filter 
        //and assigning its elements with the input gradient values scaled by
        //the corresponding pixels of the image.
        for(int i=1;i<input.length-2;i++){
            for(int j=1;j<input[0].length-2;j++){
                for(int k=0;k<filters.length;k++){
                    //get a 3X3 region of the matrix
                    float[][] region=_Mat.m_sub(input,  i - 1, i + 1, j - 1, j + 1);
                    //for each 3X3 region in the input image i,j
                    // d_L_d_filter(kth filter) = d_L_d_filter(kth filter)+ d_L_d_out(k,i,j)* sub_image(3,3)i,j
                    //       [3] X [3]          =       [3] X [3]         +     gradient    *      [3] X [3]
                    //see article as to how this gradient is computed.
                    d_L_d_filters[k]=_Mat.mm_add(d_L_d_filters[k], _Mat.m_scale(region,d_L_d_out[k][i][j]));
                }
            }
        }

        // System.out.println( "d_L_d_filters[0]: " + Tools.AryToString( d_L_d_filters[0] ));
        //System.out.println( "d_L_d_out[0]: "     + Tools.AryToString( d_L_d_out[0] ));

        //update the filter matrix with the gradient matrix obtained above.
        for(int m=0;m<filters.length;m++){
          // [3] X [3]  =   [3] X [3] + -lr * [3] X [3]   
            filters[m]= _Mat.mm_add(filters[m], _Mat.m_scale(d_L_d_filters[m],-learning_rate));
        }  
    }
}
