#include<iostream>
using namespace std;
int main(){
int i=0, count=0;
int A[]={39,19,14,19,5,5,4,1};
cout<<A[0]<<" ";
for(i=0; i<7; i++)
{   
    
    if(A[i]>=A[i+1]){
        cout<<A[i+1]<<" ";
       // count++;
    }    
}
    cout<<"\n"<<i<<"\n";
return 0;
}
