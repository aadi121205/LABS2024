// The member functions are as follows 
// 1. A function to take the input name of the person along with time frame.
// 2. Return the balance after that time frame using the ROI.

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
    cout << "The balance after " << b.calculate() << " years is: " << b.calculate() << endl;

    return 0;
}

// By Aaditya Bhatia