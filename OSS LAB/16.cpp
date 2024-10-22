// Write a program using natural function as friend P b. 
// Member function as friend to calculate the sum of two complex numbers by using a class complex

#include <iostream>

using namespace std;

class Complex;

class Natural {

public:
    friend int sum(Complex, Complex);
};

class Complex {

private:
    int real, imaginary;

public:
    Complex(int r, int i) : real(r), imaginary(i) {}

    friend int sum(Complex, Complex);
};

int sum(Complex c1, Complex c2) {
    return c1.real + c2.real + c1.imaginary + c2.imaginary;
}

int main() {
    Complex c1(1, 2), c2(3, 4);
    cout << "Sum of the two complex numbers: " << sum(c1, c2) << endl;
    return 0;
}
// By Aaditya Bhatia