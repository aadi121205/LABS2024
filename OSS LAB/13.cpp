// Write a program to aceept the student detail such as name and 3 different marks get_data0 method and display the name and average of marks using displayO method. Define a friend class for calculating the average of marks using the method mark_ avg()

#include <iostream>
using namespace std;

class Student; // Forward declaration

class Student {
private:
    string name;
    int marks[3];

public:
    // Method to get student details
    void get_data() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter marks in 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    // Method to calculate average marks

    float mark_avg() {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += marks[i];
        }
        return static_cast<float>(sum) / 3;
    }

    // Method to display student details
    void display() {
        cout << "Name: " << name << endl;
        cout << "Average marks: " << mark_avg() << endl;
    }

    // Friend class declaration
    friend class FriendClass;
};

class FriendClass {
public:
    // Friend function to calculate average marks
    static float mark_avg(Student s) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += s.marks[i];
        }
        return static_cast<float>(sum) / 3;
    }
};

int main() {
    Student s;
    s.get_data();
    s.display();
    return 0;
}
