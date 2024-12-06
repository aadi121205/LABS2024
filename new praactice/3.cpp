// make input string full caps

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << " !" << endl;
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            name[i] -= 32;
        }
    }
    cout << "Full caps: " << name;
    return 0;
}