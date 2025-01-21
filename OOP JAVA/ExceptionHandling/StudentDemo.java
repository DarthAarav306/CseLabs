import java.util.GregorianCalendar;
import java.util.Scanner;

// Custom exception for seats filled
class SeatsFilledException extends Exception {
    public SeatsFilledException(String message) {
        super(message);
    }
}

// Custom exception for duplicate registration numbers
class DuplicateRegNumberException extends Exception {
    public DuplicateRegNumberException(String message) {
        super(message);
    }
}

class STUDENT {
    int regNumber;
    String fullName;
    GregorianCalendar dateOfJoining;
    short semester;
    float gpa;
    float cgpa;

    // Constructor to initialize the student
    STUDENT(int year, int count, String fullName, GregorianCalendar dateOfJoining, short semester, float gpa, float cgpa) throws SeatsFilledException {
        this.regNumber = generateRegNumber(year, count);

        // Check if registration number exceeds the seat limit (XX25)
        if (this.regNumber > (year % 100) * 100 + 25) {
            throw new SeatsFilledException("Seats filled! Registration number exceeded: " + this.regNumber);
        }

        this.fullName = fullName;
        this.dateOfJoining = dateOfJoining;
        this.semester = semester;
        this.gpa = gpa;
        this.cgpa = cgpa;
    }

    // Generate registration number based on year and count
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
        System.out.println("-----------------------------");
    }

    // Check if registration number is unique
    static boolean isUnique(STUDENT[] students, int newRegNumber, int currentCount) {
        for (int i = 0; i < currentCount; i++) {
            if (students[i] != null && students[i].regNumber == newRegNumber) {
                return false; // Registration number is not unique
            }
        }
        return true; // Registration number is unique
    }

    // Commented out sorting functions, as we are not using them
    /*
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
    */
}

public class StudentDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        STUDENT[] students = new STUDENT[5];

        for (int i = 0; i < 5; i++) {
            try {
                System.out.println("Enter details for student " + (i + 1) + ":");
                
                // Asking year only once for both regNumber and dateOfJoining
                System.out.print("Year of Joining: ");
                int year = sc.nextInt();  // This will be used for both the registration number and date of joining
                
                System.out.print("Count of Student in that year: ");
                int count = sc.nextInt();
                sc.nextLine(); // Consume the newline
                
                System.out.print("Full Name: ");
                String fullName = sc.nextLine();
                
                System.out.print("Date of Joining (dd mm): ");  // Asking only day and month
                int day = sc.nextInt();
                int month = sc.nextInt() - 1; // GregorianCalendar months are 0-based

                // Using the same `year` for the GregorianCalendar
                GregorianCalendar dateOfJoining = new GregorianCalendar(year, month, day);

                System.out.print("Semester: ");
                short semester = sc.nextShort();
                
                System.out.print("GPA: ");
                float gpa = sc.nextFloat();
                
                System.out.print("CGPA: ");
                float cgpa = sc.nextFloat();

                // Generate regNumber and check if it's unique
                int newRegNumber = (year % 100) * 100 + count;

                if (!STUDENT.isUnique(students, newRegNumber, i)) {
                    throw new DuplicateRegNumberException("Duplicate Registration Number: " + newRegNumber);
                }

                // Creating a student object and checking for seat limit exception
                students[i] = new STUDENT(year, count, fullName, dateOfJoining, semester, gpa, cgpa);
                System.out.println();
                
            } catch (SeatsFilledException | DuplicateRegNumberException e) {
                System.out.println(e.getMessage());
            }
        }

        // Display all valid student records
        System.out.println("Displaying Student Records:");
        for (STUDENT student : students) {
            if (student != null) {
                student.display();
            }
        }

        sc.close();
    }
}
