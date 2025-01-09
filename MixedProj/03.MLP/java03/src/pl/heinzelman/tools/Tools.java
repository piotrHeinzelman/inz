package pl.heinzelman.tools;


import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.RenderedImage;
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


            byte[] trainXfile = loadBin(path + trainXname, 16, percent * 784 * 600);// offset=16 size=percent*784*600
            trainX=new double[percent*600][784];
            for (int i=0;i<percent*100;i++) {
                int off=i*784;
                for (int j=0;j<784;j++){
                    trainX[i][j]=Byte.toUnsignedInt( trainXfile[off+j] )/256.0; //0-1
                    //System.out.println( trainX[i][j] );
                }
            }

            byte[] testXfile =   loadBin( path + testXname,  16, percent*784*100 );   // offset=16, size=percent*784*100
            testX=new double[percent*100][784];
            for (int i=0;i<percent*100;i++) {
                int off=i*784;
                for (int j=0;j<784;j++){
                    testX[i][j]=Byte.toUnsignedInt( testXfile[off+j] )/256.0;
                }
            }

            // show data:
            for ( int i=0;i<100;i++ ) {
                saveVectorAsImg(trainX[i], trainYfile[i] +"_key_is_" + i );
            }
            //System.out.println( testY[1][0] );
            //System.out.println( trainXfile.length );
            //double[] doubles = testY[0];


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



    public void saveVectorAsImg( double[] doubles, String nameSuffix ){
        int width=28;
        int height=28;
            BufferedImage image = new BufferedImage( width , height , TYPE_BYTE_GRAY );

            File file = new File("image"+nameSuffix+".png");
            for ( int i=0; i<width; i++){
                int off=i*width;
                for (int j=0;j<height;j++){
                    double aDouble = (1-doubles[off + j])*254;
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




}