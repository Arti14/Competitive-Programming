#include <iostream>
using namespace std;
#define MAXM 3000000

bool dp[10][MAXM];
int main() {
	int t, n, K;
	int arr[22];
	cin >> t;
	while(t--){
		cin >> n >> K;
		long long sum = 0;
		long long x;
		long long powN = 1LL << n;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		if(n < K || sum % K != 0) {
			cout << "no" << endl;
			continue;
		}
		if(sum == 0) {
			cout << "yes" << endl;
			continue;
		}
		x = sum / K;
		for(int i = 0; i <= K; i++) {
			for(long long j = 0; j < powN; j++) {
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		for(int k = 0; k <= K-1; k++) {
			for(long long bitmask = 0; bitmask < powN; bitmask++) {
				if(!dp[k][bitmask]) {
					continue;
				}
				sum = 0;
				for(int l = 0; l < n; l++ ){
					if(bitmask & (1LL << l)) {
						sum += arr[l];
					}
				}
				sum -= x * k;
				for(int l = 0; l < n; l++) {
					if(bitmask & (1LL << l)) {
						continue;
					}	
					//if current bit is not set we can include it our solution
					long long newmask = bitmask | (1LL << l);
					if(sum + arr[l] == x) {
						dp[k+1][newmask] = 1;
					} else if((sum + arr[l]) < x) {
						dp[k][newmask] = 1;
					}
				}
			}
		}
		if(dp[K][powN-1]) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0; 
}