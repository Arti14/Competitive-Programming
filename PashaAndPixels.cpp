#include <iostream>
using namespace std;
bool arr[1000][1000];
int main() {
	int n, m, k;
	int x, y;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			arr[i][j] = false;
		}
	}
	int i;
	bool flag = false;
	for(i = 0; i < k; i++) {
		cin >> x >> y;
		x--; y--;
		arr[x][y] = true;
		if(arr[x-1][y] && (x-1) >= 0) {
			if(arr[x-1][y-1] && arr[x][y-1] && y-1 >= 0) {
				flag = true;
				break;
			}
			if(arr[x-1][y+1] && arr[x][y+1] && y+1 < m) {
				flag = true;
				break;
			}
		} 
		if(arr[x+1][y] && (x+1) < n) {
			if(arr[x+1][y-1] && arr[x][y-1] && y-1 >= 0) {
				flag = true;
				break;
			}
			if(arr[x+1][y+1] && arr[x][y+1] && y+1 < m) {
				flag = true;
				break;
			}
		} 
	}
	if(flag) {
		cout << i+1; 
	} else {
		cout << "0";
	}
	cout << endl;
	return 0;
}