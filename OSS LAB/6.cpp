// Write a C++ program to swap two number by both call by value and call by reference mechanism, using two functions swap_valuc( and swap_reference respectively, by getting the choice from the user and executing the user's choice by switch-case.

#include <iostream>
using namespace std;

// Function to swap two numbers using call by value
void swap_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "After swapping (Call by Value): a = " << a << ", b = " << b << endl;
}

// Function to swap two numbers using call by reference
void swap_reference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "After swapping (Call by Reference): a = " << a << ", b = " << b << endl;
}

int main() {
    int a, b;
    int choice;

    cout << "Enter two numbers to swap:" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    cout << "\nChoose the swapping method:" << endl;
    cout << "1. Call by Value" << endl;
    cout << "2. Call by Reference" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1:
            swap_value(a, b);
            cout << "Original values after swap by value (No change in original variables):" << endl;
            cout << "a = " << a << ", b = " << b << endl;
            break;

        case 2:
            swap_reference(a, b);
            cout << "Original values after swap by reference:" << endl;
            cout << "a = " << a << ", b = " << b << endl;
            break;

        default:
            cout << "Invalid choice. Please select 1 or 2." << endl;
            break;
    }

    return 0;
}

// By Aaditya Bhatia