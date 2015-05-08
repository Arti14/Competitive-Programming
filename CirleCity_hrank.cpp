#include <iostream>
#include <cmath>
#include <set>
using namespace std;

set<int> s;
int squares[50000];
int main() {
	int T;
	cin >> T;
	squares[0] = 0;
	for(int i = 1; i <= 50000; i++) {
		squares[i] = i*i;
		s.insert(squares[i]);
	}
	while(T--) {
		int r, k;
		int ans = 0;
		cin >> r >> k;
		for(int i = 0; i * i < r; i++) {
			int x = r - squares[i];
			if(s.count(x)) {
				ans++;
			}
		}
		ans = ans*4;
		if(k >= ans) {
			cout << "possible";
		} else {
			cout << "impossible";
		}
		cout << endl;
	}
	return 0;
}	