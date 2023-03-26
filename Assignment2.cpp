/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//create tree and level order traversal
/*
#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    //constructor
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right= NULL;
    }
};
class BST{
    node *root;
    void inorder(node *);

    BST(){
        root=NULL;
    }

};

node* buildTree(node* root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    
    if(data== -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left"<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right"<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

//levelorder traversal
void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp=q.front();
        //cout<<temp->data<<" ";
        q.pop();
        
        if(temp==NULL){//purana level complete traverse
            cout<<endl;
            if(!q.empty()){
                //queue still have child nodes
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
}

//ht recursive
int height_rec(node *root)

{

if (root==NULL) return-1;

if(root->left==NULL && root->right==NULL)//leaf nodes

return 0;

int l= height_rec(root->left);

int r= height_rec(root->right);

int m=max(l,r);

return(m+1);

//return(max( height_rec(T->left), height_rec(T->right))+1);

}

int height() //calling function

{return height_rec(root);

}

void insert_rec(int x){
    node *temp=new node(x);
    root=insertrec(root,temp);
    
}

node *BST::  insertrec(node* T,node* temp){
    if(T==NULL){
        return temp;
    }
    if(temp->data<T->data){
        T->left=insertrec(T->left,temp);
    }
    else{
        T->right=insertrec(T->right,temp);
    }
    return T;
}

void insert(int x){
    node *current,*root;
    node *temp=new node(x);
    
    if(root==NULL){
        root=temp;
    }
    
    else{
        current=root;
        
        while(current!=NULL){
            root=current;
            if(temp->data<current->data){
                current=current->left;
            }
            else{
                current=current->right;
            }
            
        }
        if(temp->data<root->data){
            root->left=temp;
        }
        else{
            root->right=temp;
        }
    }
}


int main(){
    BST obj;
    node* root=NULL;
    root =buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level levelOrderTraversal
    cout<<"Printing the level order traversal output"<<endl;
    levelOrderTraversal(root);
    
   return 0;

}





*/