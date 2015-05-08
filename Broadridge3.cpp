#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	int T, n, k, l, r;
	int c[1005];
	string str, str1;
	cin >> T;
	while(T--) {
		map < int, int > countToIndexMap;
		map < int, int > :: iterator it;
		map < char, int > specialChar;
		cin >> n >> k >> l >> r;
		long long ans = 0;
		cin >> str >> str1;
		for(int i = 0; i < k; i++) {
			specialChar[str1[i]] = 1;
		}
		c[0] = 0;
		for(int i = 1; i <= n; i++) {
			if(specialChar.count(str[i-1]) > 0) {
				c[i] = c[i-1] + 1;
				countToIndexMap[c[i]] = i;
			} else {
				c[i] = c[i-1];
			}
		}
		/*cout << "cumu " << endl;
		for(int i = 1; i <= n; i++) {
			cout << i << " " << c[i] << endl;
		}
		cout << "map " << endl;
		for(it = countToIndexMap.begin(); it != countToIndexMap.end(); ++it) {
			cout << it->first << " " << it->second << endl;
		}*/
		int start;
		int count, a, b;
		int prev, next, num;
		for(it = countToIndexMap.begin(); it != countToIndexMap.end(); ++it) {
			if(it->first < l) {
				continue;
			} 
			start = it->second; //first index -> second count
			count = c[start] - l + 1;
			a = countToIndexMap[count];
			count = (c[start] - r) >= 0 ? c[start] - r + 1 : count;
			b = countToIndexMap[count];
			//cout << "a " << a << " b " << b; 
			int temp = a - b + 1;
			if(c[start] - r > 0) {
				prev = c[start] - r;
				next = c[start] - r + 1;
				if(countToIndexMap.count(next) > 0 && countToIndexMap.count(prev) > 0) {
					temp += countToIndexMap[next] - countToIndexMap[prev] - 1;
				}
			}
			//cout << " temp " << temp;
			if(countToIndexMap.count(c[start] + 1) > 0) {
				num = countToIndexMap[(c[start] + 1)] - start; 
			}  else {
				num = n - start + 1;
			}
			//cout << "num " << num << endl;
			ans = ans + temp*num;
		}
		cout << ans << endl;
	}
	return 0;
}