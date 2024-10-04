public class MyClass {
    private int value;

    // Constructor
    public MyClass(int initialValue) {
        value = initialValue;
    }

    // Getter method
    public int getValue() {
        return value;
    }

    public static void main(String[] args) {
        MyClass obj = new MyClass(10);
        System.out.println("Value: " + obj.getValue());
    }
}