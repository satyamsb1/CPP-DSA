#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
} *first = NULL,*second=NULL,*third=NULL;

void Create(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node;
    first->Data = A[0];
    first->Next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->Data = A[i];
        t->Next = NULL;
        last->Next = t;
        last = t;
    }
}
void Create2(int A[], int n)
{
    int i;
    Node *t, *last;
    second = new Node;
    second->Data = A[0];
    second->Next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->Data = A[i];
        t->Next = NULL;
        last->Next = t;
        last = t;
    }
}
void Display(Node *p)
{

    while (p != NULL)
    {
        cout << p->Data << " ->";
        p = p->Next;
    }
    cout << endl;
}
void RDisplay(Node *p) // Recursive function
{
    if (p != NULL)
    {
        cout << p->Data << "->";
        RDisplay(p->Next);
    }
}
int Count(Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->Next;
    }
    return count;
}
int RCount(Node *p)
{
    if (p)
    {
        return RCount(p->Next) + 1;
    }
    else
        return 0;
}
int Sum(Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->Data;
        p = p->Next;
    }
    return sum;
}
int RSum(Node *p)
{
    if (p)
    {
        return RSum(p->Next) + p->Data;
    }
    else
        return 0;
}
int Max(Node *p)
{
    int Max = INT16_MIN; // max=-32768
    while (p)
    {
        if (p->Data > Max)
        {
            Max = p->Data;
        }
        p = p->Next;
    }
    return Max;
}
int RMax(Node *p)
{
    int x = 0;
    if (p == 0)
        return INT16_MIN;
    x = RMax(p->Next);

    return x > p->Data ? x : p->Data; // turnary operator
}
int Min(Node *p)
{
    int Min = INT16_MAX; // Min=32767
    while (p)
    {
        if (Min > p->Data)
        {
            Min = p->Data;
        }
        p = p->Next;
    }
    return Min;
}
Node *Search(Node *p, int key)
{
    Node *q = NULL; // This is move to head method
    while (p != NULL)
    {
        if (key == p->Data)
        {
            if (p == first)
            {
                return first;
            }
            q->Next = p->Next;
            p->Next = first;
            first = p;
            return (p);
        }
        q = p;
        p = p->Next;
    }
    return 0;
}
Node *RSearch(Node *p, int key)
{
    if (p == NULL)
    {
        return 0;
    }
    // if(key==p->Data)
    // {
    //     return p;
    // }
    // else
    // {
    //     RSearch(p->Next, key);  this method will always give warning
    // }
    return key == p->Data ? p : RSearch(p->Next, key); // turnary operator
}
void Insert(int index, int x)
{
    Node *p, *t;
    if (index < 0 || index > Count(p))
        return;
    if (index == 0)
    {
        t->Data = x;
        t->Next = first;
        first = t;
    }
    else if (index > 0)
    {
        p = first;
        for (int i = 0; i < index - 1 && p; i++)
            p = p->Next;

        if (p)
        {
            t = new Node;
            t->Data = x;
            t->Next = p->Next;
            p->Next = t;
        }
    }
}
void SortedInsert(Node *p, int x) // For sorted linked list at sorted position
{
    Node *t, *q = NULL;
    t = new Node;
    t->Data = x;
    t->Next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->Data < x)
        {
            q = p;
            p = p->Next;
        }
        if (p == first)
        {
            t->Next = first;
            first = t;
        }
        else // here x is greater than p->Data
        {
            t->Next = q->Next;
            q->Next = t;
        }
    }
}
int Delete(Node *p, int index)
{
    Node *q = new Node;
    int x = -1, i;
    if (index <= 0 || index > Count(p))
    {
        return -1;
    }
    if (index == 1)
    {
        p = first;
        first = first->Next;
        x = p->Data;
        delete p;
        return x;
    }
    else
    {
        p = first;
        q = NULL;
        for (i = 0; i < index - 1 && p; i++)
        {
            q = p;
            p = p->Next;
        }
        if (p)
        {
            q->Next = p->Next;
            x = p->Data;
            delete p;
        }
        return x;
    }
}
bool Sorted(Node *p)
{
    int x = INT16_MIN;
    while (p)
    {
        if (p->Data > x)
        {
            x = p->Data;
            p = p->Next;
        }
        else
        {
            return false;
        }
    }
    return true;
}
void RemoveDuplicate(Node *p)
{
    p=first;
    Node * q=first->Next;

    while(q)
    {
        if(p->Data!=q->Data)
        {
            p=q;
            q=q->Next;
        } 
        else
        {
            p->Next=q->Next;
            delete q;
            q=p->Next;
        }
    }
}
void Reverse(Node *p) //Reversing elements using array(a bit sloppy)
{
    int *A;
    A= new int  [Count(p)];
    int i=0;
    while(p)
    {
        A[i]=p->Data;
        p=p->Next;
        i++;
    }
    p=first;
    i--;
    while(p)
    {
        p->Data=A[i];
        p=p->Next;
        i--;
    }
}
void Reverse1(Node *p) //Sliding process (preferable)
{
    
    Node *q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->Next;
        q->Next=r;
    }
    first=q;
}
void Reverse2(Node *q, Node *p)
{
    if(p)
    {
        Reverse2(p,p->Next);
        p->Next=q;
    }
    else
        first=q;
}
void Concatenate(Node *p, Node *q)
{
    third=p;
    while(p->Next)
    {
        p=p->Next;
    }
    p->Next=q;
    q=NULL;
}
void Merge(Node *p, Node *q)
{
    Node *last;
    if(p->Data < q->Data)
    {
        third=last=p;
        p=p->Next;
        third->Next=NULL;
    }
    else
    {
        third=last=q;
        q=q->Next;
        third->Next=NULL;
    }
    while(p && q)
    {
        if(p->Data < q->Data)
        {
            last->Next=p;
            last=p;
            p=p->Next;
            last->Next=NULL;
        }
        else
        {
            last->Next=q;
            last=q;
            q=q->Next;
            last->Next=NULL;
        }
    }
        if(p)
        {
            last->Next=p;
        }
        else
        {
            last->Next=q;
        }
}
int IsLoop(Node *f)
{
    Node *p, *q;
    p=q=f;
    do
    {
        p=p->Next;
        q=q->Next;
        
        q=q!=NULL? q->Next : NULL;
    }while(p && q && p!=q);

    return p==q?true:false;
}
int main()
{
    int A[] = {1, 2, 6, 8, 15};
    Create(A, 5);

    // Node *t1, *t2;
    // t1=first->Next->Next;       //Uncomment for making the linked list loop
    // t2=first->Next->Next->Next->Next;
    // t2->Next=t1;

    if(IsLoop(first))
    {
        cout<<"It is loop"<<endl;
    }
    else{
        cout<<"Not Looop"<<endl;
    }
    

    return 0;
}
