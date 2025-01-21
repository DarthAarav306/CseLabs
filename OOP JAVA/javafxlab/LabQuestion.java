import emp.Employee;
import emp.TempWorker;
import emp.PermWorker;
import emp.NameFormatException;
import java.util.Scanner;



class Gen<T extends emp.Employee> {
    T[] arr;

    public Gen(T[] arr) {
        this.arr = arr;
    }

    public int isSimilar(Gen<? extends emp.Employee> other) {
        int count = 0;
        for (T emp1 : arr) {
            for (emp.Employee emp2 : other.arr) {
                if (emp1.age == emp2.age) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Initialize arrays
        TempWorker[] tempWorkers = new TempWorker[2];
        PermWorker[] permWorkers = new PermWorker[2];
        
        // User input for TempWorker
        for (int i = 0; i < tempWorkers.length; i++) {
            System.out.println("Enter details for TempWorker " + (i + 1));
            try {
                System.out.print("Name: ");
                String name = scanner.nextLine();
                System.out.print("Age: ");
                int age = scanner.nextInt();
                System.out.print("Department: ");
                scanner.nextLine(); // consume newline
                String department = scanner.nextLine();
                System.out.print("Hours Worked: ");
                int hours = scanner.nextInt();
                scanner.nextLine(); // consume newline

                tempWorkers[i] = new TempWorker(name, age, department, hours);
            } catch (NameFormatException e) {
                System.out.println(e.getMessage());
                i--; // Retry this entry
            }
        }

        // User input for PermWorker
        for (int i = 0; i < permWorkers.length; i++) {
            System.out.println("Enter details for PermWorker " + (i + 1));
            try {
                System.out.print("Name: ");
                String name = scanner.nextLine();
                System.out.print("Age: ");
                int age = scanner.nextInt();
                System.out.print("Department: ");
                scanner.nextLine(); // consume newline
                String department = scanner.nextLine();
                System.out.print("Hours Worked: ");
                int hours = scanner.nextInt();
                scanner.nextLine(); // consume newline

                permWorkers[i] = new PermWorker(name, age, department, hours);
            } catch (NameFormatException e) {
                System.out.println(e.getMessage());
                i--; // Retry this entry
            }
        }

        // Display TempWorkers
        System.out.println("\nTempWorkers Details:");
        for (TempWorker temp : tempWorkers) {
            temp.displayDetails();
        }

        // Display PermWorkers
        System.out.println("\nPermWorkers Details:");
        for (PermWorker perm : permWorkers) {
            perm.displayDetails();
        }

        // Use Gen to find similar ages
        Gen<TempWorker> tempGen = new Gen<>(tempWorkers);
        Gen<PermWorker> permGen = new Gen<>(permWorkers);

        int similarAges = tempGen.isSimilar(permGen);
        System.out.println("\nNumber of employees with similar ages: " + similarAges);
    }
}

