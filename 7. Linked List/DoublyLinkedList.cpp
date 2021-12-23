#include <iostream>
using namespace std;
 
class Node{
public:
    Node* prev;
    int data;
    Node* next;
};
 
class DoublyLinkedList{
private:
    Node* head;
public:
    DoublyLinkedList();
    DoublyLinkedList(int A[], int n);
    ~DoublyLinkedList();
    void Display();
    int Length();
    void Insert(int index, int x);
    void Delete(int index);
    void Reverse();

};
DoublyLinkedList::DoublyLinkedList() {
    head = new Node;
    head->prev = nullptr;
    head->data = 0;
    head->next = nullptr;
}
DoublyLinkedList::DoublyLinkedList(int *A, int n) {
 
    head = new Node;
    head->prev = nullptr;
    head->data = A[0];
    head->next = nullptr;
    Node* tail = head;
 
    for (int i=1; i<n; i++){
        Node* t = new Node;
        t->prev = tail;
        t->data = A[i];
        t->next = tail->next; // tail->next is pointing to NULL
        tail->next = t;
        tail = t;
    }
}
 
void DoublyLinkedList::Display() {
    Node* p = head;
    while (p != nullptr){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " ->" << flush;
        }
    }
    cout << endl;
}
DoublyLinkedList::~DoublyLinkedList() {
    Node* p = head;
    while (head){
        head = head->next;
        delete p;
        p = head;
    }
}
int DoublyLinkedList::Length()
{
    Node *p=new Node;
    p=head;
    int length=0;
    while(p!=nullptr)
    {
        p=p->next;
        length++;
    }
    return length;
}
void DoublyLinkedList::Insert(int index, int x)
{
    if(index < 0 || index > Length())
    {
        return; 
    }
    Node *p=head;
    Node *t=new Node;
    t->data=x;
    if(index==0)
    {
        t->next=head;
        t->prev=nullptr;
        head=t;
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }

}
void DoublyLinkedList::Delete(int index)
{
    Node *p=head;
    int x=-1, i;
    if(index < 0 || index > Length())
    {
        return; 
    }
    if(index==0)
    {
        head=head->next;
        x=p->data;
        delete p;
        if(head)
        {
            head->prev=NULL;
        }
    }
    else
    {
        for(i=0; i<index-1; i++)
            {
                p=p->next;
            }
            p->prev->next=p->next;
        if(p->next)
            {
                p->next->prev=p->prev;
            }
            x=p->data;
            delete p;
    }    
}
void DoublyLinkedList::Reverse()
{
    Node *p=new Node;
    p=head;
    Node *t;
    while(p)
    {
        t=p->next;
        p->next=p->prev;
        p->prev=t;
        p=p->prev;
    
    if(p!=NULL && p->next==NULL)
        {
            head=p;
        }
    }
}
int main() {
 
    int A[] {1, 3, 5, 7, 9};
 
    DoublyLinkedList dll(A, sizeof(A)/sizeof(A[0]));
    dll.Display();
    
    dll.Reverse();
    dll.Display();

    return 0;
}