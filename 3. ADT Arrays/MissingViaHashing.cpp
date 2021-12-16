#include<iostream>
using namespace std;
int main(){
int A[10]={3,7,4,12,1,11,10};
int H[12]={0};
int n=10;

for(int i=0; i<10; i++)
{
    
    H[A[i]]++;
}
for(int i=1; i<12; i++){
    
    if (H[i]==0)
    {
        cout<<i<<" ";
    }
    
}
cout<<"These are the elements missing in Array A"<<endl;

return 0;
}
