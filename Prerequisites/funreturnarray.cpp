#include <iostream>
using namespace std;

int *fun(int size)
{
    int *p;
    p = new int(size);
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
    }
    return p; // This is address of an array
}

int main()
{

    int sz = 5, *ptr;

    ptr = fun(sz);    //ptr=p and hence p is dereferenced as p is address and ptr is pointer

    for (int i = 0; i < 5; i++)
    {
        cout << ptr[i] << " ";
    }

    return 0;
}
