#include <iostream>
using namespace std;
int a[100010], b[100010];
long long odda[100010], evena[100010];
long long oddb[100010], evenb[100010];
int main() {
	int n, q;
	cin >> n >> q; 
	a[0] = b[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(i % 2 == 0) {
			evena[i] += evena[i-1] + a[i];
			odda[i] = odda[i-1];
		} else {
			odda[i] += odda[i-1] + a[i];
			evena[i] = evena[i-1];
		}
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		if(i % 2 == 0) {
			evenb[i] += evenb[i-1] + b[i];
			oddb[i] = oddb[i-1];
		} else {
			oddb[i] += oddb[i-1] + b[i];
			evenb[i] = evenb[i-1];
		}
	}
	while(q--) {
		int x, l, r;
		long long ans = 0;
		long long sum1, sum2;
		sum1 = sum2 = 0;
		cin >> x >> l >> r;
		if(x == 1) {
			if(l % 2 == 0) {
				sum1 += evena[r] - evena[l-1];
				sum2 += oddb[r] - oddb[l];
			} else {
				sum1 += odda[r] - odda[l-1];
				sum2 += evenb[r] - evenb[l];
			}
		} else {
			if(l % 2 == 0) {
				sum1 += evenb[r] - evenb[l-1];
				sum2 += odda[r] - odda[l];
			} else {
				sum1 += oddb[r] - oddb[l-1];
				sum2 += evena[r] - evena[l];
			}
		}
		ans += sum1 + sum2;
		cout << ans << endl;
	}
	return 0;
}