import java.util.Scanner;

class SeatsFilledException extends Exception {
    SeatsFilledException(String message) {
        super(message);
    }
}

class NotUniqueException extends Exception {
    NotUniqueException(String message) {
        super(message);
    }
}

class Student {
    String name;
    int regno;
    int year;

    // Constructor
    public Student(String name, int regno, int year) throws SeatsFilledException {
        this.name = name;
        this.regno = regno;
        this.year = year;

        // XX25 logic to check if seats are filled
        int maxReg = (year % 100) * 100 + 25;
        if (regno > maxReg) {
            throw new SeatsFilledException("Seats filled for year " + year);
        }
    }

    void display() {
        System.out.println("Name: " + name + ", Registration No: " + regno + ", Year: " + year);
    }
}

public class Student1{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Array to store students
        Student[] students = new Student[5];
        int count = 0; // Track number of students added

        try {
            while (count < 5) {
                System.out.println("Enter student name:");
                String name = scanner.nextLine();

                System.out.println("Enter registration number:");
                int regno = scanner.nextInt();

                System.out.println("Enter year of joining:");
                int year = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                // Check for uniqueness manually
                boolean isUnique = true;
                for (int i = 0; i < count; i++) {
                    if (students[i].regno == regno) {
                        isUnique = false;
                        break;
                    }
                }

                if (!isUnique) {
                    throw new NotUniqueException("Registration number must be unique: " + regno);
                }

                // Add student if valid
                students[count] = new Student(name, regno, year);
                count++;
                System.out.println("Student added successfully!");
            }
        } catch (SeatsFilledException | NotUniqueException e) {
            System.out.println("Error: " + e.getMessage());
        }

        // Display all students
        System.out.println("\nRegistered Students:");
        for (int i = 0; i < count; i++) {
            students[i].display();
        }

        scanner.close();
    }
}
