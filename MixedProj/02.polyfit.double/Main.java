
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.Arrays;
import java.sql.Time;
import java.sql.Timestamp;
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.Scanner;

public class Main {

    public static float[] loadBin( String filename ) throws IOException {
        float[] buf = null;
        int len;

        File f = new File(filename);
        len = (int) ( 0.125 * f.length());
        buf = new float[ len ];


        Scanner scanner;
        FileInputStream fis = new FileInputStream( filename );
            int[] bB=new int[8];
            for ( int i=0;i<len;i++ ) {
                 bB[0] = fis.read();
                 bB[1] = fis.read();
                 bB[2] = fis.read();
                 bB[3] = fis.read();
                 bB[4] = fis.read();
                 bB[5] = fis.read();
                 bB[6] = fis.read();
                 bB[7] = fis.read();
                System.out.println( bB[0]+"."+bB[1]+"."+bB[2]+"."+bB[3]+":"+bB[4]+"."+bB[5]+"."+bB[6]+"."+bB[7] );


            }
        return buf;
    }


    public static void main(String[] args) throws IOException {
        float[] x = loadBin("datax1_double.bin");
        float[] y = loadBin("datay1_double.bin");

    double w1 = 0.0;
    double w0 = 0.0;
    Long cycles = 987654L;

    Instant start = Instant.now();
    for ( int C=0; C<cycles; C++ ) {
        // -- start
        double xsr = 0.0;
        double ysr = 0.0;
        for (int i = 0; i < x.length; i++) {
            xsr += x[i];
            ysr += y[i];
        }
        xsr = xsr / x.length;
        ysr = ysr / y.length;

        w1 = 0.0;
        w0 = 0.0;
        double sumTop = 0.0;
        double sumBottom = 0.0;
        for (int i = 0; i < x.length; i++) {
            sumTop += ((x[i] - xsr) * (y[i] - ysr));
            sumBottom += ((x[i] - xsr) * (x[i] - xsr));
        }
        w1 = sumTop / sumBottom;
        w0 = ysr - w1 * xsr;
        //
    }
    Instant end = Instant.now();
    System.out.println( " duration: " + (ChronoUnit.MILLIS.between(start, end)/1000.0) + " [sek.]");
    System.out.println( "");
    System.out.println( " X[" + x.length + "] * " + cycles);
    System.out.println( " result: [" + w1 + ", " + w0 + "]" );
    }
}


















