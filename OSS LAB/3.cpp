// Copy Constructor
// Implement a class Book with private members title, author, and price. Include a copy constructor that copies data from one object to another and a method display() to print the book details.

#include <iostream>
#include <string>

using namespace std;

class Book
{
    string title;
    string author;
    float price;

public:

    Book(string title, string author, float price)
    {
        this->title = title;
        this->author = author;
        this->price = price;
    }

    Book(const Book &b)
    {
        title = b.title;
        author = b.author;
        price = b.price;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};

int main()
{
    Book b1("The Satanic Verses", "Salman Rushdie", 500);
    Book b2 = b1;

    b1.display();
    b2.display();

    return 0;
}

// By Aaditya Bhatia