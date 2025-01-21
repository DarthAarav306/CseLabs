import java.util.Scanner;

class InvalidReviewException extends Exception {
    public InvalidReviewException(String message) {
        super(message);
    }
}


class Product {
    private int id;
    private String review;

    // Parameterized constructor
    public Product(int id, String review) {
        this.id = id;
        this.review = review; // No validation here
    }

    // Method to display product details
    public void display() {
        System.out.println("Product ID: " + id);
        System.out.println("Review: " + review);
    }
}


public class ProductDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of products: ");
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        Product[] products = new Product[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter product ID: ");
            int id = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            System.out.print("Enter product review: ");
            String review = scanner.nextLine();

            // Validate review using equalsIgnoreCase
            try {
                if (!review.equalsIgnoreCase("Good") && !review.equalsIgnoreCase("Bad")
                        && !review.equalsIgnoreCase("Satisfactory")) {
                    throw new InvalidReviewException(
                            "Review must be 'Good', 'Bad', or 'Satisfactory'.");
                }

                products[i] = new Product(id, review);
            } catch (InvalidReviewException e) {
                System.out.println("Error: " + e.getMessage());
                i--; // Decrement to retry the current index
            }
        }

        System.out.println("\nProduct Details:");
        for (Product product : products) {
            product.display();
        }

        scanner.close();
    }
}
