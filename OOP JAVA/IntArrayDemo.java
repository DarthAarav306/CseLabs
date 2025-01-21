import java.util.Scanner;

class IntArray {
    private int[] arr;
    private int size;

    // Parameterized constructor to initialize arr
    IntArray(int size) {
        this.size = size;
        arr = new int[size];
        System.out.println("Array initialized with size: " + size);
    }

    // Method to display the array
    public void display() {
        System.out.print("Array elements: ");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // Method to append an element at the end
    public void append(int value) {
        resize(size + 1);
        arr[size] = value;
        size++;
    }

    // Method to remove an element at a given index
    public void remove(int index) {
        if (index < 0 || index >= size) {
            System.out.println("Invalid index.");
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        resize(size - 1);
        size--;
    }

    // Method to insert an element at a given index
    public void insert(int index, int value) {
        if (index < 0 || index > size) {
            System.out.println("Invalid index.");
            return;
        }
        resize(size + 1);
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    // Method to resize the array manually
    private void resize(int newSize) {
        int[] temp = new int[newSize];
        for (int i = 0; i < Math.min(size, newSize); i++) {
            temp[i] = arr[i];
        }
        arr = temp;
    }
}

public class IntArrayDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the size of the array:");
        int size = scanner.nextInt();

        IntArray intArray = new IntArray(size);

        System.out.println("Enter array elements:");
        for (int i = 0; i < size; i++) {
            intArray.append(scanner.nextInt());
        }

        intArray.display();

        System.out.println("Enter value to append:");
        intArray.append(scanner.nextInt());
        intArray.display();

        System.out.println("Enter index to remove:");
        intArray.remove(scanner.nextInt());
        intArray.display();

        System.out.println("Enter index and value to insert:");
        int index = scanner.nextInt();
        int value = scanner.nextInt();
        intArray.insert(index, value);
        intArray.display();

        scanner.close();
    }
}
