import java.util.Scanner;

class ArrayUtil {

    public static <T> void swap(T[] array, int index1, int index2) {
        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    public static <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
}

public class SwapDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of elements in the Integer array:");
        int n = scanner.nextInt();
        Integer[] intArray = new Integer[n];

        System.out.println("Enter " + n + " integer elements:");
        for (int i = 0; i < n; i++) {
            intArray[i] = scanner.nextInt();
        }
        System.out.println("Enter the first index to swap:");
        int index1 = scanner.nextInt();
        System.out.println("Enter the second index to swap:");
        int index2 = scanner.nextInt();
        System.out.println("Original Integer Array:");
        ArrayUtil.printArray(intArray);
        ArrayUtil.swap(intArray, index1, index2);
        System.out.println("After Swapping (index " + index1 + " and " + index2 + "):");
        ArrayUtil.printArray(intArray);

        System.out.println("\nEnter the number of elements in the String array:");
        int m = scanner.nextInt();
        String[] strArray = new String[m];

        System.out.println("Enter " + m + " string elements:");
        scanner.nextLine();
        for (int i = 0; i < m; i++) {
            strArray[i] = scanner.nextLine();
        }

        System.out.println("Enter the first index to swap:");
        int strIndex1 = scanner.nextInt();
        System.out.println("Enter the second index to swap:");
        int strIndex2 = scanner.nextInt();

        System.out.println("Original String Array:");
        ArrayUtil.printArray(strArray);

        ArrayUtil.swap(strArray, strIndex1, strIndex2);
        System.out.println("After Swapping (index " + strIndex1 + " and " + strIndex2 + "):");
        ArrayUtil.printArray(strArray);

        scanner.close();
    }
}
