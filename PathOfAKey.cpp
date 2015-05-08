#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
Node* newNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
string findPath(Node* root, int key, string dir) {
  if(root == NULL) {
    return "";
  }
  string str;
  if(root->data == key) {
    return dir;
  }
  if(key < root->data) {
    str = findPath(root->left, key, "1");
  } else {
    str = findPath(root->right, key, "0");
  }
  if(str == "") {
    return "";
  } 
  return (dir + str);
}
void inorder(Node* root) {
  if(root == NULL) return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main() {
  Node *root = newNode(5);
  root->left        = newNode(3);
  root->right       = newNode(7);
  root->left->left  = newNode(2);
  root->left->right = newNode(4); 
  root->right->left  = newNode(6);
  root->right->right = newNode(8); 
  inorder(root);
  cout << endl;
  string str = findPath(root, 4, "");
  cout <<"\""<< str <<"\""<< endl;
  str = findPath(root, 8, "");
  cout <<"\""<< str <<"\""<< endl;
  str = findPath(root, 2, "");
  cout <<"\""<< str <<"\""<< endl;
  str = findPath(root, 10, "");
  cout <<"\""<< str <<"\""<< endl;
  str = findPath(root, 6, "");
  cout <<"\""<< str <<"\""<< endl;
  return 0;
}