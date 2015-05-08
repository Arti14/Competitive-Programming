#include<iostream>
using namespace std;

struct tree{
int data;
tree *left;
tree *right;
};

tree *root=NULL;

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

tree* tree_to_DLL(tree *tmp, tree* prev)
{
   if(tmp->left==NULL)
   {
      if(prev!=NULL)
      {
        prev->right=tmp;
      }
      tmp->left=prev;
   }
   else
   {
      prev=tree_to_DLL(tmp->left,prev);
      prev->right=tmp;
      tmp->left=prev;
   }
   
   if(tmp->right==NULL)
   {
       return tmp;
   }
   else
   {
      return tree_to_DLL(tmp->right,tmp);
   }
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

tree* head=tree_to_DLL(root,NULL);
cout<<"reverse DLL"<<endl;
while(head!=NULL)
{
  cout<<head->data<<" ";
  head=head->left;
}
cout<<endl;

}

