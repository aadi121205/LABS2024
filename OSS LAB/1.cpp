// Basic Class Creation
// Write a C++ class named Person that has public data members name and age. Create a method display() that prints the name and age of the person.

#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        string name;
        int age;
        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

int main() {
    Person p1;
    p1.name = "John";
    p1.age = 25;
    p1.display();
    return 0;
}

