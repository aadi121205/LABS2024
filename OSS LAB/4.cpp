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
        cout << "Object is destroyed" << endl;
    }
};

int main()
{
    Student s1("Aaditya", 20);
    Student s2("Rahul", 21);
    Student s3("Rohit", 22);
    return 0;

}
// By Aaditya Bhatia