// Write a C++ program to create three objects for a class named pntr_obj with data members such as roll_no & name. Create a member function set_data() for setting the data values and print0 member function to print which object has invoked it using "this' pointer.

#include <iostream>

using namespace std;

class pntr_obj
{
    int roll_no;
    string name;

public:
    void set_data(int r, string n)
    {
        roll_no = r;
        name = n;
    }

    void print()
    {
        cout << "Object with roll number " << roll_no << " and name " << name << " has invoked this function." << endl;
    }
};

int main()
{
    pntr_obj obj1, obj2, obj3;

    obj1.set_data(1, "Aaditya");
    obj2.set_data(2, "Bhatia");
    obj3.set_data(3, "is");

    obj1.print();
    obj2.print();
    obj3.print();

    return 0;
}