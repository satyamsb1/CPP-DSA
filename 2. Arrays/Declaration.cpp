#include<iostream>
using namespace std;

int main(){
    // int A[5]; //storage for the array will be allocated 5*sizeof(int)
    // int C[5]={1,2,3,4,5};
    // int D[]={1,2,3,4,5,6}; 
    // int E[10]={1,2,3}; //rest of elements will be zero
    // int B[5]={0}; //all the elements will be assigned zero

    int A[5];
    for(int i; i<5; i++){
    cout<<&A[i]<<endl;
    }
return 0;
}
