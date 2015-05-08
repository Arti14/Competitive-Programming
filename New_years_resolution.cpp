#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int T;
	int N;
	int GP, GC, GF;
	int P[25], C[25], F[25];
	int tcase = 0;
	cin >> T;
	while(T--) {
		tcase++;
		bool flag = false;
		cin >> GP >> GC >> GF;
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> P[i] >> C[i] >> F[i];
		}
		int Pi, Ci, Fi;
		for(int i = 1; i < (1 << N); i++) {
			Pi = 0; Ci = 0; Fi = 0;
			for(int j = 0; j < N; j++) {
				if(i & (1 << j)) {
					Pi += P[j];
					Ci += C[j];
					Fi += F[j];
				}
			}
			if(Pi == GP && Ci == GC && Fi == GF) {
				flag = true;
				break;
			} 
		}
		cout << "Case #" << tcase << ": ";
		if(flag) {
			cout << "yes";
		} else {
			cout << "no";
		}
		cout << endl;
	}
	return 0;
}