#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

map < string, string > handles;
map < string, string > :: iterator it;
int main() {
	int q;
	string oldh, newh;
	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> oldh >> newh;
		for(it = handles.begin(); it != handles.end(); ++it) {
			if(it->second == oldh) {
				it->second = newh;
				break;
			}
		}
		if(it == handles.end()) {
			handles[oldh] = newh;
		}
	}
	cout << handles.size() << endl;
	for(it = handles.begin(); it != handles.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}