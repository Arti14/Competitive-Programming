#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long long x, y, x1, y1;
	int n;
	long long a[300];
	long long b[300];
	long long c[300];
	int ans = 0;
	cin >> x >> y >> x1 >> y1;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	long long p1, p2;
	for(int i = 0; i < n; i++) {
		p1 = (x * a[i]) + (y * b[i]) + c[i];
		p2 = (x1 * a[i]) + (y1 * b[i]) + c[i];
		if((p1 > 0 && p2 < 0) || (p1 < 0 && p2 > 0)) {
			ans++;
		}
	}
	cout << ans << endl;
}