#include <iostream>
using naemspace std;

struct tree{
	int data;
	tree *left;
	tree *right;
};

void deleteNode(tree *node){
	if(node->left!=NULL){
		deleteNode(node->left);
	}
	if(node->right!=NULL){
		deleteNode(node->right);
	}
	delete(node);

}

void balance_node(tree *node){
	if(node->left==NULL && node->right==NULL){
		return;
	}
	else if(node->left!=NULL && node->right!=NULL){
		balance_node(node->left);
		balance_node(node->right);
	}
	else{
		deleteNode(node);
	}

}

int main(){
	balance_node(root);
}