// Write a C++ program to create a simple banking system in which the initial halance and the rate of interest are read from the keyboard and these values are initialized using the constructor. The destructor member function is defined in this program to destroy the class object created using constructor member function. This program consists of following member functions
// The member functions are as follows
// 1. A function to take the input name of the person along with time frame.
// 2. Return the balance after that time frame using the ROI.

#include <iostream>
using namespace std;

class Bank
{
    string name;
    float balance;
    float rate;
    float time;

public:
    Bank(float b, float r)
    {
        balance = b;
        rate = r;
    }

    void input()
    {
        cout << "Enter the name of the person: ";
        cin >> name;
        cout << "Enter the time frame: ";
        cin >> time;
    }

    float calculate()
    {
        return balance + (balance * rate * time);
    }

    ~Bank()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    float balance, rate;
    cout << "Enter the initial balance: ";
    cin >> balance;
    cout << "Enter the rate of interest: ";
    cin >> rate;

    Bank b(balance, rate);
    b.input();
    cout << "The balance after " << b.calculate() << endl;

    return 0;
}

