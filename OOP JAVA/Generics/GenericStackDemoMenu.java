import java.util.Scanner;

class Stack<T> {
    private T[] elements;
    private int top;
    private int size;

    public Stack(int size) {
        this.size = size;
        elements = (T[]) new Object[size];
        top = -1;
    }

    public void push(T item) {
        if (top == size - 1) {
            System.out.println("Stack is full. Cannot push " + item);
        } else {
            elements[++top] = item;
            System.out.println("Pushed: " + item);
        }
    }

    public T pop() {
        if (top == -1) {
            System.out.println("Stack is empty.");
            return null;
        } else {
            System.out.println("Popped: " + elements[top]);
            return elements[top--];
        }
    }

    public void display() {
        if (top == -1) {
            System.out.println("Stack is empty.");
        } else {
            System.out.print("Stack: ");
            for (int i = 0; i <= top; i++) {
                System.out.print(elements[i] + " ");
            }
            System.out.println();
        }
    }
}

class Student {
    private String name;
    private int id;

    public Student(String name, int id) {
        this.name = name;
        this.id = id;
    }

    @Override
    public String toString() {
        return "Student{Name: " + name + ", ID: " + id + "}";
    }
}

class Employee {
    private String name;
    private String department;

    public Employee(String name, String department) {
        this.name = name;
        this.department = department;
    }

    @Override
    public String toString() {
        return "Employee{Name: " + name + ", Department: " + department + "}";
    }
}

public class GenericStackDemoMenu {

    public static void manageStudentStack(Stack<Student> stack, Scanner scanner) {
        while (true) {
            System.out.println("\n1. Push Student");
            System.out.println("2. Pop Student");
            System.out.println("3. Display Stack");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.print("Enter Student name: ");
                    String studentName = scanner.next();
                    System.out.print("Enter Student ID: ");
                    int studentId = scanner.nextInt();
                    stack.push(new Student(studentName, studentId));
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.display();
                    break;
                case 4:
                    return;
                default:
                    System.out.println("Invalid option.");
            }
        }
    }

    public static void manageEmployeeStack(Stack<Employee> stack, Scanner scanner) {
        while (true) {
            System.out.println("\n1. Push Employee");
            System.out.println("2. Pop Employee");
            System.out.println("3. Display Stack");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.print("Enter Employee name: ");
                    String employeeName = scanner.next();
                    System.out.print("Enter Employee Department: ");
                    System.out.print("Enter Employee Department: ");
                    String department = scanner.next();
                    stack.push(new Employee(employeeName, department));
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.display();
                    break;
                case 4:
                    return;
                default:
                    System.out.println("Invalid option.");
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose stack type:");
        System.out.println("1. Student Stack");
        System.out.println("2. Employee Stack");
        int choice = scanner.nextInt();

        System.out.print("Enter the size of the stack: ");
        int size = scanner.nextInt();

        if (choice == 1) {
            Stack<Student> studentStack = new Stack<>(size);
            manageStudentStack(studentStack, scanner);
        } else if (choice == 2) {
            Stack<Employee> employeeStack = new Stack<>(size);
            manageEmployeeStack(employeeStack, scanner);
        } else {
            System.out.println("Invalid choice.");
        }

        scanner.close();
    }
}
