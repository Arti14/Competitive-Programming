#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <utility>
using namespace std;

vector <pair <int, int > > V[100005];
map <int, int> mymap;

int findAns(int i) {
	sort(V[i].begin(), V[i].end());
	int ans = 1; 
	int last = V[i][0].first;
	for(int j = 1; j < V[i].size(); j++) {
		if(V[i][j].second >= last) {
			ans++;
			last = V[i][j].first;
		}
	}
	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int N, K;
		int pos = 0;
		int ans = 0;
		scanf("%d%d", &N, &K);
		mymap.clear();
		for(int i = 0; i < N; i++) {
			V[i].clear();
		}
		for(int i = 0; i < N; i++) {
			int s, f, p;
			scanf("%d%d%d",&s,&f,&p);
	    	p--;
			if(mymap.count(p) == 0) {
				mymap[p] = pos++;
			}
			V[mymap[p]].push_back(make_pair(f, s));
		}
		for(int i = 0; i < pos; i++) {
			ans += findAns(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}