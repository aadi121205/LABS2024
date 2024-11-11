// WAP to perform string operations using operator overloading in C++i, = String Copy l. =, Equality ii. Concatenation

#include <iostream>

using namespace std;

class String {
    char *str;
    int len;

public:
    String() {
        str = new char[1];
        str[0] = '\0';
        len = 0;
    }

    String(const char *s) {
        len = 0;
        while (s[len] != '\0') {
            len++;
        }
        str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            str[i] = s[i];
        }
        str[len] = '\0';
    }

    String(const String &s) {
        len = s.len;
        str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            str[i] = s.str[i];
        }
        str[len] = '\0';
    }

    ~String() {
        delete[] str;
    }

    void display() {
        cout << str << endl;
    }

    String operator=(const String &s) {
        len = s.len;
        delete[] str;
        str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            str[i] = s.str[i];
        }
        str[len] = '\0';
        return *this;
    }

    String operator+(const String &s) {
        String temp;
        temp.len = len + s.len;
        delete[] temp.str;
        temp.str = new char[temp.len + 1];
        for (int i = 0; i < len; i++) {
            temp.str[i] = str[i];
        }
        for (int i = 0; i < s.len; i++) {
            temp.str[len + i] = s.str[i];
        }
        temp.str[temp.len] = '\0';
        return temp;
    }

    bool operator==(const String &s) {
        if (len != s.len) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            if (str[i] != s.str[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    String s1("Hello"), s2("World"), s3;

    s3 = s1 + s2;
    s3.display();

    cout << (s1 == s2) << endl;
    cout << (s1 == s1) << endl;

    return 0;
}

// By Aaditya Bhatia
