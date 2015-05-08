#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int missing[100000];
int main() {
	int T;
	int n, k, p;
	cin >> T;
	while(T--) {
		scanf("%d %d %d", &n, &k, &p);
		bool flag = false;
		for(int i = 0; i < k; i++) {
			scanf("%d", &missing[i]);
		}
		sort(missing, missing + k);
		int count = missing[0] - 1;
		if(p <= count) {
			cout << p << endl;
			continue;
		}
		int diff, i = 1;
		for(; i < k; i++) {
			diff = (missing[i] - missing[i-1] - 1);
			if((count+diff) >= p) {
				cout << "1 "<< missing[i-1] + (p - count) << endl;
				flag = true;
				break;
			}
		}
		if(i == k) {
			diff == n - missing[k-1];
			if(count+diff >= p) {
				cout <<"2 "<< missing[k-1] + (p - count) << endl;
				flag = true;
			}
		}
		if(!flag) {
			cout << "-1" << endl;
		}
	}
	return 0;
}