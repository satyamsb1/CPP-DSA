#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int main()
{
    int a, b;
    a = 5;
    b = 15;
    swap(&a, &b);
    cout << "a=" << a << " "<< "b=" << b << endl;     
    return 0;
}