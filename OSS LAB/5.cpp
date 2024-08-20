#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int Empnumber;
    string Empname;

public:
    void getdata() {
        cout << "Enter Employee Number: ";
        cin >> Empnumber;
        cin.ignore();  // To ignore the newline character after entering Empnumber
        cout << "Enter Employee Name: ";
        getline(cin, Empname);
    }

    void display() const {
        cout << "Employee Number: " << Empnumber << endl;
        cout << "Employee Name: " << Empname << endl;
    }
};

int main() {
    const int numEmployees = 6;
    Employee employees[numEmployees];

    // Input data for each employee
    for (int i = 0; i < numEmployees; ++i) {
        cout << "\nEnter details for Employee " << i + 1 << ":" << endl;
        employees[i].getdata();
    }

    // Display data for each employee
    cout << "\nEmployee Details:" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        cout << "\nEmployee " << i + 1 << ":" << endl;
        employees[i].display();
    }

    return 0;
}
