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

    // Display Student Details
    void display() {
        System.out.println("Registration Number: " + regNumber);
        System.out.println("Full Name: " + fullName);
        System.out.println("Date of Joining: " + dateOfJoining.getTime());
        System.out.println("Semester: " + semester);
        System.out.println("GPA: " + gpa);
        System.out.println("CGPA: " + cgpa);
        System.out.println("-----------------------------");
    }

    // a) List students whose names start with a particular character
    static void listNamesStartingWith(STUDENT[] students, char ch) {
        System.out.println("Students whose names start with '" + ch + "':");
        for (STUDENT student : students) {
            if (student.fullName.charAt(0) == ch) {
                System.out.println(student.fullName);
            }
        }
    }

    // b) List all student names containing a particular substring using indexOf
    static void listNamesWithSubstringUsingIndexOf(STUDENT[] students, String substring) {
        System.out.println("Students whose names contain the substring \"" + substring + "\":");
        for (STUDENT student : students) {
            if (student.fullName.toLowerCase().indexOf(substring.toLowerCase()) != -1) {
                System.out.println(student.fullName);
            }
        }
    }

    // c) Change full name to initials and family name (using charAt)
    void convertToInitialsAndLastNameUsingCharAt() {
        String initials = "" + fullName.charAt(0) + ". "; // First initial
        for (int i = 1; i < fullName.length(); i++) {
            if (fullName.charAt(i) == ' ' && i + 1 < fullName.length()) {
                initials += fullName.charAt(i + 1) + ". "; // Add initial after every space
            }
        }
        String lastName = fullName.substring(fullName.lastIndexOf(" ") + 1);
        this.fullName = initials + lastName;
    }

    // c) Convert name using substring (alternative way)
    void convertToInitialsAndLastNameUsingSubstring() {
        String[] names = fullName.split(" ");
        String result = "";
        for (int i = 0; i < names.length - 1; i++) {
            result += names[i].substring(0, 1) + ". ";
        }
        this.fullName = result + names[names.length - 1];
    }

    // Sorting by Semester and CGPA
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

    // Sorting by Name (Using compareTo)
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
}

public class CombinedStudentDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        STUDENT[] students = new STUDENT[5];

        // Reading student details
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
        }

        // List students whose names start with a particular character
        System.out.print("Enter a character to list students whose names start with it: ");
        char ch = sc.next().charAt(0);
        STUDENT.listNamesStartingWith(students, ch);

        // List students with a particular substring using indexOf
        sc.nextLine();  // Consume newline
        System.out.print("Enter a substring to search in names: ");
        String substring = sc.nextLine();
        STUDENT.listNamesWithSubstringUsingIndexOf(students, substring);

        // Modify student names to initials and last name using charAt
        for (STUDENT student : students) {
            student.convertToInitialsAndLastNameUsingCharAt();
        }
        System.out.println("Displaying Modified Student Names (with initials using charAt):");
        for (int i = 0; i < 5; i++) {
            students[i].display();
        }

        // Sorting by Semester and CGPA
        System.out.println("Sorting by Semester and CGPA:");
        STUDENT.sortBySemesterAndCGPA(students, 5);
        for (int i = 0; i < 5; i++) {
            students[i].display();
        }

        // Sorting by Name
        System.out.println("Sorting by Name:");
        STUDENT.sortByName(students, 5);
        for (int i = 0; i < 5; i++) {
            students[i].display();
        }
    }
}
