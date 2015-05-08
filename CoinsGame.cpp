#include <iostream>
using namespace std;
int main() {
	int T;
	int tcase = 0;
	cin >> T;
	while(T--) {
		tcase++;
		int n, c, k;
		int ans = 0;
		int dist = 0;
		int extra = 0;
		cin >> n >> k >> c;
		if(k < n) {
			ans = (n-k) + c;
			cout << "Case #" << tcase << ":" << ans << endl;
			continue;
		}
		dist = n/k;
		if(c <= n*dist) {
			ans = c;
			cout << "Case #" << tcase << ":" << ans << endl;
			continue;
		}
		extra = n % k;
		ans = n*dist + (n-extra) + (c - n*dist);
		cout << "Case #" << tcase << ":" << ans << endl;
	}
	return 0;
}