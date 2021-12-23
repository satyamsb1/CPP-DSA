#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
}* head;
class CircularLinkedList
{
    private:
        Node *head;

public:
    CircularLinkedList(int A[], int n);

    void Display(Node *p);
    void RecursiveDisplay(Node *p);
    void Insert(Node *p, int x, int index);
    int Length(Node *p);
    int Delete(Node *p, int index);
};
CircularLinkedList::CircularLinkedList(int *A, int n)
{
    Node *t;
    Node *tail;

    head = new Node;

    head->Data = A[0];
    head->Next = head;
    tail = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->Data = A[i];
        t->Next = tail->Next;
        tail->Next = t;
        tail = t;
    }
}
void CircularLinkedList ::Display(Node *p)
{
    p = head;
    do
    {
        cout << p->Data << " ->" << flush;
        p = p->Next;
    } while (p != head);
    cout << endl;
}
void CircularLinkedList::RecursiveDisplay(Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->Data << " ->";
        RecursiveDisplay(p->Next);
    }
    flag = 0;
}
void CircularLinkedList ::Insert(Node *p, int x, int index)
{
    Node *t=new Node;
    p=head;        //it is already equal but for understanding purpose

    if(index < 0 || index > Length(p)) return;

    if(index==0)
    {
        t->Data=x;
        if(head==NULL)
        {
            head=t;
            head->Next=head;
        }
        else
        {
            while(p->Next!=head)
            {
                p=p->Next;
            }
            p->Next=t;
            t->Next=head;
            head=t;
        }
    }
    else
    {
        for(int i=1; i<index-1; i++)
        {
            p=p->Next;
        }
        t->Data=x;
        t->Next=p->Next;
        p->Next=t;
    }
}
int CircularLinkedList::Length(Node *p)
{
    int length=0;
    
    do{
        p=p->Next;
        length++;
    }while(p!=head);
    
    return length;
}
int CircularLinkedList ::Delete(Node *p, int index)
{
    Node *q;
    p=head;
    int x;
    if(index < 0 || index > Length(p))
        return -1;
    if(index==1)
    {   
        while(p->Next!=head)p=p->Next;
        x=head->Data;
        if(head==p)
        {
            delete head;
            head=NULL;
        } 
        else
        {
            p->Next=head->Next;
            delete head;
            head=p->Next;
        }
    }
    else
    {
        p=head;
        for(int i=0; i<index-2; i++)
        {
            p=p->Next;
        }
        q = new Node;
        q=p->Next;
        p->Next=q->Next;
        x = q->Data;
        delete q;
       
    }
    return x;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    CircularLinkedList cl(A, sizeof(A) / sizeof(A[0]));
    cout<<cl.Delete(head,1)<<"\n";
    cl.Display(head);
    return 0;
}
