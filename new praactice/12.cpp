// write aa program to calculate the perimerter/ circumfrenece of a circle and a rectangle, squre, triangle using the concept of function overloading.

#include <iostream>

using namespace std;

// Function to calculate perimeter of a circle

float perimeter(float radius)
{
    return 2 * 3.14159 * radius;
}

// Function to calculate perimeter of a rectangle

float perimeter(float length, float breadth)
{
    return 2 * (length + breadth);
}

// Function to calculate perimeter of a square

float perimeter(float side)
{
    return 4 * side;
}

// Function to calculate perimeter of a triangle

float perimeter(float side1, float side2, float side3)
{
    return side1 + side2 + side3;
}

int main()
{
    float radius, length, breadth, side1, side2, side3;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    cout << "Enter the length and breadth of the rectangle: ";
    cin >> length >> breadth;

    cout << "Enter the side of the square: ";
    cin >> side1;

    cout << "Enter the sides of the triangle: ";
    cin >> side1 >> side2 >> side3;

    cout << "Perimeter of the circle: " << perimeter(radius) << endl;
    cout << "Perimeter of the rectangle: " << perimeter(length, breadth) << endl;
    cout << "Perimeter of the square: " << perimeter(side1) << endl;
    cout << "Perimeter of the triangle: " << perimeter(side1, side2, side3) << endl;

    return 0;
}