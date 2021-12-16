#include <iostream>
using namespace std;

class LowerTri
{
    int *A;
    int n;

public:
    LowerTri()
    {
        n=2;
        A=new int [2*(2+1)/2];
    }
    LowerTri(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~LowerTri()
    {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension(){return n;}
};
void LowerTri ::Set(int i, int j, int x)
{
    if (i <= j)
    {
        A[j*(j-1)/2+i-1] = x;
        //A[n*(i-1)-(i-2)*(i-1)/2+j-i]=x;
    }
}
int LowerTri ::Get(int i, int j)
{
    if (i <= j)
       return A[j*(j-1)/2+i-1];
       // return A[n*(i-1)-(i-2)*(i-1)/2+j-i];
    else
        return (0);
}
void LowerTri ::Display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                cout<<A[j*(j-1)/2+i-1]<<" ";  //column major formula
                //cout << A[n*(i-1)-(i-2)*(i-1)/2+j-i] << " "; //Row major formula
            }
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}
int main()
{
    int d;
    cout<<"Enter the size of the matrix ";
    cin>>d;
    
    LowerTri lm(d);

    int x;
    cout<<"Enter all elements\n";
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin>>x;
            lm.Set(i,j,x);
        }
    }

    lm.Display();
    return 0;
}
