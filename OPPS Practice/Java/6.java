class Shape {
    double length, width, height;

    Shape(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }
}

class Rectangle extends Shape {
    Rectangle(double length, double width) {
        super(length, width, 0);
    }

    double area() {
        return length * width;
    }
}

class Cuboid extends Rectangle {
    Cuboid(double length, double width, double height) {
        super(length, width);
        this.height = height;
    }

    double volume() {
        return length * width * height;
    }
}

public class Main {
    public static void main(String[] args) {
        Cuboid cuboid = new Cuboid(5, 3, 4);
        System.out.println("Volume of the cuboid: " + cuboid.volume());
    }
}