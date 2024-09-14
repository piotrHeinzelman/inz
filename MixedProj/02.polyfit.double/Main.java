
import java.util.Arrays;
import java.sql.Time;
import java.sql.Timestamp;
import java.time.Instant;
import java.time.temporal.ChronoUnit;

public class Main {

    public static void main(String[] args) {
    double[] x = new double[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    double[] y = new double[]{ -1.69, -0.79, 5.77, 7.80, 4.56, 14.32, 15.47, 8.88, 7.41, 17.26, 14.83, 20.47, 20.39, 27.04, 22.53, 22.36, 29.35, 22.86, 31.22, 28.13  };

    double w1 = 0.0;
    double w0 = 0.0;
    Long cycles = 987L;

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






















