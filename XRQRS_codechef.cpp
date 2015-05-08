#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define MAXNUM 15

struct Trie {
	vector<int> indexes;
	Trie *edges[2];
};
Trie *head;
int y;
vector<int>::iterator low, up;
void insertInTrie(Trie *node, int arrayIndex, int num, int pos) {
	if(pos == 0) {
		return;
	}
	int bit = num & pos ? 1 : 0;
	Trie *n = node->edges[bit];
	if(n == NULL) {
		n = new Trie;
		for(int i = 0; i < 2; i++) {
			n->edges[i] = NULL;
		}
		node->edges[bit] = n;
	}
	n->indexes.push_back(arrayIndex);
	insertInTrie(n, arrayIndex, num, pos >> 1);
}

void findMaxXor(Trie *node, int L, int R, int x, int pos) {
	if(pos == 0) {
		return;
	}
	int bit = x & pos ? 1 : 0;
	int nbit = bit ^ 1;
	Trie *n = node->edges[nbit];
	if(n != NULL) {
		low = lower_bound((n->indexes).begin(), (n->indexes).end(), L);
		if(low != (n->indexes).end() && *low <= R) {
			y = y | pos;
		} else {
			n = node->edges[bit];
		}
	} else {
		n = node->edges[bit];
	}
	findMaxXor(n, L, R, x, pos >> 1);
}

void Delete(Trie *node, int currIndex) {
	if(node == NULL) {
		return;
	}
	int maxIndex = node->indexes.size() - 1;
	cout << "maxIndex " << maxIndex << endl;
	if(maxIndex >= 0) {
		if(node->indexes[maxIndex] <= currIndex) {
			return;
		}
		while(node->indexes[maxIndex] > currIndex) {
			(node->indexes).pop_back();
			maxIndex--;
		}
	}
	Delete(node->edges[0], currIndex);
	Delete(node->edges[1], currIndex);
}
int main() {
	int M;
	int queryType;
	int arrayIndex = 0;
	int x, L, R, k;
	int ans;
	int maxBits = 1;
	int temp = MAXNUM;
	head = new Trie;
	while(temp >>= 1) {
		maxBits <<= 1;
	}
	cin >> M;
	while(M--) {
		cin >> queryType;
		switch(queryType) {
			case 0: cin >> x;
					arrayIndex++;
					insertInTrie(head, arrayIndex, x, maxBits);
					break;
			case 1: cin >> L >> R >> x;
					y = 0;
					findMaxXor(head, L, R, x, maxBits);
					cout << (y ^ x) << endl;
					break;
			case 2: cin >> k;
					arrayIndex -= k;
					Delete(head, arrayIndex);
			default: break;
		}
	}
}