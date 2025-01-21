import java.util.Scanner;

public class Isprime {

    boolean isPrime(int n) {
        if (n == 0 || n == 1) {
            return false;
        }

        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {  // Corrected from n/i to n%i
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of prime numbers to display: ");
        int n = scanner.nextInt();
        Isprime prime = new Isprime();
        int count = 0;
        int i = 2;  // Start from 2 as 0 and 1 are not prime numbers

        while (count < n) {  // Changed from <= to <
            if (prime.isPrime(i)) {
                System.out.println(i);
                count++;
            }
            i++;
        }
    }
}
