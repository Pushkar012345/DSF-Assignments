#include<iostream>
using namespace std;


class Node{
public:
int data;
Node *left, *right;
Node(int val){
data = val;
left = NULL;
right = NULL;
}
};

//insertBST
Node* insertBST(Node *root, int val){
if(root == NULL){
return new Node(val);
}
else if(val<root->data){
root->left = insertBST(root->left, val);
}
else{
root->right = insertBST(root->right, val);
}
return root;
}

int main() {
Node *root = NULL;
int choice,x,i,z;
cout<<"Enter root:- ";
cin>>z;

root = insertBST(root, z);
do
{
cout<<"\n1)Insert\n2)Display Inorder\n3)Search\n4)Height of tree\n5)Level wise display\n6)Delete\n7)Mirror\n8)Exit"<<endl;
cin>>choice;
switch (choice)
{
case 1:
cout<<"How many insertions:- ";
cin>>x;
for ( i = 0; i < x; i++)
{
cout<<"Enter value:- ";
cin>>z;
insertBST(root, z);
}
break;
/*
case 2:
//inorder(root);
break;
case 3:
cout<<"Enter value to serach:- ";
cin>>z;
//if(searchinBST(root, z) == NULL){
cout << "key doesn't exist";
}
else{
cout<<"key exists";
}
break;
//case 4:
//cout<<"Height of tree: "<<maxdepth(root)<< endl;
break;
case 5:
//levelOrderTraversal(root);
break;
case 6:
cout<<"Enter value to delete:- ";
cin>>z;
root = deleteinBST(root, z);
break;
case 7:
mirror_rec(root);
break;
}
}while(choice!=8);
*/

}

}while(choice!=8);
return 0;

}