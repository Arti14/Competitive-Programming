/*find sum of square of size of palindromic substrings in the word.  
For example, word "abaa" has 6 palindromic substrings. "aba","aa","a","b","a","a"*/
#include <iostream>
#include <string>
using namespace std;
int dp[1005][1005];
string s;

bool findPalnSub(int l, int r) {
	if(l > r) {
		return false;
	}
	if(l == r) {
		return true;
	}
	if(dp[l][r] != -1) {
		return dp[l][r];
	}
	if(l+1 == r && s[l] == s[r]) {
		dp[l][r] = 1;
		return true;
	}
	if(l+1 == r && s[l] != s[r]) {
		dp[l][r] = 0;
		return false;
	}
	bool flag = findPalnSub(l+1, r-1);
	findPalnSub(l, r-1);
	findPalnSub(l+1, r);
	if(s[l] == s[r] && flag) {
		dp[l][r] = 1;
	} else {
		dp[l][r] = 0;
	}
	return dp[l][r];
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> s;
		for(int i = 0; i < 1005; i++) {
			for(int j = 0; j < 1005; j++) {
				if(i == j) {
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] = -1;
			}
		}
		int len = s.length() - 1;
		long long ans = 0;
		findPalnSub(0, len);
		for(int i = 0; i <= len; i++) {
			for(int j = i; j <= len; j++) {
				//cout << dp[i][j] << " ";
				if(dp[i][j]) {
					ans += (j - i + 1) * (j - i + 1);
				}
			}
			//cout << endl;
		}
		cout << ans << endl;
	}
	return 0;
}