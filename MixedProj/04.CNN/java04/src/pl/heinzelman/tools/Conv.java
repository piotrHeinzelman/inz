package pl.heinzelman.tools;

public class Conv {


    public static float[][] extendAry( float[][] X, int padding ){
        int oversize=X.length+padding+padding;
        float[][] XPadd = new float[oversize][oversize];

        for ( int i=0;i<oversize;i++){
            for (int j=0;j<oversize;j++){
                XPadd[i][j]=0f;
            }
        }
        for ( int i=0;i<X.length;i++ ){
            for ( int j=0;j<X.length;j++){
                XPadd[i+padding][j+padding]=X[i][j];
            }
        }
        return XPadd;
    }



    public static float[][] fullConv( float[][] X, float[][] F ){
        int padding = F.length-1;
        return  conv (  extendAry( X , padding ) , F,  null , 1 ) ;
    }

    public static float[][] conv( float[][] X, float[][] F, float[][] bias ){
        return conv( X, F, bias, 1 );
    }

    public static float[][] conv( float[][] X, float[][] F, float[][] bias, int stride /* 1 */ ){

        int outputSize= 1+(( X.length-F.length )/stride);
        int fSize=F.length;
        float [][] Y = new float[outputSize][outputSize];
        for ( int i=0;i<outputSize;i++ ){
            for ( int j=0;j<outputSize;j++ ){
                float YIJ= (bias==null) ? 0f : bias[i][j];
                {
                    for (int m=0;m<fSize;m++){
                        for (int n=0;n<fSize;n++){
                            //System.out.println( "YIJ="+YIJ + " + " + F[m][n] +" X "+ X[i+m][j+n] );
                            YIJ += ( F[m][n] * X[i+m][j+n]);

                        }
                    }
                }
                Y[i][j]=  /*relu*/( YIJ );
            }
        }
        return Y;
    }


    public static float[][] getRot180( float[][] W ){
        float[][] Rot180 = new float[ W.length ][ W.length ];
        for (int i=0;i<W.length;i++){
            for (int j=0;j<W.length;j++){
                Rot180[W.length-i-1][W.length-j-1] = W[i][j];
            }
        }
        return Rot180;
    }


    public static float relu( float xij ){
        return xij>0?xij:0f;
    }


}
