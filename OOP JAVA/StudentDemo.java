import java.util.Scanner;

class Student {
    String sname;
    int[] marks_array;
    int total = 0;
    double avg = 0;

    // Default constructor
    Student() {
        this.sname = "Default name";
        this.marks_array = new int[]{0, 0, 0}; // Correct way to initialize the array
    }

    // Parameterized constructor
    Student(String sname, int[] marks) {
        this.sname = sname;
        this.marks_array = marks;
    }

    // Method to compute total and average marks
    void compute() {
        for (int i = 0; i < marks_array.length; i++) {
            this.total += marks_array[i];
        }
        this.avg = (double) this.total / marks_array.length;  // Cast to double for accurate average
    }

    // Method to display the STUDENT object
    void display() {
        System.out.println("\nDisplaying student object:");
        System.out.println("Student name: " + sname);
        System.out.println("Student marks: ");
        for (int i = 0; i < marks_array.length; i++) {
            System.out.print(marks_array[i] + " ");
        }
        System.out.println("\nTotal: " + total);
        System.out.println("Average: " + avg);
    }
}

class StudentDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter name: ");
        String name = scanner.nextLine();  // Changed to nextLine to read a String

        System.out.println("Enter number of subjects: ");
        int n = scanner.nextInt();

        int[] marks = new int[n];
        System.out.println("Enter marks: ");
        for (int i = 0; i < n; i++) {
            marks[i] = scanner.nextInt();
        }

        // Using the parameterized constructor
        Student s1 = new Student(name, marks);
        System.out.println("Parameterized:");
        s1.compute();  // Ensure compute is called before display
        s1.display();

        // Using the default constructor
        Student s2 = new Student();
        System.out.println("Default:");
        s2.compute();  // Ensure compute is called before display
        s2.display();
    }
}
