import java.util.Scanner; // Importing the Scanner class for user input

class Main {
    // Method to read input from the user
    public static void readInput() {
        // Using try-with-resources to manage the Scanner
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter an integer: ");
            int n = sc.nextInt(); // Read an integer
            sc.nextLine(); // Consume the newline left by nextInt()

            System.out.print("Enter a string: ");
            String s = sc.nextLine(); // Read a string

            System.out.println("You entered the integer: " + n);
            System.out.println("You entered the string: " + s);
        }
    }

    // Main method: Entry point of the program
    public static void main(String[] args) {
        System.out.println("Hello World"); // Print a welcome message

        // Call the readInput method
        readInput();
    }
}
