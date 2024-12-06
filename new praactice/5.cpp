// make a basic calculator using switch case
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

    switch (op)
    {
    case '+':
        cout << n1 + n2 << endl;
        break;
    case '-':
        cout << n1 - n2 << endl;
        break;
    case '*':
        cout << n1 * n2 << endl;
        break;
    case '/':
        cout << n1 / n2 << endl;
        break;
    default:
        cout << "Invalid operator" << endl;
        break;
    }

    return 0;
}

