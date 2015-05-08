#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define MAX 200001

int T, N;
int arr[MAX];
int childCount[MAX];
long long K1[MAX];
long long K2[MAX];
int C[MAX];
vector<int> child[MAX];
long long delta[MAX];

void compute(int node) {
	//cerr << node << " ";
	while (true) {
	if (childCount[node] != 0) {
		break;
	}

	if (arr[node] != -1) childCount[arr[node]]--;
	
	if (child[node].size() == 0) {
		K1[node] = 1;
		C[node] = 1;
		K2[node] = 2;

		if (arr[node] != -1) {
			node = arr[node];
		} else {
			break;
		}
		continue;
	}

	long long K = 0;
	int d = child[node].size();
	K1[node] = K2[node] = C[node] = -1;
	for (int i = 0; i < d; ++i) {
		K += K1[child[node][i]];
	}
	for (int i = 1; i <= d + 1; ++i) {
		delta[i] = K + i;
	}

	for (int i = 0; i < d; ++i) {
		if (C[child[node][i]] <= d + 1) {
			delta[C[child[node][i]]] += (K2[child[node][i]] - K1[child[node][i]]);
		}
	}

	for (int i = 1; i <= d + 1; ++i) {
		if (K1[node] == -1) {
			K1[node] = delta[i];
			C[node] = i;
		}

		if (K1[node] > delta[i]) {
			K1[node] = delta[i];
			C[node] = i;
		}
	}

	for (int i = 1; i <= d + 1; ++i) {
		if (K2[node] == -1 && C[node] != i) {
			K2[node] = delta[i];
		}

		if (K2[node] > delta[i] && C[node] != i) {
			K2[node] = delta[i];
		}
	}

	if (arr[node] != -1) {
		node = arr[node];
		continue;
	} else {
		break;
	}
	}
}

int main() {
	cin >> T;
	for (int c = 1; c <= T; ++c) {
		cout << "Case #" << c << ": ";
		cin >> N;

		for (int i = 0; i < N; ++i) {
			scanf("%d", &arr[i]);
			arr[i]--;
			childCount[i] = 0;
		}
		// if (c < 20) {continue;}
		for (int i = 0; i < N; ++i) {
			if (arr[i] != -1) {
				childCount[arr[i]]++;
				child[arr[i]].push_back(i);
			}
		}

		for (int i = 0; i < N; ++i) {
			compute(i);
		}

		cout << K1[0] << "\n";
		for (int i = 0; i < N; ++i) {
			child[i].clear();
		}
	}
	return 0;
}