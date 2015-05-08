#include <iostream>
using namespace std;
int main() {
	int T;
	unsigned long long L, D, S, C;
	cin >> T;
	while(T--) {
		bool flag = false;
		cin >> L >> D >> S >> C;
		if(S >= L) {
			cout << "ALIVE AND KICKING" << endl;
			continue;
		}
		for(int i = 2; i <= D; i++) {
			S = S + S*C;
			if(S >= L) {
				flag = true;
				break;
			}
		}
		if(flag) {
			cout << "ALIVE AND KICKING" << endl;
		} else {
			cout << "DEAD AND ROTTING" << endl;
		}
	}
}