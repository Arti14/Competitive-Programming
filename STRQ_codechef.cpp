#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

#define MAXN 1000010

char str[MAXN];

struct stNode {
	long long n[4][4];
	long long count[4];
};

stNode st[2100010];
map<char, int> nm;
map<int, vector<int> > al;

int getCharToInt(char c) {
	return nm[c];
}

void initializeNode(int index) {
	for(int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
		{
			st[index].n[i][j] = 0;
		}
	}
	//update prefixes
	for(int i = 0; i < 4; ++i) {
		st[index].count[i] = 0;
	}
}

void createST(int L, int R, int index) {
	if(L == R) {
		initializeNode(index);
		int i = getCharToInt(str[L]);
		st[index].count[i] = 1; 
		return;
	}
	int mid = L + (R - L) / 2;
	createST(L, mid, 2*index + 1);
	createST(mid+1, R, 2*index + 2);
	//combine nodes
	for(int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j)
		{
			st[index].n[i][al[i][j]] = st[2*index + 1].n[i][al[i][j]] + st[2*index + 2].n[i][al[i][j]];
		}
	}
	//calulate for intermediate substrings formed on combining two strings
	for(int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			st[index].n[i][al[i][j]] +=  st[2*index + 1].count[i] * st[2*index + 2].count[al[i][j]];
		}
	}
	//update prefixes
	for(int i = 0; i < 4; ++i) {
		st[index].count[i] = st[2*index + 1].count[i] + st[2*index + 2].count[i];
	}
}

stNode* getAns(int i, int j, int qs, int qe, int s, int e, int index) {
	if(qs <= s && qe >= e) {
		//cerr << st[index].n[i][j] << endl;
		return st + index;
	}
	if (e < qs || s > qe) {
		return NULL;
	}
	int mid = s + (e - s) / 2;
	stNode* leftChild = getAns(i, j, qs, qe, s, mid, 2*index + 1);
	stNode* rightChild = getAns(i, j, qs, qe, mid+1, e, 2*index + 2);

	if (leftChild == NULL) return rightChild;
	if (rightChild == NULL) return leftChild;

	stNode* ans = new stNode;
	
	ans->n[i][j] = leftChild->n[i][j] + rightChild->n[i][j];

	//calulate for intermediate substrings formed on combining two strings
	ans->n[i][j] +=  leftChild->count[i] * rightChild->count[j];
	
	//update prefixes
	ans->count[i] = leftChild->count[i] + rightChild->count[i];
	ans->count[j] = leftChild->count[j] + rightChild->count[j];
	return ans;
}

int main() {
	int Q, qs, qe;
	char a, b;
	nm['c'] = 0;
	nm['e'] = 1;
	nm['f'] = 2;
	nm['h'] = 3;

	for (int i = 0; i < 4; ++i) {
		vector<int> v;
		for (int j = 0; j < 4; ++j) {
			if (i != j) v.push_back(j);
		}
		al[i] = v;
	}

	scanf("%s", str);
	int len = strlen(str);
	createST(0, len - 1, 0);
	cin >> Q;
	while(Q--) {
		scanf("\n%c %c %d %d", &a, &b, &qs, &qe);
		qs--; qe--;
		int i = getCharToInt(a);
		int j = getCharToInt(b);
		//cerr << i <<" " << j << endl;
		stNode* ans = getAns(i, j, qs, qe, 0, len - 1, 0);
		printf("%lld\n", ans->n[i][j]);
	}
	return 0;
}