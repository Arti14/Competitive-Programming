#include <iostream>
#include <string>
using namespace std;

struct treap{
    long key ;
    long weight;
    treap *L ;
    treap *R;
};

treap *root =NULL;

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
 

void insert( struct treap **node, long k, long w)
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
    
void del( struct treap **node, long x)
    {
        if(*node == NULL ) return;
        if( x < (*node)->key ) del( & ( (*node)->L) , x );
        else if ( x > (*node)->key )  del( & ( (*node)->R) , x );
        else 
         {
            if( (*node)->L == NULL && (*node)->R == NULL ) *node = NULL;
            else if ( (*node)->L == NULL ) *node = (*node)->R;
            else if ( (*node)->R == NULL ) *node = (*node)->L;
            else
            {
               
                if ( (*node)->L->weight > (*node)->R->weight ) rotate_C( node );
                else rotate_A( node );
                del(node,x);
            }
        }
    }
    
int distance(treap *node, long x)
{
    if(node==NULL)
    {
        return 0;
    }
    if(node->key==x)
    {
        return 1;
    }
    if(node->key>x)
    {
        int dist =distance(node->L,x)+1;
        return dist;
    }
    if(node->key<x)
    {
        int dist =distance(node->R,x)+1;
        return dist;
    }
    
}

int LCA(treap *node, long a, long b)
{
    if(node==NULL)
    {
        return 0;
    }
    if(node->key>a&&node->key>b)
    {
       return LCA(node->L, a, b);
    }
    if(node->key<a&&node->key<b)
    {
        return LCA(node->R, a, b);
    }
    return distance (root,node->key);
}



int main()
{
    int op; 
    cin>>op;
    int index;
    long k, w,ku,kw;
    while(op--)
    {
        
        cin>>index;
        switch(index)
        {
            case 0:
                cin>>k>>w;
                insert(&root,k,w);
                break;
        
            case 1:
                cin>>k;
                del(&root,k);
                break;
            
            case 2:
               
               cin>>ku>>kw;
               if(ku==kw)
               {
                   cout<<0<<endl;
                   continue;
               }
               int dist1=LCA(root,ku,kw);
               int dist_s=distance(root,ku);
               int dist_e=distance(root,kw);
               cout<<dist_s+dist_e-2*dist1<<endl;
               break;
            
        }
        
    }

}