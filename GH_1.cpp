#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long compute(long long n) {
	long long ans = 0;
	if (n == 0) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	if (n == 3) {
		return 3;
	}

	if (n % 2 == 0) {
		ans = n / 2 * (n - 2) + n - 1;
	} else {
		ans = n + (n - 3) / 2 * (n + 1);
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n; 
		cin >> n;
		if(n == 1) {
			cout << "1"<< endl;
			continue;
		}
		long long ans = 0;
		ans = compute(n);
		cout << ans << "\n";
	}
	return 0;
} 