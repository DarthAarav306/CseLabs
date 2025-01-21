import java.util.GregorianCalendar;
import java.util.Scanner;

class Student {
    int regno;
    String fullname;
    GregorianCalendar dateOfJoining;
    short semester;
    float gpa;
    float cgpa;

    // Parameterized constructor to initialize the student's details
    Student(String fullname, GregorianCalendar dateOfJoining, short semester, float gpa, float cgpa, int count, int year) {
        this.fullname = fullname;
        this.dateOfJoining = dateOfJoining;
        this.semester = semester;
        this.gpa = gpa;
        this.cgpa = cgpa;
        this.regno = (year % 100) * 100 + count;  // Generate registration number
    }

    // Method to display student's details
    void display() {
        System.out.println("Registration Number: " + regno);
        System.out.println("Full Name: " + fullname);
        System.out.println("Date of Joining: " + dateOfJoining.getTime());  // Display formatted date
        System.out.println("Semester: " + semester);
        System.out.println("GPA: " + gpa);
        System.out.println("CGPA: " + cgpa);
        System.out.println("----------------------------");
    }
}

public class Trial {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Student[] students = new Student[5];  // Array to hold student records

        // Input details for 5 students
        for (int i = 0; i < 5; i++) {
            System.out.println("Enter details for student " + (i + 1) + ":");

            // Input the full name
            System.out.print("Full Name: ");
            String name = scanner.nextLine();

            // Input the date of joining (day, month, year)
            System.out.print("Enter Date of Joining (dd mm yyyy): ");
            int day = scanner.nextInt();
            int month = scanner.nextInt() - 1;  // Adjust month for GregorianCalendar (0-based)
            int year = scanner.nextInt();
            GregorianCalendar dateOfJoining = new GregorianCalendar(year, month, day);

            // Input semester, GPA, and CGPA
            System.out.print("Semester: ");
            short semester = scanner.nextShort();

            System.out.print("GPA: ");
            float gpa = scanner.nextFloat();

            System.out.print("CGPA: ");
            float cgpa = scanner.nextFloat();

            // Input count for student in the year
            System.out.print("Student count in that year: ");
            int count = scanner.nextInt();
            scanner.nextLine();  // Consume the newline character

            // Create student object and store it in the array
            students[i] = new Student(name, dateOfJoining, semester, gpa, cgpa, count, year);
            System.out.println();
        }

        // Display the details of all students
        System.out.println("Displaying Student Details:");
        for (Student student : students) {
            student.display();
        }

        scanner.close();  // Close the scanner
    }
}
