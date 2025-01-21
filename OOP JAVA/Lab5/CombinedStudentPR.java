import java.util.GregorianCalendar;
import java.util.Scanner;

class STUDENT {
    int regNumber;
    String fullName;
    GregorianCalendar dateOfJoining;
    short semester;
    float gpa;
    float cgpa;

    // Constructor
    STUDENT(int year, int count, String fullName, GregorianCalendar dateOfJoining, short semester, float gpa, float cgpa) {
        this.regNumber = generateRegNumber(year, count);
        this.fullName = fullName;
        this.dateOfJoining = dateOfJoining;
        this.semester = semester;
        this.gpa = gpa;
        this.cgpa = cgpa;
    }

    // Generate Registration Number
    int generateRegNumber(int year, int count) {
        return (year % 100) * 100 + count;
    }

    // Display student details
    void display() {
        System.out.println("Registration Number: " + regNumber);
        System.out.println("Full Name: " + fullName);
        System.out.println("Date of Joining: " + dateOfJoining.getTime());
        System.out.println("Semester: " + semester);
        System.out.println("GPA: " + gpa);
        System.out.println("CGPA: " + cgpa);
    }

    // Sort by Semester and CGPA
    static void sortBySemesterAndCGPA(STUDENT[] students, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (students[i].semester > students[j].semester ||
                    (students[i].semester == students[j].semester && students[i].cgpa < students[j].cgpa)) {
                    STUDENT temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    // Sort by Name
    static void sortByName(STUDENT[] students, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (students[i].fullName.compareTo(students[j].fullName) > 0) {
                    STUDENT temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    // List students by the initial
    void listStudentsByInitial(char initial) {
        if (fullName.charAt(0) == initial) {
            display();
        }
    }

    // List students by a substring in their name
    void listStudentsBySubstring(String substring) {
        if (fullName.contains(substring)) {
            display();
        }
    }

    // Convert full name to initials
    void convertToInitials() {
        String initials = "";
        String[] parts = fullName.split(" ");
        for (int i = 0; i < parts.length - 1; i++) {
            initials += parts[i].charAt(0) + ". ";
        }
        initials += parts[parts.length - 1];
        fullName = initials;
    }
}

class CombinedStudentPR {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        STUDENT[] students = new STUDENT[5];

        // Input student details
        for (int i = 0; i < 5; i++) {
            System.out.println("Enter details for student " + (i + 1) + ":");

            System.out.print("Year of Joining: ");
            int year = sc.nextInt();

            System.out.print("Count of Student in that year: ");
            int count = sc.nextInt();
            sc.nextLine(); // Consume the newline

            System.out.print("Full Name: ");
            String fullName = sc.nextLine();

            System.out.print("Date of Joining (dd mm yyyy): ");
            int day = sc.nextInt();
            int month = sc.nextInt() - 1; // GregorianCalendar months are 0-based
            int yearJoining = sc.nextInt();
            GregorianCalendar dateOfJoining = new GregorianCalendar(yearJoining, month, day);

            System.out.print("Semester: ");
            short semester = sc.nextShort();

            System.out.print("GPA: ");
            float gpa = sc.nextFloat();

            System.out.print("CGPA: ");
            float cgpa = sc.nextFloat();

            students[i] = new STUDENT(year, count, fullName, dateOfJoining, semester, gpa, cgpa);
            System.out.println();
        }

        // Display student records
        System.out.println("Displaying Student Records:");
        for (int i = 0; i < 5; i++) {
            students[i].display();
            System.out.println();
        }

        // Sort by Semester and CGPA
        System.out.println("Sorting by Semester and CGPA:");
        STUDENT.sortBySemesterAndCGPA(students, 5);
        for (int i = 0; i < 5; i++) {
            students[i].display();
            System.out.println();
        }

        // Sort by Name
        System.out.println("Sorting by Name:");
        STUDENT.sortByName(students, 5);
        for (int i = 0; i < 5; i++) {
            students[i].display();
            System.out.println();
        }

        // List students by the initial
        System.out.println("Listing students whose names start with a specific character:");
        System.out.print("Enter the initial: ");
        char initial = sc.next().charAt(0);
        for (int i = 0; i < 5; i++) {
            students[i].listStudentsByInitial(initial);
        }

        // List students by a substring in their name
        System.out.println("Listing students whose names contain a specific substring:");
        sc.nextLine(); // Consume the newline
        System.out.print("Enter the substring: ");
        String substring = sc.nextLine();
        for (int i = 0; i < 5; i++) {
            students[i].listStudentsBySubstring(substring);
        }

        // Convert full names to initials
        System.out.println("Converting full names to initials:");
        for (int i = 0; i < 5; i++) {
            students[i].convertToInitials();
            students[i].display();
            System.out.println();
        }

        sc.close();  // Close the scanner
    }
}
