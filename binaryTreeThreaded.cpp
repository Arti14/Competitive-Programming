#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    bool isThreaded;
};

Node *newNode(int key) {
    Node *n = new Node;
    n->left = n->right = NULL;
    n->key = key;
    n->isThreaded = false;
    return n;
}

Node* createThreaded(Node *root) {
    if(!root->left && !root->right) {
        return root;
    } 
    Node *prev = NULL;
    if(root->left != NULL) {
        prev = createThreaded(root->left);
        if(prev != NULL) {
            cout << "prev data " << prev->key << endl;
            prev->right = root;
            prev->isThreaded = true;
        }
    }
    if(root->right != NULL) {
       return createThreaded(root->right);
    }
}

struct Node* leftMost(struct Node *n)
{
    if (n == NULL)
       return NULL;
 
    while (n->left != NULL)
        n = n->left;
 
    return n;
}

void inOrder(Node *root) {
    struct Node *cur = leftMost(root);
    while (cur != NULL)
    {
        cout << cur->key << " ";
 
        // If this node is a thread node, then go to
        // inorder successor
        if (cur-> isThreaded)
            cur = cur->right;
        else // Else go to the leftmost child in right subtree
            cur = leftMost(cur->right);
    }
}

int main() {
    /*       1
            / \
           2   3
          / \ / \
         4  5 6  7   */
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    createThreaded(root);
 
    cout << "Inorder traversal of creeated threaded tree is\n";
    inOrder(root);
    return 0;
}