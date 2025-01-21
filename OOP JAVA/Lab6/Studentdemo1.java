import java.util.Scanner;

// Base class Student
class Student {
    String name;
    int id;

    // Constructor to initialize name and id
    Student(String name, int id) {
        this.name = name;
        this.id = id;
    }
}

// Derived class Sports from Student
class Sports extends Student {
    int s_grade;

    // Constructor to initialize name, id and s_grade
    Sports(String name, int id, int s_grade) {
        super(name, id);
        this.s_grade = s_grade;
    }
}

// Derived class Exam from Student
class Exam extends Student {
    int e_grade;

    // Constructor to initialize name, id and e_grade
    Exam(String name, int id, int e_grade) {
        super(name, id);
        this.e_grade = e_grade;
    }
}

// Class Results inherits from both Sports and Exam
class Results extends Sports {
    int e_grade;  // Since Results inherits only from Sports, we have to include e_grade manually here
    String final_result;

    // Constructor to initialize name, id, s_grade, e_grade and final_result
    Results(String name, int id, int s_grade, int e_grade) {
        super(name, id, s_grade);
        this.e_grade = e_grade;
        computeResult();
    }

    // Method to compute the final result
    void computeResult() {
        if (s_grade >= 75 && e_grade >= 75) {
            final_result = "Pass with Distinction";
        } else if (s_grade >= 50 && e_grade >= 50) {
            final_result = "Pass";
        } else {
            final_result = "Fail";
        }
    }

    // Method to display the final result
    void display() {
        System.out.println("Student Name: " + name);
        System.out.println("Student ID: " + id);
        System.out.println("Sports Grade: " + s_grade);
        System.out.println("Exam Grade: " + e_grade);
        System.out.println("Final Result: " + final_result);
    }
}

// Main class to demonstrate the usage of the classes
public class Studentdemo1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for student details
        System.out.println("Enter Student Name:");
        String name = scanner.nextLine();
        System.out.println("Enter Student ID:");
        int id = scanner.nextInt();

        // Input for grades
        System.out.println("Enter Sports Grade:");
        int s_grade = scanner.nextInt();
        System.out.println("Enter Exam Grade:");
        int e_grade = scanner.nextInt();

        // Create Results object
        Results result = new Results(name, id, s_grade, e_grade);

        // Display the final result
        result.display();

        scanner.close();
    }
}
