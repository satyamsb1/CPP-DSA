#include<iostream>
using namespace std;

struct Element
{
    int i;
    int j; 
    int x;
};
struct Sparse
{
    int m;
    int n; 
    int num;
    struct Element *ele;
};
void Create(struct Sparse *s)
{
    cout<<"Enter Dimensions";
    cin>>&s->m>>&s->n; 
    cout<<"Number of non zero elements";
    cin>>&s->num;

    s->ele=new int [s->num*(struct Element)];
    cout<<"Enter all non zero element";
    for(int i=0; i<s->num; i++)
    {
        cin>>&s->ele[i].i,&s->ele[i].j,&s->ele[i].x;
    }
}
void Display(struct Sparse s)
{
    int i,j,k=0;
    for(i=0;i<s->m;i++)
    {
        for(j=0; j<s->n;j++ )
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
                cout<<s.ele[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}
int main(){

    struct Sparse s;

    Create(&s);
    Display(s);

return 0;
}
