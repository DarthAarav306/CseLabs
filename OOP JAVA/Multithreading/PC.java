// Class representing the Queue (shared resource)
class Q {
    private int n;
    private boolean valueSet = false; // To track if there's data to consume

    // Producer will call this to put data in the queue
    synchronized void put(int n) {
        while (valueSet) {
            try {
                wait(); // Wait until the consumer consumes the data
            } catch (InterruptedException e) {
                System.out.println("InterruptedException caught");
            }
        }
        this.n = n; // Producer produces data
        System.out.println("Produced: " + n);
        valueSet = true; // Mark that data is ready to be consumed
        notify(); // Notify the consumer that data is available
    }

    // Consumer will call this to get data from the queue
    synchronized int get() {
        while (!valueSet) {
            try {
                wait(); // Wait until the producer produces data
            } catch (InterruptedException e) {
                System.out.println("InterruptedException caught");
            }
        }
        System.out.println("Consumed: " + n);
        valueSet = false; // Mark that data has been consumed
        notify(); // Notify the producer that there's space for more data
        return n;
    }
}

// Producer class (Thread)
class Producer implements Runnable {
    Q q; // Shared queue
    Thread t;

    Producer(Q q) {
        this.q = q;
        t = new Thread(this, "Producer");
        t.start(); // Start the producer thread
    }

    public void run() {
        int i = 0;
        while (true) {
            q.put(i++); // Produce increasing integers and put them in the queue
            try {
                Thread.sleep(1000); // Simulate production time
            } catch (InterruptedException e) {
                System.out.println("Producer interrupted.");
            }
        }
    }
}

// Consumer class (Thread)
class Consumer implements Runnable {
    Q q; // Shared queue
    Thread t;

    Consumer(Q q) {
        this.q = q;
        t = new Thread(this, "Consumer");
        t.start(); // Start the consumer thread
    }

    public void run() {
        while (true) {
            q.get(); // Consume items from the queue
            try {
                Thread.sleep(1000); // Simulate consumption time
            } catch (InterruptedException e) {
                System.out.println("Consumer interrupted.");
            }
        }
    }
}

// Main class to create the Producer, Consumer, and Queue
public class PC {
    public static void main(String[] args) {
        Q q = new Q(); // Create a single shared queue

        // Create Producer and Consumer, passing them the same queue
        new Producer(q);
        new Consumer(q);

        // Main thread has nothing more to do, so it can exit
    }
}
