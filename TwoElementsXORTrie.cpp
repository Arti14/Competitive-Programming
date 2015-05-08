/* find two elements in an array whose XOR is maximum (using TRIE)*/
#include <iostream>
using namespace std;
struct Trie {
	Trie *edges[2];
};

Trie *head; 
int arr[100000];
int maxNum;

Trie *initializeNode() {
	Trie *n = new Trie;
	for(int i = 0; i <2; i++) {
		n->edges[i] = NULL;
	}
	return n;
}

void insertTrie(Trie *node, int pos, int num) {
	if(pos == 0) {
		return;
	}
	int bit = num & pos ? 1 : 0;
	Trie *n = node->edges[bit];
	if(n == NULL) {
		n = initializeNode();
		node->edges[bit] = n;
	}
	insertTrie(n, pos >> 1, num);
}z

void findMaxXOR(Trie *node, int pos, int num) {
	if(pos == 0) {
		return;
	}
	int bit = num & pos ? 1 : 0;
	int nbit = bit ^ 1;             //invert this bit so that (bit ^ inverted bit) = 1
	Trie *n = node->edges[nbit];
	if(n != NULL) {
		maxNum = maxNum | pos;
	} else {   //inverted bit is not present, check for original bit
		n = node->edges[bit];
	}
	findMaxXOR(n, pos >> 1, num);
}	

int main() {
	int N;
	int msb = 1;
	int maxm = 0;
	cin >> N;
	head = new Trie;
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		maxm = max(maxm, arr[i]);
	}
	int temp = maxm;
	while(temp >>= 1) {
		msb <<= 1;
	}
	//cout << "msb "<< msb << endl;
	for(int i = 0; i < N; i++) {
		insertTrie(head, msb, arr[i]);
	}
	for(int i = 0; i < N; i++) {
		maxNum = 0;
		findMaxXOR(head, msb, arr[i]);
		maxm = (maxm ,maxNum);
	}
	cout << maxm << endl;
	return 0;
}