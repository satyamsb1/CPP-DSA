#include <iostream> //Iterating through string
using namespace std;

int main()
{

    string A = "Finding";
    int i, j;
    int n= A.length();
    for (i = 0; i < n; i++)
    {
        int count = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
        }
        if (count > 1)
        {
            cout << A[i] << " Repeated for " << count << " times" << endl;
        }
    }

    return 0;
}
