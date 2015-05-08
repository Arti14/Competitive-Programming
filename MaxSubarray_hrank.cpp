#include <iostream>
using namespace std;
int main() {
	int T;
	int a[100005];
	cin >> T;
	while(T--) {
		int n;
		long long maxC = 0;
		long long maxNC = 0;
		long long temp = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		maxC = a[0];
		maxNC = 0;
		temp = a[0];
		for(int i = 1; i < n; i++) {
			temp += a[i];
			if(temp > maxC) {
				maxC = temp;
			}
			if(temp < 0) {
				temp = 0;
			}
		}
		int maxm = -10005;
		for(int i = 0; i < n; i++) {
			if(a[i] > 0) {
				maxNC += a[i];
			}
			if(maxm < a[i]) {
				maxm = a[i];
			}
		}
		if(maxNC == 0) {
			maxNC = (long long)maxm;
		}
		cout << maxC <<" " << maxNC << endl;
	}
	return 0;

}