// Custom Exception Class
class CustomException extends Exception {
    public CustomException(String message) {
        super(message);
    }
}

public class ExceptionHandlingDemo {

    // Method that throws a custom exception
    public static void riskyMethod(boolean condition) throws CustomException {
        if (condition) {
            throw new CustomException("Custom Exception occurred!");
        }
    }

    public static void main(String[] args) {
        try {
            // Outer try-catch block
            try {
                int result = 10 / 0; // This will cause ArithmeticException
                System.out.println("Result: " + result);
            } catch (ArithmeticException e) {
                System.out.println("Caught ArithmeticException: " + e.getMessage());
            }

            // Calling method that throws a custom exception
            riskyMethod(true);

        } catch (CustomException e) {
            System.out.println("Caught CustomException: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed: Cleaning up resources.");
        }

        System.out.println("Program execution continues...");
    }
}
