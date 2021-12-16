#include<iostream>
using namespace std;
int main(){

char S[]="welcome";
int i;

for(i=0; S[i]!=0; i++)
{
    S[i]=S[i]-32; 
}
cout<<S;

return 0;
}
