#include <iostream>
#include <string>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		string str;
		bool flag = 0;
		cin >> str;
		int len = str.length();
		for(int i = 0; i < len; i++) {
			if(str[i] == '1' && i+2 < len) {
				if(str[i+1] == '0' && str[i+2] == '1') {
					flag = 1;
					break;
				}
			} else if(str[i] == '0' && i+2 < len) {
				if(str[i+1] == '1' && str[i+2] == '0') {
					flag = 1;
					break;
				}
			} 
		}
		if(flag) {
			cout << "Good";
		} else {
			cout << "Bad";
		}
		cout << endl;
	}
	return 0;
}