#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define LOGMAX 20
#define MAXLEN 200010
#define MOD 1000000009
struct entry {
	int n[2];
	int p;
} L[MAXLEN], TL[MAXLEN];

int inverseRank[MAXLEN];
int height[MAXLEN];
int P[LOGMAX][MAXLEN];
int H[MAXLEN];
vector<int> v[MAXLEN + 1005];

int cmp(entry a, entry b) {
	return a.n[0] == b.n[0] ? (a.n[1] < b.n[1] ? 1 : 0) : (a.n[0] < b.n[0] ? 1 : 0); 
}

void sort(int N) {
	for (int i = 0; i < N; ++i) {
		v[L[i].n[1] + 1000].push_back(i);
	}
	int j = 0;
	for (int i = 0; i <= N + 1500; ++i) {
		for (int k = 0; k < v[i].size(); ++k) {
			TL[j++] = L[v[i][k]];
		}
		v[i].clear();
	}
	j = 0;
	for (int i = 0; i < N; ++i) {
		v[TL[i].n[0] + 1000].push_back(i);
	}
	for (int i = 0; i <= N + 1500; ++i) {
		for (int k = 0; k < v[i].size(); ++k) {
			L[j++] = TL[v[i][k]];
		}
		v[i].clear();
	}
}

void getHeight(int step, int N) {
	height[0] = 0;
	int h = 0;
	int rank = 0, j;
	for (int i = 0; i < N; ++i) {
		if (P[step][i] > 0) {
			rank = P[step][i];
			j = inverseRank[rank - 1];
			while (P[0][i + h] == P[0][j + h] && i + h < N && j + h < N) h++;
			height[rank] = h;
			if (h > 0) h--;
		}
	}
}

int LCP(int x, int y, int step, int N) {
	int count = 0;
	int powK;
	if (x == y) { return N - x; }
	for(int i = step; i >= 0 && x < N && y < N; i--) {
		if(P[i][x] == P[i][y]) {
			powK = 1 << i;
			count += powK;
			x += powK;
			y += powK;
		}
	}
	
	return count;
}
int main() {
	int T;
	int N;
	ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> N;
		long long ans = 0;
		for(int i = 0; i < N; i++) {
			cin >> H[i];
		}
		if(N == 1) {
			cout << ans << endl;
			continue;
		}
		if(N == 2) {
			cout << "1" << endl;
			continue;
		}
		N--;
		for(int i = 0; i < N; i++) {
			P[0][i] = H[i+1] - H[i];	
		}
		int step, count;
		for(step = 1, count	= 1; count < N; ++step, count = count*2) {
			for(int i = 0; i < N; i++) {
				L[i].n[0] = P[step-1][i];
				L[i].n[1] = (i+count) < N ? P[step-1][i+count] : -500;
				L[i].p = i;
			}
			
			// sort(L, L+N, cmp);
			sort(N);
			
			for(int i = 0; i < N; i++) {
				P[step][L[i].p] = i > 0 && L[i].n[0] == L[i-1].n[0] && L[i].n[1] == L[i-1].n[1] ? P[step][L[i-1].p] : i; 	
			}
		}
		for(int i = 0; i < N; i++) {
			inverseRank[P[step - 1][i]] = i;
		}

		getHeight(step - 1, N);
		long long oAns = 0;
		for (int j = 0; j < N; ++j) {
			oAns = (oAns + N - inverseRank[j] - height[j]) % MOD;
		}
		if (oAns < 0) { oAns += MOD; }
		/**
		int prevIndex = L[0].p;
		ans += N - prevIndex;
		for(int j = 1; j < N; j++) {
			int curr = L[j].p;
			ans = (ans + N - curr - LCP(prevIndex, curr, step-1, N)) % MOD;
			prevIndex = curr;
		}
		if (ans < 0) { ans += MOD; }
		*/
		cout << oAns << endl;
	}
	return 0;
}