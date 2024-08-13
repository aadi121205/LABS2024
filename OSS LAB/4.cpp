// Destructor
// Write a class Student with a destructor that prints a message when an object is destroyed. Create and destroy multiple objects in your main function to demonstrate the use of the destructor.

#include <iostream>
#include <string>

using namespace std;

class Student
{
    string name;
    int age;

public:

    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    ~Student()
    {
        cout << "Object destroyed" << endl;
    }
};

int main()
{

    Student s1("John", 20);
    Student s2("Jane", 21);

    return 0;
}