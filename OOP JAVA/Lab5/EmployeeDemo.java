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

    // Method 1: Format the employee's name in-place using ASCII operations
    void formatEmployeeNameInPlace() {
        char[] charArray = Ename.toCharArray();
        boolean capitalizeNext = true;

        for (int i = 0; i < charArray.length; i++) {
            if (charArray[i] == ' ') {
                capitalizeNext = true;
            } else if (capitalizeNext && charArray[i] >= 'a' && charArray[i] <= 'z') {
                charArray[i] = (char) (charArray[i] - 32);
                capitalizeNext = false;
            } else if (!capitalizeNext && charArray[i] >= 'A' && charArray[i] <= 'Z') {
                charArray[i] = (char) (charArray[i] + 32);
            } else {
                capitalizeNext = false;
            }
        }

        Ename = new String(charArray);
    }
    void formatEmployeeName() {
    // Convert the entire name to lowercase first
    Ename = Ename.toLowerCase();
    String format = "";

    // Capitalize the first character if it's a lowercase letter
    if (Ename.charAt(0) >= 'a' && Ename.charAt(0) <= 'z') {
        format += (char) (Ename.charAt(0) - 32);  // Convert to uppercase
    } else {
        format += Ename.charAt(0);  // Keep it as is if not a lowercase letter
    }

    // Traverse the rest of the string
    for (int i = 1; i < Ename.length(); i++) {
        // If the current character is lowercase and preceded by a space, capitalize it
        if (Ename.charAt(i) >= 'a' && Ename.charAt(i) <= 'z' && Ename.charAt(i - 1) == ' ') {
            format += (char) (Ename.charAt(i) - 32);  // Convert to uppercase
        } else {
            format += Ename.charAt(i);  // Keep it as is if no condition matches
        }
    }

    // Assign the formatted name back to Ename
    Ename = format;
}


    // Method 3: Generate email using split method
    String generateEmailUsingSplit() {
        String[] names = Ename.split(" ");
        String email = "";

        if (names.length > 1) {
            String firstName = names[0].toLowerCase();
            String lastName = names[names.length - 1].toLowerCase();
            email = firstName.charAt(0) + lastName + "@example.com";
        } else {
            email = Ename.toLowerCase() + "@example.com";
        }

        return email;
    }

    // Method 4: Generate email using indexOf and substring
    String generateEmailUsingIndex() {
        String nameLower = Ename.toLowerCase();
        int spaceIndex = nameLower.indexOf(' ');
        
        if (spaceIndex != -1) {
            char firstInitial = nameLower.charAt(0);
            String lastName = nameLower.substring(spaceIndex + 1);
            return firstInitial + lastName + "@example.com";
        } else {
            return nameLower + "@example.com";
        }
    }

    public static void main(String[] args) {
        // Example to show the new methods in action
        Employee emp = new Employee("JOHN DOE", 101, 50000);

        System.out.println("Before Formatting: " + emp.Ename);

        // Format the employee's name using the in-place method
        emp.formatEmployeeNameInPlace();
        System.out.println("After Formatting In-Place: " + emp.Ename);

        // Format the employee's name using string manipulation
        emp.Ename = "JOHN DOE";  // Reset to original name for comparison
        //emp.formatEmployeeNameWithStringManipulation();
        System.out.println("After Formatting With String Manipulation: " + emp.Ename);

        // Generate and print the employee's email using split
        String emailUsingSplit = emp.generateEmailUsingSplit();
        System.out.println("Generated Email Using Split: " + emailUsingSplit);

        // Generate and print the employee's email using indexOf and substring
        emp.Ename = "JOHN DOE";  // Reset to original name for comparison
        String emailUsingIndex = emp.generateEmailUsingIndex();
        System.out.println("Generated Email Using Index: " + emailUsingIndex);

        // Compute salary and display details
        emp.compute_net_sal();
        emp.display();
    }
}
