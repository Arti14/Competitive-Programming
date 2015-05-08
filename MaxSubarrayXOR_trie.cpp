/*F(L, R) = XOR of subarray arr[L, l+1, l+2 ... R];
          = F(1, L-1) XOR F(1, R)
  insert F(1, i) in the trie and then check the max XOR that can be obtained using already inserted values (by finding max XOR of two elements)
*/
#include <iostream>
#include <cmath>
using namespace std;

#define MAXM 100000
int arr[MAXM];

struct Trie{
	Trie *edges[2];
};

Trie *head;
int maxXOR;

void insertInTrie(Trie *node, int num, int pos) {
	if(pos == 0) {
		return;
	}
	int bit = num & pos ? 1 : 0;
	Trie *n = node->edges[bit];
	if(n == NULL) {
		Trie *n = new Trie;
		for(int i = 0; i < 2; i++) {
			n->edges[i] = NULL;
		}
		node->edges[bit] = n;
	}
	insertInTrie(node->edges[bit], num, pos >> 1);
}

void findMaxXOR(Trie *node, int num, int pos) {
	if(pos == 0) {
		return;
	}
	int bit = num & pos ? 1: 0;
	int nbit = bit ^ 1;
	Trie *n = node->edges[nbit];
	if(n != NULL) {
		maxXOR = maxXOR | pos;
	} else {   //inverted bit is not present, check for original bit
		n = node->edges[bit];
	}
	findMaxXOR(n, num, pos >> 1);
}

void solve() {
	int N;
	int prev = 0;
	int maxBits = 1;
	int maxm = 0;
	int temp;
	int ans = 0;
	head = new Trie;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> arr[i]; 
		maxm = max(maxm, arr[i]);
	}
	temp = maxm;
	while(temp >>= 1) {
		maxBits <<= 1;
	}
	insertInTrie(head, prev, maxBits); //insert 0 in trie
	for(int i = 0; i < N; i++) {
		maxXOR = 0;
		prev = prev ^ arr[i];
		insertInTrie(head, prev, maxBits);
		findMaxXOR(head, prev, maxBits);
		ans = max(ans, maxXOR);
	}
	cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}