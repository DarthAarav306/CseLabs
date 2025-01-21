import java.util.Scanner;

class Employee {
    String Ename;
    int Eid;
    double Basic;
    double DA = 0.0;
    double Gross_Sal = 0.0;
    double Net_Sal = 0.0;

    // Default constructor
    Employee() {
        this.Ename = "Default Name";
        this.Eid = 0;
        this.Basic = 0.0;
    }

    // Parameterized constructor
    Employee(String Ename, int Eid, double Basic) {
        this.Ename = Ename;
        this.Eid = Eid;
        this.Basic = Basic;
    }

    // Method to compute net salary
    void compute_net_sal() {
        DA = 0.52 * Basic;
        Gross_Sal = Basic + DA;
        double IT = 0.3 * Gross_Sal;  // IT (Income Tax) is 30% of Gross Salary
        Net_Sal = Gross_Sal - IT;
    }

    // Method to display employee details
    void display() {
        System.out.println("Employee Name: " + Ename);
        System.out.println("Employee ID: " + Eid);
        System.out.println("Basic Salary: " + Basic);
        System.out.println("DA: " + DA);
        System.out.println("Gross Salary: " + Gross_Sal);
        System.out.println("Net Salary: " + Net_Sal);
        System.out.println("--------------------------");
    }

    // Method to read N employee details
    /* 
    void read(int n, Employee[] employees) {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            employees[i] = new Employee();  // Initialize each Employee object
            System.out.println("Enter details for employee " + (i + 1) + ":");
            System.out.print("Enter name of employee: ");
            employees[i].Ename = scanner.next();
            System.out.print("Enter Eid: ");
            employees[i].Eid = scanner.nextInt();
            System.out.print("Enter Basic salary: ");
            employees[i].Basic = scanner.nextDouble();
        }
    }
    */
}

public class Employeedemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of employees: ");
        int n = scanner.nextInt();

        Employee[] employees = new Employee[n];

        // Reading employee details in the main method
        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for employee " + (i + 1) + ":");
            System.out.print("Enter name of employee: ");
            String name = scanner.next();
            System.out.print("Enter Eid: ");
            int id = scanner.nextInt();
            System.out.print("Enter Basic salary: ");
            double basic = scanner.nextDouble();

            // Creating an Employee object using the parameterized constructor
            employees[i] = new Employee(name, id, basic);

            // Compute net salary
            employees[i].compute_net_sal();
        }

        // Displaying all employee details
        System.out.println("\nEmployee Details:");
        for (Employee employee : employees) {
            employee.display();
        }

        // Example of using the default constructor
        System.out.println("Using Default Constructor:");
        Employee defaultEmp = new Employee();  // Using the default constructor
        defaultEmp.compute_net_sal();
        defaultEmp.display();

        scanner.close();  // Close the scanner at the end
    }
}
