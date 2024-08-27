// Write a program to accept five different numbers by creating a class called friendfuncl and friendfunc2 taking 2 and 3 arguments respectively and calculate the average of these numbers by passing obiect of the class to friend function

#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

class FriendFunc2; // Forward declaration

class FriendFunc1 {
private:
    int num1, num2;

public:
    FriendFunc1(int a, int b) : num1(a), num2(b) {}

    friend float calculateAverage(FriendFunc1, FriendFunc2);
};

class FriendFunc2 {
private:
    int num3, num4, num5;

public:
    FriendFunc2(int a, int b, int c) : num3(a), num4(b), num5(c) {}

    friend float calculateAverage(FriendFunc1, FriendFunc2);
};

float calculateAverage(FriendFunc1 obj1, FriendFunc2 obj2) {
    int sum = obj1.num1 + obj1.num2 + obj2.num3 + obj2.num4 + obj2.num5;
    return static_cast<float>(sum) / 5;  // Average of 5 numbers
}

int main() {
    int a, b, c, d, e;
    cout << "Enter five numbers: ";
    cin >> a >> b >> c >> d >> e;

    FriendFunc1 obj1(a, b);         // First two numbers
    FriendFunc2 obj2(c, d, e);      // Last three numbers

    float average = calculateAverage(obj1, obj2);
    cout << "The average of the five numbers is: " << average << endl;

    return 0;
}
