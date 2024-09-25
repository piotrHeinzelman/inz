import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.math.BigDecimal;
import java.nio.ByteBuffer;
import java.time.Instant;
import java.time.temporal.ChronoUnit;

public class MainBigDecimal {

    public static BigDecimal[] loadBin( String filename ) throws IOException {
        BigDecimal[] buf = null;
        int len;

        File f = new File(filename);
        len = (int) ( 0.125 * f.length());
        buf = new BigDecimal[ len ];

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
            buf[i]=  BigDecimal.valueOf( val );

        }
        return buf;
    }




    public static void main(String[] args) throws IOException {

        System.out.println( 0.1 + 0.2 );
        BigDecimal[] x = loadBin("datax1_double.bin");
        BigDecimal[] y = loadBin("datay1_double.bin");

        BigDecimal w1 = BigDecimal.ZERO;
        BigDecimal w0 = BigDecimal.ZERO;

        Double w1d=null;
        Double w0d=null;
    Long cycles = 1000L;

    Instant start = Instant.now();
    for ( int C=0; C<cycles; C++ ) {
        // -- start
        BigDecimal xsr =  BigDecimal.ZERO;
        BigDecimal ysr = BigDecimal.ZERO;
        for (int i = 0; i < x.length; i++) {
            xsr=xsr.add( x[i]);
            ysr=ysr.add( y[i]);
        }
        xsr = xsr.divide( BigDecimal.valueOf( x.length ));
        ysr = ysr.divide( BigDecimal.valueOf( y.length ));

        w1 = BigDecimal.ZERO;
        w0 = BigDecimal.ZERO;
        BigDecimal sumTop = BigDecimal.ZERO;
        BigDecimal sumBottom = BigDecimal.ZERO;
        for (int i = 0; i < x.length; i++) {
            sumTop = sumTop.add ( x[i].subtract( xsr) ).multiply( y[i].subtract( ysr ) );
            sumBottom = sumBottom.add ( x[i].subtract(xsr)).multiply( x[i].subtract(xsr));
        }

         w1d = sumTop.doubleValue() /  sumBottom.doubleValue();
         w0d = ysr.doubleValue()/( w1d*(xsr.doubleValue()));
        //
    }
    Instant end = Instant.now();
    System.out.println( " duration: " + (ChronoUnit.MILLIS.between(start, end)/1000.0) + " [sek.]");
    System.out.println( "");
    System.out.println( " X[" + x.length + "] * " + cycles);
    System.out.println( " result: [" + w1d + ", " + w0d + "]" );
    }
}


















