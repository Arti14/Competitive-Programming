#include <iostream>
#include <string>
using namespace std;
string str;
int maxlength = 0;
bool finLongestPalindrome(int i, int j) {
	if(i > j) return 0;
	if(i == j) return 1;
	int ans = 0;
	if(str[i] == str[j]) {
		ans = finLongestPalindrome(i+1, j-1) + 2;
	} else {
		ans = max(finLongestPalindrome(i, j-1), finLongestPalindrome(i+1, j));
	}
	return ans;
}

int main() {
	cin >> str;
	int ans = finLongestPalindrome(0, str.length() - 1);
	cout << ans << endl;
	return 0;
}