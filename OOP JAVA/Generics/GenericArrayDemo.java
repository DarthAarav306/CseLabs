class C<T> {
    T value;

    C(T value) {
        this.value = value;
    }

    void display() {
        System.out.println("Value: " + value);
    }
}

public class GenericArrayDemo {
    public static void main(String[] args) {
        // Attempting to create a generic array of C<T> type directly will cause an error
        // C<String>[] array = new C<String>[10]; // This line would be illegal

        // However, you can create an array with wildcard type C<?>[]
        C<?>[] array = new C<?>[10]; // This is legal

        // Assign instances to the array with different types
        array[0] = new C<String>("Hello"); // C<String> type
        array[1] = new C<Integer>(123);     // C<Integer> type

        // Display elements of the array
        for (C<?> element : array) {
            if (element != null) {
                element.display();
            }
        }
    }
}
