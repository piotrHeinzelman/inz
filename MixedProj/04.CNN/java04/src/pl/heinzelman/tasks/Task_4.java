package pl.heinzelman.tasks;

import pl.heinzelman.tools.Tools2;

public class Task_4 implements Task{

    private Tools2 tools = new Tools2();

    public void prepare() {

    }

    public float[][] forward_( float[][] X ){
        return null;
    }

    public float[][][] backward_( float[][] gradient ){
        return null;
    }


// *********************

    @Override
    public void run() {
        train();
    }

    public void train(){

    }

    public void test(){

    }



}


