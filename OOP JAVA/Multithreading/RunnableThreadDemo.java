// Class implementing Runnable interface
class MyRunnableTask implements Runnable {
    private String taskName;

    // Constructor to initialize task name
    MyRunnableTask(String taskName) {
        this.taskName = taskName;
    }

    // Entry point for the thread
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(taskName + " - Iteration: " + i);
            try {
                Thread.sleep(1000); // Simulating some work by making the thread sleep for 1 second
            } catch (InterruptedException e) {
                System.out.println(taskName + " was interrupted.");
            }
        }
        System.out.println(taskName + " has completed execution.");
    }
}

public class RunnableThreadDemo {
    public static void main(String[] args) {
        // Create two Runnable tasks
        MyRunnableTask task1 = new MyRunnableTask("Runnable Task 1");
        MyRunnableTask task2 = new MyRunnableTask("Runnable Task 2");

        // Create Thread objects and associate them with Runnable tasks
        Thread thread1 = new Thread(task1);
        Thread thread2 = new Thread(task2);

        // Start the threads
        thread1.start();
        thread2.start();

        // Ensure main waits for both threads to complete
        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        System.out.println("Both Runnable-based threads have finished execution.");
    }
}
