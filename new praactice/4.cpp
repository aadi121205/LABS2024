// make a dataa structer to store emploey data

#include <iostream>
#include <string>

using namespace std;

struct employee
{
    int id;
    string name;
    float salary;
};

int main()
{
    employee e1;
    e1.id = 1;
    e1.name = "John";
    e1.salary = 100000;

    cout << "Employee id: " << e1.id << endl;
    cout << "Employee name: " << e1.name << endl;
    cout << "Employee salary: " << e1.salary << endl;

    return 0;
}