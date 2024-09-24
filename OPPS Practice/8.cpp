#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructor to initialize complex number
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Function to display the complex number
    void display() {
        if (imag < 0)
            cout << real << " - " << -imag << "i" << endl;
        else
            cout << real << " + " << imag << "i" << endl;
    }

    // Addition of two complex numbers
    Complex operator + (const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction of two complex numbers
    Complex operator - (const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication of two complex numbers
    Complex operator * (const Complex& other) {
        return Complex((real * other.real - imag * other.imag), (real * other.imag + imag * other.real));
    }

    // Division of two complex numbers
    Complex operator / (const Complex& other) {
        float denom = other.real * other.real + other.imag * other.imag;
        return Complex(((real * other.real + imag * other.imag) / denom), 
                       ((imag * other.real - real * other.imag) / denom));
    }
};

int main() {
    Complex c1(4, 5); // First complex number
    Complex c2(2, 3); // Second complex number

    Complex c3 = c1 + c2; // Addition
    cout << "Addition: ";
    c3.display();

    Complex c4 = c1 - c2; // Subtraction
    cout << "Subtraction: ";
    c4.display();

    Complex c5 = c1 * c2; // Multiplication
    cout << "Multiplication: ";
    c5.display();

    Complex c6 = c1 / c2; // Division
    cout << "Division: ";
    c6.display();

    return 0;
}
