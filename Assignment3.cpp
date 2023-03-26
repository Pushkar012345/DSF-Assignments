#include<iostream>
using namespace std;

class node
{
    public:
    int data,leftThread,rightThread;
    node *left,*right;
    
    node(int x)
    {
        data=x;
        leftThread=1;
        rightThread=1;
    }
};

class TBT
{
    public:
    node *root,*dummy;
    TBT()
    {
       root=NULL;
       dummy=new node(-1);
       dummy->rightThread=0;
       dummy->leftThread=1;
       dummy->right=dummy;
       dummy->left=dummy;
    }
    void insertNode();
    void insert(node*,node*);
    void inorder();
    void preorder();
};

void TBT::insertNode()
{
    int x;
    node *temp;
    cout<<"Enter the data:";
    cin>>x;
    temp=new node(x);

    if(dummy->leftThread==1)
    {
        root=temp;
        root->left=dummy;
        root->right=dummy;
        dummy->left=root;
        dummy->leftThread=0;
    }
    else
    {
        insert(root,temp);
    }
}

void TBT::insert(node *root,node *temp)
{
    if(temp->data<root->data)
    {
        if(root->leftThread==1)
        {
            temp->leftThread=root->leftThread;
            temp->left=root->left;
            temp->right=root;
            root->left=temp;
            root->leftThread=0;
        }
        else
        {
            insert(root->left,temp);
        }
    }
    else
    {
        if(root->rightThread==1)
        {
            temp->rightThread=root->rightThread;
            temp->right=root->right;
            temp->left=root;
            root->right=temp;
            root->rightThread=0;
        }
        else
        {
            insert(root->right,temp);
        }
    }
}

node* preorderSuccessor(node *p)
{
    if(p->leftThread==0)
    {
        return p->left;
    }
    while(p->rightThread==1)
    {
        p=p->right;
        return p->right;
    }
}

void TBT::preorder()
{
    node *T=root;
    cout<<"Preorder Traversal";
    while(T!=dummy)
    {
        cout<<" "<<T->data;
        T=preorderSuccessor(T);

    }
    cout<<endl;
}

node* inorderSuccessor(node *p)
{
    if(p->rightThread==1)
    {
        return p->right;
    }
    p=p->right;
    while(p->leftThread==0)
    {
        p=p->left;
    }
    return p;
}

void TBT::inorder()
{
    node *T=root;
    while(T->leftThread==0)
    {
        T=T->left;
    }
    cout<<"\nInorder Traversal:";
    while(T!=dummy)
    {
        cout<<" "<<T->data;
        T=inorderSuccessor(T);
    }
    cout<<endl;
}

int menu()
{
    int x;
    cout<<"Insert The nodde\n"
          "2.display in preorder\n"
          "3.display in inorder\n"
          "4.exit\n"
          "Enter choice:";
    cin>>x;
    return x;
}

int main()
{
    TBT t;
while(1)
    {
        switch(menu())
        {
            case 1:
            t.insertNode();
            break;

            case 2:
            t.preorder();
            break;

            case 3:
            t.inorder();
            break;

            case 4:
            exit(0);
            break;
        }
   }
    return 0;
}