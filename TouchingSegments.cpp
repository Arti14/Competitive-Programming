#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

vector < pair <int, int> > segments;
vector <int> uniqueSets;
bool cmp( const pair <int, int> &e1, const pair <int, int> &e2){
	if(e1.first == e2.first) {
		return e1.second < e2.second; 
	}
	return e1.first < e2.first;
}
int main() {
	int T, N;
	int x1, x2;
	int tcase = 0;
	//scanf("%d", &T);
    cin >> T;
	while(T--) {
		tcase++;
		int ans = 0;
		segments.clear();
		uniqueSets.clear();
		//scanf("%d", &N);
        cin >> N;
		for(int i = 0; i < N; i++) {
			//scanf("%d %d", &x1, &x2);
            cin >> x1 >> x2;
			segments.push_back(make_pair(x1, x2));
		}
		sort(segments.begin(), segments.end(), cmp);
		int count = 1;
		for(int i = 1; i < segments.size(); i++) {
			if(segments[i].first > segments[i-1].second) {
				uniqueSets.push_back(count);
				count = 1;
			} else {
				count++;
			}
		}
		uniqueSets.push_back(count);
		sort(uniqueSets.begin(), uniqueSets.end());
        int s = uniqueSets.size();
		if(s == 1) {
			ans = N;
		} else {
			ans = uniqueSets[s-1] + uniqueSets[s-2];
		}
		//printf("Case %d: %d\n", tcase, ans);
        cout << "Case " << tcase << ": "<< ans << endl;
	}
	return 0;
}