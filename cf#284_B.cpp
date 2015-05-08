#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
map < string, string > mymap;
vector < string > p;
int main() {
	int n, m;
	string s1, s2;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> s1 >> s2;
		mymap[s1] = s1.length() <= s2.length() ? s1 : s2;
	}
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		p.push_back(s);
	}
	for(int i = 0; i < n; i++) {
		cout << mymap[p[i]] << " ";
	}
	cout << endl;
	return 0; 
}