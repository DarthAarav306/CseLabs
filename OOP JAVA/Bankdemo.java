import java.util.Scanner;
class Bank {
    String name;
    int acno;
    String actype;
    double balance = 0.0;
    static double rate = 0.09;
    Scanner scanner = new Scanner(System.in); // Make Scanner an instance variable

    // Default constructor
    Bank() {
        name = "Default Name";
        acno = 0;
        actype = "Savings";
    }

    // Parameterized constructor
    Bank(String name, int acno, String actype) {
        this.name = name;
        this.acno = acno;
        this.actype = actype;
    }

    // Method to deposit money
    void deposit() {
        System.out.println("Enter amount to deposit:");
        double deposit = scanner.nextDouble();
        this.balance += deposit;
    }

    // Method to withdraw money
    void withdraw() {
        System.out.println("Enter amount you want to withdraw:");
        double withdraw = scanner.nextDouble();
        if (withdraw > this.balance) {
            System.out.println("Insufficient balance");
        } else {
            this.balance -= withdraw;
        }
    }

    // Method to display account details
    void display() {
        System.out.println("Name: " + name);
        System.out.println("Account number: " + acno);
        System.out.println("Type of account: " + actype);
        System.out.println("Account balance: " + balance);
        System.out.println("Rate of interest: " + rate);
    }

    // Static method to display rate of interest
    static void roi(double balance) {
        System.out.println("Rate of interest is: " + rate * balance);
    }
}

class Bankdemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String name;
        int acno;
        String actype;

        // Create first Bank object using parameterized constructor
        System.out.println("Enter details for the first account:");
        System.out.println("Enter name:");
        name = scanner.next();
        System.out.println("Enter account number:");
        acno = scanner.nextInt();
        System.out.println("Enter account type:");
        actype = scanner.next();
        Bank ac1 = new Bank(name, acno, actype);

        // Operations for the first account
        while (true) {
            System.out.println("What would you like to do:\n1.Deposit\n2.Withdraw\n3.Display\n4.Display Rate\n5.Exit");
            int ch = scanner.nextInt();
            switch (ch) {
                case 1:
                    ac1.deposit();
                    break;
                case 2:
                    ac1.withdraw();
                    break;
                case 3:
                    ac1.display();
                    break;
                case 4:
                    Bank.roi(ac1.balance);
                    break;
                case 5:
                    // Exit the loop and continue with the second account
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
            if (ch == 5) break; // Exit the loop if choice is 5
        }

        // Create second Bank object using default constructor
        Bank ac2 = new Bank();
        System.out.println("Default constructor:");
       
        // Operations for the second account
        while (true) {
            System.out.println("What would you like to do:\n1.Deposit\n2.Withdraw\n3.Display\n4.Display Rate\n5.Exit");
            int ch = scanner.nextInt();
            switch (ch) {
                case 1:
                    ac2.deposit();
                    break;
                case 2:
                    ac2.withdraw();
                    break;
                case 3:
                    ac2.display();
                    break;
                case 4:
                    Bank.roi(ac2.balance);
                    break;
                case 5:
                    // Exit the loop
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
            if (ch == 5) break; // Exit the loop if choice is 5
        }

        scanner.close(); // Close the scanner at the end
    }
}




