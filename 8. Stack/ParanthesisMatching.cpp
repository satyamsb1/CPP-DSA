#include<iostream>
#include<string>
using namespace std;
class Stack
{
    private:
        int size;
        int top;
        int *S;
    public:
        bool isBalance(char *exp);
        Stack(char *exp);
};
Stack(char *exp)
{
    this->size=strlen(exp);
}
bool Stack::isBalance(char *exp)
{

}
int main(){
return 0;
}
