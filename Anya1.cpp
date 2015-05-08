#include <iostream>
using namespace std;
#define MAXM 1000
int main() {
	int m, r, t;
	int ghosts[MAXM];
	bool candles[MAXM];
	bool flag = true;
	int index;
	cin >> m >> t >> r;	
	int ans = 0;
	int count = 0;
	for(int i = 0; i < m; i++) {
		cin >> ghosts[i];
	}
	for(int i = 0; i < MAXM; i++) {
		candles[i] = 0;
	} 
	for(int i = 0; i < m; i++) {
		int j;
		for(j = 1, count = 0; j <= t && count != r; j++) {
			int m = ghosts[i] - j;
			if(m < 0) {
				m = MAXM + m;
			}
			if(candles[m]) {
				count++;
			}
		}
		for(j = 1; j <= t && count != r; j++) {
			int k = ghosts[i] - j;
			if(k < 0) {
				k = MAXM + k;
			}
			if(!candles[k]) {
				candles[k] = 1;
				count++;
			}
		}
		if(count != r) {
			flag = false;
			break;
		}
	}
	if(flag) {
		for(int i = 0; i < MAXM; i++) {
			ans += candles[i] ? 1 : 0;
		}
		cout << ans << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}