#include <iostream>
using namespace std;
int main()
{

    char A[] = "verbose";
    char B[] = "observe";

    int i, H[25] = {0};

    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97] += 1;
    }
    for (i = 0; B[i] != '\0'; i++)
    {
        H[A[i] - 97] -= 1;
        if (H[B[i] - 97] < 0)
        {
            cout << "Not an anagram ";
            break;
        }
    }
    if (B[i] == '\0')
    {
        cout << "Its an anagram";
    }

    return 0;
}
