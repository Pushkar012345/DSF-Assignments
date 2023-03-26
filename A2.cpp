
#include<iostream> 
#include<stdlib.h> 
#include<math.h> 
using namespace std;

//class node
class NODE { 
public: 
int data; 
NODE *left, *right; 
NODE() { 
left = right = NULL; 
} 
NODE(int x) { 
data = x; 
left = right = NULL; 
} 
};

//class BST
class BST { 
NODE *root; 
void inorder(NODE*); 
NODE* insertrec(NODE* T, NODE *temp); 
public: 
BST() { 
root = NULL; 
} 
void insert(int x); 
void display_inorder(); 
int search_recursive(int x); 
void insert_rec(int x); 
int search(NODE* curr,int key); 
int non_recursive_search(int x); 
int height_rec(NODE* T); 
int ht_rec(); 
NODE* mirror(NODE* rt); 
void del(); 
NODE* delete_node(NODE* T,int key); 
void display_mirror(); 
void printGivenLevel(NODE* temp, int level); 
void printLevelOrder(); 
}; 

//Insert rec
void BST::insert_rec(int x) 
{ 
NODE *temp=new NODE(x); 
root=insertrec(root,temp); 
}

NODE* BST::insertrec(NODE* T,NODE* temp){ 
if(T==NULL) 
 return temp; 
if(temp->data<T->data) 
T->left=insertrec(T->left,temp); 
else 
T->right=insertrec(T->right,temp); 
return T; 
} 
void BST::insert(int x){ 
 NODE* current,*parent; 
 NODE* temp=new NODE(x); 
 if(root==NULL) 
 root=temp; 
 else{ 
 current=root; 
 while(current!=NULL){ 
 parent=current; 
 if(temp->data<current->data) 
 current=current->left; 
 else 
 current=current->right; 
 } 
 if(temp->data<parent->data) 
 parent->left=temp; 
 else 
 parent->right=temp; 
 } 
} 
void BST::display_inorder(){ 
cout<<"Inorder Traversal of BST: "<<endl; 
inorder(root); 
} 
void BST::inorder(NODE *r){ 
if(r!=NULL){ 
inorder(r->left); 
cout<<r->data<<" "; 
inorder(r->right); 
} 
} 
int BST::search_recursive(int x){ 
 return search(root,x); 
} 
int BST::search(NODE* curr,int key){ 
 if(curr==NULL) 
 return 0; 
 if(curr->data==key) 
 return 1; 
 if(curr->data>key) 
 return search(curr->left,key); 
 else 
 return search(curr->right,key); 
} 
int BST::non_recursive_search(int x){ 
 NODE* current; 
 if(root==NULL){ 
 return 0; 
 } 
 current=root; 
 while(current!=NULL){ 
 if(current->data==x) 
 return 1; 
 if(current->data>x) 
 current=current->left; 
 else 
 current=current->right; 
 } 
 return 0; 
} 
int BST::height_rec(NODE* T){ 
 if(T==NULL){ 
 return 0; 
 } 
 if(T->left==NULL && T->right==NULL){ 
 return 1; 
 } 
 int h1=height_rec(T->left); 
 int h2=height_rec(T->right); 
 int m=max(h1,h2); 
 return (m+1); 
} 
int BST::ht_rec(){ 
 return height_rec(root); 
} 
void BST::del(){ 
 int k; 
 cout<<"Enter the element to delete: "; 
 cin>>k; 
 root=delete_node(root,k); 
} 
NODE* BST::delete_node(NODE* T,int key){ 
 NODE* temp; 
 if(T==NULL){ 
 cout<<"key not found !"<<endl; 
 return T; 
 } 
 if(key<T->data){ 
 T->left=delete_node(T->left,key); 
 return T; 
 } 
 if(key>T->data){ 
 T->right=delete_node(T->right,key); 
 return T; 
 } 
 if(T->left==NULL && T->right==NULL){ 
 temp=T; 
 free(temp); 
 cout<<"Deleted "<<key<<" Successfully (Leaf Node)"<<endl; 
 return NULL; 
 } 
 if(T->left==NULL){ 
 temp=T; 
 T=T->right; 
 free(temp); 
 cout<<"Deleted "<<key<<" Successfully"<<endl; 
 return T; 
 } 
} 
void BST::printGivenLevel(NODE* temp, int level) 
{ 
 if (temp == NULL) 
 return; 
 if (level == 1) 
 cout<<temp->data<<" "; 
 else if (level > 1) { 
 printGivenLevel(temp->left, level - 1); 
 printGivenLevel(temp->right, level - 1); 
 } 
} 
 
void BST::printLevelOrder() 
{ 
 int h = ht_rec(); 
 int i; 
 for (i = 1; i <= h; i++) { 
 printGivenLevel(root, i); 
 cout<<"\n"; 
 } 
} 
NODE* BST::mirror(NODE* rt){ 
 NODE* temp; 
 if(rt==NULL) 
 return NULL; 
 else{ 
 temp=new NODE(rt->data); 
 temp->left=mirror(rt->right); 
 temp->right=mirror(rt->left); 
 return temp; 
 } 
} 
void BST::display_mirror(){ 
 NODE* temproot; 
 temproot=mirror(root); 
 cout<<"Mirror Successful"<<endl; 
 cout<<"Inorder Traversal of BST"<<endl; 
 inorder(temproot); 
} 
int main(){ 
BST obj; 
int opt,x,op,flag,a,b; 
do{ 
cout<<endl; 
cout<<"\t\t"<<"MAIN MENU"<<"\t\t"<<endl; 
cout<<endl<<"Select an option"<<endl; 
cout<<"1. Insert node in BST\n2. Display BST in Inorder\n3. Recursive 
Search\n4. Non-Recursive Search\n5. Height of BST\n6. Level Wise 
Display\n7. Delete a node\n8. Mirror\n9. Exit"<<endl; 
cin>>opt; 
switch(opt){ 
case 1: 
do{ 
cout<<"Enter the element to insert in BST"<<endl; 
cin>>x; 
obj.insert_rec(x); 
cout<<"Do you want to add more elements ?"<<endl<<"1. Yes\n2. 
No"<<endl; 
cin>>op; 
}while(op==1); 
break; 
case 2: 
obj.display_inorder(); 
break; 
case 3: 
cout<<"Enter the element you want to search"<<endl;
cin>>a; 
flag=obj.search_recursive(a); 
if(flag==1) 
 cout<<"Element found !"<<endl; 
else 
 cout<<"Element not found !"<<endl; 
break; 
case 4: 
cout<<"Enter the element you want to search"<<endl;
cin>>a; 
flag=obj.non_recursive_search(a); 
if(flag==1) 
 cout<<"Element found !"<<endl; 
else 
 cout<<"Element not found !"<<endl; 
break; 
case 5: 
b=obj.ht_rec(); 
cout<<"Height of BST: "<<b; 
break; 
case 6: 
cout<<"Level Wise Display"<<endl; 
obj.printLevelOrder(); 
break; 
case 7: 
obj.del(); 
break; 
case 8: 
obj.display_mirror(); 
break; 
} 
}while(opt!=9); 
return 0; 
} 
