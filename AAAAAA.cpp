#include <iostream>
#include <string>
#include <cmath>

using namespace std;
char arr[500][500];
bool visited[500][500];

int queueLength(int i, int j, int n, int m) {
	visited[i][j] = true;
	if(i == n && j == m) {
		return 1;
	}
	int r = 0;
	int d = 0;
	if(i+1 <= n && !visited[i+1][j]) {
		r = queueLength(i+1, j, n, m) + 1;
	}
	if(j+1 <= m && !visited[i][j+1]) {
		d = queueLength(i, j+1, n, m) + 1;
	}
	return max(r, d);
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> arr[i][j];
				visited[i][j] = false;
			}
		}
		int maxLength = queueLength(0, 0, n-1, m-1);
		cout << maxLength << endl;
	}
}