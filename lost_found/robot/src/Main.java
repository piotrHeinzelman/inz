import java.awt.*;
import java.awt.event.InputEvent;

public class Main {
    private static Robot robot;
    public static void main(String[] args) {

        System.out.println("Hello world!");



        try {
             robot = new Robot();


            Thread.sleep(1000 );

            if (true) return;

            //getBonus();

            //
            //if (true) return;

            while ( true ){
            gotoPage(1);
            getBonus();
            clickAllTrains();
            gotoBlue();
            getBonus();
            gotoPage(1);
            robot.delay(1000*15);
            robot.delay(1000*15);
            robot.delay(1000*15);
                getBonus();
                waitInMin( 1 );
                getBonus();
                waitInMin( 1 );
                getBonus();
                waitInMin( 1 );
                getBonus();
                waitInMin( 1 );
                //resend( 13 );
            //    waitInMin( 3 );
            //    getBonus();
            //    clickTrains();
            //    robot.delay(1000*15); // Click one second
            //    clickTrains();
            //    getBonus();
            //    robot.delay(1000*15); // Click one second
            //    clickTrains();
            }


            /*
            // (1) =
            robot.mouseMove(786,325);
            click();
moment();

            //(2)
            robot.mouseMove(786+36,325);
            click();
moment();
            //(3)
            robot.mouseMove(786+2*36,325);
            click();
moment();
            //(4)
            robot.mouseMove(786+3*36,325);
            click();
            moment();
/*
            robot.mouseMove(1530,670);
            click();
            click();
            robot.delay(8*1000); // Click one second
            click();
            click();
            robot.delay(8*1000); // Click one second
            click();
            click();
*/



        } catch (AWTException e) {
            throw new RuntimeException(e);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }


    }



    public static void click(){
        robot.mousePress(InputEvent.BUTTON1_MASK);
        robot.delay(300); // Click one second
        robot.mouseRelease(InputEvent.BUTTON1_MASK);
        robot.delay(300); // Click one second
    }

    public static void moment(){
        robot.delay(100); // Click one second
    }

    public static void resend( int times ){
        robot.mouseMove(786,325);
        click();
        moment();

        for ( int i=0; i<times; i++ ) {
            robot.mouseMove(1600, 725);
            click();
            moment();
            robot.delay(7 * 1000);
        }

    }

    public static void gotoPage( int i) {
        robot.mouseMove(786+(i-1)*36,325);
        click();
        moment();
    }


    public static void getBonus(){
        robot.mouseMove(206,325);
        click();
        moment();
        moment();
        click();
        moment();
        moment();

    }

    public static void clickAllTrains() throws InterruptedException {
        clickTrains();
        getBonus();
        Thread.sleep(5000);
        clickTrains();
        getBonus();
        Thread.sleep(5000);
    }


    public static void clickTrains() throws InterruptedException {
        for (int i=0;i<12;i++) {
            //robot.mouseMove(1270+10*i, 770 - i * 8);
            //click();
            //moment();
            //robot.mouseMove(1100, 815);
            //click();
            //moment();

            // click rotate
            robot.mouseMove(1500, 735);
            click();
            moment();
            Thread.sleep(1500);
        }
    }

    public static void waitInMin(int i){
        for ( int j=1;j<i;j++) {
            robot.delay(1000 * 30 ); // Click one second
            System.out.println( " ");
            robot.delay(1000 * 30 ); // Click one second
        }
    }


    public static void  gotoBlue(){
        robot.mouseMove(45, 450);
        click();
        for (int i=0;i<12;i++) {
            robot.mouseMove(870+i*(100/12), 760-5*i );
            //robot.mouseMove(970, 700 );
            click();
            moment();
        }
    }

}