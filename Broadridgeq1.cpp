#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define SIZE 100005

map < vector < int > , string > dinosaur;
int main() {
	int n, k, l, q, x;
	string name;
	cin >> n >> k >> l >> q;
	for(int i = 0; i < n; i++) {
		cin >> name;
		vector < int > v;
		for(int j = 0; j < k; j++) {
			cin >> x;
			v.push_back(x);
		}
		dinosaur[v] = name;
	} 
	while(q--) {
		vector < int > v;
		for(int j = 0; j < k; j++) {
			cin >> x;
			v.push_back(x);
		}
		if(dinosaur.count(v) > 0) {
			cout << dinosaur[v]; 
		} else {
			cout << "You cant fool me :P";
		}
		cout << endl;
	}
	return 0;
}