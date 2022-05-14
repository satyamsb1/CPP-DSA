#include<iostream>
#include<cstring>
using namespace std;
class Stack
{
    private:
        int size;
        int top;
        int *S;

    public:
        Stack();
        // Stack(int size);
        ~Stack();
        void Create();
        void Push(int x); 
        void Display();
        int pop();
        int peek(int pos);
        char StackTop();
        int IsEmpty();
        int IsFull();
        int isOperand(char x);
        // char *Convert(char *infix);
        int Presidence(char x);
        int PostEval(char *postfix);
};

Stack::Stack() {
    top = -1;
}

// Stack ::Stack(int size)
// {
//     this->size=size;
//     top=-1;
//     S=new int [size];
// }
void Stack::Display()
{
    int i;
    for(i=top; i>=0; i--)
    {
        cout<<S[i]<<" "; 
    }
    cout<<endl;
}

Stack::~Stack()
{
    delete []S;
}

void Stack::Push(int x)
{
    if(top==size-1)
        cout<<"Stack Overflow"<<endl;
    else
        {
            top++;
            S[top]=x;
        }
}
int Stack::pop()
{
    int x=-1;
    if(top==-1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        x=S[top];
        top--;
    }   
    return x;   
}
int Stack::peek(int pos)
{
    int x=-1;
    if(top-pos+1<0)
        cout<<"Invalid Position"<<endl;
    else
        x=S[top-pos+1];
    return x;    
}
int Stack::IsFull()
{
    if(top==size-1)
    {
        return 1;
    }
    return 0;
}
int Stack::IsEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}


char Stack::StackTop()
{
    if(top==-1){
       
        return -1;
    }
    return S[top];
}
// bool isBalance(char *exp)
// {
//     Stack stk((int)strlen(exp));

//     for(int i=0; i<strlen(exp); i++)
//     {
//         if(exp[i]=='(')
//         {
//             stk.Push(exp[i]);
//         }else if(exp[i]==')')
//         {
//             if(stk.IsEmpty())
//             {
//                     return false;
//             }
//             else
//                 stk.pop();
//         }

//     }
//     return stk.IsEmpty()?true:false;
// }
int Stack::isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
    {
        return 0;
    }else
        return 1; 
}
int Stack :: Presidence(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }else if(x=='*' || x=='/')
    {
        return 2;
    }else if(x=='^')
    {
        return 3;
    }
    return 0;
}
// char* Stack :: Convert(char *infix)
// {
//     Stack st(strlen(infix)+1);
//     char *postfix=new char[strlen(infix)+1];
//     int i=0, j=0;
//     while(infix[i]!='\0')
//     {
//         if(st.isOperand(infix[i]))
//         {
//             postfix[j++]=infix[i++];
//         }else
//         {
//             if(st.Presidence(infix[i])>st.Presidence(st.StackTop()))
//             {
//                 st.Push(infix[i++]);
//             }
//             else
//             {
//                 postfix[j++]=st.pop();
//             }
//         }
//     }
//     while(!st.IsEmpty())
//     {
//         postfix[j++]=st.pop();
//     }
//     postfix[j]='\0';
//     return postfix;
// }
int Stack :: PostEval(char *postfix)
{
    Stack S;
    int i,x1,x2,r;
    for(int i=0; i<postfix[i]!='\0'; i++)
    {
        if(isOperand(postfix[i]))
        {
            S.Push(postfix[i]-'0');
        }
        else{
            x1=S.pop();
            x2=S.pop();
            switch (postfix[i])
            {
            case '+':
                S.Push(x1+x2);
                break;
            case '*':
                S.Push(x1*x2);
                break;
            case '/':
                S.Push(x1/x2);
                break;
            case '-':
                S.Push(x1-x2);
                break;
            }
        }
    }
    return S.pop();
}
int main(){
    Stack s;
   char postfix[] = "35*62/+4-";
    cout << s.PostEval(postfix) << endl;
    return 0; 
}
