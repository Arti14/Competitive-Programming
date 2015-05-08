#include<iostream>
using namespace std;

struct tree{
    int data;
    tree *left;
    tree *right;
    };
tree *root;

int maxm=-1;

void inorder(tree *tmp){
    if(tmp==NULL){
    return;
    }
    inorder(tmp->left);
    cout<<tmp->data<<" ";
    inorder(tmp->right);
}

int diam =0;

int longest_path( tree *tmp, int path)
{
    if(tmp==NULL){
    return 0;
    }
    
    int l=longest_path( tmp->left,path);
    int r=longest_path(tmp->right,path);
    path=l+r+1;
    
    if(diam<path){
    diam=path;
    }
    
    if(l>=r){
    return l+1;
    }
    else{
    return r+1;
    }
}

void left_view(tree *tmp,int h){
    
    if(tmp==NULL){
    return;
    }
    
    if(h>maxm){
    maxm=h;
    cout<<tmp->data<<endl;
    }
    
    left_view(tmp->left,h+1);
    left_view(tmp->right,h+1);
}

    
    

int main(){
    tree *n=new tree;
    n->data=10;
    n->left=NULL;
    n->right=NULL;
    root=n;
    
    tree *n1=new tree;
    n1->data=25;
    n1->left=NULL;
    n1->right=NULL;
    n->left=n1;
    
    tree *n2=new tree;
    n2->data=30;
    n2->left=NULL;
    n2->right=NULL;
    n->right=n2;
    
    tree *n3=new tree;
    n3->data=2;
    n3->left=NULL;
    n3->right=NULL;
    n1->left=n3;
    
    tree *n4=new tree;
    n4->data=32;
    n4->left=NULL;
    n4->right=NULL;
    n1->right=n4;
    
    tree *n5=new tree;
    n5->data=55;
    n5->left=NULL;
    n5->right=NULL;
    n2->left=n5;
    
    tree *n6=new tree;
    n6->data=21;
    n6->left=NULL;
    n6->right=NULL;
    n2->right=n6;
    
    tree *n7=new tree;
    n7->data=35;
    n7->left=NULL;
    n7->right=NULL;
    n4->left=n7;
    
    tree *n8=new tree;
    n8->data=63;
    n8->left=NULL;
    n8->right=NULL;
    n4->right=n8;
    
    inorder(root);
    cout<<endl;
    cout<<"left view of the tree "<<endl;
    left_view(root,0);
    cout<<endl;
    
    cout<<"Longest path is "<<endl;
    longest_path( root,0);
    cout<<diam<<endl;
}
    
    
    
