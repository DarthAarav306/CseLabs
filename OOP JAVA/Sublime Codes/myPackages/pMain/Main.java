package pMain;

import java.util.Scanner;
import myPackages.pIntegers.SearchSort;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements
        System.out.println("Enter number of elements in array:");
        int n = sc.nextInt();

        // Read the array of integers
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Create object of SearchSort class
        SearchSort searchSort = new SearchSort();

        // Sort the array using IntSort
        searchSort.IntSort(arr);
        System.out.println("Array after sorting:");
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();

        // Perform Binary Search
        System.out.println("Enter the element to search:");
        int key = sc.nextInt();
        int result = searchSort.binSearch(arr, key);

        // Display search result
        if (result == -1) {
            System.out.println("Element not found.");
        } else {
            System.out.println("Element found at index: " + result);
        }

        sc.close();
    }
}
