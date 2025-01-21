import java.util.Scanner;

class STUDENT {
    String fullName;
    int regNumber;

    // Default constructor
    STUDENT() {
        this.fullName = "Default Name";
        this.regNumber = 0;
    }

    // Parameterized constructor
    STUDENT(String fullName, int regNumber) {
        this.fullName = fullName;
        this.regNumber = regNumber;
    }

    // Method 1: Extract initials using split
    String extractInitials() {
        String[] words = fullName.split(" ");
        String initials = "";

        for (String word : words) {
            if (!word.isEmpty()) {
                initials += word.charAt(0);  // Take the first character of each word
            }
        }

        return initials.toUpperCase();  // Return initials in uppercase
    }

    // Method 2: Extract initials using charAt
    String extractInitialsUsingCharAt() {
        String initials = "";
        initials += fullName.charAt(0);  // First character of the name

        for (int i = 1; i < fullName.length(); i++) {
            if (fullName.charAt(i) == ' ' && i + 1 < fullName.length()) {
                initials += fullName.charAt(i + 1);  // Take the next character after space
            }
        }

        return initials.toUpperCase();
    }

    // Method 3: Remove all whitespaces using replaceAll
    String removeWhitespace() {
        return fullName.replaceAll("\\s", "");  // Remove all whitespace characters
    }

    // Method 4: Remove all whitespaces using charAt
    String removeWhitespaceUsingCharAt() {
        String result = "";

        for (int i = 0; i < fullName.length(); i++) {
            if (fullName.charAt(i) != ' ') {
                result += fullName.charAt(i);
            }
        }

        return result;
    }

    // Method 5: List names containing a substring using indexOf (case-insensitive)
    static void listNamesWithSubstringUsingIndexOf(STUDENT[] students, String substring) {
        String substringLower = substring.toLowerCase();
        System.out.println("Names containing the substring \"" + substring + "\":");

        for (STUDENT student : students) {
            if (student.fullName.toLowerCase().indexOf(substringLower) != -1) {
                System.out.println(student.fullName);
            }
        }
    }

    // Method 6: Sort students alphabetically using bubble sort (compareToIgnoreCase)
    static void sortStudentsAlphabeticallyUsingBubbleSort(STUDENT[] students) {
        int n = students.length;
        STUDENT temp;

        // Bubble sort algorithm
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (students[j].fullName.compareToIgnoreCase(students[j + 1].fullName) > 0) {
                    // Swap
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        System.out.println("Students sorted alphabetically by name:");
        for (STUDENT student : students) {
            System.out.println(student.fullName);
        }
    }

    // Display student details
    void display() {
        System.out.println("Student Name: " + fullName);
        System.out.println("Registration Number: " + regNumber);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Array of students for testing
        STUDENT[] students = new STUDENT[3];
        students[0] = new STUDENT("John Doe", 101);
        students[1] = new STUDENT("Alice Johnson", 102);
        students[2] = new STUDENT("Michael Smith", 103);

        // Test the extractInitials() method
        System.out.println("Initials of " + students[0].fullName + ": " + students[0].extractInitials());
        System.out.println("Initials using charAt of " + students[0].fullName + ": " + students[0].extractInitialsUsingCharAt());

        // Test the removeWhitespace() method
        System.out.println("Name without whitespace: " + students[0].removeWhitespace());
        System.out.println("Name without whitespace using charAt: " + students[0].removeWhitespaceUsingCharAt());

        // Test the listNamesWithSubstringUsingIndexOf() method
        System.out.print("Enter a substring to search for: ");
        String substring = sc.nextLine();
        listNamesWithSubstringUsingIndexOf(students, substring);

        // Test the sortStudentsAlphabeticallyUsingBubbleSort() method
        sortStudentsAlphabeticallyUsingBubbleSort(students);

        sc.close();
    }
}
