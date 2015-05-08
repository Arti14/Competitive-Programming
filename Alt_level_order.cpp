#include<iostream>
#include<queue>
using namespace std;

struct tree{
       int data;
       tree *left;
       tree *right;
       };

queue < tree* > q;
queue< int > q1;
int l=0;
int pl=0;  
int x=-1;
void alt_lvl(tree *n)
{
     tree *n1= new tree;
     int a[10];
     q.push(n);
     q1.push(l);
     n1=q.front();
     l=q1.front();
     while (!q.empty())
     {
         if(l!=pl)
         {
                      cout<<endl;
                      pl=l;
                      x=-1;  
          } 
         while(l==pl)
         { 
                   a[++x]=q.front()->data;
                   q.pop();
                   q1.pop();
                   if(n1->left!=NULL)
                   {
                      q.push(n1->left);
                      q1.push(l+1);
                   }
                   if(n1->right!=NULL)
                   {           
                      q.push(n1->right);
                      q1.push(l+1);
                   }
                   n1=q.front();
                   l=q1.front();
                   
         }
         int j=0;
         while(j<=x)
         {
                    if(pl%2==0)
                    {
                      cout<<a[j]<<" ";
                      j++;
                    }
                    else
                    
                    {
                      cout<<a[x]<<" ";
                      x--;
                    }
                
           } 
      }
}    
int main()
{    
    tree *n = new tree;
    n->data = 1;
    n->left=n->right=NULL;
    
    tree *n1 = new tree;
    n1->data=2;
    n1->left=n1->right=NULL;
    n->left=n1;
    
    tree *n2 = new tree;
    n2->data=3;
    n2->left=n2->right=NULL;
    n->right=n2;
    
    tree *n3 = new tree;
    n3->data=4;
    n3->left=n3->right=NULL;
    n1->left=n3;
    
    tree *n4 = new tree;
    n4->data=5;
    n4->left=n4->right=NULL;
    n2->left=n4;
    
    tree *n5 = new tree;
    n5->data=6;
    n5->left=n5->right=NULL;
    n2->right=n5;
    
    cout<<"alternate level order elements are"<<endl;
    alt_lvl(n);
    
  
}
