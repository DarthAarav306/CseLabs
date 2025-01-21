class MyThread implements Runnable {
    MyThread(String name) {

        new Thread(this, name).start();

    }

    public void run() {

        System.out.println("Exiting child thread: " + Thread.currentThread().getName());

    }

}

class ThreadDemoA {

    public static void main(String[] args) {

        MyThread mt = new MyThread("Child Thread");

        Thread t_main = Thread.currentThread();

        System.out.println("Main thread priority is " + t_main.getPriority());

        System.out.println("Exiting main thread!");

        try {

            t_main.join();

        }

        catch (InterruptedException e) {

        }

    }

}