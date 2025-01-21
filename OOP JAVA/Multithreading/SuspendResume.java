// Suspending and resuming a thread for Java using mysuspend and myresume

class NewThread implements Runnable {
    String name; // name of thread
    Thread t;
    boolean suspendFlag; // flag to control suspension

    // Constructor to initialize the thread
    NewThread(String threadname) {
        name = threadname;
        t = new Thread(this, name);
        System.out.println("New thread: " + t);
        suspendFlag = false; // initially, the thread is not suspended
        t.start(); // Start the thread
    }

    // Entry point for the thread
    public void run() {
        try {
            for (int i = 15; i > 0; i--) {
                System.out.println(name + ": " + i);
                Thread.sleep(200); // simulate work
                synchronized (this) {
                    while (suspendFlag) {
                        wait(); // wait if the thread is suspended
                    }
                }
            }
        } catch (InterruptedException e) {
            System.out.println(name + " interrupted.");
        }
        System.out.println(name + " exiting.");
    }

    // Method to suspend the thread
    void mysuspend() {
        suspendFlag = true; // set the suspend flag to true
    }

    // Method to resume the thread
    synchronized void myresume() {
        suspendFlag = false; // clear the suspend flag
        notify(); // notify the thread to resume
    }
}

public class SuspendResume {
    public static void main(String[] args) {
        // Create two threads
        NewThread ob1 = new NewThread("One");
        NewThread ob2 = new NewThread("Two");

        try {
            // Let threads run for some time
            Thread.sleep(1000);

            // Suspend Thread One
            ob1.mysuspend();
            System.out.println("Suspending thread One");
            Thread.sleep(1000);

            // Resume Thread One
            ob1.myresume();
            System.out.println("Resuming thread One");

            // Suspend Thread Two
            ob2.mysuspend();
            System.out.println("Suspending thread Two");
            Thread.sleep(1000);

            // Resume Thread Two
            ob2.myresume();
            System.out.println("Resuming thread Two");
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        // Wait for threads to finish
        try {
            System.out.println("Waiting for threads to finish.");
            ob1.t.join();
            ob2.t.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        System.out.println("Main thread exiting.");
    }
}
