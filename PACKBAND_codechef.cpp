#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define MAXM 1005
vector < pair < long long, long long > > arr;
int main() {
	int T;
	int n, m;
	long long length[MAXM];
	bool ans[MAXM];
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> length[i];
			length[i] = 7 * length[i];
		}
		sort(length, length + n);
		cin >> m;
		for (int i = 0; i < m; ++i){
			ans[i] = 0;
		}
		for(int i = 0; i < m; i++) {
			long long r1, r2; 	
			cin >> r1 >> r2;
			arr.push_back(make_pair(r2*11, r1*11));
		}
		sort(arr.begin(), arr.end());
		int count = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(length[i] >= arr[j].second && length[i] <= arr[j].first && ans[j] == 0) {
					ans[j] = 1;
					count++;
					break;
				}	
			}
		}
		cout << count << endl;
	}
	return 0;
}