#include <iostream>

template <typename T>
class Pair {
private:
    T first, second, third;

public:
    // Constructor
    Pair(T a, T b, T c) : first(a), second(b), third(c) {}

    // Member function to find the minimum of three values
    T get_min() {
        T min_val = first;
        if (second < min_val) min_val = second;
        if (third < min_val) min_val = third;
        return min_val;
    }
};

int main() {
    // Create an object of Pair with int type
    Pair<int> intPair(3, 1, 2);
    std::cout << "The smallest integer is: " << intPair.get_min() << std::endl;

    // Create an object of Pair with double type
    Pair<double> doublePair(3.5, 1.2, 2.8);
    std::cout << "The smallest double is: " << doublePair.get_min() << std::endl;

    // Create an object of Pair with float type
    Pair<float> floatPair(3.3f, 1.4f, 2.2f);
    std::cout << "The smallest float is: " << floatPair.get_min() << std::endl;

    return 0;
}
