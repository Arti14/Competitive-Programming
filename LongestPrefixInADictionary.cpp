//Given a dictionary of words and an input string, find the longest prefix of the string which is also a word in dictionary.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node{
	bool isWord;
	Node* edge[26];
};
Node* root ;
string ans, temp;
Node* newNode() {
	Node* n = new Node;
	n->isWord = false;
	for(int i = 0; i < 26; i++) {
		n->edge[i] = NULL;
	}
	return n;
}

void insert(string s, int pos, Node* root) {
	if(pos == s.length()) {
		root->isWord = true;
		return;
	}
	int index = (int)(s[pos] - 'a');
	Node* n = root->edge[index];
	if(n == NULL) {
		n = newNode();
		root->edge[index] = n;
	}
	insert(s, pos+1, n);
}

void findLongestPrefix(Node* root, string s, int pos) {
	if(root->isWord) {
		ans = temp;
	}
	if(pos == s.length()) {
		return;
	}
	int index = (int) (s[pos] - 'a');
	if(!root->edge[index]) {
		return;
	} 
	temp = temp + s[pos];
	//cout << "temp: " << temp << endl;
	findLongestPrefix(root->edge[index], s, pos+1);
}

int main() {
	string sArray[7] = {"are", "area", "base", "cat", "cater", "children", "basement"};
	root = newNode();
	for(int i = 0; i < 7; i++) {
		insert(sArray[i], 0, root);
	}
	string input;
	while(true) {
		ans = "";
		temp = "";
		cin >> input;
		findLongestPrefix(root, input, 0);
		if(ans == "") {
			cout << "<empty>" ;
		} else {
			cout << ans ;
		}
		cout << endl;	
	}
	return 0;
}