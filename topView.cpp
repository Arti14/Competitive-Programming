#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
map <int, int> mymap;

Node* newNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

void topView(Node* root, int hd, int level) {
  if(root == NULL) {
    return;
  }
  if(mymap.count(hd) == 0) {
    mymap[hd] = level;
  }
  topView(root->left, hd-1, level+1);
  if(mymap[hd] == level) {
    cout << root->data << " ";
  }
  topView(root->right, hd+1, level+1);
  
}

void inorder(Node* root) {
  if(root == NULL) return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main() {
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  inorder(root);
  cout << endl;
  topView(root, 0, 1);
  cout << endl;
  return 0;
}