package CNN;

import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class FileReadr {
    //private final String path="D:\\SN3\\src\\main\\resources\\Data\\";
    /*
    private final String path="C:\\Users\\Bill\\Desktop\\SN3\\src\\main\\resources\\Data\\";
    private final String TestImagesName="t10k-images-idx3-ubyte";
    private final String TestLabelsName="t10k-labels-idx1-ubyte";
    private final String TrainImagesName="train-images-idx3-ubyte";
    private final String TrainLabelsName="train-labels-idx1-ubyte";
    */
    private final String path="D:\\INZ\\inz\\MixedProj\\04.CNN\\java04\\test\\CNN\\";
    private final String TestImagesName="t10k-images-idx3-ubyte";
    private final String TestLabelsName="t10k-labels-idx1-ubyte";
    private final String TrainImagesName="train-images-idx3-ubyte";
    private final String TrainLabelsName="train-labels-idx1-ubyte";

    int trainImagesSize=30000; //59900;
    int testImagesSize=10000; //59900;
    int Toffset=16;
    int Loffset=8;

    private final int[][][] train = new int[trainImagesSize][28][28];
    private final int[][][] test  = new int[testImagesSize ][28][28];

    private final List<Integer> trainIndex = new ArrayList<>( trainImagesSize );
    private final List<Integer>  testIndex = new ArrayList<>( testImagesSize );

    private Random random = new Random();





    public FileReadr() {
        try {
            // read Images for Train
            InputStream trainImg = new FileInputStream( path + TrainImagesName );
            trainImg.skip( Toffset );
            byte[] bytes = trainImg.readNBytes( trainImagesSize*784 );

            for (int n=0;n<trainImagesSize;n++){ // number of picturte
                for (int y=0;y<28;y++){
                    for (int x=0;x<28;x++) {
                        train[n][y][x]=Byte.toUnsignedInt(bytes[ (n*784) + (y*28) + x ]);
                    }
                }
            }

            // read Labels for Train
            InputStream trainLabel = new FileInputStream( path + TrainLabelsName );
            trainLabel.skip( Loffset );
            byte[] bytes2 = trainLabel.readNBytes( trainImagesSize );

            for (int n=0;n<trainImagesSize;n++){ // number of picturte
                train[n][0][0]=Byte.toUnsignedInt(bytes2[ n ]);
            }




            // TEST
            // read Images for Test
            InputStream testImg = new FileInputStream( path + TestImagesName );
            testImg.skip( Toffset );
            byte[] bytes3 = testImg.readNBytes( testImagesSize*784 );

            for (int n=0;n<testImagesSize;n++){ // number of picturte
                for (int y=0;y<28;y++){
                    for (int x=0;x<28;x++) {
                        test[n][y][x]=Byte.toUnsignedInt(bytes3[ (n*784) + (y*28) + x ]);
                    }
                }
            }

            // read Labels for Test
            InputStream testLabel = new FileInputStream( path + TestLabelsName );
            testLabel.skip( Loffset );
            byte[] bytes4 = testLabel.readNBytes( testImagesSize );

            for (int n=0;n<testImagesSize;n++){ // number of picturte
                test[n][0][0]=Byte.toUnsignedInt(bytes4[ n ]);
            }

        } catch( Throwable t ){ System.out.println(t); }
    }

    public void ReloadTrainIndex(){ /*System.out.println( "ReloadTrainIndex" ); */ trainIndex.clear();  for ( int i=0;i<trainImagesSize;i++ ) trainIndex.add( i ); }
    public void ReloadTestIndex(){  /*System.out.println( "ReloadTextIndex" ); */  testIndex.clear();   for ( int i=0;i<testImagesSize;i++ )  testIndex.add( i ); }

    public  int[][] getTrain( int i ) { return getItem( i , true ); }
    public  int[][] getTest ( int i ) { return getItem( i , false ); }
    private int[][] getItem ( int i , boolean isTrain ){
       return ( isTrain ) ? train[ i ] : test[ i ];
    }


    public int[][]  getNextTrainX(){ return getNextX( true );  }
    public int[][]  getNextTestX() { return getNextX( false ); }
    private int[][] getNextX( Boolean isTrain ){
        int i=0; int j=0;
        if ( isTrain ){
            if ( trainIndex.size()==0  ) { ReloadTrainIndex(); }
            i = random.nextInt( trainIndex.size() );
            j = trainIndex.remove( i );
        } else {
            if ( testIndex.size()==0  ) { ReloadTestIndex(); }
            i = random.nextInt( testIndex.size() );
            j = testIndex.remove( i );
        }
        return getItem ( j, isTrain );
    }

}
