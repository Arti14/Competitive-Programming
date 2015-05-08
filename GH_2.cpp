#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool tmatrix[1025][1025];
int main() {
	int n;
	cin >> n;
	int ans;
	for(int i = 0; i <= (1 << (n - 1)); i++) {
		for(int j = 0; j <= i; j++) {
			bool x;
			cin >> x;
			tmatrix[i][j] = x;
			tmatrix[j][i] = !x;
		}
	}
	for(int i = (n-1); i > 0; i--) {
		int arr[1025];
		int index = 0;
		for(int j = 0; j <= (1 << (i - 1)); j += 2) {
			arr[index++] = tmatrix[j][j+1] ? j : j+1;
		}
		if(i == 1) {
			ans = arr[0];
		}
	}
	cout << ans << endl;
	return 0;
} 