#include <iostream>
using namespace std;

template <class T>

class arithmatic
{
private:
    T a;
    T b;

public:
    arithmatic(T a, T b);
    T add();
    T sub();
};
template <class T>

arithmatic<T>::arithmatic(T a, T b) 
{
    this->a = a;  //if name of data member and parameter is same use this keyword
    this->b = b;
}
template <class T>

T arithmatic<T>::add()
{
    T c;
    return c = a + b;
}
template <class T>
T arithmatic<T>::sub()
{
    T c;
    return c = a - b;
}

int main()
{
    arithmatic<int> ar(10, 5);
    arithmatic<float> ar1(10.05, 5.33);
    cout<<"Sub " << ar.add() << endl;
    cout<<"Add " << ar1.add() << endl;
    return 0;
}
