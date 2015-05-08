#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int dp[5005][5005];

bool isVowel(char c) {
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
		return true;
	}
	return false;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	//cout << s1 << " " << s2 << endl;
	for(int i = 0; i < len1; i++) {
		for(int j = 0; j < len2; j++) {
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i <= len1; i++) {
		for(int j = 1; j <= len2; j++) {
			dp[i][j] = dp[i - 1][j - 1];
			if(s1[i-1] == s2[j-1] &&  !isVowel(s1[i-1])) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}

			dp[i][j] = max(dp[i][j], dp[i][j-1]);
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= len1; i++) {
		for(int j = 1; j <= len2; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}