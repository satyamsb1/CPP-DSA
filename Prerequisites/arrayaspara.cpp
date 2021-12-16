#include <iostream>
using namespace std;

void fun(int A[], int n) //Here array is passed by address and number of elements by value
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    //cout<<sizeof(A)/sizeof(int)<<endl; //A here is pointer
}

int main()
{

    int A[5] = {1, 2, 3, 4, 5};
    int n = 5;
    fun(A, n);

    //cout<<sizeof(A)/sizeof(int)<<endl; // Now A here is not pointer it is an array i.e 20/4=5

    for (int x : A)
        cout << x << " ";
    //Address of an array is always passed like this no ampersand is used

    return 0;
}
