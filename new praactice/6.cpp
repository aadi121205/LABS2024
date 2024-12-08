// write aa code showing use of elseif and ifelse
#include <iostream>
#include <string>

using namespace std;

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
        cout << n1 + n2 << endl;
    }
    else if (op == '-')
    {
        cout << n1 - n2 << endl;
    }
    else if (op == '*')
    {
        cout << n1 * n2 << endl;
    }
    else if (op == '/')
    {
        cout << n1 / n2 << endl;
    }
    else
    {
        cout << "Invalid operator" << endl;
    }

    return 0;
}