#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    long long x;
    cin >> T;
    while(T--) {
        cin >> x;
        long long ans = 0;
        for(int i = 0; i < 32; i++){
            long long bit = x & (1 << i) ? 0 : 1;
            //cout <<bit << " ";
            if(bit) {
                ans = ans |(bit << i);
                //cout << ans << " ";
            }
        }
        cout << ans << endl;
    }
    return 0;
}
