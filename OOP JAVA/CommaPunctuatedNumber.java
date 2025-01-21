public class CommaPunctuatedNumber {

    static String convert(String number) {
        String newString = ""; // Changed 'new' to 'newString' to avoid using a reserved keyword
        int count = 0;

        // Loop starts from the end of the string
        for (int i = number.length() - 1; i > 0; i--) {
            if (count % 3 != 0) { // Add the current character without a comma
                newString = number.charAt(i) + newString;
            } else { // Add a comma before the current character
                newString = "," + number.charAt(i) + newString;
            }
            count++;
        }

        // Add the first character to the result
        newString = number.charAt(0) + newString;

        return newString; // Return the formatted string
    }

    public static void main(String[] args) {
        // Test the convert method
        String number = "1234567890";
        String formattedNumber = convert(number);
        System.out.println("Original Number: " + number);
        System.out.println("Formatted Number: " + formattedNumber);
    }
}
