# include <cstdio>
# include <iostream>
# include <vector>
# include <set>
# include <queue>
using namespace std;

int G[501][501];

struct Node {
	int cost;
	int nodeId;
	int parentNodeId;
};

vector< vector<int> > parentNodeIdList;

class mycomparison {
  
public:
  bool operator() (const Node& lhs, const Node& rhs) const {
  	if (lhs.cost <= rhs.cost) {
		return false;
	}
	return true;
  }
};

void removeEdges(int nodeId) {
	if (nodeId == -1) {
		return;
	}

	for (int i = 0; i < parentNodeIdList[nodeId].size(); ++i) {
		// cout << nodeId <<  " " << parentNodeIdList[nodeId][i] << "\n";
	
		int parentNodeId = parentNodeIdList[nodeId][i];
		if (parentNodeId == -1 || G[parentNodeId][nodeId] == -1) {
			continue;
		}
		G[parentNodeId][nodeId] = -1;
		removeEdges(parentNodeId);
	}
}

int main() {
	
	for (int i = 0; i < 501; ++i) {
		vector<int> v;
		parentNodeIdList.push_back(v);
	}

	int V, E;
	while (1) {
		scanf("%d %d", &V, &E);
		int S, D;
		
		if (V == 0 && E == 0) {
			break;
		}

		scanf("%d %d", &S, &D);
		int Ux, Vx, C;

		// cout << S << " " << D << "\n";

		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				G[i][j] = -1;
			}
		}	

		for (int i = 0; i < E; ++i) {
			scanf("%d %d %d", &Ux, &Vx, &C);
			// cout << U << " " << V << " " << C << "\n";
			G[Ux][Vx] = C;
		}

		priority_queue <Node,vector<Node>,mycomparison> queue;

		Node startNode;
		startNode.cost = 0;
		startNode.parentNodeId = -1;
		startNode.nodeId = S;

		queue.push(startNode);

		int shortestPathLength[501];
		
		for (int i = 0; i < V; ++i) {
			parentNodeIdList[i].clear();
			shortestPathLength[i] = -1;
		}

		while (!queue.empty()) {
			Node node = queue.top();
			queue.pop();

			int nodeId = node.nodeId;
			int parentNodeId = node.parentNodeId;
			int cost = node.cost;

			if (shortestPathLength[nodeId] == -1) {
				shortestPathLength[nodeId] = cost;
				parentNodeIdList[nodeId].push_back(parentNodeId);
			} else {
				if (shortestPathLength[nodeId] == cost) {
					parentNodeIdList[nodeId].push_back(parentNodeId);
				}
				continue;
			}

			for (int childNodeId = 0; childNodeId < V; ++childNodeId) {
				if (G[nodeId][childNodeId] > 0) {
					Node newNode;
					newNode.nodeId = childNodeId;
					newNode.parentNodeId = nodeId;
					newNode.cost = cost + G[nodeId][childNodeId];

					queue.push(newNode);
				}
			}
		}

		// for (int i = 0; i < V; ++i) { 
			// cout << shortestPathLength[i] << " ";
		// }
		// cout << "\n";

		removeEdges(D);
	
		startNode.cost = 0;
		startNode.parentNodeId = -1;
		startNode.nodeId = S;

		queue.push(startNode);

		for (int i = 0; i < V; ++i) {
			shortestPathLength[i] = -1;
		}

		int secondShortestPath = -1;

		while (!queue.empty()) {
			Node node = queue.top();
			queue.pop();

			int nodeId = node.nodeId;
			int parentNodeId = node.parentNodeId;
			int cost = node.cost;

			if (nodeId == D) {
				secondShortestPath = cost;
				break;
			}
			if (shortestPathLength[nodeId] == -1) {
				shortestPathLength[nodeId] = cost;
			} else {
				continue;
			}

			for (int childNodeId = 0; childNodeId < V; ++childNodeId) {
				if (G[nodeId][childNodeId] > 0) {
					Node newNode;
					newNode.nodeId = childNodeId;
					newNode.parentNodeId = nodeId;
					newNode.cost = cost + G[nodeId][childNodeId];

					queue.push(newNode);
				}
			}
		}

		cout << secondShortestPath << "\n";
	}
	return 0;
}