// use of taaamplates of class and function

#include <iostream>

using namespace std;

template <class T>

class myclass
{
    T a, b;

public:
    myclass(T x, T y)
    {
        a = x;
        b = y;
    }
    T add()
    {
        return a + b;
    }
};

template <class T>
T add(T x, T y)
{
    return x + y;
}

template <class T1, class T2>
auto add(T1 x, T2 y) -> decltype(x + y)
{
    return x + y;
}

int main()
{
    myclass<int> obj(4, 5);
    cout << obj.add() << endl;
    cout << add(4, 5) << endl;
    cout << add(4.5, 5.5) << endl;
    cout << add(4.5f, 5.5f) << endl;
    cout << add(4.5, 5) << endl;
    cout << add(4, 5.5) << endl;

    return 0;
}

// output:
// 9