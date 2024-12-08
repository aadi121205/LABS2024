// use friend function to add two complex numbers

#include <iostream>

using namespace std;

// Forward declaration of Complex class

class Complex;

// Function prototype for addition

Complex add(Complex, Complex);

// Complex class definition

class Complex
{
private:
    float real;
    float imag;

public:
    // Constructor to initialize real and imag to 0
    Complex() : real(0), imag(0) {}

    // Friend function declaration
    friend Complex add(Complex, Complex);

    // Method to set values of real and imag
    void setValues(float r, float i)
    {
        real = r;
        imag = i;
    }

    // Method to display values
    void display()
    {
        cout << real << " + " << imag <<"i"<< endl;
    }
};

// Function definition to add two Complex numbers

Complex add(Complex c1, Complex c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main()
{
    Complex c1, c2, result;

    // Setting values of c1 and c2
    c1.setValues(3, 4);
    c2.setValues(5, 6);

    // Adding c1 and c2
    result = add(c1, c2);

    // Displaying the result
    result.display();

    return 0;
}
