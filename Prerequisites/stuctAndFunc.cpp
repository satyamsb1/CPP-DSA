#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};
void initialize(Rectangle *r, int l, int b){
    r->length=l;
    r->breadth=b;
}
int area(Rectangle r){
    return r.length*r.breadth;
}
void changelength(Rectangle *r,int l){
    r->length=l;
}
int main(){
 
Rectangle r;

initialize(&r, 10, 15);
cout<<area(r);
changelength(&r, 20);

return 0;
}
