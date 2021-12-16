#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main(){
    // struct Rectangle r={10, 15};
    // struct Rectangle *p=&r;

    // r.length++;
    // cout<<r.length<<endl;

    // (*p).length++;
    // cout<<r.length<<endl;

    // p->length++;  // This is ideal method to access the variable using pointer
    // cout<<r.length<<endl;

    struct Rectangle *p;
    p= new Rectangle;
    p->length=15;
    cout<<p->length<<endl;

return 0;
}
