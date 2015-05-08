#include<iostream>
#include<conio.h>
using namespace std;
struct tree
  {int data;
   tree *left;
   tree *right;
  };
tree *mainroot;  

void insert(tree *root, int val)
{
    if(mainroot ==NULL)
             {
                         tree *n1= new tree;
                        n1->data = val;
                        n1->left=n1->right=NULL;
                         mainroot=n1;
             }
    
      
     else if(val<=root->data)
     {
            if(root->left==NULL)
            {    
                 tree *n1= new tree;
                 n1->data = val;
                 n1->left=n1->right=NULL; 
                 root->left=n1;
            }
            else
            {
                insert(root->left,val);
            }
     }
     
     else
     {
          if(root->right==NULL)
          {
                 tree *n1=new tree;
                 n1->data=val;
                 n1->left=n1->right=NULL;
                 root->right=n1;
          }
          else
          {
               insert(root->right,val);
          }
     }
}

 

void inorder(tree *root)
{
     if(root==NULL)
     {
                   return;
     }
       inorder(root->left );
         cout<<root->data<<endl;
         inorder(root->right);
         
           
}
int lar_bst(tree *n)
{
     n=n->left;
     while(n->right!=NULL)
     {
        n=n->right;
     }
     return n->data;
     
}
     
     
     
void deletion(tree *root, int del)
{     
     
    
     if(root==NULL)
     { 
                   cout<<"key not found";
     }
     else if(root->data==del)
     {            
                                  
                   if(root->left==NULL&&root->right==NULL)
                   {
                          root=NULL;
                          delete root;
                   }
                   else if(root->left==NULL)
                   {  
                        tree *temp =new tree ;
                        temp=root;
                        root=root->right;
                       
                        temp=NULL;
                        delete temp;
                   }
                   else if(root->right==NULL)
                   {  
                        tree *temp =new tree ;
                        temp=root;
                        root=root->left;
                        temp=NULL;
                        delete temp;
                   }
                   else
                   {
                             int largest; 
                             largest=lar_bst(root);
                             root->data=largest;
                             deletion(root->left,largest); 
                   }
                          
     }
     else if(root->data>del)
     {
            if(root->left->data==del)
            {
                     tree *temp = new tree ;
                     temp=root;
                     root=root->left;
                     if(root->left==NULL&&root->right==NULL)
                     {
                          root=NULL;
                          delete root;
                     }
                     else if(root->left==NULL)
                     {  
                        
                        temp->left=root->right;
                        root=NULL;
                        delete root;
                     }
                     else if(root->right==NULL)
                     {  
                        
                        temp->left=root->left;
                        root=NULL;
                        delete root;
                     }
                   else
                   {
                             
                     int largest;
                     largest=lar_bst(root);
                     root->data=largest;
                     deletion(root->left,largest); 
                   }
                            
            }
            else deletion(root->left,del);
        }
    
     else
     {
         if(root->right->data==del)
            {
                     tree *temp =new tree ;
                     temp=root;
                     root=root->right;
                     if(root->left==NULL&&root->right==NULL)
                     {
                          root=NULL;
                          delete root;
                     }
                     else if(root->left==NULL)
                     {  
                        
                        temp->left=root->right;
                        root=NULL;
                        delete root;
                     }
                     else if(root->right==NULL)
                     {  
                        
                        temp->left=root->left;
                        root=NULL;
                        delete root;
                     }
                   else
                   {
                             
                     int largest;
                     largest=lar_bst(root);
                     root->data=largest;
                     deletion(root->left,largest); 
                   }
                            
            }
            else deletion(root->right,del);
     }
}                           

int main()
{
    mainroot=NULL;
    int n;
    int  val;
    int del;
    cout<<"enter how many nodes u want in the tree"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>val;
            insert(mainroot,val);
    }
    cout<<"inorder traversal"<<endl;
    inorder(mainroot);
    cout<<"enter which node you want to delete"<<endl;
    cin>>del;
    deletion(mainroot,del);
    cout<<"inorder traversal after deletion is "<<endl;
    inorder(mainroot);
    system("pause");
    return 0;
}
