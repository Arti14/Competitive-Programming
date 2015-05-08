#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int stringToInt(string s) {
	int res = 0;
	int powx = 1;
	int len = s.length();
	for (int i = len - 1; i >= 0; i--) {
		res += powx * (int) (s[i] - '0');
		powx *= 10;
	}
	return res;
}

int main() {
	int T, tcase = 0;
	string str;
	cin >> T;
	while (T--) {
		tcase++;
		cin >> str;
		int maxNum, minNum;
		int strAsNum = stringToInt(str);
		maxNum = strAsNum;
		minNum = strAsNum;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < str.length(); j++) {
				if (i == j) continue;
				if (i < j) {
					if (i == 0 && str[j] == '0') {
						continue;
					}
				}
				if (j < i) {
					if (j == 0 && str[i] == '0') {
						continue;
					}
				}
				string tempStr = str;
				tempStr[i] = str[j];
				tempStr[j] = str[i];
				strAsNum = stringToInt(tempStr);
				if (strAsNum > maxNum) {
					maxNum = strAsNum;
				}
				if (strAsNum < minNum) {
					minNum = strAsNum;
				}
			}
		}
		printf("Case #%d: %d %d\n", tcase, minNum, maxNum);
	}
	return 0;
}