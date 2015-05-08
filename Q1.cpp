#include <iostream>
#include <string>
using namespace std;
int main() {
	string s1, s2;
	int T;
	cin >> T;
	while(T--) {
		cin >> s1 >> s2;
		int arr1[26];
		for(int i = 0; i < s1.length(); i++) {
			int index = s1[i] - 'a';
			arr1[index] += 1;
		}
		bool flag = false;
		for(int i = 0; i < s2.length(); i++) {
			int index = s2[i] - 'a';
			if(arr1[index] > 0) {
				flag = true;
				break;
			}
		}
		if(flag) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}