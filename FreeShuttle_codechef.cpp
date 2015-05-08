#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		int cannot = 0;
		cin >> N;
		for(int i = 2; i <= N-1; i++) {
			if(N % i == 0) {
				cannot++;
			}
		}
		cout << N - 1 - cannot << endl;
	}
	return 0;
}