#include <iostream>
using namespace std;

int fib1(int n)
{
    int t0 = 0, t1 = 1, i, s;
    if (n <= 1)
    {
        return n;
    }
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int rfib(int n) // Recursive
{
    if (n <= 1)
        return n;
    else
        return rfib(n - 1) + rfib(n - 2);
}

int F[10];       // Memoization

int mfib(int n)
{
    if (n <= 1)
        return n;

    if (F[n - 2] == -1)
        F[n - 2] = mfib(n - 2);

    if (F[n - 1] == -1)
        F[n - 1] = mfib(n - 1);
        F[n]=F[n-2]+F[n-1];
    return mfib(n - 1) + mfib(n - 2);
}

int main()
{

    int i = 0;
    for (i = 0; i < 10; i++)
        F[i] = -1;

    cout << mfib(5) << " ";
    return 0;
}
