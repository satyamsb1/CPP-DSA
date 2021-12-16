#include<iostream>
using namespace std;
int main(){

char A[]="Painter";
char B[]="Painting";
int i,j;

for(i=0, j=0; (A[i]!='\0' && B[j]!='\0'); i++, j++)
{
    if(A[i]!=B[j])
    {
        break;
    }
}
if(A[i]==B[j])
{
    cout<<"Equal";
}
if(A[i]>A[j]){
    cout<<"Greater ";
}
else 
{
    cout<<"Smaller";
}

return 0;
}
