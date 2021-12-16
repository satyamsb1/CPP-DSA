#include<iostream> // Call by value

using namespace std;

struct rectangle{
    int length;
    int breadth;
};

int area(struct rectangle r1){
    
    return r1.length*r1.breadth;
}


int main(){     //Call by reference

struct rectangle r={10,5};

area(r);

cout<<area(r)<<endl;

int area(struct rectangle &r1){
    
    return r1.length*r1.breadth;
}

int main(){

struct rectangle r={10,5};

area(r);

cout<<area(r)<<endl;


return 0;
}
