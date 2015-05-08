#include <iostream>
using namespace std;
int main() {
	int arr[10][10];
	int m, n;
	cin >> m >> n;
	int count = 1;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			arr[i][j] = count++;
		}
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int l = min(m, n);
	if(l % 2 != 0) {
		l = l/2 + 1;
	} else {
		l = l/2;
	}
	int i, j;
	for(int k = 0; k < l; k++) {
		i = k;
		for(j = k; j < n -k- 1; j++) {
			cout << arr[i][j] << " ";
		}
		j = n-k-1;
		for(i = k; i < m-k-1; i++) {
			cout << arr[i][j] << " ";
		}
		i = m - k - 1;
		for(j = n-k-1; j > k ; j--) {
			cout << arr[i][j] << " ";
		}
		j = k;
		for(i = m-k-1; i > k ; i--) {
			cout << arr[i][j] << " ";
		}
	}
	cout << endl;
	return 0;
}