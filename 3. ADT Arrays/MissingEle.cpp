#include <iostream>
using namespace std;
int main()
{

    //int A[]={6,7,8,9,10,11,13,14,15,16,17};
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11};

    int l = 6, h = 19, n = 11, diff = l - 0;

    /*for(int i=0; i<n; i++)
{
    if(A[i]-i!=diff)
    {
        cout<<"Missing element is "<<diff+i<<endl;
        break;
    }
}                                                */
    // for(int i=0; i<11; i++)
    // {
    //     if(A[i]-i!=diff){
    //         while(diff<A[i]-i)
    //         {
    //             cout<<"Missing Elements are "<<i+diff<<endl;
    //             diff++;
    //         }
    //     }
    // }
    int s=A[0], key = 0;
    int sum=0;
    for (int i = 1; i < n; i++)
    {
        s = s + A[i];
    }
    sum = (n * (n + 1)) / 2;

    key = sum - s;

    cout << key << " is the missing element" << endl;
    return 0;
}
