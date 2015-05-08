#include <iostream>
#include <cstdio>
using namespace std;
int arr[200005];
int gcd[400005];

int fincGCD(int x,int y) {
	if (y!=0)
		return fincGCD(y,x%y);
	else
		return x;
}

int fincGCDInRange(int ss, int se, int qs, int qe, int index) {

	if(qs <= ss && qe >= se) {
		return gcd[index];
	}
	if(ss > qe || se < qs) {
		return 0;
	}
	int mid = (ss + se) / 2;
	return fincGCD(fincGCDInRange(ss, mid, qs, qe, 2*index+1), fincGCDInRange(mid+1, se, qs, qe, 2*index+2));
}

int createRangeTree(int ss, int se, int index){
	if(ss == se) {
		gcd[index] = arr[se];
		return arr[se];
	}
	int mid = (ss + se) / 2;
	gcd[index] = fincGCD(createRangeTree(ss, mid, 2*index + 1), createRangeTree(mid+1, se, 2*index+2));
	return gcd[index];
}

int main() {
	int T;
	int N, Q;
	int l, r;
	int ans;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &Q);
		for(int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		createRangeTree(0, N-1, 0);
		while(Q--) {
			scanf("%d %d", &l, &r);
			l--; r--;
			if(l == 0) {
				ans = fincGCDInRange(0, N-1, r+1, N-1, 0);
			} else if(r == N-1) {
				ans = fincGCDInRange(0, N-1, 0, l-1, 0);
			} else {
				ans = fincGCD(fincGCDInRange(0, N-1, 0, l-1, 0), fincGCDInRange(0, N-1, r+1, N-1, 0));
			}
			printf("%d\n", ans);
		}	
	}
	return 0;
};
