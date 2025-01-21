import java.util.Scanner;
public class AdditionalDemo {

    // Generic method to print elements of an array
    public static <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    // Generic method to find the largest of three Comparable objects
    public static <T extends Comparable<T>> T findLargest(T x, T y, T z) {
        T max = x; // Assume x is the largest to start
        if (y.compareTo(max) > 0) {
            max = y; // y is larger
        }
        if (z.compareTo(max) > 0) {
            max = z; // z is larger
        }
        return max; // Return the largest object
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for Integer array
        System.out.println("Enter the number of elements in the Integer array:");
        int intSize = scanner.nextInt();
        Integer[] intArray = new Integer[intSize];
        System.out.println("Enter " + intSize + " integers:");
        for (int i = 0; i < intSize; i++) {
            intArray[i] = scanner.nextInt();
        }
        System.out.println("Printing Integer array:");
        printArray(intArray);

        // Input for String array
        System.out.println("\nEnter the number of elements in the String array:");
        int strSize = scanner.nextInt();
        String[] strArray = new String[strSize];
        System.out.println("Enter " + strSize + " strings:");
        scanner.nextLine(); // Consume the leftover newline
        for (int i = 0; i < strSize; i++) {
            strArray[i] = scanner.nextLine();
        }
        System.out.println("Printing String array:");
        printArray(strArray);

        // Input for Double array
        System.out.println("\nEnter the number of elements in the Double array:");
        int dblSize = scanner.nextInt();
        Double[] dblArray = new Double[dblSize];
        System.out.println("Enter " + dblSize + " doubles:");
        for (int i = 0; i < dblSize; i++) {
            dblArray[i] = scanner.nextDouble();
        }
        System.out.println("Printing Double array:");
        printArray(dblArray);

        // Finding the largest of three integers
        System.out.println("\nEnter three integers to find the largest:");
        int int1 = scanner.nextInt();
        int int2 = scanner.nextInt();
        int int3 = scanner.nextInt();
        System.out.println("The largest integer is: " + findLargest(int1, int2, int3));

        // Finding the largest of three strings
        System.out.println("\nEnter three strings to find the largest:");
        String str1 = scanner.next();
        String str2 = scanner.next();
        String str3 = scanner.next();
        System.out.println("The largest string is: " + findLargest(str1, str2, str3));

        // Finding the largest of three doubles
        System.out.println("\nEnter three doubles to find the largest:");
        double dbl1 = scanner.nextDouble();
        double dbl2 = scanner.nextDouble();
        double dbl3 = scanner.nextDouble();
        System.out.println("The largest double is: " + findLargest(dbl1, dbl2, dbl3));

        scanner.close();
    }
}
