#include <iostream>
#include <cmath>
using namespace std;

int isPerfectSquare(long long n)
{
    int h = n & 0xF;  // h is the last hex "digit"
    if (h > 9)
        return 0;
    // Use lazy evaluation to jump out of the if statement as soon as possible
    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        int t = (int) floor( sqrt((double) n) + 0.5 );
        if(t*t == n) return 1;
    }
    return 0;
}

#define MAXM 1000000000
int main() {
	int T;
	long long l, r;
	cin >> T;
	while(T--) {
		cin >> l >> r;
		int ans = 0;
		long long next;
		for(next = l; next <= r; next++) {
			if(isPerfectSquare(next)) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}