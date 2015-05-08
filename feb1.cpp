#include <iostream>
using namespace std;
#define MAXM 1000001
int ans[MAXM];
int main() {
	int T;
	cin >> T;
	int primes[] = {2, 3, 5, 7};
	ans[0] = -1;
	for(int i = 1; i < MAXM; i++) {
		int count = 0;
		int maxc = MAXM;
		bool flag = false;
		for(int j = 0; j < 4; j++) {
			if(i == primes[j]) {
				maxc = 1;
				flag = true;
				break;
			} else if((i - primes[j]) > 0 && ans[i-primes[j]] > 0) {
				flag = true;
				count = ans[i-primes[j]] + 1;
				if(count < maxc) {
					maxc = count;
				}
			}
		}
		if(!flag) {
			ans[i] = -1;
		} else {
			ans[i] = maxc;
		}
	}
	while(T--) {
		int x;
		cin >> x;
		cout << ans[x] << endl;
	}
	return 0;
}