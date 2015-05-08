#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

#define MAXSIZE 2000

struct Node{
	int bug;
	char gender;
};

vector < int > graph[MAXSIZE];
bool visited[MAXSIZE];
map < int, char > bugGender; 
stack < Node > myStack;
bool dfs(int n){
	Node nd;
	Node s;
	bool flag = true;
	nd.bug = n;
	nd.gender = 'M';
	myStack.push(nd);
	bugGender[n] = nd.gender;
	while(!myStack.empty()) {
		nd = myStack.top();
		myStack.pop();
		if(bugGender.count(nd.bug) > 0 && bugGender[nd.bug] != nd.gender) {
			//cout <<" bug " << nd.bug << " " << nd.gender << endl;
			flag = false;
			break;
		}
		if(visited[nd.bug]) {
			continue;
		}
		bugGender[nd.bug] = nd.gender;
		visited[nd.bug] = true;
		for(int i = 0; i < graph[nd.bug].size(); i++) {
			if(nd.bug == graph[nd.bug][i]) {
				continue;
			}
			char g = nd.gender == 'M' ? 'F' : 'M';
			s.bug = graph[nd.bug][i];
			s.gender = g;
			myStack.push(s);
		}
	}
	while(!myStack.empty()) {
		myStack.pop();
	}
	return flag;
}
int main() {
	int T;
	string st1, st2;
	int V, E;
	int u, v;
	st1 = "Suspicious bugs found!";
	st2 = "No suspicious bugs found!";
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		bool flag = true;
		bugGender.clear();
		scanf("%d %d", &V, &E);
		for(int k = 0; k < V; k++) {
			visited[k] = false;
			graph[k].clear();
		}
		for(int j = 0; j < E; j++) {
			scanf("%d %d", &u, &v);
			u--; v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for(int k = 0; k < V; k++) {
			if(visited[k]) {
				continue;
			}
			flag = flag & dfs(k);
			//cout << k << " " << flag << endl;
		}
		cout << "Scenario #" << i << ":" << endl;
		if(!flag) {
			cout << st1 << endl;
		} else {
			cout << st2 << endl;
		}
	}
	return 0;
}