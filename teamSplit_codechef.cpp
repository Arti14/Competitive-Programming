#include <iostream>
#include <algorithm>
using namespace std;

#define Mod 1000000
typedef unsigned long long ull;
int s[1000005];

int main() {
	int T;
	cin >> T;
	while(T--) {
		ull totalDiff = 0;
		ull s1 = 0;
		ull s2 = 0;
		int a, b, c, d, N;
		for (int i = 0; i < Mod; ++i) s[i] = 0;
		cin >> N >> a >> b >> c >> d;
		ull prev = d;
		s[(int) prev]++;
		for(int i = 1; i < N; i++) {
			prev = (a * prev * prev + b * prev + c) % Mod;
			s[(int) prev]++;
		}
		bool first = true;
		for(int i = 0; i < Mod; i++) {
			while (s[i] != 0) {
				if (first) {
					s1 += i;
				} else {
					s2 += i;
				}
				s[i]--;
				first = !first;
			}
		}
		if(s1 > s2) {
			totalDiff = s1 - s2;
		} else {
			totalDiff = s2 - s1;
		}
		cout << totalDiff << endl;
	}
	return 0;
}