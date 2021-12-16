#include<iostream>
using namespace std;

struct rectangle {
    int length;
    int breadth;
};

int main(){
    
    struct rectangle r={10,15};
    r.length=15; //dot operator is used for accesing the member of the struct
    cout<<"Area of rectangle is "<<r.length*r.breadth<<" sq units"<<endl;

return 0;
}
