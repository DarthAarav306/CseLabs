class Counter {
    private int count;
    boolean shouldCount = true;

    void setCount(int count) {
        this.count = count;
    }

    int getCount() {

        return count;
    }

    synchronized void increment() {
        try {
            while (count >= 3) {
                System.out.println("Count is 3 cant increment");
                wait();
            }
        } catch (InterruptedException exc) {
            exc.printStackTrace();
        }
        count++;
        System.out.println("Count is " + count);
        notify();
    }

    synchronized void decrement() {
        try {
            while (count <= 0) {
                System.out.println("Count is 0 cant decrement");
                wait();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        count--;
        System.out.println("Count is " + count);
        notify();
    }
}

class IncDec implements Runnable {
    Thread t;
    Counter count;
    boolean increment;

    IncDec(boolean increment, Counter count) {
        this.increment = increment;
        this.count = count;
        t = new Thread(this);
    }

    public void run() {
        if (increment) {
            try {
                for (int i = 0; i < 20; i++) {
                    count.increment();
                    Thread.sleep(700);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else {
            try {
                for (int i = 0; i < 20; i++) {
                    count.decrement();
                    Thread.sleep(800);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class PersonalCounter {
    public static void main(String[] args) {
        Counter count = new Counter();
        IncDec inc = new IncDec(true, count);
        IncDec dec = new IncDec(false, count);
        inc.t.start();
        dec.t.start();

        try {
            inc.t.join();
            dec.t.join();
        } catch (InterruptedException exc) {
            exc.printStackTrace();
        }
    }
}
