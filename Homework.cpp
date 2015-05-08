#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAXM 10000005
vector <int> primes;
bool prime[MAXM];
int primacity[MAXM];

int main() {
	int T;
	int tcase = 0;
	cin >> T;
	for(int i = 0; i <= MAXM; i++) {
		prime[i] = true;
		primacity[i] = 0;
	}
	for(int i = 2; i <= MAXM; i++) {
		if(prime[i]) {
			primacity[i]++;
			for(int j = 2*i; j <= MAXM; j = j+i) {
				prime[j] = false;
				primacity[j]++;
			}
		}
	}
	while(T--) {
		tcase++;
		int a, b, k;
		cin >> a >> b >> k;
		int count = 0;
		for(int i = a; i <= b; i++) {
			if(primacity[i] == k) {
				count++;
			}
		}
		cout << "Case #" << tcase <<": "<< count << endl;
	}
	return 0;
}