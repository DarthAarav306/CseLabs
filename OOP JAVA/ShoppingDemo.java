import java.util.Scanner;

class Shopping {
    private String customerName;
    private int customerId;
    private String productName;
    private int productId;
    private double unitPrice;
    private int quantity;
    private double cost;
    static int totalOrders = 0;
    static double discountRate = 0.09;

    // Default Constructor
    Shopping() {
        this.customerName = "Default Name";
        this.customerId = 000000;
        this.productName = "Default Product";
        this.productId = 000000;
        this.unitPrice = 0.0;
        this.quantity = 0;
        this.cost = 0.0;
    }

    // Parameterized Constructor
    Shopping(String customerName, int customerId, String productName, int productId, double unitPrice, int quantity) {
        this.customerName = customerName;
        this.customerId = customerId;
        this.productName = productName;
        this.productId = productId;
        this.unitPrice = unitPrice;
        this.quantity = quantity;
        this.cost = unitPrice * quantity;
    }

    // Method to read the details of the order
    void readOrderDetails() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter customer Name:");
        this.customerName = scanner.nextLine();
        System.out.println("Enter customer Id:");
        this.customerId = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        System.out.println("Enter product name:");
        this.productName = scanner.nextLine();
        System.out.println("Enter product Id:");
        this.productId = scanner.nextInt();
        System.out.println("Enter unit price:");
        this.unitPrice = scanner.nextDouble();
        System.out.println("Enter quantity:");
        this.quantity = scanner.nextInt();
        this.cost = this.quantity * this.unitPrice;

        // Increment totalOrders only here
        totalOrders++;
    }

    // Method to update the quantity
    void updateQuantity() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter new quantity:");
        this.quantity = scanner.nextInt();
        this.cost = this.quantity * this.unitPrice;
        System.out.println("New cost is: " + this.cost);
    }

    // Method to display order details
    void displayOrderDetails() {
        System.out.println("Customer Name: " + customerName);
        System.out.println("Customer ID: " + customerId);
        System.out.println("Product Name: " + productName);
        System.out.println("Product ID: " + productId);
        System.out.println("Cost: " + cost);
        System.out.println("With discount, cost = " + (cost - (cost * discountRate)));
    }

    // Static method to display total orders
    static void displayTotalOrders() {
        System.out.println("Total orders: " + totalOrders);
    }
}

class ShoppingDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Shopping[] shoppings = new Shopping[8];
        
        for (int i = 0; i < 8; i++) {
            shoppings[i] = new Shopping();
            shoppings[i].readOrderDetails();
            shoppings[i].displayOrderDetails();
            shoppings[i].updateQuantity();
            shoppings[i].displayOrderDetails();
        }
        
        Shopping.displayTotalOrders();
        scanner.close(); // Closing the scanner at the end
    }
}
