#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define MAXN 65540

priority_queue < pair < int, int > > pq;
vector < int > adj[MAXN];
vector < pair < int, int > > ans;
int degree[MAXN];
int s[MAXN];

int main() {
	int n, di, si;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> di >> si;
		pq.push(make_pair(-di, i));
		degree[i] = di;
		s[i] = si;
	}
	while(!pq.empty()) {
		int vertex = pq.top().second;
		int dv = -pq.top().first;
		pq.pop();
		int sv = s[vertex];
		if(degree[vertex] == adj[vertex].size()) {
			continue;
		}
		for(int i = 0; i < adj[vertex].size(); i++) {
			sv = sv ^ adj[vertex][i];
		}
		adj[sv].push_back(vertex);
		adj[vertex].push_back(sv);
		ans.push_back(make_pair(vertex, sv));
		int newDeg = -(degree[sv] - adj[sv].size());
		pq.push(make_pair( newDeg, sv ));
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}