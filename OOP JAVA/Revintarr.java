//Write a program that creates an array of integers and then uses a for loop to reverse
//the order of the elements in the array.
import java.util.Scanner;
public class Revintarr {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        System.out.println("Enter number of elements:-");
        n = scanner.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = scanner.nextInt();
        }
        for(int i=0;i<n/2;i++)
        {
            int temp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = temp;
        }
        for(int i:arr)
        {
            System.out.print(i+" ");
        }
        scanner.close();
    }

}
