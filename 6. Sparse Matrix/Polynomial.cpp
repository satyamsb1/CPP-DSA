#include <iostream>

using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Polynomial
{
private:
    int n;
    Term *t;

public:
    Polynomial(int n)
    {
        this->n = n;
        t = new Term[this->n];
    }

    friend istream &operator>>(istream &is, Polynomial &p)
    {
        cout << "Enter terms: \n";
        for (int i = 0; i < p.n; ++i)
        {
            cin >> p.t[i].coeff;
            cin >> p.t[i].exp;
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, Polynomial &p)
    {
        for (int i = 0; i < p.n; ++i)
        {
            cout << p.t[i].coeff << "x^" << p.t[i].exp;
            if (i + 1 != p.n)
                cout << " + ";
        }
        cout << endl;
        return os;
    }

    Polynomial operator+(Polynomial p)
    {
        int i, j, k;
        i = j = k = 0;
        Polynomial *sum = new Polynomial(n + p.n);
        while (i < n && j < p.n)
        {
            if (t[i].exp == p.t[j].exp)
            {
                sum->t[k].coeff = t[i].coeff + p.t[j].coeff;
                sum->t[k++].exp = t[i++].exp + p.t[j++].exp;
            }
            else if (t[i].exp > p.t[j].exp)
                sum->t[k++] = t[i++];
            else
                sum->t[k++] = p.t[j++];
        }
        for (; i < n; ++i)
            sum->t[k++] = t[i++];
        for (; j < n; ++j)
            sum->t[k++] = p.t[j++];
        sum->n = k;
        return *sum;
    }
};

int main()
{
    Polynomial p1(3);
    cin >> p1;
    cout << p1;

    Polynomial p2(3);
    cin >> p2;
    cout << p2;

    Polynomial p3 = p1 + p2;

    cout << p3;

    return 0;
}