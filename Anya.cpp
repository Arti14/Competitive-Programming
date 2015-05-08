#include <iostream>
#include <map>
using namespace std;
map <int, int> mymap;
int main() {
	int m, r, t;
	int ghosts[300];
	int candles[300];
	bool flag = true;
	int index;
	cin >> m >> t >> r;	
	int ans = r;
	for(int i = 0; i < m; i++) {
		cin >> ghosts[i];
	}
	for(int i = 0; i < r; i++) {
		candles[i] = ghosts[0] - i;
		mymap[ghosts[0] - i - 1] = 1;
	}
	for(int i = 0; i < m; i++) {
		for(int k = 0; k < r; k++) { 
			if((candles[k] + t) <= ghosts[i]) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			break;
		}
		int c = 0;
		for(int k = 0; k < r && (i+1) < m; k++) {
			int key = ghosts[i+1] - c - 1;
			if((candles[k] + t) < ghosts[i+1] && mymap.count(key) == 0) {
				candles[k] = ghosts[i+1] - c;
				mymap[ghosts[i+1] - c - 1] = 1;
				ans++;
				c++;
			}
		}
	}
	if(flag) {
		cout << ans << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}