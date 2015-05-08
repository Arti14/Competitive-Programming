//using stack and queue
struct tree{
	int val;
	tree* left;
	tree* right;
};

stack <tree> mystack1;
queue <tree> mystack2;
printAltLevel(tree*root){
	tree* m;
	m = root;
	int level = 1;
	mystack1.push(m);
	while(!mystack1.empty() || !mystack2.empty()){
		if(level%2 != 0){
			while(!mystack1.empty()){
				tree* node = mystack1.top();
				mystack1.pop();
				cout<<node->val<<" ";
				if (node->left != NULL){
					mystack2.push(node->left);
				}
				if(node->right != NULL){
					mystack2.push(node->right);
				}
			}
		} else {
			while(!mystack2.empty()){
				tree* node = mystack2.top();
				mystack2.pop();
				cout<<node->val<<" ";
				if (node->right != NULL){
					mystack1.push(node->right);
				}
				if(node->left != NULL){
					mystack1.push(node->left);
				}
			}
		}
		cout<<endl;
		level++;
	}
}