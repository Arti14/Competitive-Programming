#include <iostream>
#include <cmath>
using namespace std;
bool dp[10][2097200];
int main() {
	int T;
	int n, k;
	long long arr[22];
	long long total = 0;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		total = 0;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			total += arr[i];
		}
		if(total % k != 0) {
			cout << "no" << endl;
			continue;
		}
		long long X = total / k;
		int val = 1 << n ;
		for(int i = 0; i <= k; i++) {
			for (int j = 0; j <= val - 1; j++) {
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		for(int i = 0; i <= k-1; i++) {
			for(int j = 0; j <= val-1; j++) {
				if(!dp[i][j]) {
					continue;
				}
				long long sum = 0;
				for(int l = 0; l <= n-1; l++) {//calculate total sum for this bit mask
					if(j & (1 << l)) { //lth bit is a set bit
						sum += arr[l];
					}
				}
				sum = sum - i*X;
				for(int l = 0; l <= n-1; l++) {
					if(j & (1 << l)) { //cant add it to bit mask as it is already set bit
						continue;
					}
					int newMask = j | (1 << l);
					if(sum + arr[l] == X) {
						dp[i+1][newMask] = 1;
					} else if ((sum + arr[l]) < X) {
						dp[i][newMask] = 1;
					}
				}
			}
		}
		if(dp[k][val-1]) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
}