#include <iostream>

class Shape {
protected:
    double width, height;

public:
    virtual void get_data() {
        std::cin >> width >> height;
    }

    virtual double display_area() = 0;
};

class Triangle : public Shape {
public:
    double display_area() override {
        return (width * height / 2);
    }
};

class Rectangle : public Shape {
public:
    double display_area() override {
        return width * height;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Triangle();
    shapes[1] = new Rectangle();

    std::cout << "Enter width and height for triangle: ";
    shapes[0]->get_data();
    std::cout << "Area of triangle: " << shapes[0]->display_area() << std::endl;

    std::cout << "Enter width and height for rectangle: ";
    shapes[1]->get_data();
    std::cout << "Area of rectangle: " << shapes[1]->display_area() << std::endl;

    delete shapes[0];
    delete shapes[1];
    return 0;
}
