/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<iostream>
using namespace std;

//class node
class node
{
    public:
    int data;
    node *left,*right;
    int lth,rth; 
    
    //flags to tell pointing to actual child or thread
    //if th=1 i.e pointing to inorder predecessor or succesor
    //th=0,pointing to left or right child
    
    node(int x)  //parameterized constructor
    {
        data=x;
        lth=1; //both initialized to 1
        rth=1;
    }
};

class thread
{
    public:
    //2 pointer root and dummy
    node *root,*dummy; //in constructor create dummy and dummy
    //left will point to root
    
    thread()
    {
        root=NULL;
        dummy=new node(-1); //allocating mem for dummy,putting data -1
        dummy->rth=0;//i.e actual child pointing itself
        dummy->lth=1;//i.e dummy also itself first initially
        dummy->left=dummy;
        dummy->right=dummy;
    }
    void insertNode();//if first node create root
    void insert(node*,node*);//recursive  function BST logic
    void inorder();
    void preorder();
};

void thread::insertNode()//insertion of single node
{
    int data; //ip data
    node *newnode;  //create node for that data
    cout<<"\n Enter the data:";
    cin>>data;
    newnode=new node(data);//create node for that data
    //this newnode have to insert in TBT
    if(dummy->lth==1) //i.e thread->tree empty-no node
    {                 //empty TBT-root is new node-
        root=temp;
        root->left=dummy;
        root->right=dummy;
        dummy->left=root;//insertion of root
        dummy->lth=0; //it is now actual child
    }                 //initially lth =1 i.e thread,now
                      //child
    else //if root is already there ,lth=0,insering node-
    {    //follo BST logic
        insert(root,temp);
    }
}

//insertrecursive f--follow BSt logic
void thread::insert(node *root,node *newnode)
{
    //insertion at left
    if(newnode->data<root->data)
    {   
        //checking reach at leftmost or not
        if(root->lth==1)//insertion to leftmost of root
        {   
            //copied leftpart as it is from root
            newnode->lth=root->lth;
            newnode->left=root->left;
            //and right of root point to root
            newnode->right=root;
            //attached newnode to left of root
            newnode->rth=1;
            root->left=newnode;
            root->lth=0;  //as attached actual child th=0
        }
        else//move leftmost foll recursive call until
        //reach thread with value 1
        {//insertnode in left subtree
          insert(root->left,newnode);  
        }
    }
    
    else //insertion at right
    {
        if(root->rth==1)
        {
            //copied rightpart as it is from root
            newnode->rth=root->rth;
            newnode->right=root->right;
            //leftthread point parent node
            newnode->lth=1;
            newnode->left=root;
            root->right=newnode;
            root->rth=0;
        }
        else
        {   //insertnode in right subtree,until reach th value 1
            insert(root->right,newnode);
        }
    }
}

node* preorderSuccessor(node *p)
{
    if(p->leftThread==0)//if  climb till leftnode is link
    {
        return p->left;
    }
    while(p->rightThread==1)//right child
    {
        p=p->right;//take parent node
        return p->right;//its right preorder successor
    }
}

void thread::preorder()
{
    node *T=root;//root
    cout<<"\nPreorder traversal:";
    T=T->left;
    while(T!=dummy)
    {//untill reach dummy node,display data find preorder suc
        cout<<" "<<T->data;
        T=preorderSuccessor(T);
    }
    cout<<endl;
}

node* inorderSuccessor(node *p)
{
    if(p->rightThread==1)//if right is thread then it is successor
    {
        return p->right;
    }
    p=p->right;//right link
    while(p->leftThread==0)
    {
        p=p->left; //leftmost of right
    }
    return p;
}

void TBT::inorder()
{
    node *T=root;
    while(T->leftThread==0)//reach leftmost
    {
        T=T->left;
    }
    cout<<"Inorder Traversal";
    while(T=dummy)//untill reach dummy node
    {//display data,find inorderSuccessor
       cout<<" "<<T->data;
       T=inorderSuccessor(T);
    }
    cout<<endl;
}









