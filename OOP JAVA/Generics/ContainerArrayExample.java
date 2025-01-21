// Generic Container class (similar to C<T> in your question)
class Container<T> {
    private T value;

    public Container(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }

    public void displayType() {
        System.out.println("Type of T: " + value.getClass().getName());
    }
}

public class ContainerArrayExample {
    public static void main(String[] args) {
        // Create Container objects with different types
        Container<Integer> intContainer = new Container<>(42);
        Container<String> stringContainer = new Container<>("Hello World");
        Container<Double> doubleContainer = new Container<>(3.14);

        // Create an array of Container<?> to hold various types of Container objects
        Container<?>[] containers = new Container<?>[3];
        containers[0] = intContainer;
        containers[1] = stringContainer;
        containers[2] = doubleContainer;

        // Display the contents and types of each container
        for (Container<?> container : containers) {
            container.displayType();
            System.out.println("Value: " + container.getValue());
            System.out.println("-----");
        }
    }
}
