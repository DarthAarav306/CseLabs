 // Define a generic stack class using an array
class ArrayStack<T> {
    private T[] stack;
    private int top;
    private int capacity;

    // Constructor to initialize the stack with a specific capacity
    public ArrayStack(int capacity) {
        this.capacity = capacity;
        stack = (T[]) new Object[capacity]; // Create a generic array
        top = -1;
    }

    // Push an element onto the stack
    public void push(T data) {
        if (top == capacity - 1) {
            throw new RuntimeException("Stack is full");
        }
        stack[++top] = data;
    }

    // Pop an element from the stack
    public T pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return stack[top--];
    }

    // Peek at the top element of the stack
    public T peek() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return stack[top];
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Print all elements in the stack
    public void printStack() {
        for (int i = top; i >= 0; i--) {
            System.out.println(stack[i]);
        }
    }
}

public class StackOfStacksExample {
    public static void main(String[] args) {
        // Creating different stacks of various types with a capacity of 5
        ArrayStack<Integer> integerStack = new ArrayStack<>(5);
        integerStack.push(1);
        integerStack.push(2);

        ArrayStack<String> stringStack = new ArrayStack<>(5);
        stringStack.push("Hello");
        stringStack.push("World");

        ArrayStack<Double> doubleStack = new ArrayStack<>(5);
        doubleStack.push(3.14);
        doubleStack.push(2.71);

        // Creating a stack that can hold any type of ArrayStack
        ArrayStack<ArrayStack<?>> stackOfStacks = new ArrayStack<>(5);

        // Pushing different types of stacks onto stackOfStacks
        stackOfStacks.push(integerStack);
        stackOfStacks.push(stringStack);
        stackOfStacks.push(doubleStack);

        // Accessing elements from stackOfStacks
        while (!stackOfStacks.isEmpty()) {
            ArrayStack<?> stack = stackOfStacks.pop();

            // Print elements of each inner stack
            System.out.println("Elements in stack:");
            stack.printStack();
            System.out.println("-----");
        }
    }
}
 