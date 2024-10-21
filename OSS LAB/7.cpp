// Write a C++ program to perform dilfferent arithmetic operation such as addition, subtraction, division, modulus and multiplication using inline function.

#include <iostream>
using namespace std;

inline int add(int a, int b) {
    return a + b;
}

inline int subtract(int a, int b) {
    return a - b;
}

inline int multiply(int a, int b) {
    return a * b;
}

inline float divide(int a, int b) {
    return static_cast<float>(a) / b;
}

inline int mod(int a, int b) {
    return a % b;
}

int main() {
    int a, b;
    cout << "Enter two numbers:" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    cout << "Addition: " << add(a, b) << endl;
    cout << "Subtraction: " << subtract(a, b) << endl;
    cout << "Multiplication: " << multiply(a, b) << endl;
    cout << "Division: " << divide(a, b) << endl;
    cout << "Modulus: " << mod(a, b) << endl;

    return 0;
}

// By Aaditya Bhatia