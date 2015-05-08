#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

vector < map <int, int> > vecOfMaps;
map <int, int> arr;
map <int, int> :: iterator it;
int N;

int query_all() {
	int count = 0;
	bool flag;
    int s = arr.size();
	for(int i = 0; i < N; i++) {
        if(s > vecOfMaps[i].size()) continue;
		flag = true;
		for(it = arr.begin(); it != arr.end(); ++it) {
			if(vecOfMaps[i].count(it->first) <= 0 || vecOfMaps[i][it->first] < it->second) {
				flag = false;
				break;
			}
		}
		if(flag) count++;
	}
	return count;
}

int query_any() {
	int count = 0;
	bool flag;
	for(int i = 0; i < N; i++) {
		for(it = arr.begin(); it != arr.end(); ++it) {
			if(vecOfMaps[i].count(it->first) > 0) {
				count++;
				break;
			}
		}
	}
	return count;
}

int query_some(int K) {
	int count = 0;
	int temp_count = 0;
	bool flag;
	for(int i = 0; i < N; i++) {
		temp_count = 0;
		for(it = arr.begin(); it != arr.end(); ++it) {
			if(vecOfMaps[i].count(it->first) > 0) {
				temp_count += min(it->second, vecOfMaps[i][it->first]);
			}
		}
		if(temp_count > 0 && temp_count < K) {
			count++;
		}
	}
	return count;
}

int main() {
	int T, Q, M, K;
		int x;
		scanf("%d", &N);
		for(int i = 0; i < N; i++) {
			vecOfMaps.push_back(map<int,int>());
		}
		for(int i = 0; i < N; i++) {
			scanf("%d", &M);
			for(int j = 0; j < M; j++) {
				scanf("%d", &x);
				if(vecOfMaps[i].count(x) == 0) {
					vecOfMaps[i][x] = 1;
				} else {
					vecOfMaps[i][x] += 1;
				}
			}
		}
		scanf("%d", &Q);
		int q;
		while(Q--) {
			scanf("%d %d", &q, &K);
			arr.clear();
			for(int i = 0; i < K; i++) {
				scanf("%d", &x);
				arr[x] += 1;
			}
			int ans = 0;
			if(q == 1) {
				ans = query_all();
			} else if(q == 2) {
				ans = query_any();
			} else {
				ans = query_some(K);
			}
			printf("%d\n", ans);
		}
	return 0;
}