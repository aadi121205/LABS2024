// use friend function to make aa calculator

#include <iostream>

using namespace std;

class Calculator
{
public:
    static int add(int a, int b)
    {
        return a + b;
    }

    static int subtract(int a, int b)
    {
        return a - b;
    }

    static int multiply(int a, int b)
    {
        return a * b;
    }

    static int divide(int a, int b)
    {
        return a / b;
    }
};

int main()
{
    int n1, n2;
    char op;

    cout << "Enter first number: ";
    cin >> n1;

    cout << "Enter operator: ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> n2;

    if (op == '+')
    {
        cout << Calculator::add(n1, n2) << endl;
    }
    else if (op == '-')
    {
        cout << Calculator::subtract(n1, n2) << endl;
    }
    else if (op == '*')
    {
        cout << Calculator::multiply(n1, n2) << endl;
    }
    else if (op == '/')
    {
        cout << Calculator::divide(n1, n2) << endl;
    }
    else
    {
        cout << "Invalid operator" << endl;
    }

    return 0;
}