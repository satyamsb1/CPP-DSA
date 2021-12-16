#include <iostream>
using namespace std;

void swap(int &num1, int *num2) //you can call one parameter by reference and one by address
{
    int temp;
    temp = num1;
    num1 = *num2;
    *num2 = temp;
}

int main()
{
    int a = 5, b = 10;
    cout<<"Before swap a = "<<a<<" b = "<<b<<endl;
    swap(a, &b);
    cout << "After swap a = " << a << " " << "b = " << b << endl;
    return 0;
}