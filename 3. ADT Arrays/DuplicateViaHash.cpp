#include<iostream>
using namespace std;
int main(){

int A[]={3,6,8,8,10,12,15,15,15,20}; 
int i,n=10;
int H[21]={};

for(i=0; i<10; i++) //Sorted Array      
{
    H[A[i]]++;
}
for(i=0; i<20; i++)
{
    if(H[i]>1)
    {
        cout<<i<<" is repeated for "<<H[i]<<" number of times"<<endl;
    }
}
return 0;
}
