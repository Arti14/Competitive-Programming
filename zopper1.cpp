#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string wobbly(int first, int second, int n) {
	string a, b;
	//cout << first <<" " << second << endl;
	string temp ;
	a = (char)(first + '0');
	if(second <= first) {
		second--;
	}
	b = (char)(second + '0');
	//cout << a << " " << b << endl;
	for(int i = 0; i < n; i++) {
		temp += (i+1) % 2 == 1 ? a : b;

	}
	return temp;
}

int main() {
	int T, n, k;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		int first, second;
		if(k > 81) {
			cout << "-1" << endl;
			continue;
		}
		if(k % 9 == 0) {
			first = k / 9;
			second = 9;
		} else {
			first = k/9 + 1;
			second = k % 9;
		}
		string digit = wobbly(first, second, n);
		cout << digit << endl;
	}
	return 0;
}