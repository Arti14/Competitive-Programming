#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int index;
	int steps;
};

#define MAXLEN 100010
bool visited[MAXLEN];
vector < int > digIndex[10];
queue < Node > myq;
string str;
int bfs(int sIndex, int dIndex) {
	int tSteps = 0;
	Node n;
	n.index = sIndex;
	n.steps = 0;
	bool digitSeen[10] = { false };
	visited[0] = true;
	myq.push(n);
	while(!myq.empty()) {
		Node curr = myq.front();
		myq.pop();
		//cout << str[curr.index] << " " << curr.steps << endl;
		tSteps = curr.steps;
		if(curr.index == dIndex) {
			break;
		}

		int indx = str[curr.index] - '0';
		if (!digitSeen[indx]) {
			for(int i = 0; i < digIndex[indx].size(); i++) {
				if(curr.index == digIndex[indx][i] || visited[digIndex[indx][i]]) { 
					continue; 
				}
				visited[digIndex[indx][i]] = true;
				n.index = digIndex[indx][i];
				n.steps = tSteps + 1;
				myq.push(n);
			}
		}
		digitSeen[indx] = true;
		if(curr.index - 1 > 0 && !visited[curr.index - 1]) {
			visited[curr.index - 1] = true;
			n.index = curr.index - 1;
			n.steps = tSteps + 1;
			myq.push(n);
		}
		if(curr.index + 1 <= dIndex && !visited[curr.index + 1]) {
			visited[curr.index + 1] = true;
			n.index = curr.index + 1;
			n.steps = tSteps + 1;
			myq.push(n);
		}
	}
	return tSteps;
} 

int main() {
	cin >> str;
	int len = str.length();
	for(int i = 0; i < len; i++) {
		visited[i] = false;
	}
	for(int i = 0; i < len; i++) {
		int index = str[i] - '0';
		digIndex[index].push_back(i);
	}
	int steps = bfs(0, len-1);
	cout << steps << endl;
}