#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
	int x;
	int c;
};
vector < node > graph[100];
bool visited[100];
queue < node > myq;
bool dfs(int s, int d, int color) {
	int val = 0;
	visited[s] = true;
	if(s == d) {
		return 1;
	}
	for(int i = 0; i < graph[s].size(); i++) {
		node n = graph[s][i];
		if(!visited[n.x] && n.c == color) {
			val += dfs(n.x, d, color);
		}
	}
	return val;
}
int main() {
	int n, m, q;
	int a, b;
	node y;
	int u, v, c;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		u--; v--;
		y.x = v;
		y.c = c;
		graph[u].push_back(y);
		y.x = u;
		graph[v].push_back(y);
	}
	cin >> q;
	while(q--) {
		cin >> a >> b;
		a--; b--;
		int ans = 0;
		for(int color = 1; color <= 100; color++) {
			for(int j = 0; j < n; j++) {
				visited[j] = false;
			}
			ans += dfs(a, b, color);
		}
		cout << ans << endl;
	}
}