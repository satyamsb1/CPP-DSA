#include<iostream>
using namespace std;
int main(){

int A[]={1,2,3,4,5,6,7,8,9,10};
int B[10];
int i, j;
for(i=9,j=0;i>=0;i--,j++){
    
    B[j]=A[i];
}

for(i=0; i<10;i++){
   A[i]=B[i];
   cout<<A[i]<<" ";
}


return 0;
}
