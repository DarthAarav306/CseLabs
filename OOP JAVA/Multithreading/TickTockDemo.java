class TickTock {
    String state; // To keep track of the current state

    synchronized void tick(boolean running) {
        if (!running) { // Stop the clock
            state = "ticked";
            notify(); // Notify any waiting thread
            return;
        }

        System.out.print("Tick ");

        state = "ticked"; // Set the state to "ticked"

        notify(); // Notify the waiting thread (which is waiting in tock())

        try {
            while (!state.equals("tocked")) {
                wait(); // Wait for the state to change to "tocked"
            }
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted.");
        }
    }

    synchronized void tock(boolean running) {
        if (!running) { // Stop the clock
            state = "tocked";
            notify(); // Notify any waiting thread
            return;
        }

        System.out.println("Tock");

        state = "tocked"; // Set the state to "tocked"

        notify(); // Notify the waiting thread (which is waiting in tick())

        try {
            while (!state.equals("ticked")) {
                wait(); // Wait for the state to change to "ticked"
            }
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted.");
        }
    }
}

class MyThread implements Runnable {
    Thread t;
    TickTock ttOb;

    // Constructor that accepts a TickTock object and a name for the thread
    MyThread(String name, TickTock tt) {
        t = new Thread(this, name);
        ttOb = tt;
        t.start(); // Start the thread when the object is created
    }

    public void run() {
        if (t.getName().equals("Tick")) {
            for (int i = 0; i < 5; i++) {
                ttOb.tick(true); // Print "Tick"
            }
            ttOb.tick(false); // Stop the clock
        } else {
            for (int i = 0; i < 5; i++) {
                ttOb.tock(true); // Print "Tock"
            }
            ttOb.tock(false); // Stop the clock
        }
    }
}

public class TickTockDemo {
    public static void main(String[] args) {
        TickTock tt = new TickTock(); // Create a TickTock object

        // Create two threads: one for "Tick" and one for "Tock"
        MyThread mt1 = new MyThread("Tick", tt);
        MyThread mt2 = new MyThread("Tock", tt);

        // Wait for both threads to finish
        try {
            mt1.t.join();
            mt2.t.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        System.out.println("Clock stopped.");
    }
}
