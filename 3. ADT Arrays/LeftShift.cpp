#include<iostream>
using namespace std;
int main(){

int A[]={1, 2, 4, 5, 6, 8, 12, 13, 16, 6};

for(int i=1;i<10;i++)
{   
    int temp=A[i];
    A[i]=A[i-1];
    A[i-1]=temp;
}
for(int i=0;i<10;i++){
    cout<<A[i]<<" ";
}
return 0;
}
