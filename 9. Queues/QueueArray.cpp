#include<iostream>
using namespace std;

template<class T>

class Queue
{
    private:
        int front;
        int rear;
        int size;
        T* Q;

    public:
        Queue()
        {
            front=rear=-1;
            size=10;
            Q=new int[size];
        }
        Queue(int size)
        {
            this->size=size;
            front=rear=-1;
            Q=new int[this->size];
        }
        void Enqueue(int x);
        T Dequeue();
        void Display();
};
void Queue :: Enqueue(T x)
{
    if(rear==size-1)
    {
        cout<<"Queue is Full"<<endl;
    }
    else
    {
        rear++;
        Q[rear]=x;
    }
}
T Queue ::Dequeue()
{
    int x=-1;
    if(rear==front)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        
        front++;
        x=Q[front];
        
    } 
    return x;
}
void Queue :: Display()
{
    for(int i=front+1; i<=rear; i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}
int main(){

    int n;
    cout<<"Enter the size of queue";
    cin>>n;

    Queue q(n);
    cout<<"Enter the elements";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        q.Enqueue(x);
    }
    q.Display();


return 0;
}
