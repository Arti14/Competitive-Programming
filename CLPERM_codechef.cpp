#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int missing[500010];
int main() {
	int T;
	long long n;
	int k, x;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %d", &n, &k);
		long long ans = 0;
		long long p;
		if(k == 0) {
			ans = ans + (n*(n+1)) / 2;
			if((ans+1) % 2 == 0) {
				cout << "Mom" << endl;
			} else {
				cout << "Chef" << endl;
			}
			continue;
		}
		for(int i = 0; i < k; i++) {
			scanf("%d", &missing[i]);
		}
		ans = 0;
		missing[k] = 0;
		missing[k + 1] = n + 1;
		sort(missing, missing + k + 2);
		long long mv, pmv, diff;
		for(int i = 1; i <= k + 1; i++) {
			mv = missing[i], pmv = missing[i - 1];
			diff = ((mv - 1) * mv - (pmv + 1) * pmv) / 2;
			ans += diff;
			if (ans < mv) {
				break;
			}
		}
		if((ans+1) % 2 == 0) {
			cout << "Mom" << endl;
		} else {
			cout << "Chef" << endl;
		}
	}
	return 0;
}