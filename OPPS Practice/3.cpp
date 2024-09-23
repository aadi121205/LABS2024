#include <iostream>
#include <vector>
#include <string>

class Employee
{
public:
    int employeeNumber;
    std::string name;
    std::string address;
    std::string department;

    Employee(int num, const std::string &n, const std::string &addr, const std::string &dept)
        : employeeNumber(num), name(n), address(addr), department(dept) {}

    void displayInfo() const
    {
        std::cout << "Employee Number: " << employeeNumber
                  << "\nName: " << name
                  << "\nAddress: " << address
                  << "\nDepartment: " << department << std::endl;
    }
};

class Manager
{
public:
    std::vector<Employee> employees;
    int managerNumber;
    std::string name;
    std::string address;
    std::string department;

    Manager(int num, const std::string &n, const std::string &addr, const std::string &dept)
        : managerNumber(num), name(n), address(addr), department(dept) {}

    void addEmployee(const Employee &emp)
    {
        employees.push_back(emp);
    }

    void displayManagerAndEmployees() const
    {
        std::cout << "Manager Number: " << managerNumber
                  << "\nName: " << name
                  << "\nAddress: " << address
                  << "\nDepartment: " << department << "\n"
                  << std::endl;
        for (const auto &emp : employees)
        {
            emp.displayInfo();
        }
    }
};

int main()
{
    Employee e1(1, "John Doe", "123 Elm St", "HR");
    Employee e2(2, "Jane Smith", "456 Oak St", "Marketing");

    Manager m1(101, "Alice Johnson", "789 Pine St", "Operations");
    m1.addEmployee(e1);
    m1.addEmployee(e2);

    m1.displayManagerAndEmployees();
    return 0;
}
