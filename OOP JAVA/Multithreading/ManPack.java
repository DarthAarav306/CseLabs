class Warehouse {
    private final int MAX_CAPACITY = 5; // Maximum buffer size
    private final String[] buffer = new String[MAX_CAPACITY]; // Shared buffer array
    private int count = 0; // Number of products in the buffer

    // Manufacturer adds a product to the buffer
    public synchronized void produce(int productId) {
        try {
            while (count == MAX_CAPACITY) { // Buffer is full
                System.out.println("Buffer is full. Manufacturer is waiting...");
                wait(); // Wait for space in the buffer
            }

            buffer[count] = "Product-" + productId; // Add product to the buffer
            count++;
            System.out.println("Produced: Product-" + productId + " | Buffer size: " + count);
            notify(); // Notify the Packager thread
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    // Packager takes a product from the buffer
    public synchronized void consume() {
        try {
            while (count == 0) { // Buffer is empty
                System.out.println("Buffer is empty. Packager is waiting...");
                wait(); // Wait for a product to be available
            }

            String product = buffer[--count]; // Remove product from the buffer
            System.out.println("Packaged: " + product + " | Buffer size: " + count);
            notify(); // Notify the Manufacturer thread
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Manufacturer implements Runnable {
    private final Warehouse warehouse;

    Manufacturer(Warehouse warehouse) {
        this.warehouse = warehouse;
        new Thread(this, "Manufacturer").start();
    }

    public void run() {
        int productCount = 1;
        while (true) {
            warehouse.produce(productCount); // Produce product with an ID
            productCount++;
            try {
                Thread.sleep(1000); // Simulate production time
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Packager implements Runnable {
    private final Warehouse warehouse;

    Packager(Warehouse warehouse) {
        this.warehouse = warehouse;
        new Thread(this, "Packager").start();
    }

    public void run() {
        while (true) {
            warehouse.consume(); // Consume a product
            try {
                Thread.sleep(1500); // Simulate packaging time
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class ManPack {
    public static void main(String[] args) {
        Warehouse warehouse = new Warehouse();
        new Manufacturer(warehouse); // Start the Manufacturer thread
        new Packager(warehouse);     // Start the Packager thread
    }
}

