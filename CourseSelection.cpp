#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MX 105
#define INF 10000000

int M, N, K, S, T;
int X[MX][MX];
int A[MX], B[MX];
int d1[MX], d2[MX];
int prv[MX * MX];

struct Edge {
	int st, en, cap;

	Edge(int st, int en, int cap): st(st), en(en), cap(cap) {}
};

vector<int> adj[MX * MX];
vector< Edge > edges;

int hash(int semester, int course) {
	return course * M + semester;
}

void addEdge(int a, int b, int c) {
	adj[a].push_back(edges.size());
	edges.push_back(Edge(a, b, c));
	adj[b].push_back(edges.size());
	edges.push_back(Edge(b, a, 0));
}

int maxFlow() {
	int maxflow = 0, e, v, c, u, flow;
	while (1) {
		fill_n(prv, N * M + 2, -1);
		queue<int> q;
		q.push(S);
		prv[S] = -2;
		while (!q.empty()) {
			u = q.front();
			q.pop();
			if (u == T) {
				break;
			}

			for (int i = 0; i < adj[u].size(); ++i) {
				e = adj[u][i]; v = edges[e].en; c = edges[e].cap;
				if (c == 0 || prv[v] != -1) {
					continue;
				}
				q.push(v);
				prv[v] = e;
			}
		}

		if (prv[T] == -1) {
			break;
		}

		v = T;
		flow = INF;
		while (prv[v] != -2) {
			e = prv[v];
			u = edges[e].st;
			c = edges[e].cap;
			flow = min(flow, c);
			v = u;
		}
		maxflow += flow;
		v = T;
		while (prv[v] != -2) {
			e = prv[v];
			u = edges[e].st;
			edges[e].cap -= flow;
			edges[e ^ 1].cap += flow;
			v = u;
		}
	}
	return maxflow;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &X[i][j]);
		}
	}

	for (int i = 0; i < K; ++i) {
		scanf("%d %d", &A[i], &B[i]);
		A[i]--; B[i]--;
		d2[B[i]]++;
	}

	S = N * M;
	T = N * M + 1;
	int c;
	for (int i = 0; i < N; ++i) { // Loop over number of courses
		c = (X[i][0] == -1 || d2[i]) ? INF : (MX - X[i][0]);
		addEdge(S, hash(0, i), c);
		for (int j = 1; j < M; ++j) { // Loop over semesters
			c = (X[i][j] == -1) ? INF : (MX - X[i][j]);
			addEdge(hash(j - 1, i), hash(j, i), c);
		}
		addEdge(hash(M - 1, i), T, INF);
	}

	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			addEdge(hash(j, A[i]), hash(j + 1, B[i]), INF);
		}
	}
	int tot = MX * N;
	int res = tot - maxFlow();
	printf("%.2lf", res * 1.0 / N);
	return 0;
}