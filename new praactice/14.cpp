#include <iostream>

using namespace std;

class BankManager;

class BankAccount
{
private:
    string name;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accoutNumber, double balance)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (balance - amount >= 0)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    friend BankManager;
};

class BankManager
{
    public:
        void displayAccount(BankAccount account)
        {
            cout << "Balwnce of account: " << account.balance << endl;
        }
        void deposit(BankAccount account, double amount)
        {
            account.balance += amount;
            cout << "Deposited " << amount << " to account" << endl;
        }
};

int main()
{
    BankAccount account("John Doe", 123456, 1000);
    BankManager manager;
    account.deposit(500);
    account.withdraw(200);
    account.display();
    manager.displayAccount(account);
    manager.deposit(account, 1000);
    return 0;
}