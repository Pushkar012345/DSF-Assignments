#include <iostream>
using namespace std;

//class node
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


//search in BST
Node* searchinBST(Node *root, int key){ //O(logN)
if(root==NULL){
return NULL;
}
if(root->data == key){
return root;
}
else if(root->data > key){
return searchinBST(root->left, key);
}
else{
return searchinBST(root->right, key);
}
}
Node* inorderSucc(Node* root){
Node* curr = root;
while(curr && curr->left != NULL){
curr = curr->left;
}
return curr;
}


//DELETE IN BST
Node* deleteinBST(Node *root, int key){
if(key < root->data){
root->left = deleteinBST(root->left, key);

}
else if(key > root->data){
root->right = deleteinBST(root->right, key);
}
else{
if(root->left == NULL){
Node* temp = root->right;
free(root);
return temp;
}
else if(root->right == NULL){
Node* temp = root->left;
free(root);
return temp;
}
Node* temp = inorderSucc(root->right);
root->data = temp->data;
root->right = deleteinBST(root->right, temp->data);
}
return root;
}

//inorder fuction
void inorder(Node *root) {
if (root != NULL) {
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}
}

//display leaf node
void displayleafnode(Node *root){
if(!root){
return;
}
if(!root->left && !root->right){
cout<<root->data<< " ";
return;
}
if(root->right){
displayleafnode(root->right);
}
if(root->left){
displayleafnode(root->left);
}
}

//max depth
int maxdepth(Node* T){
if(T==NULL){
return -1;
} else{
int ldepth = maxdepth(T->left);
int rdepth = maxdepth(T->right);
if(ldepth>rdepth){
return (ldepth+1);
} else{
return (rdepth+1);

}
}
}

//mirror rec
void mirror_rec(Node* root)
{
if (root==NULL){
return;
}
mirror_rec(root->left);
mirror_rec(root->right);
Node* temp = root->left;
root->left = root->right;
root->right = temp;
}
bool printLevel(Node* root, int level)
{
if (root == nullptr) {
return false;
}
if (level == 1)
{
cout << root->data << " ";
// return true if at least one node is present at a given level
return true;
}
bool left = printLevel(root->left, level - 1);
bool right = printLevel(root->right, level - 1);
return left || right;
}
// Function to print level order traversal of a given binary tree
void levelOrderTraversal(Node* root)
{
// start from level 1 — till the height of the tree
int level = 1;
// run till printLevel() returns false
while (printLevel(root, level)) {
level++;
}
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
case 2:
inorder(root);
break;
case 3:
cout<<"Enter value to serach:- ";
cin>>z;
if(searchinBST(root, z) == NULL){
cout << "key doesn't exist";
}
else{
cout<<"key exists";
}
break;
case 4:
cout<<"Height of tree: "<<maxdepth(root)<< endl;
break;
case 5:
levelOrderTraversal(root);
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
return 0;
}
