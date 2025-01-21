import java.util.Scanner;

class PushException extends Exception {
    public PushException(String message) {
        super(message);
    }
}

class PopException extends Exception {
    public PopException(String message) {
        super(message);
    }
}

class Stack {
    private int[] stackArray;
    private int top;
    private int maxSize;

    public Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    public void push(int value) throws PushException {
        if (top == maxSize - 1) {
            throw new PushException("Stack is full! Cannot push element.");
        } else {
            stackArray[++top] = value;
            System.out.println("Pushed: " + value);
        }
    }
    public int pop() throws PopException {
        if (top == -1) {
            throw new PopException("Stack is empty! Cannot pop element.");
        } else {
            int poppedValue = stackArray[top--];
            System.out.println("Popped: " + poppedValue);
            return poppedValue;
        }
    }

    public void display() {
        if (top == -1) {
            System.out.println("Stack is empty.");
        } else {
            System.out.print("Stack elements: ");
            for (int i = 0; i <= top; i++) {
                System.out.print(stackArray[i] + " ");
            }
            System.out.println();
        }
    }
}

// Main Class
public class StackDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the size of the stack: ");
        int size = scanner.nextInt();
        Stack myStack = new Stack(size);  
        
        while (true) {
            System.out.println("\n1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            
            switch (choice) {
                case 1:
                    System.out.print("Enter the value to push: ");
                    int value = scanner.nextInt();
                    try {
                        myStack.push(value);
                    } catch (PushException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                
                case 2:
                    try {
                        myStack.pop();
                    } catch (PopException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                    
                case 3:
                    myStack.display();
                    break;
                    
                case 4:
                    System.out.println("Exiting...");
                    scanner.close();
                    System.exit(0);
                    
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
