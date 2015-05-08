#include <iostream>
#include <cstdio>
using namespace std;
int chefDiv[505][2];
int boyDiv[505][2];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, k, p;
		bool flag;
		scanf("%d%d%d", &n, &k, &p);
		for(int i = 0; i < k; i++) {
			scanf("%d%d", &chefDiv[i][0], &chefDiv[i][1]);
		}
		for(int i = 0; i < p; i++) {
			scanf("%d%d", &boyDiv[i][0], &boyDiv[i][1]);
		}
		for(int i = 0; i < p; i++) {
			flag = false;
			for(int j = 0; j < k; j++) {
				if(boyDiv[i][0] == chefDiv[j][0]) {
					flag = true;
					break;
				}
			}
			if(!flag) {
				break;
			}
		}
		if(flag) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << endl;
	}
	return 0;
}