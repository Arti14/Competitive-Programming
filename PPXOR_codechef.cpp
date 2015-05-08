#include <iostream>
using namespace std;

#define MAXM 100000
int preXOR[MAXM+1];
int arr[MAXM+1];
int c[MAXM+1][32]; //c[i][j] is total number of set bits in jth column of the sum (preXOR[0]+ preXOR[1] + preXOR[2] +...+ preXOR[i])
int main() {
	int T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		long long sum = 0;
		preXOR[0] = 0;
		for(int j = 0; j < 32; j++) {
			c[0][j] = 0;
		}
		arr[0] = 0;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i];
			preXOR[i] = preXOR[i-1] ^ arr[i];
			for(int j = 0; j < 32; j++) {
				c[i][j] = preXOR[i] & (1LL << j) ? 1 : 0;
				c[i][j] += c[i-1][j];
			}
		}
		for(int i = 1; i <= n; i++) {
			long long temp = 0;
			int nBit;
			for(int j = 0; j < 32; j++) {
				nBit = preXOR[i] & (1LL << j) ? (i - c[i-1][j]) : c[i-1][j]; //if jth bit of preXOR[i] is 1 then 
				temp += nBit * (1LL << j);
			}
			sum += temp;
		}
		cout << sum << endl;
	}
	return 0;
}