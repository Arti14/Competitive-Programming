#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct treap{
    string key ;
    int weight;
    treap *L ;
    treap *R;
};



void rotate_C( treap **node) 
    {
        treap *tmp = (*node)->L;
        (*node)->L=tmp->R;
        tmp->R=*node;
        *node = tmp;
     }
 

void rotate_A( treap **node)
    {
         treap *tmp = (*node)->R;
        (*node)->R=tmp->L;
        tmp->L=*node;
        *node = tmp;
         
     }
 

void balance(treap **node )
    {
        if( (*node)->L != NULL &&   (*node)->L->weight > (*node)->weight ) 
        {
            rotate_C( node );
        }
        else if (  (*node)->R != NULL && (*node)->R->weight > (*node)->weight) 
        {
            rotate_A( node );
        }
     }
 

void insert( struct treap **node, string k, int w)
    {
 
         
        if(*node == NULL)
        {
            *node = new treap;
            (*node)->key=k;
            (*node)->weight=w;
            (*node)->L=(*node)->R= NULL;
            return;
        }
        else if (k <= (*node)->key) 
        {
            insert( &( (*node)->L ),k,w);
        }
        else 
        {
            insert( &( (*node)->R ), k , w);
        }
        balance(node);
         
    }

void print_treap( treap *node)
    {
        if(node == NULL ) return;
        cout<<"(";
        print_treap(node->L);
        cout<<node->key<<"/"<< node->weight;  
        print_treap(node->R);
        cout<<")";
        
        
    } 

int main()
{
    char str[50]; 
    int T;
    scanf("%d",&T);
    while(T>0)
    {
        treap *root =NULL;
        for(int i=0;i<T;i++)
        {
            string k;
            char tmp[50];
            int w;
            scanf("%s",str);
            int j=0;
            while(str[j]!='/')
            {
                k=k+str[j++];
            }
            j++;
            int l=0;
            while(str[j]!='\0')
            {
                tmp[l++]=str[j++];
            }
            tmp[l]='\0';
            w=atoi(tmp);
            insert(&root,k,w);
        }
        print_treap(root);
        cout<<endl;
        scanf("%d",&T);
        
    }

}




