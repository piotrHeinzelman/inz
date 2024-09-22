package pl.heinzelman;

import pl.heinzelman.tasks.*;

public class Main {

    public static void main(String[] args) {

    Task task;
    // task = new TaskForLoop2sek(); //
    // task = new Task2x3_simple_backward();
     task = new Task3x1CrossEntropy();
    //   task = new Task3x2SoftMax();
    task.doTask();


    }
}
