#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	char c ;
	cin >> str;
	int len = str.length();
	bool flag = true;
	string ans;
	for(int i = 0; i <= len; i++) {
		string temp;
		for(char c = 'a', j = 0; j < 26; j++, c = (char)(c + 1)) {
			flag = true;
			if(i == 0){
				temp = c + str.substr(0, len);
			}else if(i == len) {
				temp = str.substr(0, i) + c;
			} else {
				temp = str.substr(0, i) + c + str.substr(i, len-i);
			}
			//cout << temp <<" ";
			int end = temp.length() - 1;
			for(int k = 0; k < temp.length() / 2; k++, end--) {
				if(temp[k] != temp[end]) {
					flag = false;
					break;
				}
			}
			if(flag == true) {
				ans = temp;
				break;
			}
		}
		if(flag) {
			break;
		}
	}
	if(flag == true) {
		cout << ans << endl;
	} else {
		cout << "NA" << endl;
	}
	return 0;
}