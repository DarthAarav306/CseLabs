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

public class Tables {
    public static void main(String[] args) {
        MultiplicationTable tableOf5 = new MultiplicationTable(5);
        MultiplicationTable tableOf7 = new MultiplicationTable(7);
        tableOf5.start();
        tableOf7.start();
        try {
            tableOf5.join();
            tableOf7.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        System.out.println("Both multiplication tables completed.");
    }
}
