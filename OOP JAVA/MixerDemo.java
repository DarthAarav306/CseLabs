import java.util.Scanner;

class Mixer {
    int[] arr; // To store the array elements

    // Method to accept the elements of the array in ascending order without duplicates
    void accept() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        int n = sc.nextInt();
        arr = new int[n];

        System.out.println("Enter " + n + " elements in ascending order without duplicates:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            // Check for invalid input (not sorted or duplicates)
            if (i > 0 && arr[i] <= arr[i - 1]) {
                System.out.println("Error: Enter elements in ascending order without duplicates.");
                i--; // Re-take the input for the current index
            }
        }
    }

    // Method to merge two sorted arrays into a new Mixer object
    Mixer mix(Mixer A) {
        int[] tempArr = new int[this.arr.length + A.arr.length]; // Temporary large array
        int i = 0, j = 0, k = 0;

        // Merge logic for sorted arrays
        while (i < this.arr.length && j < A.arr.length) {
            if (this.arr[i] < A.arr[j]) {
                tempArr[k++] = this.arr[i++];
            } else if (this.arr[i] > A.arr[j]) {
                tempArr[k++] = A.arr[j++];
            } else { // Equal elements
                tempArr[k++] = this.arr[i++];
                j++;
            }
        }

        // Add remaining elements from this.arr
        while (i < this.arr.length) {
            tempArr[k++] = this.arr[i++];
        }

        // Add remaining elements from A.arr
        while (j < A.arr.length) {
            tempArr[k++] = A.arr[j++];
        }

        // Create the final merged Mixer object with correctly sized array
        Mixer mergedMixer = new Mixer();
        mergedMixer.arr = new int[k];
        for (int m = 0; m < k; m++) {
            mergedMixer.arr[m] = tempArr[m];
        }

        return mergedMixer;
    }

    // Method to display the elements of the array
    void display() {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}

// Main class to test the Mixer class
public class MixerDemo {
    public static void main(String[] args) {
        Mixer mixer1 = new Mixer();
        Mixer mixer2 = new Mixer();

        System.out.println("Enter elements for first array:");
        mixer1.accept();

        System.out.println("Enter elements for second array:");
        mixer2.accept();

        Mixer mergedMixer = mixer1.mix(mixer2);

        System.out.println("Merged array:");
        mergedMixer.display();
    }
}
