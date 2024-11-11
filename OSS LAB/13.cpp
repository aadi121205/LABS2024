// Consider a class network of figure given below. The class master derives information from both account and admin classes which in turn derived derive information from the class person,
// Define all the four classes and write a program to create, update and display the information contained in master objects. Also demonstrate the use of different access specifiers by means of member variables and member functions

#include <iostream>

using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    void getDetails()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Account : public Person
{

protected:
    string accountNumber;

public:
    void getAccountDetails()
    {
        cout << "Enter account number: ";
        cin >> accountNumber;
    }

    void displayAccountDetails()
    {
        displayDetails();
        cout << "Account number: " << accountNumber << endl;
    }
};

class Admin : public Person
{

protected:
    string adminID;

public:
    void getAdminDetails()
    {
        cout << "Enter admin ID: ";
        cin >> adminID;
    }

    void displayAdminDetails()
    {
        displayDetails();
        cout << "Admin ID: " << adminID << endl;
    }
};

class Master : public Account, public Admin
{

public:
    void getMasterDetails()
    {
        Account::getDetails();
        getAccountDetails();
        Admin::getDetails();
        getAdminDetails();
    }

    void displayMasterDetails()
    {
        displayAccountDetails();
        displayAdminDetails();
    }
};

int main()
{
    Master m;
    m.getMasterDetails();
    m.displayMasterDetails();
    return 0;
}
