#include <iostream>
#include<string>
using namespace std;

int main()
{
    string a = "madam";
    int length = a.length();
    int i, j;
    int flag = 0;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        if (a[i] != a[j])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "not palindrom";
    }
    else
    {
        cout << "palindrom";
    }
    return 0;
}