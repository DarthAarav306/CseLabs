import java.util.Scanner;

class Mixer {
    int arr[];
    Scanner scanner = new Scanner(System.in);

    void accept() {
        System.out.println("Enter number of elements:");
        int n = scanner.nextInt();
        arr = new int[n]; // Initialize the array with the input size
        System.out.println("Enter " + n + " elements in ascending order:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
    }

    Mixer mix(Mixer A) {
        int i = 0, j = 0, k = 0;
        // Create a temporary array to hold the merged elements
        int[] tempArr = new int[this.arr.length + A.arr.length];

        while (i < this.arr.length && j < A.arr.length) {
            if (this.arr[i] < A.arr[j]) {
                tempArr[k] = this.arr[i];
                i++;
            } else if (this.arr[i] > A.arr[j]) {
                tempArr[k] = A.arr[j];
                j++;
            } else {
                tempArr[k] = this.arr[i];
                i++;
                j++;
            }
            k++;
        }

        // Copy remaining elements from this.arr, if any
        while (i < this.arr.length) {
            tempArr[k] = this.arr[i];
            i++;
            k++;
        }

        // Copy remaining elements from A.arr, if any
        while (j < A.arr.length) {
            tempArr[k] = A.arr[j];
            j++;
            k++;
        }

        // Create a new Mixer object for the merged array
        Mixer mixed = new Mixer();
        // Initialize mixed.arr with the exact number of elements copied
        mixed.arr = new int[k];
        
        // Manually copy elements from tempArr to mixed.arr
        for (int x = 0; x < k; x++) {
            mixed.arr[x] = tempArr[x];
        }

        return mixed;
    }

    void display() {
        System.out.print("Array elements: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Mixer mixer1 = new Mixer();
        Mixer mixer2 = new Mixer();
        
        System.out.println("Accepting elements for Mixer 1:");
        mixer1.accept();
        
        System.out.println("Accepting elements for Mixer 2:");
        mixer2.accept();
        
        Mixer mixed = mixer1.mix(mixer2);
        
        System.out.println("Merged array:");
        mixed.display();
    }
}
