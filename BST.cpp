#include <iostream>
#include <queue>
using namespace std;

struct tree
{
	int data;
	tree *left;
	tree *right;
};

tree *root =NULL;

queue < tree* > qdata;
queue < int > qlevel;

int lar_bst(tree *n1)
{
	n1=n1->left;
	while(n1->right!=NULL)
	{
		n1=n1->right;
	}
	return n1->data;
}

void del(tree *node, int x)
{
	if(node==NULL)
	{
		return;
	}
	
	if(x<node->data) // data to be deleted is on left subtree
	{
		if(x==node->left->data)
		{
			tree *tmp = new tree;
			tmp = node->left;
			if(tmp->left==NULL && node->right==NULL)
			{
				node->left=NULL;
				delete tmp;
			}
			else if(tmp->left==NULL)
			{
				node->left=tmp->right;
				tmp->right=NULL;
				delete tmp;
			}
			else if(tmp->right==NULL)
			{
				node->left=tmp->left;
				tmp->left=NULL;
				delete tmp;
			}
			else
			{
				int largest;
                largest=lar_bst(tmp);
                del(tmp,largest);
                tmp->data=largest;
			}
			

		}
		else
		{
			del(node->left, x);
		}
	}
	if(x>node->data) // data to be deleted is on left subtree
	{
		if(x==node->right->data)
		{
			tree *tmp = new tree;
			tmp = node->right;
			if(tmp->left==NULL && node->right==NULL)
			{
				node->right=NULL;
				delete tmp;
			}
			else if(tmp->left==NULL)
			{
				node->right=tmp->right;
				tmp->right=NULL;
				delete tmp;
			}
			else if(tmp->right==NULL)
			{
				node->right=tmp->left;
				tmp->left=NULL;
				delete tmp;
			}
			else
			{
				int largest;
                largest=lar_bst(tmp);
                del(tmp,largest);
                tmp->data=largest;
                

			}
			

		}
		else
		{
			del(node->right, x);
		}
	}
}

void insert(tree *n, int x)
{
	if(root==NULL)
	{
		tree *node = new tree;
		node->data=x;
		node->left=NULL;
		node->right=NULL;
		root=node;
		return;
	}
	if(n->data>=x)
	{
		if(n->left==NULL)
		{
			tree *node = new tree;
			node->data=x;
			node->left=NULL;
			node->right=NULL;
			n->left=node;
			return;
		}
		else
		{
			insert(n->left, x);
		}
	}
	else
	{
		if(n->right==NULL)
		{
			tree *node = new tree;
			node->data=x;
			node->left=NULL;
			node->right=NULL;
			n->right=node;
			return;
		}
		else
		{
			insert(n->right, x);
		}	
	}

}

void inorder(tree* node)
{
	if(node==NULL)
	{
		return ;
	}
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);

}

void level_order(tree *node)
{
	qdata.push(node);
	qlevel.push(0);
	tree *n1 = new tree;
	n1 = qdata.front();
	int al=qlevel.front();
	while(!qdata.empty())
	{
		
		int level = al;
		while(level == al && !qdata.empty())
		{
			
			cout<<n1->data<<" ";
			qdata.pop();
			qlevel.pop();
			if(n1->left!=NULL)
			{
				qdata.push(n1->left);
				qlevel.push(al+1);
			}
			if(n1->right!=NULL)
			{
				qdata.push(n1->right);
				qlevel.push(al+1);
			}
			n1 = qdata.front();
			al=qlevel.front();
		}
		cout<<endl;
		
	}
}

int main()
{
	int x;
	cout<<"start insertion"<<endl;
	while(1)
	{
		cin>>x;
		if(x==-1)
		{
			break;
		}
		insert(root,x);
	}
	cout<<"inorder traversal"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"level order traversal "<<endl;
	level_order(root);
	cout<<endl;
	cout<<"delete nodes"<<endl;
	int i=0;
	while(1)
	{
		int value;
		cin>>value;
		if(value==-1)
		{
			break;
		}
		//handling the case when root data is the value to be deleted
		if(root->data==value)
		{
			if(root->left==NULL && root->right==NULL)
			{
				delete root;
			}
			else if(root->left==NULL)
			{
				tree *tmp =root;
				root=root->right;
				delete tmp;
			}
			else if(root->right==NULL)
			{
				tree *tmp = root;
				root=root->left;
				delete tmp;
			}
			else
			{
				int largest=lar_bst(root);
				del(root,largest);
				root->data=largest;
			}

		}
		else{
			del(root,value);
		}
		cout<<"tree after deletion "<<++i<<endl;
		inorder(root);
		cout<<endl;
		cout<<"level order traversal "<<endl;
		level_order(root);
		cout<<endl;
	}
	
}