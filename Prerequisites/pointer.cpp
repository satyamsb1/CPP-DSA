#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main()
{

    // int a=10;
    // int *p;
    // p= &a;

    // cout<<a<<endl;
    // //cout<<p<<" "<<&a<<endl;  // This will print same address
    // cout<<"Using pointer "<<*p<<endl; //Derefercing

    // int A[5]={1,2,4,5,6};
    // int *p;
    // p=A;

    // cout<<*p<<" "<<A<<endl;

    // for(int i=0; i<5; i++){
    //     cout<<A[i]<<endl;
    // }

    // for(int i=0; i<5; i++){
    //     cout<<p[i]<<endl; // Using Name if the array
    // }

    // int *p; // Arrays in heap
    // p = new int[5];
    // p[0] = 1;
    // p[1] = 3;
    // p[2] = 6;
    // p[3] = 9;
    // p[4] = 12;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << &p[i] << endl;
    // }
    // delete[] p; //When we use heap memory it is necessory to delete it later
    
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;
    
    return 0;
}
