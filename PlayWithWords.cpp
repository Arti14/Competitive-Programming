#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int dp[3000][3000];

int func(string str, int i, int j) {
	if(i == j) {
		dp[i][j] = 1;
		return 1;	
	}
	if(dp[i][j] != 0) {
		return dp[i][j];
	}
	
	dp[i][j] = max(func(str, i+1, j), func(str, i, j-1));
	if (str[i] == str[j]) {
		if((i+1) == j) {
			dp[i][j] = 2;
		} else {
			dp[i][j] = func(str, i+1, j-1) + 2;
		}
	}

	return dp[i][j];
}

int main() {
	string str;
	int maxProd = 1;
	cin >> str;
	int len = str.length();
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			if(i != j) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = 1;
			}
			
		}
	}
	int maxLen = func(str, 0, len - 1);
	for(int i = 1; i < len; i++) {
		int p = dp[0][i-1]*dp[i][len-1];
		if(maxProd < p) {
			maxProd = p;
		}
	}
	cout << maxProd << endl;
    return 0;
}
