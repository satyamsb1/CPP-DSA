#include <iostream>
using namespace std;
int main()
{

    char A[] = "Python";

    int i, j;
    char t;
    for (j = 0; A[j] != '\0'; j++)  // just for getting length
    {
    }
    j = j - 1;
    for (i = 0; j > i; i++, j--) //continue until i is less than j
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    cout << A;

    return 0;
}
