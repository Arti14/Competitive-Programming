#include <iostream>
using namespace std;

struct listNode {
	int data;
	listNode* next;
};

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
 
Node* newNode(int data)
{
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

listNode* newNodeList(int data)
{
  listNode* node = new listNode;
  node->data = data;
  node->next = NULL;
  return(node);
}
int height(struct Node* node)
{
   if (node==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = height(node->left);
     int rheight = height(node->right);
 
     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
}
 
 
/* Print nodes at a given level */
void printGivenLevel(struct Node* root, int level, listNode** head, listNode** prev)
{
  if(root == NULL)
    return;
  if(level == 1){
  	//cout << root->data << " ";
  	listNode* n = newNodeList(root->data);
  	if(*head == NULL) {
  		*head = n;
  	} else {
  		(*prev)->next = n;
  	}
  	*prev = n;
  }
  else if (level > 1)
  {
    printGivenLevel(root->left, level-1, head, prev);
    printGivenLevel(root->right, level-1, head, prev);
  }
}
/* Function to print level order traversal a tree*/
void printLevelOrder(struct Node* root)
{
  int h = height(root);
  listNode* head[4] = {NULL};
  listNode* prev ;
  int i;
  for(i=1; i<=h; i++) {
  	head[i] = NULL; prev = NULL;
  	printGivenLevel(root, i, &head[i], &prev);
  	listNode* temp = head[i];
  	cout <<"list[" << i << "]" <<" : ";
  	while(temp != NULL) {
  		cout << temp->data <<" ";
  		temp = temp->next;
  	}
  	cout << endl;
  }
}     

int main()
{
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  root->right->left  = newNode(6);
  root->right->right = newNode(7); 
 
  cout <<"Linked list for each level" << endl;
  printLevelOrder(root);
  return 0;
}