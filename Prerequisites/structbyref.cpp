#include<iostream>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

void changeLength(struct Rectangle *p, int l)
{
    p->length=l;
}

int main(){

struct Rectangle r={5,15};
changeLength(&r,15);

cout<<r.length<<endl;


return 0;
}
