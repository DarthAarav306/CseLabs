import java.util.Scanner;

// Base class Person
class Person {
    private String name;
    private String birthDate; // Assuming birth date as a string in the format "dd-mm-yyyy"

    // Constructor
    public Person(String name, String birthDate) {
        this.name = name;
        this.birthDate = birthDate;
    }

    // Accessor methods
    public String getName() {
        return name;
    }

    public String getBirthDate() {
        return birthDate;
    }

    // Method to display person details
    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Birth Date: " + birthDate);
    }
}

// Subclass CollegeGraduate
class CollegeGraduate extends Person {
    private double gpa;
    private int graduationYear;

    // Constructor
    public CollegeGraduate(String name, String birthDate, double gpa, int graduationYear) {
        super(name, birthDate); // Call the superclass constructor
        this.gpa = gpa;
        this.graduationYear = graduationYear;
    }

    // Accessor methods
    public double getGpa() {
        return gpa;
    }

    public int getGraduationYear() {
        return graduationYear;
    }

    // Method to display college graduate details
    @Override
    public void display() {
        super.display(); // Call the superclass display method
        System.out.println("GPA: " + gpa);
        System.out.println("Graduation Year: " + graduationYear);
    }
}

// Main class to demonstrate functionality
public class PersonDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get input for a general person
        System.out.println("Enter Person's Name:");
        String name = scanner.nextLine();
        System.out.println("Enter Person's Birth Date (dd-mm-yyyy):");
        String birthDate = scanner.nextLine();
        Person person = new Person(name, birthDate);
        
        // Display person details
        System.out.println("\nPerson Details:");
        person.display();

        // Get input for a college graduate
        System.out.println("\nEnter College Graduate's Name:");
        name = scanner.nextLine();
        System.out.println("Enter College Graduate's Birth Date (dd-mm-yyyy):");
        birthDate = scanner.nextLine();
        System.out.println("Enter College Graduate's GPA:");
        double gpa = scanner.nextDouble();
        System.out.println("Enter Graduation Year:");
        int graduationYear = scanner.nextInt();
        CollegeGraduate graduate = new CollegeGraduate(name, birthDate, gpa, graduationYear);
        
        // Display college graduate details
        System.out.println("\nCollege Graduate Details:");
        graduate.display();

        scanner.close();
    }
}
