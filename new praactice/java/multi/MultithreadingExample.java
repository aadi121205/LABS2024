// Class to print numbers from 1 to 10
class NumberPrinter extends Thread {
    private final Object lock;

    public NumberPrinter(Object lock) {
        this.lock = lock;
    }

    @Override
    public void run() {
        synchronized (lock) {
            for (int i = 1; i <= 10; i++) {
                System.out.println("Number: " + i);
                try {
                    Thread.sleep(100); // Simulate delay
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

// Class to print letters from A to J
class LetterPrinter extends Thread {
    private final Object lock;

    public LetterPrinter(Object lock) {
        this.lock = lock;
    }

    @Override
    public void run() {
        synchronized (lock) {
            for (char c = 'A'; c <= 'J'; c++) {
                System.out.println("Letter: " + c);
                try {
                    Thread.sleep(100); // Simulate delay
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

public class MultithreadingExample {
    public static void main(String[] args) {
        Object lock = new Object(); // Shared lock for synchronization

        // Create threads
        NumberPrinter numberThread = new NumberPrinter(lock);
        LetterPrinter letterThread = new LetterPrinter(lock);

        // Set thread priorities
        numberThread.setPriority(Thread.MAX_PRIORITY);
        letterThread.setPriority(Thread.MIN_PRIORITY);

        // Start threads
        numberThread.start();
        letterThread.start();

        try {
            // Wait for threads to finish
            numberThread.join();
            letterThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Main thread execution complete.");
    }
}
