import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.time.Instant;
import java.time.temporal.ChronoUnit;

public class Main {

    public static double[] loadBin( String filename ) throws IOException {
        double[] buf = null;
        int len;

        File f = new File(filename);
        len = (int) ( 0.125 * f.length());
        buf = new double[ len ];

        FileInputStream fis = new FileInputStream( filename );
        byte[] bB=new byte[8];
        byte[] bR=new byte[8];
        double val=0;
        for ( int i=0;i<len;i++ ) {

            fis.read(bB,0,8);
            bR[0]=bB[7];
            bR[1]=bB[6];
            bR[2]=bB[5];
            bR[3]=bB[4];
            bR[4]=bB[3];
            bR[5]=bB[2];
            bR[6]=bB[1];
            bR[7]=bB[0];
            val=ByteBuffer.wrap(bR).getDouble();
            buf[i]=val;

        }
        return buf;
    }




    public static void main(String[] args) throws IOException {
        double[] x = loadBin("datax1_double.bin");
        double[] y = loadBin("datay1_double.bin");

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


















