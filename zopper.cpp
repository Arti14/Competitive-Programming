#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define SIZE 1000000 
int upper[SIZE];
int lower[SIZE];
int main() {
	int T, l;
	scanf("%d", &T);
	while(T--) {
		long long mins = 1;
		long long maxMin = 0;
		cin >> l;
		for(int i = 0; i < l-1; i++) {
			scanf("%d", &upper[i]);
		}
		for(int i = 0; i < l-1; i++) {
			scanf("%d", &lower[i]);
		}
		for(int i = 0; i < l-1; i++) {
			long long temp = mins + max(upper[i], lower[i]);
			mins++;
			if(temp > maxMin) {
				maxMin = temp;
			}
		}
		if(l == 2) {
			maxMin++;
		}
		cout << maxMin << endl;
	}
}