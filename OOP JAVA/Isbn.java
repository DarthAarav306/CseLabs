import java.util.Scanner;

public class Isbn {
    long isbncode;

    void inputISBN() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the ISBN code:");
        this.isbncode = scanner.nextLong();
        scanner.close();  // Close the scanner after use
    }

    void checkISBN() {
        int count = 0;
        long num = isbncode;

        // Count the number of digits
        while (num != 0) {
            num = num / 10;
            count++;
        }

        if (count != 10) {
            System.out.println("ISBN should be a 10-digit number");
        } else {
            long sum = 0;
            long numm = isbncode;

            // Calculate the sum using the ISBN formula
            for (int i = 10; i >= 1; i--) {
                long rd = numm % 10;
                sum += rd * i;
                numm = numm / 10;
            }

            // Check if the sum is divisible by 11
            if (sum % 11 == 0) {
                System.out.println("Legal ISBN");
            } else {
                System.out.println("Illegal ISBN");
            }
        }
    }

    public static void main(String[] args) {
        Isbn isbn = new Isbn();
        isbn.inputISBN();
        isbn.checkISBN();
    }
}
