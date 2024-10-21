#include <iostream>
#include <cstring>

class String {
private:
    char* str;
public:
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // String Copy
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Equality
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Concatenation
    String operator+(const String& other) const {
        char* temp = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        String result(temp);
        delete[] temp;
        return result;
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Getter
    const char* getStr() const {
        return str;
    }
};

int main() {
    String s1 = "Hello";
    String s2 = "Hello";

    // String Copy
    String s3 = s1;

    // Equality
    if (s1 == s2) {
        std::cout << "s1 and s2 are equal" << std::endl;
    } else {
        std::cout << "s1 and s2 are not equal" << std::endl;
    }

    // Concatenation
    String s4 = s1 + s2;

    std::cout << "s1: " << s1.getStr() << std::endl;
    std::cout << "s2: " << s2.getStr() << std::endl;
    std::cout << "s3: " << s3.getStr() << std::endl;
    std::cout << "s4: " << s4.getStr() << std::endl;

    return 0;
}