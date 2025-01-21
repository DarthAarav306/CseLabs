import java.util.Scanner;

class Stack<T> {
    private T[] elements;
    private int top;
    private int size;

    public Stack(int size) {
        this.size = size;
        elements = (T[]) new Object[size]; // Array of generic type
        top = -1;
    }

    public void push(T item) {
        if (top == size - 1) {
            System.out.println("Stack is full. Cannot push " + item);
        } else {
            elements[++top] = item;
        }
    }

    public T pop() {
        if (top == -1) {
            System.out.println("Stack is empty.");
            return null;
        } else {
            return elements[top--];
        }
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public void printStack() {
        System.out.print("Stack: ");
        for (int i = 0; i <= top; i++) {
            System.out.print(elements[i] + " ");
        }
        System.out.println();
    }
}

class Student {
    private String name;
    private int id;

    public Student(String name, int id) {
        this.name = name;
        this.id = id;
    }

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

    public String toString() {
        return "Employee{Name: " + name + ", Department: " + department + "}";
    }
}

public class GenericStackDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of Students to add to the stack:");
        int studentCount = scanner.nextInt();
        Stack<Student> studentStack = new Stack<>(studentCount);

        System.out.println("Enter Student details:");
        for (int i = 0; i < studentCount; i++) {
            System.out.print("Enter name of Student " + (i + 1) + ": ");
            String studentName = scanner.next();
            System.out.print("Enter ID of Student " + (i + 1) + ": ");
            int studentId = scanner.nextInt();
            studentStack.push(new Student(studentName, studentId));
        }

        System.out.println("\nPopping Students from Stack:");
        while (!studentStack.isEmpty()) {
            System.out.println(studentStack.pop());
        }
        System.out.println("\nEnter the number of Employees to add to the stack:");
        int employeeCount = scanner.nextInt();
        Stack<Employee> employeeStack = new Stack<>(employeeCount);

        System.out.println("Enter Employee details:");
        for (int i = 0; i < employeeCount; i++) {
            System.out.print("Enter name of Employee " + (i + 1) + ": ");
            String employeeName = scanner.next();
            System.out.print("Enter Department of Employee " + (i + 1) + ": ");
            String department = scanner.next();
            employeeStack.push(new Employee(employeeName, department));
        }
        System.out.println("\nPopping Employees from Stack:");
        while (!employeeStack.isEmpty()) {
            System.out.println(employeeStack.pop());
        }

        scanner.close();
    }
}
