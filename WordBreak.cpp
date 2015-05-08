#include <iostream>
#include <string>
#include <map>
using namespace std;
map < string, int > dictionary;

bool wordBreak(int start, int end, string str) {
	if(end < start) {
		return false;
	}
	string s = str.substr(start, end - start + 1);
	cout <<"1 "<< s << endl;
	if(dictionary[s] > 0) {
		return true;
	}
	for(int i = start+1; i < end; i++) {
		s = str.substr(start, i-start);
		cout << "2 " << s << endl;
		if(dictionary[s] > 0 && wordBreak(i, end, str)) {
			return true;
		}
	}
	return false;
}

int main() {
	int n, q;
	string str;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> str;
		dictionary[str] = 1;
	}
	cin >> q;
	while(q--) {
		cin >> str;
		cout << "str " << str << endl;
		int len = str.length();
		bool found = wordBreak(0, len - 1, str);
		if(found) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}