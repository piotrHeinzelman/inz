import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.Arrays;

public class Main {

    public static int[] loadBin( String filename ) throws IOException {
        int[] buf = null;
        int len;

        File f = new File(filename);
        len = (int) ( 0.5 * f.length());
        buf = new int[ len ];


        FileInputStream fis = new FileInputStream( filename );
            for ( int i=0;i<len;i++ ) {
                int read = fis.read();
                int read2 = fis.read();
                buf[i] = ( int ) (read2*256+read);
            }
        return buf;
    }



    public static void main(String[] args) throws IOException {
        int[] x = loadBin("datax_uint16.bin");
        int[] y = loadBin("datay_uint16.bin");

    double w1 = 0.0;
    double w0 = 0.0;
    Long cycles = 1000L;

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
        for ( int i = 0; i < x.length; i++ ) {
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






















