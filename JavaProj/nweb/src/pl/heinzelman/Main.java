package pl.heinzelman;

import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;
import pl.heinzelman.tasks.Task;
import pl.heinzelman.tasks.Task2x3_simple_backward;
import pl.heinzelman.tasks.Task3x1CrossEntropy;
import pl.heinzelman.tasks.TaskForLoop2sek;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {

    Task task;
    // task = new TaskForLoop2sek(); //
    //    task = new Task2x3_simple_backward();
          task = new Task3x1CrossEntropy();
    task.doTask();




    }
}
