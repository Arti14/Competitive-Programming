#include <iostream>
#include <string>
#include <map>

using namespace std;
map < int, bool > mymap;
int main() {
	string str;
	int count = 0;
	cin >> str; 
	for(int i = 2;i <= 9; i++ ) {
		mymap[i] = 1;
	}
	int len = str.length();
	for(int i = 0; i < len; i++) {
		int key = (int)(str[i] - '0');
		if(mymap[key]) {
			count = count*key;
		} else {
			count++;
		}
	}	
	cout << count << endl;
}