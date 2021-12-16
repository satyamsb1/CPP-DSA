#include<iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};
struct rectangle *fun(){
    rectangle *p;
    p= new rectangle;

    p->length=15;
    p->breadth=10;

    return p;
}
int main(){
    struct rectangle *ptr=fun();
    cout<<"length "<<ptr->length<<endl<<"breadth "<<ptr->breadth<<endl;

return 0;
}
