#include <iostream>
#include <queue>
#include <vector>
using namespace std;


vector <int> edge;

struct Node {
	int cost;
	int vertex;
};

struct T {
	int edge1;
	int edge2;
	int cost;
};

class mycomparison {
  
public:
  bool operator() (const Node& lhs, const Node& rhs) const {
  	if (lhs.cost <= rhs.cost) {
		return false;
	}
	return true;
  }
};

vector <bool> visited;
vector < vector<Node> > graph;
vector <T> MST;
priority_queue <Node,vector<Node>,mycomparison> pq;


int MST_algo(Node node){
	pq.push(node);
	int minCost = 0;
	int edge1 = node.vertex;
	int edge2;
	while(!pq.empty()){
		int x = pq.top().vertex;
		int cost = pq.top().cost;
		pq.pop();
		if(!visited[x]){

			cout<<"popped node "<<x<<" "<<cost<<endl;
			minCost += cost;
			edge2 = x;
			visited[x]=true;
			for(int i=0;i<graph[x].size();i++){
				Node n;
				n.vertex = graph[x][i].vertex;
				n.cost = graph[x][i].cost;
				pq.push(n);
			}
			T t;
			t.edge1 = edge1;
			t.edge2 = edge2;
			t.cost = cost;
			cout<<"edge1 "<<edge1<<"edge2 "<<edge2<<"cost "<<cost<<endl;
			MST.push_back(t);
			edge1 = edge2;
		}


	}
	return minCost;

}
int main(){

	int V, E;
	cin>>V>>E;

	for (int i = 0; i < V; ++i) {
		vector<Node> edge;
		graph.push_back(edge);
	}
	Node n;
	for(int i=0;i<E;i++){
		int u, v, cost;
		cin>>u>>v>>cost;
		n.vertex = u;
		n.cost = cost;
		graph[v].push_back(n);
		n.vertex = v;
		n.cost = cost;
		graph[u].push_back(n);
	}
	
	for(int i=0;i<V;i++)
    {   
        visited.push_back(false);
    }
	Node startNode;
	startNode.vertex = 0;
	startNode.cost = 0;
	int mincost = MST_algo(startNode);
	cout<<"minimum cost for MST is "<<mincost<<endl;
	cout<<"MST is "<<endl;
	for(int i =0; i<MST.size(); i++){
		cout<<MST[i].edge1<<"-"<<MST[i].edge2<<" "<<MST[i].cost<<endl;
	}

}




