public class InterruptTest extends Thread {

    public void run() {

        try {

            System.out.println("Thread is sleeping");

            Thread.sleep(5000);

        } catch (InterruptedException e) {

            System.out.println("Thread was interrupted");

        }

        System.out.println("Thread finished");

    }

    public static void main(String[] args) throws InterruptedException {

        InterruptTest t = new InterruptTest();

        t.start();

        Thread.sleep(2000); // Main thread sleeps for 2 seconds

        t.interrupt();

        t.join();

        System.out.println("Main thread finished");

    }

}