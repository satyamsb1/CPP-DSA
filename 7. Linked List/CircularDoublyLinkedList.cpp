#include<iostream>
using namespace std;

class Node
{
    public:
        Node *prev;
        int data;
        Node *next;
};
class CDoublyLinkedList
{
    private:
        Node *head=NULL;
    public:
        CDoublyLinkedList();
        CDoublyLinkedList(int A[], int n);
       ~CDoublyLinkedList();

        void Insert(int index, int x);
        void Display();
        int Count();
        void Delete(int index);
};
CDoublyLinkedList::CDoublyLinkedList()
{
    head=new Node;
    head->prev=head;
    head->data=0;
    head->next=head;
}
CDoublyLinkedList::CDoublyLinkedList(int *A, int n)
{
    head=new Node;
    head->prev=head;
    head->data=A[0];
    head->next=head;
    Node *tail=head;

    for(int i=1; i<n; i++)
    {
        Node *t=new Node;
        t->prev=tail;
        t->data=A[i];
        t->next=tail->next;
        tail->next=t;
        tail=t;
    }
    head->prev=tail; 
}
CDoublyLinkedList::~CDoublyLinkedList()
{
    Node* p = head;
    while (p->next!=head){
        p=p->next;
    }
    while(p!=head){
        p->next=head->next;
        delete head;
        head=p->next;
    }
    if(p==head)
    {
        delete head;
        head=NULL;
    }
}

void CDoublyLinkedList::Display()
{
    Node *p=head;
    do
    {
        cout<<p->data<<" ->";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}
int CDoublyLinkedList::Count()
{
    int length=0;
    Node *p=head;
    do
    {
        length++;
        p=p->next;
    }while(p!=head);
    return length;
}
void CDoublyLinkedList::Insert(int index, int x)
{
    if(index < 0 || index > Count())
    return;
    Node *p=head;
    Node *t =new Node;
    t->data=x;

    if(index==1)
    {
        t->prev=head->prev;
        head->prev->next=t;
        t->next=head;
        head->prev=t;
        head=t;
    }
    else
    {
        int i;
        for(i=1; i<index-2;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next==head){
           p->next->prev=t;
        }
        p->next=t;
    }
}
void CDoublyLinkedList::Delete(int index)
{
    if(index > Count() || index < 0)
    return;
    Node *p=head;
    int x,i;
    if(index==0)
    {
        head->prev->next=head->next;
        head=head->next;
        x=p->data;
        delete p;
    }
    else
    {
        for(i=1; i<index; i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p;
        x=p->data;
        delete p;
    } 
    
} 
int main(){
    int A[]={1,2,3,4,5};
    CDoublyLinkedList c(A,sizeof(A)/sizeof(A[0]));
    c.Display();
    c.Delete(5);
    c.Display();
return 0;
}
