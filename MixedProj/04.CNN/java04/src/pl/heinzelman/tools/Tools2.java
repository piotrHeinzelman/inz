package pl.heinzelman.tools;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;


public class Tools2 {

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
                    trainX[i][j]=Byte.toUnsignedInt( trainXfile[off+j] )/254.0f;///256.0f; //0-1
                    //System.out.println( trainX[i][j] );
                }
            }

            byte[] testXfile =   loadBin( path + testXname,  16, percent*784*100 );   // offset=16, size=percent*784*100
            testX=new float[percent*100][784];
            for (int i=0;i<percent*100;i++) {
                int off=i*784;
                for (int j=0;j<784;j++){
                    testX[i][j]=Byte.toUnsignedInt( testXfile[off+j] )/254.0f;///256.0f;
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

    public static float[][] convertToSquare28x28( float[] vector ){
        float[][] square = new float[28][28];
        for ( int y=0;y<28;y++ ){
            for ( int x=0;x<28;x++ ) {
                square[y][x]=vector[x+28*y];
            }
        }
        return square;
    }


    public int getIndexMaxFloat(float[] floats ){
        int maxI=0;
        float val=0f + floats[0];
        for ( int i=1;i<floats.length; i++ ){
            if ( 0f+floats[i] > val ) { val=floats[i]; maxI=i; }
        }
        return maxI;
    }

    public float[][] getTrainY() { return trainY; }
    public float[][] getTestY()  { return testY;  }
    public float[][] getTrainX() { return trainX; }
    public float[][] getTestX()  { return testX;  }

    public static String AryToString( float[]X ){
        return Arrays.toString( X );
    }
    public static String AryToString( float[][]X ){
        StringBuffer out = new StringBuffer();
        out.append("[");
        for (int i=0;i<X.length;i++) {
            out.append(""+Arrays.toString( X[i])+"\n");
        }
        out.append("]");
        return out.toString();
    }


}
