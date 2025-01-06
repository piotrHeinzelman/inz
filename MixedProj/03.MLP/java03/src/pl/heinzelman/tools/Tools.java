package pl.heinzelman.tools;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class Tools {

    private static String path="../data/";
    private static String testXname="t10k-images-idx3-ubyte";
    private static String testYname="t10k-labels-idx1-ubyte";
    private static String trainXname="train-images-idx3-ubyte";
    private static String trainYname="train-labels-idx1-ubyte";

    private byte[] trainYfile=null;
    private byte[] testYfile=null;
    private double[][] trainY=null;
    private double[][] testY=null;

    private double[][] trainX=null;
    private double[][] testX=null;

    public  void prepareData( int percent ){

        try {
            trainYfile =  loadBin( path + trainYname,  8, percent*600 ); // offset=8, size=percent*600  // OK
            testYfile =  loadBin( path + testYname,   8, percent*100 );   // offset=8, size=percent*100 // OK

            trainY = new double[percent*600][];
            testY  = new double[percent*100][];
            //train Y
            for (int i=0;i<percent*600;i++){
                trainY[i] = new double[]{ 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d };
                trainY[i][ trainYfile[i] ]=1.0d;
            }
            // test Y
            for (int i=0;i<percent*100;i++){
                testY[i] = new double[]{ 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d, 0.0d };
                testY[i][ testYfile[i] ]=1.0d;
            }

            // byte[] trainXfile =  loadBin( path + trainXname, 16, percent*784*600 );// offset=16 size=percent*784*600
           // byte[] testXfile =   loadBin( path + testXname,  16, percent*784*100 );   // offset=16, size=percent*784*100



            System.out.println( testY );
            double[] doubles = testY[0];


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


}