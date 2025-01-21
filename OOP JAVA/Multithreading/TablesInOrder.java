class MultiplicationTable extends Thread {
    private int number;

    MultiplicationTable(int number) {
        this.number = number;
    }

    public void run() {
        System.out.println("Multiplication Table for " + number);
        for (int i = 1; i <= 10; i++) {
            System.out.println(number + " x " + i + " = " + (number * i));
        }
        System.out.println("Finished printing table for " + number + "\n");
    }
}

public class TablesInOrder {
    public static void main(String[] args) {
        MultiplicationTable tableOf5 = new MultiplicationTable(5);
        MultiplicationTable tableOf7 = new MultiplicationTable(7);

        tableOf5.start();
        try {
            tableOf5.join(); // Ensure table of 5 finishes before starting the next
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        tableOf7.start();
        try {
            tableOf7.join(); // Ensure table of 7 finishes before main thread completes
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Main thread exiting.");
    }
}
