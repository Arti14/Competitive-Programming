#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXSIZE 30001
int gem[MAXSIZE];
int dp[MAXSIZE][500];
bool used[MAXSIZE][250*2] = {};
int d;
int solve(int i, int j) {
    int jj = j-(d-250);
    if (i >= MAXSIZE) return 0;
    if (used[i][jj]) return dp[i][jj];
    used[i][jj] = true;
    int res;
    if (j == 1) {
        res = gem[i] + max(solve(i+j, j), solve(i+j+1, j+1));
    } else {
        res = gem[i] + max(max(solve(i+j-1, j-1), solve(i+j, j)), solve(i+j+1, j+1));
    }
    dp[i][jj] = res;
    return res;
}

int main() {
	int n;
	int pos;
	cin >> n >> d;
	for(int i = 0; i < MAXSIZE; i++) {
		gem[i] = 0;
	}
	for(int i = 0; i < MAXSIZE; i++) {
		for(int j = 0; j <= 500; j++) {
			dp[i][j] = -1;
		}
	}
	for(int i = 0; i < n; i++) {
		cin >> pos;
		gem[pos]++;
	}
	int ans = solve(d, d);
	cout << ans << endl;
}