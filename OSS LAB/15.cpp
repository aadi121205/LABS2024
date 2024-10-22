// Write a program in C+-+-using static variable to get the sum of the salary of 10 employees

#include <iostream>

using namespace std;

class Employee {
    static float totalSalary;

    float salary;

public:
    Employee(float s) : salary(s) {
        totalSalary += salary;
    }

    static float getTotalSalary() {
        return totalSalary;
    }
};

float Employee::totalSalary = 0;

int main() {
    float salary;
    for (int i = 0; i < 10; i++) {
        cout << "Enter salary of employee " << i + 1 << ": ";
        cin >> salary;
        Employee e(salary);
    }

    cout << "Total salary of all employees: " << Employee::getTotalSalary() << endl;

    return 0;
}

// By Aaditya Bhatia
