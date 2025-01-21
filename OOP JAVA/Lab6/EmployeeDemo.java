import java.util.Scanner;

// Base class EMPLOYEE
class EMPLOYEE {
    String Ename;
    int Eid;
    double Basic;
    double Gross_Sal = 0.0;

    // Default constructor
    EMPLOYEE() {
        this.Ename = "Default Name";
        this.Eid = 0;
        this.Basic = 0.0;
    }

    // Parameterized constructor
    EMPLOYEE(String Ename, int Eid, double Basic) {
        this.Ename = Ename;
        this.Eid = Eid;
        this.Basic = Basic;
    }

    // Method to calculate salary (to be overridden)
    void calculateSalary() {
        Gross_Sal = Basic;
    }

    // Method to display employee details (to be overridden)
    void displayEmployeeDetails() {
        System.out.println("Employee Name: " + Ename);
        System.out.println("Employee ID: " + Eid);
        System.out.println("Basic Salary: " + Basic);
        System.out.println("Gross Salary: " + Gross_Sal);
    }
}

// Subclass for Full-Time Employees
class FullTimeEmp extends EMPLOYEE {
    private double bonus;
    private double deductions;

    // Constructor
    FullTimeEmp(String Ename, int Eid, double Basic, double bonus, double deductions) {
        super(Ename, Eid, Basic); // Call to the superclass constructor
        this.bonus = bonus;
        this.deductions = deductions;
    }

    // Overriding the calculateSalary method
    @Override
    void calculateSalary() {
        Gross_Sal = Basic + bonus - deductions;
    }

    // Overriding the displayEmployeeDetails method
    @Override
    void displayEmployeeDetails() {
        super.displayEmployeeDetails();
        System.out.println("Bonus: " + bonus);
        System.out.println("Deductions: " + deductions);
        System.out.println("Net Salary: " + Gross_Sal);
    }
}

// Subclass for Part-Time Employees
class PartTimeEmp extends EMPLOYEE {
    private int hoursWorked;
    private static final double hourlyRate = 100.0;

    // Constructor
    PartTimeEmp(String Ename, int Eid, int hoursWorked) {
        super(Ename, Eid, 0); // Call to the superclass constructor
        this.hoursWorked = hoursWorked;
    }

    // Overriding the calculateSalary method
    @Override
    void calculateSalary() {
        Gross_Sal = hoursWorked * hourlyRate;
    }

    // Overriding the displayEmployeeDetails method
    @Override
    void displayEmployeeDetails() {
        super.displayEmployeeDetails();
        System.out.println("Hours Worked: " + hoursWorked);
        System.out.println("Hourly Rate: " + hourlyRate);
        System.out.println("Salary: " + Gross_Sal);
    }
}

// Main class to demonstrate functionality
public class EmployeeDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create a FullTimeEmp object
        System.out.println("Enter Full-Time Employee Name:");
        String name = scanner.nextLine();
        System.out.println("Enter Employee ID:");
        int id = scanner.nextInt();
        System.out.println("Enter Basic Salary:");
        double basic = scanner.nextDouble();
        System.out.println("Enter Bonus:");
        double bonus = scanner.nextDouble();
        System.out.println("Enter Deductions:");
        double deductions = scanner.nextDouble();
        FullTimeEmp fullTimeEmp = new FullTimeEmp(name, id, basic, bonus, deductions);
        fullTimeEmp.calculateSalary();
        fullTimeEmp.displayEmployeeDetails();

        // Create a PartTimeEmp object
        scanner.nextLine(); // Consume newline
        System.out.println("\nEnter Part-Time Employee Name:");
        name = scanner.nextLine();
        System.out.println("Enter Employee ID:");
        id = scanner.nextInt();
        System.out.println("Enter Hours Worked:");
        int hoursWorked = scanner.nextInt();
        PartTimeEmp partTimeEmp = new PartTimeEmp(name, id, hoursWorked);
        partTimeEmp.calculateSalary();
        partTimeEmp.displayEmployeeDetails();

        scanner.close();
    }
}
