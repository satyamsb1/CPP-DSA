#include <iostream>
using namespace std;

int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int main()
{
    int y = 10;
    int z = 20;
    int x = add(y, z);
    cout << x << endl;
    return 0;
}
