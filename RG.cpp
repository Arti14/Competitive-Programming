#include <iostream>
#include <algorithm>
using namespace std;
bool isA(long long v, int K, int P, int L, int U) {
	long long fl = v / K;
	if (fl - P <= L && fl + P >= U) {
		return false;
	}
	if (v % K) {
		fl++;
	}
	if (fl - P <= L && fl + P >= U) {
		return false;
	}
	return true;
}

int main() {
	int T, N, K, P;
	int arr[100010];

	cin >> T;
	while (T--) {
		cin >> N >> K >> P;
		for (int i = 0; i < N; ++i) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		long long val = 0;
		for (int i = 0; i < K; ++i) {
			val += arr[i];
		}
		bool can = isA(val, K, P, arr[0], arr[K - 1]);
		if (can) {
			for (int i = K; i < N; ++i) {
				val -= arr[i - K];
				val += arr[i];
				can = isA(val, K, P, arr[i - K + 1], arr[i]);
				if (!can) {
					break;
				}
			}
		}
		if (can) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}