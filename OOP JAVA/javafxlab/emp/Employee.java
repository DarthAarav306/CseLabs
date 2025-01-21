package emp;

class NameFormatException extends Exception {
    public NameFormatException(String message) {
        super(message);
    }
}

// File: emp/Employee.java
package emp;

public abstract class Employee {
    String name;
    int age;
    double salary;
    String department;

    public Employee(String name, int age, String department) throws NameFormatException {
        // Check for special characters in the name using charAt
        for (int i = 0; i < name.length(); i++) {
            if (!Character.isLetter(name.charAt(i))) {
                throw new NameFormatException("Special character detected in name: " + name);
            }
        }
        this.name = name;
        this.age = age;
        this.department = department;
    }

    // Abstract method to compute salary
    abstract void computePay(int hours);

    public void displayDetails() {
        System.out.println("Name: " + name + ", Age: " + age + ", Department: " + department + ", Salary: " + salary);
    }
}

class TempWorker extends Employee {  // No access modifier, so it's package-private
    private static final int HOURLY_RATE = 100;

    public TempWorker(String name, int age, String department, int hours) throws NameFormatException {
        super(name, age, department);
        computePay(hours);
    }

    @Override
    void computePay(int hours) {
        this.salary = HOURLY_RATE * hours;
    }
}

class PermWorker extends Employee {  // No access modifier, so it's package-private
    private static final int HOURLY_RATE = 150;

    public PermWorker(String name, int age, String department, int hours) throws NameFormatException {
        super(name, age, department);
        computePay(hours);
    }

    @Override
    void computePay(int hours) {
        this.salary = HOURLY_RATE * hours;
    }
}
