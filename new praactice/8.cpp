// nested classes
#include <iostream>

using namespace std;

class Book
{
public:
    string title;
    string author;
    int pages;

    class NestedClass
    {
    public:
        string nestedString;
    };
};

int main()
{
    Book book1;
    book1.title = "Harry Potter";
    book1.author = "JK Rowling";
    book1.pages = 500;

    cout << book1.title << endl;
    cout << book1.author << endl;
    cout << book1.pages << endl;

    Book::NestedClass nestedObject;
    nestedObject.nestedString = "This is a nested string";

    cout << nestedObject.nestedString << endl;

    return 0;
}