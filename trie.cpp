/* has following 4 methods:
	1.) initilize():
	2.) addWord(word): adds word to the trie
	3.) countPrefixes(prefix): returns number of words having given prefix
	4.) countWords(): how many times this word occurs in the text
*/
#include <iostream>
using namespace std;

struct Trie {
	int word;
	int prefix;
	Trie *edges[26];
};
Trie *head;
string s;

Trie *initialzeNewNode() {
	Trie *n = new Trie;
	n->word = 0;
	n->prefix = 0; 
	for(int i = 0; i < 26; i++) {
		n->edges[i] = NULL;
	}
	return n;
}

void addWord(Trie *node, int pos) {
	if(pos == s.length()) {
		node->word++;
		return;
	}
	int index = (int)(s[pos] - 'a');
	Trie *n = node->edges[index]; 
	if(n == NULL) {
		//create a new node n
		n = initialzeNewNode();
		node->edges[index] = n;
	}
	n->prefix += 1;
	addWord(n, pos+1);
}

int countPrefixes(Trie *node, int pos) {
	if(pos == s.length()) {
		return node->prefix;
	}
	int index = (int)(s[pos] - 'a');
	if(node->edges[index] == NULL) {
		return 0;
	}
	return countPrefixes(node->edges[index], pos+1);
}

int countWords(Trie *node, int pos) {
	if(pos == s.length()) {
		return node->word;
	}
	int index = (int)(s[pos] - 'a');
	if(node->edges[index] == NULL) {
		return 0;
	}
	return countWords(node->edges[index], pos+1);
}

int main() {
	head = new Trie;
	int x;
	int n = 0;
	while(true) {
		cin >> x;
		switch(x) {
			case 1: cin >> s;
					addWord(head, 0);
					break;
			case 2: cin >> s;
					n = countPrefixes(head, 0);
                    cout << n << endl;
                    break;
            case 3: cin >> s;
            		n = countWords(head, 0);
            		cout << n << endl;
            		break;
            default: break;
		}
	}
	return 0;
}