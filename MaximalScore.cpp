#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define MAXC 1000000000;
struct Node{
	int x, cost;
};
vector <vector< Node >> graph;
int maxm[1000];
bool visited[1000];

class mycomparison{
  public:
  
  bool operator() (const Node& lhs, const Node& rhs) const
  {
	if (lhs.cost >= rhs.cost) {
		return false;
	}
	return true;
  }
};

priority_queue < Node, vector < Node >, mycomparison > pq;

void findPath(int s){
	Node n;
	n.x = s;
	n.cost = MAXC;
	pq.push(n);
	while(!pq.empty()) {
		n = pq.top();
		pq.pop();
		if(visited[n.x]) {
			continue;
		}
		visited[n.x] = true;
		maxm[n.x] = n.cost;
		for(int i = 0; i < graph[n.x].size(); i++) {
			Node m = graph[n.x][i];
			if(visited[m.x]) {
				continue;
			}
			m.cost = min(n.cost, m.cost);
			pq.push(m);
		}
	}
	maxm[s] = 0;
}

int main() {
	int V, E;
	int u, v, w;
	ios_base::sync_with_stdio(false);
	Node n;
	cin >> V >> E;
	for(int i = 0; i < V; i++) {
		vector < Node > edge;
		graph.push_back(edge);
	}
	for (int i = 0; i < V; ++i){
		visited[i] = false;
	}
	for(int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		n.x = v;
		n.cost = w;
		graph[u].push_back(n);
		n.x = u;
		graph[v].push_back(n);
	}

	for(int i = 0; i < V; i++) {
		findPath(i);
		cout << maxm[0];
		visited[0] = false;
		for(int i = 1; i < V; i++) {
			visited[i] = false;
			cout << " " << maxm[i];
		}
		cout << "\n";
	}
	return 0;
}