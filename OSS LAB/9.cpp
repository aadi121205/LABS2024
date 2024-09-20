// Write a program to return absolute value of variable types integer and float using function overloading

#include <iostream>

int abs(int n) {
    return n < 0 ? -n : n;
}

float abs(float n) {
    return n < 0 ? -n : n;
}

int main() {
    int a = -5;
    float b = -5.5;

    std::cout << "Absolute value of " << a << " is " << abs(a) << std::endl;
    std::cout << "Absolute value of " << b << " is " << abs(b) << std::endl;

    return 0;
}

