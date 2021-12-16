#include<iostream>
using namespace std;

int sum(int n){
    if(n==0){
        return 0;
    }
    else 
    return sum (n-1)+n;
}
// int Isum(int n){
//     int s=0;
//     int i=0;
//     for(i=1;i<=n;i++)
//     s=s+i;

//     return s;
// }
// int s(int n){
//     return n*(n+1)/2;
// }

int main(){

int x=10;
cout<<sum(x)<<" ";

return 0;
}
