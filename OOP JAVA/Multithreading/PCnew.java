//Write and execute a java program to implement a producer and consumer problem using Inter-thread communication. 

class Q {
    boolean valueSet = false;
    int num;

    synchronized void put(int num) {
        try {
            while (valueSet) {
                wait();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        valueSet = true;
        this.num = num;
        System.out.println("Produced:- " + num);
        notify();
    }

    synchronized int get() {
        try {
            while (!valueSet) {
                wait();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        valueSet = false;
        System.out.println("Consumed:- " + num);
        notify();
        return num;
    }
}

class Producer implements Runnable {
    Thread t;
    Q q;
    int i = 0;

    Producer(Q q) {
        t = new Thread(this);
        this.q = q;
    }

    public void run() {
        try {
            while (true) {
                q.put(i++);
                Thread.sleep(800);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class Consumer implements Runnable {
    Thread t;
    Q q;

    Consumer(Q q) {
        t = new Thread(this);
        this.q = q;
    }

    public void run() {
        try {
            while (true) {
                q.get();
                Thread.sleep(800);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class PCnew {
    public static void main(String[] args) {
        Q q = new Q();
        Producer producer = new Producer(q);
        Consumer consumer = new Consumer(q);
        producer.t.start();
        consumer.t.start();

    }
}