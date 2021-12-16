#include<iostream>
using namespace std;

double e(int x, int n){  // Horners rule
    static double s=1;
    if(n==0){
        return s;
    }
    else 
        s=1+x*s/n;
    return e(x,n-1);
}
double e2(int x, int n){
    double s=1;

    for(; n>0; n--){
        s=1+x*s/n;
    }
    return s;
}

int main(){
    cout<<e2(1,20)<<" ";
return 0;
}
