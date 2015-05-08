#include <iostream>
#include <algorithm>
using namespace std;
#define MAXM 109
int main() {
	int n, k;
	int flower[MAXM], friends[MAXM];
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> flower[i];
	}
	sort(flower, flower + n);
	reverse(flower, flower + n);
	long long cost = 0;
	for(int i = 0; i < k; i++) {
		friends[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		int x = i % k;
		cost += (1 + friends[x]) * flower[i];
		friends[x]++;
	}
	cout << cost << endl;
	return 0;
}