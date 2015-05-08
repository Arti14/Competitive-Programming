#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MAXSIZE 100010
int arr[MAXSIZE];
int main() {
	int T;
	long long n;
	long long s;
	cin >> T;
	while(T--) {
		cin >> n >> s;
		int i;
		for(i = 1; i <= n; i++) {
			int remaining = n - i;
			if((s - i) >= (n - i)) {
				s = s - i;
			} else {
				break;
			}
		}
		cout << n - i + 1 << endl;
	}
}