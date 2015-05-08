#include<iostream>
using namespace std;

struct tree{
int data;
tree *left;
tree *right;
};

tree *root=NULL;

struct node{
int x;
node *next;
node *previous;
};

node *head=NULL;

void insert_DLL(int x)
{
   if(head==NULL)
   {
     node *n = new node;
     n->x=x;
     n->next=NULL;
     n->previous=NULL;
     head=n;
     return;
   }
   node *tmp=head;
   while(tmp->next!=NULL)
   {
   		tmp=tmp->next;
   	}
   node *n=new node;
   n->x=x;
   n->next=NULL;
   n->previous=tmp;
   tmp->next=n;
}
void tree_to_DLL(tree *tmp)
{
   if(tmp==NULL)
   {
     return;
   }
   tree_to_DLL(tmp->left);
   insert_DLL(tmp->data);
   tree_to_DLL(tmp->right);
}

void inorder(tree *r)
{
  if(r==NULL)
  {
	return;
  }
  inorder(r->left);
  cout<<r->data<<" ";
  inorder(r->right);
 }
int main()
{
tree *n=new tree;
n->data =10;
n->left=NULL;
n->right =NULL;
root=n;

tree *n1 = new tree;
n1->data=8;
n1->left=NULL;
n1->right =NULL;
n->left = n1;

tree *n2 =new tree;
n2->data=20;
n2->left =NULL;
n2->right=NULL;
n->right=n2;

tree *n3 = new tree;
n3->data=7;
n3->left=NULL;
n3->right=NULL;
n1->left=n3;

tree *n4=new tree;
n4->data=9;
n4->left=NULL;
n4->right=NULL;
n1->right=n4;

inorder(root);
cout<<endl;

tree_to_DLL(root);

node *tmp=head;

while(tmp!=NULL)
{
   cout<<tmp->x<<" ";
   tmp=tmp->next;
}
cout<<endl;


}





