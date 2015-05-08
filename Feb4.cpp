#include <iostream>
#include <algorithm>
using namespace std;

int arr[2050], N, K;
int sortedArr[2050][2050];

int binarySearch(int v, int pos) {
	int l = 0, u = N - pos - 1, m;
	if (sortedArr[pos][0] > v) {
		return 0;
	}

	while (l + 1 < u) {
		m = (l + u) / 2;
		if (sortedArr[pos][m] <= v) {
			l = m;
		} else {
			u = m - 1;
		}
	}
	if (sortedArr[pos][u] <= v) {
		return u + 1;
	}
	return l + 1;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			sortedArr[i][j - i] = arr[j];
		}
		sort(sortedArr[i], sortedArr[i] + N - i);
		for (int j = i; j < N; ++j) {
			cout << sortedArr[i][j - i] << " ";
		}
		cout << "\n";
	}

	long long res = 0;
	long long F;
	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			int k = j + 1;
			F = arr[i] * arr[j];
			if (F > K) { continue; }
			res += binarySearch (K / F, k);
		}
	}
	cout << res << "\n";
	return 0;
}