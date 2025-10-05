package pl.heinzelman.LayerDeep;

import org.junit.Test;

import java.util.Random;

public class randTest {

    @Test
    public void randTest(){
        Random rand = new Random();
        for (int i=0;i<100;i++,System.out.println( rand.nextFloat() ));
    }
}
