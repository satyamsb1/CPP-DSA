#include<iostream>
using namespace std;

class Rectangle{
    int length;
    int breadth;

public:
Rectangle(int l, int b)
{
    length=l;
    breadth=b;
}
int area(){
    return length*breadth;
}

int perimeter(){
    return 2*(length+breadth);
}
};

int main(){
    
    Rectangle r(10,15);
    int a=r.area();
    int b=r.perimeter();

    cout<<"Area "<<a<<" perimeter "<<b<<endl;
return 0;
}
