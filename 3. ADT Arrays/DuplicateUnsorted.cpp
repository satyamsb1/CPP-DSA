#include<iostream>
using namespace std;
int main(){

int A[]={8,3,6,4,6,5,6,8,2,7};
int n=10;

for(int i=0; i<n; i++)
{
    int count = 1;
    if(A[i]!=-1)
    {
        for(int j=i+1; i<n;j++)
        {
            if(A[i]==A[j])
            {
                count++;
                A[j]=-1;
            }
        }
    }
    if(count>1)
    {
        cout<<A[i]<<" Repeated for "<<count<<" times"<<endl;
    }
}
return 0;
}
