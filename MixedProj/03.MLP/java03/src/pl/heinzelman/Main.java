package pl.heinzelman;

import pl.heinzelman.tasks.*;
import pl.heinzelman.tools.Tools;

public class Main {

    public static void main(String[] args) {

        Tools tools = new Tools();
        tools.prepareData( 1 );
        if (true) return;

        Task task;
        task = new Task_64_64_simple_backward();
        task.doTask();
    }
}
        