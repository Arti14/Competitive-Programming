#include<iostream>
#include<queue>
using namespace std;
struct tree{
int data;
tree *left;
tree *right;
};

tree *root=NULL;

queue <tree*> qtree;
queue <int> qlevel;

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

int l=0;

void tree_to_Link(tree *tmp)
{
   if(tmp==NULL)
   {
      return;
   }
   qlevel.push(l);
   qtree.push(tmp);
   int al=0;
   while(!qtree.empty())
   {
      
      while(al==l)
      {
         tmp =qtree.front();
         cout<<tmp->data<<" ";
         qtree.pop();
         qlevel.pop();
         if(tmp->left!=NULL){
            qtree.push(tmp->left);
            qlevel.push(l+1);
            }
            if(tmp->right!=NULL){
            qtree.push(tmp->right);
            qlevel.push(l+1);
            }
         
         al=qlevel.front();
      }
      l=l+1;
      cout<<endl;
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
n2->right=n4;

inorder(root);
cout<<endl;
tree_to_Link(root);
cout<<endl;
}


