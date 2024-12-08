// Classes aaand objects in cpp

#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
    string title;
    string author;
    int pages;
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

    return 0;
}

