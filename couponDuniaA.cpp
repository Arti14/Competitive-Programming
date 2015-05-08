#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int T;
	int a, b, c;
	cin >> T;
	while(T--) {
		cin >> a >> b >> c;
		int max1, max2, max3;
		if(a > b) {
			if(a > c) {
				max1 = a;
				max2 = max(b, c);
				max3 = min(b, c);
			} else {
				max1 = c;
				max2 = max(a, b);
				max3 = min(a, b);
			}
		} else {
			if( b > c) {
				max1 = b;
				max2 = max(a, c);
				max3 = min(a, c);
			} else {
				max1 = c;
				max2 = max(a, b);
				max3 = min(a, b);
			}
		}
		int ans = max2;
		if(max1 > max2) {
			ans += (max2+1);
		} else {
			ans += max2;
		}
		cout << ans << endl;
	}
	return 0;

}