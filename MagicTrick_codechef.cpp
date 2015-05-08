#include <iostream>
#include <string> 

using namespace std;
typedef unsigned long long ull;

ull L[1005];

/*void swap(int *begin, int *end) {	
	int *temp = begin;
	begin = end;
	end = temp;
}*/

ull fastMult(ull a, ull b, ull c) {
	if(b == 0) {
		return 0;
	}
	ull ret = fastMult(a, b >> 1, c);
	ret = (ret + ret) % c;
	if(b & 1) {
		ret = (ret + a) % c;
	}
	return ret;
}

int main() {
	int T, N;
	cin >> T;
	while(T--) {
		ull A, B, C;
		ull K = 0;
		ull D = 1;
		int dir = 1;
		int begin, end;
		string str;
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> L[i];
		}
		cin >> A >> B >> C;
		cin >> str;
		begin = 0;
		end = N-1;
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == 'R') {
				//swap(&begin, &end);
				int temp = begin;
				begin = end;
				end = temp;
				dir = dir * -1;
			} else if(str[i] == 'A') {
				K = K + A;
			} else {
				D = fastMult(D, B, C) % C;
				K = fastMult(K, B, C) % C;
			}
			ull ans = (fastMult(L[begin], D, C) + K) % C;
			begin = begin + dir;
			cout << ans << " ";
		}
		cout << endl;
	}
}