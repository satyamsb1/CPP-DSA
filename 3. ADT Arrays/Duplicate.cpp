#include<iostream>
using namespace std;
int main(){
int A[]={3,6,8,8,10,12,15,15,15,20};
int lastdup=0;

for(int i=0;i<10;i++)
{
    if(A[i]==A[i+1] && A[i]!=lastdup)
    {
            cout<<A[i]<<" ";
            lastdup=A[i];
    }
}cout<<"These are the duplicates ";

return 0;

}
