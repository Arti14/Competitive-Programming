#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
int main() {
    int n, M, T;
    cin >> T;
    while(T--) {
        cin >> n >> M;
        ll x, prefix = 0;
        ll maxS = 0;
        set < ll > s;
        set < ll > :: iterator it;
        s.insert(0);
        for(int i = 0; i < n; i++) {
            cin >> x;
            prefix = (prefix + x) % M;
            maxS = max(maxS, prefix);
            it = s.lower_bound(prefix + 1);
            if(it != s.end()) {
                maxS = max(maxS, (prefix - (*it) + M));
            }
            s.insert(prefix);
        }
        cout << maxS << endl;
    }
    return 0;
}