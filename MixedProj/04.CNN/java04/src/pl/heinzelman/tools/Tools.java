package pl.heinzelman.tools;


import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

import static java.awt.image.BufferedImage.TYPE_BYTE_GRAY;
import static java.awt.image.BufferedImage.TYPE_INT_RGB;

public class Tools {

    private static String path="../data/";
    private static String testXname="t10k-images-idx3-ubyte";
    private static String testYname="t10k-labels-idx1-ubyte";
    private static String trainXname="train-images-idx3-ubyte";
    private static String trainYname="train-labels-idx1-ubyte";

    private byte[] trainYfile=null;
    private byte[] testYfile=null;
    private float[][] trainY=null;
    private float[][] testY=null;

    private float[][] trainX=null;
    private float[][] testX=null;

    public  void prepareData( int percent ){

        try {
            trainYfile =  loadBin( path + trainYname,  8, percent*600 ); // offset=8, size=percent*600  // OK
            testYfile =  loadBin( path + testYname,   8, percent*100 );   // offset=8, size=percent*100 // OK

            trainY = new float[percent*600][];
            testY  = new float[percent*100][];
            //train Y
            for (int i=0;i<percent*600;i++){
                trainY[i] = new float[]{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
                trainY[i][ trainYfile[i] ]=1.0f;
            }
            // test Y
            for (int i=0;i<percent*100;i++){
                testY[i] = new float[]{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
                testY[i][ testYfile[i] ]=1.0f;
            }


            byte[] trainXfile = loadBin(path + trainXname, 16, percent * 784 * 600);// offset=16 size=percent*784*600
            trainX=new float[percent*600][784];
            for (int i=0;i<percent*100;i++) {
                int off=i*784;
                for (int j=0;j<784;j++){
                    trainX[i][j]=Byte.toUnsignedInt( trainXfile[off+j] )/16;///256.0f; //0-1
                    //System.out.println( trainX[i][j] );
                }
            }

            byte[] testXfile =   loadBin( path + testXname,  16, percent*784*100 );   // offset=16, size=percent*784*100
            testX=new float[percent*100][784];
            for (int i=0;i<percent*100;i++) {
                int off=i*784;
                for (int j=0;j<784;j++){
                    testX[i][j]=Byte.toUnsignedInt( testXfile[off+j] )/16;///256.0f;
                }
            }

            // show data:
            //for ( int i=0;i<100;i++ ) {
            //    saveVectorAsImg( trainX[i], trainYfile[i] +"_key_is_" + i );
            //}
        } catch (IOException e) {
            throw new RuntimeException(e);
        }


    }


    public static byte[] loadBin( String filename, int offset, int len ) throws IOException {
        byte[] bytesBuf = new byte[ len ];
        File f = new File( filename );
        FileInputStream fis = new FileInputStream( filename );
        fis.skip(offset);
        fis.read( bytesBuf, 0, len );
        return bytesBuf;
    }



    public void saveVectorAsImg( float[] doubles, String nameSuffix ){
        int width=28;
        int height=28;
            BufferedImage image = new BufferedImage( width , height , TYPE_BYTE_GRAY );

            File file = new File("image"+nameSuffix+".png");
            for ( int i=0; i<width; i++){
                int off=i*width;
                for (int j=0;j<height;j++){
                    float aDouble = (1-doubles[off + j])*254;
                    aDouble=aDouble*255;
                    image.setRGB( j, i, (int) aDouble);
                }
            }
        try {
            ImageIO.write(image ,  "png", file );
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


    public float[][] getTrainY() {
        return trainY;
    }

    public float[][] getTestY() {
        return testY;
    }

    public float[][] getTrainX() {
        return trainX;
    }

    public float[][] getTestX() {
        return testX;
    }


    public int getIndexMaxFloat( float[] floats ){
        int maxI=0;
        float val=floats[0];
            for ( int i=1;i<floats.length; i++ ){
                if ( floats[i]>val ) { val=floats[i]; maxI=i; }
            }
        return maxI;
    }

    public String toStr( float[] floats ){
        String out="[";
        for (int i=0;i<floats.length; i++){
            out+=", "+floats[i];
        }
        return out+"]";
    }


    public static float[] vectorSubstSsubZ( float[] s, float[] z ){
        float[] out = new float[ z.length];
        for ( int i=0;i<z.length; i++ ){
            out[i] = ( s[i] - z[i] );
        }
        return out;
    }



    public static float meanSquareError( float[] s, float[]z ){
        float out = 0.0f;
        for ( int i=0;i<z.length; i++ ){
            float delta = s[i] - z[i];
            out+=delta*delta;
        }
        return out;
    }

    public static float crossEntropyBinaryError2input( float[] s, float[]z ){
        float out = 0.0f;
        for ( int i=0;i<z.length; i++ ){
            float delta = s[i] - z[i];
            out+=delta*delta;
        }
        return out;
    }

    public static float crossEntropyMulticlassError( float[] z ){
        float out = 0.0f;
        for ( int i=0;i<z.length; i++ ){
            out += -Math.log( z[i] );
        }
        return out;
    }


    public static BufferedImage arrayOfFloatToImage( float[] data , int xScale ){
        int width = data.length/xScale;
        int height = 510;
        float min = data[0];
        float max = data[0];
        for ( int i=1;i< data.length;i++ ){
            if ( data[i]<min ) { min=data[i]; }
            if ( data[i]>max ) { max=data[i]; }
        }
        float delta=( max-min )/(height-10);
        BufferedImage image = new BufferedImage( width , height , TYPE_INT_RGB );

        int pointColor = (255*255*240)+(255*244)+244;
        for ( int i=0;i<width;i++ ){
            int val=(int) (( data[xScale*i]-min )/delta ) ;
            //System.out.println( "min: " + min + ", max: " + max + ", data[100*i]: " + ( data[100*i]-min )/delta );
            image.setRGB( i, 5+val , pointColor );
        }
        return image;
    }

    public static void saveImg( BufferedImage image, String nameSuffix ){
        File file = new File("image"+nameSuffix+".png");
        try {
            ImageIO.write(image ,  "png", file );
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }



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

    public static float[][] conv( float[][] X, float[][] F, float bias, int stride /* 1 */ , int padding /* 0 */  ){
        return  conv (  extendAry( X , padding ) , F,  bias , stride ) ;
    }

    public static float[][] conv( float[][] X, float[][] F, float bias  ){
        return conv( X, F , bias, 1 );
    }

    public static float[][] conv( float[][] X, float[][] F, float bias, int stride /* 1 */ ){
        int outputSize= 1+(( X.length-F.length )/stride);
        int fSize=F.length;
        float [][] Y = new float[outputSize][outputSize];
        for ( int i=0;i<outputSize;i++ ){
            for ( int j=0;j<outputSize;j++ ){
                float YIJ=bias;
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












    public static float[][] aryAdd( float[][] A, float[][] B){
        float [][] C = new float[A.length][A[0].length];
        for ( int i=0;i<A.length;i++ ){
            for ( int j=0;j<A[0].length;j++ ) {
                C[i][j] = A[i][j]+B[i][j];
            }
        }
        return C;
    }

    public static float[][] aryAdd( float[][] A, float[][] B, float[][] C, float[][] D ){
        float [][] OUT = new float[A.length][A[0].length];
        for ( int i=0;i<A.length;i++ ){
            for ( int j=0;j<A[0].length;j++ ) {
                OUT[i][j] = ( A[i][j]+B[i][j] ) + ( C[i][j]+D[i][j] );
            }
        }
        return OUT;
    }


    public static String AryToString( float[][]X ){
        StringBuffer out = new StringBuffer();
        for (int i=0;i<X.length;i++){
            out.append("\n[" );
            for ( int j=0;j<X.length;j++ ){
                out.append( " "+X[i][j]+"," );
            }
            out.append("]");
        }
        return out.toString();
    }


    public static String AryToString ( float[][][] T ){
        StringBuffer out = new StringBuffer();
        for ( int i=0;i<T.length;i++ ){
            out.append( AryToString( T[i] ));
        }
        return out.toString();
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