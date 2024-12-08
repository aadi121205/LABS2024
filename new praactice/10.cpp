// This program demonstrates method overriding and inheritance in C++

#include <iostream>

using namespace std;

// Base class definition
class Base
{
public:
    // Method to display a message
    void display()
    {
        cout << "Display of Base" << endl;
    }
};

// Derived class inheriting from Base class
class Derived : public Base
{
public:
    // Overriding the display method of Base class
    void display()
    {
        cout << "Display of Derived" << endl;
    }
};

int main()
{
    Derived d; // Creating an object of Derived class
    d.display(); // Calls the display method of Derived class
    d.Base::display(); // Calls the display method of Base class using scope resolution operator
    return 0;
}
