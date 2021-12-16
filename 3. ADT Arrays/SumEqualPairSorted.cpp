#include<iostream>
using namespace std;
int main(){

int A[]={1,3,4,5,6,8,9,10,12,14};
int n=10;
int i=0,j=n-1;
int k=10;
while(j>i)
{
    if(A[i]+A[j]==k)
    {
        cout<<A[i]<<" "<<A[j]<<" "<<k<<endl;
        i++;
        j++;
    }
    else if(A[i]+A[j]<k)
    {
        i++;
    }
    else
    {
        j--;
    }
}

return 0;
}
