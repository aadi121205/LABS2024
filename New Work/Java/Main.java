class One extends Thread {
    static Object lock = new Object();

    One(Object lock) {
        this.lock = lock;
    }

    public void run() {
        synchronized (lock) {
            for (int i = 0; i < 5; i++) {
                System.out.println("Thread 1");
                try {
                    Thread.sleep(1000);
                } catch (Exception e) {
                    System.out.println(e);
                }
            }
        }
    }
}

class Two extends Thread {

    static Object lock = new Object();

    Two(Object lock) {
        this.lock = lock;
    }

    public void run() {
        synchronized (lock) {
            for (int i = 0; i < 5; i++) {
                System.out.println("Thread 2");
                try {
                    Thread.sleep(1000);
                } catch (Exception e) {
                    System.out.println(e);
                }
            }
        }
    }
}

class Main {
    public static void main(String[] args) {
        Object lock = new Object();
        One t1 = new One(lock);
        Two t2 = new Two(lock);
        t1.start();
        t2.start();
    }
}