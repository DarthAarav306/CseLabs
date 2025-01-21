// Class extending Thread
class MyExtendedThread extends Thread {
    private String threadName;

    // Constructor to initialize thread name
    MyExtendedThread(String threadName) {
        this.threadName = threadName;
    }

    // Entry point for the thread
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(threadName + " - Iteration: " + i);
            try {
                Thread.sleep(1000); // Simulating some work by making the thread sleep for 1 second
            } catch (InterruptedException e) {
                System.out.println(threadName + " was interrupted.");
            }
        }
        System.out.println(threadName + " has completed execution.");
    }
}

public class ExtendedThreadDemo {
    public static void main(String[] args) {
        // Create thread objects by extending Thread class
        MyExtendedThread thread1 = new MyExtendedThread("Extended Thread 1");
        MyExtendedThread thread2 = new MyExtendedThread("Extended Thread 2");

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

        System.out.println("Both Extended-Thread-based threads have finished execution.");
    }
}
