#include<iostream>
using namespace std;
int main(){

int n;
cout<<"Enter the Number ";
cin>>n;
int A[n];

for(int i=0;i<n; i++){
    cin>>A[i];
}
for(int x:A){
    cout<<x<<" ";
}
return 0;
}
