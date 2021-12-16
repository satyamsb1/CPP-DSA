#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
        
    }
    int area()
    {
        return length * breadth;
    }
    void changelength(int l)
    {
        length = l;
       
    }
};
int main()
{

    Rectangle r(10,15);

    r.area();
    r.changelength(20);

    return 0;
}
