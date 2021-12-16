#include<iostream>
using namespace std;

int main(){

    int *p, *q;
    int i;

    p= new int[5];
    p[0]=1; p[1]=2; p[2]; p[3]=9; p[4]=10;

    q= new int[10];

    for(i=0;i<5;i++)
    
        q[i]=p[i]; 

    delete []p;
    p=q;
    q=NULL; 
    p[5]=12;
    p[6]=43;

    for(i=0;i<7;i++)
        cout<<p[i]<<" "<<endl;

   

return 0;
}
