#include <iostream>
using namespace std;
/*Here the swap function wont work because call
 by reference dont modify the actual parameter 
 
 But it can be used for addition or to print the result */

int add(int x, int y){
    int c;
    c= x+y;
    return c;
}
void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()  
{
    int a, b;
    a = 10;
    b = 15;
    swap(a, b);   
    cout << "a=" << a << " "<< "b=" << b <<" unswaped "<< endl;
    cout<<add(a,b)<<" here addition works "<<endl;

    return 0;
}
