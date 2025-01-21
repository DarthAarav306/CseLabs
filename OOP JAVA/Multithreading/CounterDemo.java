// Counter class with synchronized increment and decrement methods
class Counter {
    private int count = 0;

    // Synchronized method to increment the count
    public synchronized void increment() {
        // If count is already at 3, wait until it's less than 3
        while (count >= 3) {
            try {
                System.out.println("Counter is at maximum (3). Waiting to increment...");
                wait(); // Wait until notified
            } catch (InterruptedException e) {
                System.out.println("Interrupted while waiting to increment.");
            }
        }

        // Increment the count and notify waiting threads
        count++;
        System.out.println("Incremented: Counter = " + count);
        notifyAll(); // Notify any waiting threads (likely decrement)
    }

    // Synchronized method to decrement the count
    public synchronized void decrement() {
        // If count is already at 0, wait until it's greater than 0
        while (count <= 0) {
            try {
                System.out.println("Counter is at minimum (0). Waiting to decrement...");
                wait(); // Wait until notified
            } catch (InterruptedException e) {
                System.out.println("Interrupted while waiting to decrement.");
            }
        }

        // Decrement the count and notify waiting threads
        count--;
        System.out.println("Decremented: Counter = " + count);
        notifyAll(); // Notify any waiting threads (likely increment)
    }
}

// A class to increment and decrement the counter in separate threads
class CounterUser implements Runnable {
    private Counter counter;
    private boolean increment; // True if incrementing, false if decrementing

    public CounterUser(Counter counter, boolean increment) {
        this.counter = counter;
        this.increment = increment;
    }

    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            if (increment) {
                counter.increment();
            } else {
                counter.decrement();
            }

            try {
                // Sleep for a random time between 0 and 500 milliseconds
                Thread.sleep((int) (Math.random() * 500));
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted during sleep.");
            }
        }
    }
}

public class CounterDemo {
    public static void main(String[] args) {
        Counter counter = new Counter();

        // Create two threads: one for incrementing and one for decrementing
        Thread incrementThread = new Thread(new CounterUser(counter, true));
        Thread decrementThread = new Thread(new CounterUser(counter, false));

        // Start the threads
        incrementThread.start();
        decrementThread.start();

        // Wait for both threads to complete
        try {
            incrementThread.join();
            decrementThread.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        System.out.println("Both threads have finished execution.");
    }
}
