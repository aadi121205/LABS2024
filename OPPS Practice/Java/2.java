public class MinMaxFinder {
    public static void main(String[] args) {
        int[] array = new int[20];
        
        // Initialize the array with random values for demonstration
        for (int i = 0; i < array.length; i++) {
            array[i] = (int) (Math.random() * 100); // Random values between 0 and 99
        }

        int min = array[0];
        int max = array[0];

        for (int i = 1; i < array.length; i++) {
            if (array[i] < min) {
                min = array[i];
            }
            if (array[i] > max) {
                max = array[i];
            }
        }

        System.out.println("Array: " + java.util.Arrays.toString(array));
        System.out.println("Minimum value: " + min);
        System.out.println("Maximum value: " + max);
    }
}