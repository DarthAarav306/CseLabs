import java.util.Scanner;

class STUDENT {
    String sname;
    int[] marks_array;
    int total = 0;
    double avg = 0;

    // Default constructor
    STUDENT() {
        this.sname = "Default Name";
        this.marks_array = new int[]{0, 0, 0};
    }

    // Parameterized constructor
    STUDENT(String sname, int[] marks) {
        this.sname = sname;
        this.marks_array = marks;
    }

    // Method to compute total and average marks
    void compute() {
        total = 0;
        for (int mark : marks_array) {
            total += mark;
        }
        avg = (double) total / marks_array.length;
    }

    // Method to display the STUDENT object
    void display() {
        System.out.println("\nStudent Name: " + sname);
        System.out.print("Marks: ");
        for (int mark : marks_array) {
            System.out.print(mark + " ");
        }
        System.out.println("\nTotal: " + total);
        System.out.println("Average: " + avg);
    }
}

// Subclass for Science Students
class ScienceStudent extends STUDENT {
    private int practicalMarks;

    // Constructor
    ScienceStudent(String sname, int[] marks, int practicalMarks) {
        super(sname, marks); // Call to the superclass constructor
        this.practicalMarks = practicalMarks;
    }

    // Overriding the compute method
    @Override
    void compute() {
        total = practicalMarks;
        for (int mark : marks_array) {
            total += mark;
        }
        avg = (double) total / (marks_array.length + 1);
    }

    // Overriding the display method to include practical marks
    @Override
    void display() {
        super.display();
        System.out.println("Practical Marks: " + practicalMarks);
    }
}

// Subclass for Arts Students
class ArtsStudent extends STUDENT {
    private String electiveSubject;

    // Constructor
    ArtsStudent(String sname, int[] marks, String electiveSubject) {
        super(sname, marks); // Call to the superclass constructor
        this.electiveSubject = electiveSubject;
    }

    // Overriding the display method to include elective subject
    @Override
    void display() {
        super.display();
        System.out.println("Elective Subject: " + electiveSubject);
    }
}

// Main class to demonstrate functionality
public class StudentDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create a general student object
        System.out.println("Enter Student Name:");
        String name = scanner.nextLine();
        System.out.println("Enter number of subjects:");
        int numSubjects = scanner.nextInt();
        int[] marks = new int[numSubjects];
        System.out.println("Enter marks:");
        for (int i = 0; i < numSubjects; i++) {
            marks[i] = scanner.nextInt();
        }
        STUDENT student = new STUDENT(name, marks);
        student.compute();
        student.display();

        // Create a ScienceStudent object
        System.out.println("Enter Science Student Name:");
        scanner.nextLine(); // Consume newline
        name = scanner.nextLine();
        System.out.println("Enter marks:");
        for (int i = 0; i < numSubjects; i++) {
            marks[i] = scanner.nextInt();
        }
        System.out.println("Enter practical marks:");
        int practicalMarks = scanner.nextInt();
        ScienceStudent scienceStudent = new ScienceStudent(name, marks, practicalMarks);
        scienceStudent.compute();
        scienceStudent.display();

        // Create an ArtsStudent object
        System.out.println("Enter Arts Student Name:");
        scanner.nextLine(); // Consume newline
        name = scanner.nextLine();
        System.out.println("Enter marks:");
        for (int i = 0; i < numSubjects; i++) {
            marks[i] = scanner.nextInt();
        }
        scanner.nextLine(); // Consume newline
        System.out.println("Enter elective subject:");
        String electiveSubject = scanner.nextLine();
        ArtsStudent artsStudent = new ArtsStudent(name, marks, electiveSubject);
        artsStudent.compute();
        artsStudent.display();

        // Demonstrate dynamic polymorphism
        STUDENT polymorphicStudent;

        polymorphicStudent = scienceStudent;
        polymorphicStudent.compute();
        polymorphicStudent.display();

        polymorphicStudent = artsStudent;
        polymorphicStudent.compute();
        polymorphicStudent.display();

        scanner.close();
    }
}
