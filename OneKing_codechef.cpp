#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <utility>
using namespace std;
vector <pair <int, int > > arr;
vector <pair <int, int > > ans;

int main() {
	int T, N;
	scanf("%d", &T);
	while(T--) {
		vector <pair <int, int > > :: iterator it;
		vector <pair <int, int > > :: reverse_iterator rit;
		scanf("%d", &N);
		int x, y;
		arr.clear();
		ans.clear();
		for(int i = 0; i < N; i++) {
			scanf("%d %d", &x, &y);
			arr.push_back(make_pair(x, y));
		}
		sort(arr.begin(), arr.end());
		ans.push_back(arr[0]);
		rit = ans.rbegin();
		for(it = arr.begin()+1; it != arr.end(); ++it) {
			if(it->first <= rit->second) {
				rit->first = max(rit->first, it->first);
				rit->second = min(rit->second, it->second);
			} else {
				int a, b;
				a = it->first;
				b = it->second;
				ans.push_back(make_pair(a, b));
				rit = ans.rbegin();
			}
		}
		int result = 0;
		for(rit = ans.rbegin(); rit != ans.rend(); ++rit) {
			result++;
		}
		cout << result << endl;
	}
	return 0;
}