#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n, x;
	int l[51], r[51];
	cin >> n >> x;
	for(int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	int curr = 1;
	int total = 0;
	for(int i = 0; i < n; i++) {
		while(curr + x <= l[i]) {
			curr += x;
		}
		total += r[i] - curr + 1;
		curr = r[i] + 1;
	}
	cout << total << endl;
	return 0;	
}