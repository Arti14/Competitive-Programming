#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int n, k, x;
	vector < pair <int, int > > arr;
	vector < int > indexes;
	vector < pair < int, int > > :: iterator it;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(make_pair(x, i+1));
	}
	sort(arr.begin(), arr.end());
	int total = 0;
	for(it = arr.begin(); it != arr.end(); ++it) {
		total += it->first;
		if(total > k) {
			break;
		}
		indexes.push_back(it->second);
	}
	sort(indexes.begin(), indexes.end());
	if(indexes.size() > 0) {
		cout << indexes.size() << endl;
		for(int i = 0; i < indexes.size(); ++i) {
			cout << indexes[i] << " ";
		}
	} else {
		cout << "0";
	}
	cout << endl;
}