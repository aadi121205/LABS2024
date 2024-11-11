// Write a program to accept five different numbers by creating a class called friendfuncl and friendfunc2 taking 2 and 3 arguments respectively and calculate the average of these numbers by passing object of the class to friend function

#include <bits/stdc++.h>

using namespace std;

class friendfuncl;

class friendfunc2;

class friendfuncl
{
    float a, b, c, d, e;

public:
    friendfuncl(float a, float b, float c, float d, float e)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->e = e;
    }

    friend float average(friendfuncl f, friendfunc2 g);
};

class friendfunc2
{
    float a, b, c;

public:
    friendfunc2(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    friend float average(friendfuncl f, friendfunc2 g);
};

float average(friendfuncl f, friendfunc2 g)
{
    return (f.a + f.b + f.c + f.d + f.e + g.a + g.b + g.c) / 8;
}

int main()
{
    float a, b, c, d, e;
    cout << "Enter five numbers: ";
    cin >> a >> b >> c >> d >> e;

    friendfuncl f(a, b, c, d, e);

    float x, y, z;
    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    friendfunc2 g(x, y, z);

    cout << "The average of the numbers is: " << average(f, g) << endl;

    return 0;
}

// By Aaditya Bhatia