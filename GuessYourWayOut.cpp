#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int h;
	long long n;
	cin >> h >> n;
	int curHeight = 0;
	long long totalNodes = 0;
	long long leafNodes = 0;
	while(curHeight <= h && leafNodes != n) {
		int nodes = 1 << (h - curHeight - 1);
		if(((leafNodes + nodes) <= n) && nodes >= 0) {
			leafNodes += nodes;
			totalNodes += (1 << (h - curHeight)) - 1;
		} else {
			totalNodes++;
			curHeight++;
			cout << "totalNodes "<<totalNodes << " curHeight " << curHeight << endl;
		}
	}
	//totalNodes++;
	cout << totalNodes << endl;
	return 0;
}