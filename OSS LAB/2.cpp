// Constructor Usage
// Create a class Rectangle with private data members length and breadth. Implement a constructor that initializes these values and a public method area() that returns the area of the rectangle.

#include <iostream>
#include <string>

using namespace std;

class Rectangle {
    private:
        int length;
        int breadth;
    public:
        Rectangle(int l, int b) {
            length = l;
            breadth = b;
        }
        int area() {
            return length * breadth;
        }
};


int main() {
    Rectangle r(10, 5);
    cout << "Area: " << r.area() << endl;
    return 0;
}

// By Aaditya Bhatia