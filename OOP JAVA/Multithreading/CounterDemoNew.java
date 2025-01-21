class Counter {
    private int count = 0;

    synchronized void increment() {
        try {
            while (count >= 3) {
                System.out.println("Count is equal to 3, so waiting...");
                wait();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        count++;
        System.out.println("Count incremented to " + count);
        notify(); // Notify the other thread after incrementing
    }

    synchronized void decrement() {
        try {
            while (count <= 0) {
                System.out.println("Waiting because count is less than or equal to 0...");
                wait();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        count--;
        System.out.println("Count decremented to " + count);
        notify(); // Notify the other thread after decrementing
    }
}

class IncDec extends Thread {
    Counter counter;
    boolean increment;

    IncDec(boolean increment, Counter counter) {
        this.counter = counter;
        this.increment = increment;
    }

    public void run() {
        try {
            for (int i = 0; i < 20; i++) {
                if (increment) {
                    counter.increment();
                } else {
                    counter.decrement();
                }
                // Sleep for a random amount of time between 0 and 500 milliseconds
                Thread.sleep((int) (Math.random() * 500));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class CounterDemoNew {
    public static void main(String[] args) {
        Counter counter = new Counter();
        IncDec inc = new IncDec(true, counter); // Thread to increment
        IncDec dec = new IncDec(false, counter); // Thread to decrement

        inc.start();
        dec.start();

        try {
            inc.join();
            dec.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("All done!");
    }
}
