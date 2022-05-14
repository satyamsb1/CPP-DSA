#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    Node *rchild;
    int data;
    Node *lchild;
};

class Tree
{
private:
    Node *root;

public:
    Tree() { root = NULL; }
    void CreateTree();
    void Preorder(Node *p);
    void Preorder() { Preorder(root); }
    void Postorder(Node *p);
    void Postorder() { Postorder(root); }
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    void LevelOrder(Node *p);
    void LevelOrder() { LevelOrder(root); }
    int Height(Node *root);
    int Height() { return Height(root); }
    void iterativePreorder(Node *p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node *p);
    void iterativeInorder() { iterativeInorder(root); }
    void Levelorder(Node *p);
    void Levelorder() { Levelorder(root); }
    int Count(Node *root);
    int Count(){return Count(root);}
    int LeafNode(Node *root);
    int LeafNode(){return LeafNode(root);}
    int DegreeTwo(Node *root);
    int DegreeTwo(){return DegreeTwo(root);}
    int Sum(Node *root);
    int Sum(){return Sum(root);}
};
int Tree :: LeafNode(Node *root)
{
    int x=0; int y=0;
    if(root)
    {
        x=LeafNode(root->rchild);
        y=LeafNode(root->lchild);
        if(!root->rchild && !root->lchild)
        return x+y+1;
        else return x+y;
    }
    return 0;
}
int Tree :: DegreeTwo(Node *root)
{
    int x=0; int y=0;
    if(root)
    {
        x=DegreeTwo(root->rchild);
        y=DegreeTwo(root->lchild);
        if(root->rchild && root->lchild)
        return x+y+1;
        else return x+y;
    }
    return 0;
}
int Tree :: Sum(Node *root)
{
    int x=0; int y=0;
    if(root)
    {
        x=Sum(root->rchild);
        y=Sum(root->lchild);
        return x+y+root->data;
    }
    return 0;
}
int Tree :: Count(Node *root)
{
    int x=0,y=0;
    if(root)
    {
        x=Count(root->rchild);
        y=Count(root->lchild);
        return x+y+1;   //If u use only this statement itll count the number of nodes
    }
    return 0;
}
void Tree::CreateTree()
{
    Node *p, *t = NULL;
    int x;
    queue<Node *> q;
    cout << "Enter the root value : ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter the left child of " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.emplace(t);
        }
        cout << "Enter the right child " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.emplace(t);
        }
    }
}
void Tree ::LevelOrder(Node *root)
{
    queue<Node *> q;

    cout << root->data << " ";
    q.emplace(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            q.emplace(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            q.emplace(root->rchild);
        }
    }
}
void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << " " << p->data;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << " " << p->data;
        Inorder(p->rchild);
    }
}
void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << " " << p->data;
    }
}
int Tree::Height(Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
void Tree ::iterativePreorder(Node *p)
{
    stack<Node *> stk;

    while (!stk.empty() || p)
    {
        if (p)
        {
            cout << p->data << " ";
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
}
void Tree ::iterativeInorder(Node *p)
{
    stack<Node *> stk;

    while (!stk.empty() || p)
    {
        if (p)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}
void Tree ::Levelorder(Node *p)
{
    queue<Node *> q;
    cout << p->data << " ";
    q.emplace(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->rchild)
        {
            cout << p->lchild->data << " ";
            q.emplace(p->rchild);
        }
        if (p->lchild)
        {
            cout << p->rchild->data << " ";
            q.emplace(p->lchild);
        }
    }
}
int main()
{

    Tree t;
    t.CreateTree();
    cout<<t.Count()<<endl;

    return 0;
}
