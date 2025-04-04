
// git@github.com:eliasyilma/CNN.git

package pl.heinzelman;

import pl.heinzelman.tasks.*;

public class Main {
// https://zzutk.github.io/docs/reports/2016.10%20-%20Derivation%20of%20Backpropagation%20in%20Convolutional%20Neural%20Network%20(CNN).pdf
    public static void main(String[] args) {
        Task task;
        //task = new Task_64_64_simple_backward();
        task = new Task_CNN();
        task.doTask();
    }
}

