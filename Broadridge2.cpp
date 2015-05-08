#include <iostream>
#include <map>
using namespace std;
#define MOD 1000000007
map < char, int > workers;
int main() {
	string s1, s2;
	int n, M;
	char c;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> c;
		if(workers.count(c) > 0) {
			workers[c] += 1;
		} else {
			workers[c] = 1;
		}
	}
	cin >> M;
	while(M--) {
		cin >> s2;
		long long ans = 1;
		for(int i = 0; i < 3; i++) {
			if(workers[s2[i]] > 0) {
				ans = (ans * workers[s2[i]]) % MOD;
			} else {
				ans = 0;
				break;
			}
		}
		if(ans != 0) {
			for(int i = 0; i < 3; i++) {
			   workers[s2[i]] -= 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}