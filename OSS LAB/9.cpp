// Write a C++ program to create a simple banking system in which the initial halance and the rate of interest are read from the keyboard and these values are initialized using the constructor. 
// The destructor member function is defined in this program to destroy the class object created using constructor member function. This program consists of following member functions:

#include <bits/stdc++.h>

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
        cin.ignore(); // Clear the newline character from the input buffer
        cout << "Enter the name of the person: ";
        getline(cin, name);
        cout << "Enter the time frame in years: ";
        cin >> time;
    }

    float calculate()
    {
        float compoundInterest = balance * pow((1 + rate), time);
        return compoundInterest;
    }

    ~Bank()
    {
        cout << "Destructor called for " << name << endl;
    }
};

int main()
{
    float balance, rate;
    cout << "Enter the initial balance: ";
    cin >> balance;
    cout << "Enter the rate of interest (in decimal form, e.g., 0.05 for 5%): ";
    cin >> rate;

    Bank b(balance, rate);
    b.input();
    cout << "The balance is: " << b.calculate() << endl;

    return 0;
}

// By Aaditya Bhatia
