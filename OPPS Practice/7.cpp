#include <iostream>
using namespace std;

// A template class to work with different data types
template <typename T>
class MyClass {
private:
    T value;

public:
    // Constructor: Initializes the object
    MyClass(T val) : value(val) {
        cout << "Constructor called. Value initialized to: " << value << endl;
    }

    // Destructor: Cleans up when the object is destroyed
    ~MyClass() {
        cout << "Destructor called. Object with value " << value << " is destroyed." << endl;
    }

    // A friend function declaration
    friend void friendFunc(MyClass<T>& obj);

    // A member function to display the value
    void displayValue() const {
        cout << "The value is: " << value << endl;
    }
};

// A friend function that can access private members of MyClass
// even though it's not a member of the class
template <typename T>
void friendFunc(MyClass<T>& obj) {
    cout << "Friend function accessing private value: " << obj.value << endl;
}

int main() {
    // Creating an object of the template class with int data type
    MyClass<int> obj1(10);

    // Display the value using a member function
    obj1.displayValue();

    // Access the private member using a friend function
    friendFunc(obj1);

    // Creating another object of the template class with double data type
    MyClass<double> obj2(5.5);

    // Display the value using a member function
    obj2.displayValue();

    // Access the private member using the friend function
    friendFunc(obj2);

    // When main() ends, the destructors will be automatically called
    return 0;
}
