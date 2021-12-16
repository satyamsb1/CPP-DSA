#include<iostream>
using namespace std;

class Node{
    public: 

    int Data;
    Node *Next;
}*first=NULL;
 
void Create(int A[], int n)
{
    int i;
    Node *t, *last;
    first=new Node;
    first->Data=A[0];
    first->Next=NULL;
    last=first;

    for(i=1; i<n; i++)
    {
        t=new Node;
        t->Data=A[i];
        t->Next=NULL;
        last->Next=t;
        last=t;
    }
}
void Display(Node *p)
{
    
    while(p!=NULL)
    {
        cout<<p->Data<<" ->";
        p=p->Next;
        
    }
    cout<<endl;
}
void RDisplay(Node *p) //Recursive function
{
    if(p!=NULL)
    {
        cout<<p->Data<<"->";
        RDisplay(p->Next);
    }
}
int Count(Node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->Next;
    }
    return count;
}
int RCount(Node *p)
{
    if(p)
    {
        return RCount(p->Next)+1;
    }
    else
        return 0;
}
int Sum(Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->Data;
        p=p->Next;
    }
    return sum;
}
int RSum(Node *p)
{
    if(p)
    {
       return RSum(p->Next)+p->Data;
    }
    else 
        return 0;
}
int Max(Node *p)
{
    int Max=INT16_MIN; //max=-32768 
    while(p)
    {
        if(p->Data>Max)
        {
            Max=p->Data;
        }
         p=p->Next;   
    }
    return Max;
}
int RMax(Node *p)
{
    int x=0;
    if(p==0)
        return INT16_MIN;
    x=RMax(p->Next);

    return x>p->Data?x:p->Data; //turnary operator

}
int Min(Node *p)
{
    int Min=INT16_MAX; //Min=32767
    while(p)
    {
        if(Min>p->Data)
        {
            Min=p->Data;
        }
        p=p->Next;
    }
    return Min;
}
Node* Search(Node *p, int key)
{
    Node *q=NULL;       //This is move to head method
    while(p!=NULL)
    {
        if(key ==p->Data)
        {
            q->Next=p->Next;
            p->Next=first;
            first=p;
            return (p);
        }
        q=p;
        p=p->Next;
    }
    return 0;
}
Node* RSearch(Node *p, int key)
{
    if(p==NULL)
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
    return key==p->Data?p:RSearch(p->Next,key); //turnary operator
}
void Insert(int index, int x)
{
    Node *p, *t;
    if(index < 0 || index > Count(p) )
        return;
    if(index==0)
    {
        t->Data=x;
        t->Next=first;
        first=t;
    }
    else if(index > 0)
    {
        p=first;
        for(int i=0;i<index-1 && p ; i++)
           p=p->Next;
        
            if(p)
            {   
                t= new Node;
                t->Data=x;
                t->Next=p->Next;
                p->Next=t;             
            }
    }
}
int main(){
int A[]={3,5,35};

Create(A, 3);
Display(first);

// cout<<RCount(first)<<" number of nodes are present \n";
// cout<<Sum(first)<<" is the Addition of elemets ";    


// Node* temp=Search(first,35);
// if(temp)
//     cout<<"Key "<<temp->Data<< " is found at address "<<temp<<endl;
// else
//     cout<<"Key not found "<<endl;
//cout<<"After Inserting:\n";
Insert(1, 12);

Display(first);

return 0;

}
