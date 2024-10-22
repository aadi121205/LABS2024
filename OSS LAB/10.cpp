// Write a program to return absolute value of variable types integer and float using function overloading

#include <iostream>
using namespace std;

int customAbs(int num) {
    return num < 0 ? -num : num;
}

float customAbs(float num) {
    return num < 0 ? -num : num;
}

int main() {
    int num1;
    float num2;

    cout << "Enter an integer: ";
    cin >> num1;
    cout << "Absolute value of " << num1 << " is " << customAbs(num1) << endl;

    cout << "Enter a float: ";
    cin >> num2;
    cout << "Absolute value of " << num2 << " is " << customAbs(num2) << endl;

    return 0;
}

// By Aaditya Bhatia
