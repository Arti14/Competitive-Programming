#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    long long a, b;
    long long temp1, temp2;
    cin >> T;
    while(T--) {
        long long ans = 0;
        int len = 0;
        cin >> a >> b;
        temp1 = a;
        temp2 = b;
        while(temp2 >>= 1) {
            len++;
        }
        while(len) {
            long long bit = (1 << len);
            if((a & bit) == (b & bit)) {
                ans += (a & bit) ;
                len--;
                continue;
            }
            break;
        }
        cout << ans << endl;
    }
    return 0;
}
