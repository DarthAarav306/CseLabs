import java.util.Scanner;

public class SubstringOperations {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the main string and the substring
        System.out.println("Enter the main string:");
        String mainString = sc.nextLine();
        System.out.println("Enter the substring:");
        String subString = sc.nextLine();

        // Count the number of occurrences
        int count = 0;
        int index = mainString.indexOf(subString);
        System.out.println("\nOccurrences of the substring:");
        while (index >= 0) {
            System.out.println("Found at index: " + index);
            count++;
            index = mainString.indexOf(subString, index + 1);
        }

        // Display the count of the substring occurrences
        System.out.println("\nNumber of occurrences of the substring: " + count);

        // Remove all occurrences of the substring from the main string
        String modifiedString = mainString.replace(subString, "");
        System.out.println("\nString after removing all occurrences of the substring:");
        System.out.println(modifiedString);

        sc.close();
    }
}

/*import java.util.Scanner;

public class SubstringOperationsWithSplit {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the main string and the substring
        System.out.println("Enter the main string:");
        String mainString = sc.nextLine();
        System.out.println("Enter the substring:");
        String subString = sc.nextLine();

        // Split the main string using the substring as a delimiter
        String[] parts = mainString.split(subString);

        // Count the number of occurrences
        int count = parts.length - 1;

        // Display the count of the substring occurrences
        System.out.println("\nNumber of occurrences of the substring: " + count);

        // Print the parts array to verify the split
        System.out.println("\nAfter splitting:");
        for (String part : parts) {
            System.out.println(part);
        }

        // Rebuild the string without the substring (effectively removing the substring)
        String modifiedString = String.join("", parts);
        System.out.println("\nString after removing all occurrences of the substring:");
        System.out.println(modifiedString);

        sc.close();
    }
}

 */