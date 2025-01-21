// Define a class that implements the Runnable interface to create threads.
class Clicker implements Runnable {
    int click = 0; // To store the number of clicks (or iterations)
    Thread t; // A Thread object to hold the thread reference
    private volatile boolean running = true; // A flag to keep the thread running
    // Constructor to set the priority of the thread

    public Clicker(int p) {
        t = new Thread(this); // Create a new Thread object associated with this Runnable
        t.setPriority(p); // Set the priority for this thread
    }

    // The run() method will contain the logic to be executed by the thread
    public void run() {
        while (running) { // Keep looping while the thread is "running"
            click++; // Increment the click counter (this simulates work)
        }
    }

    // Method to stop the thread by setting the running flag to false
    public void stop() {
        running = false;
    }

    // Method to start the thread
    public void start() {
        t.start(); // Starts the thread and calls run() method in a separate thread of execution
    }
}

// Main class to demonstrate thread priorities
class HiLoPri {
    public static void main(String args[]) {
        // Set the priority of the main thread to maximum
        Thread.currentThread().setPriority(Thread.MAX_PRIORITY);

        // Create two Clicker objects (threads) with different priorities
        Clicker hi = new Clicker(Thread.NORM_PRIORITY + 2); // High-priority thread
        Clicker lo = new Clicker(Thread.NORM_PRIORITY - 2); // Low-priority thread

        // Start both threads
        lo.start(); // Start low-priority thread
        hi.start(); // Start high-priority thread

        try {
            // Let both threads run for 10 seconds
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        // Stop both threads after 10 seconds
        lo.stop();
        hi.stop();

        // Wait for both threads to finish their execution
        try {
            hi.t.join(); // Join ensures that main waits for hi thread to finish
            lo.t.join(); // Join ensures that main waits for lo thread to finish
        } catch (InterruptedException e) {
            System.out.println("InterruptedException caught");
        }

        // Print the number of clicks each thread was able to perform
        System.out.println("Low-priority thread: " + lo.click);
        System.out.println("High-priority thread: " + hi.click);
    }
}
