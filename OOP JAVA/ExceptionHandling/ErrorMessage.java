class CustomException extends Exception {
    private int errorCode; // Custom field to hold error code

    // Constructor to initialize message and error code
    public CustomException(String message, int errorCode) {
        super(message); // Pass the message to Exception's constructor
        this.errorCode = errorCode;
    }

    // Overriding the toString() method to customize exception printing
    @Override
    public String toString() {
        return "CustomException: " + getMessage() + " (Error Code: " + errorCode + ")";
    }
}


public class ErrorMessage {
    public static void main(String[] args) {
        try {
            // Throwing a custom exception with a message and error code
            throw new CustomException("Something went wrong", 404);
        } catch (CustomException e) {
            // Calls the overridden toString() method
            System.out.println(e); // Prints CustomException: Something went wrong (Error Code: 404)

            // Only prints the message part
            System.out.println(e.getMessage()); // Prints: Something went wrong
        }
    }
}


