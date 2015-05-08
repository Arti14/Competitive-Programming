#include <iostream>
using namespace std;
bool dp[1001][1024];
int main() {
    int T;
    int N, K;
    int arr[1005];
    cin >> T;
    while(T--) {
        cin >> N >> K;
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= 1023; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= 1023; j++) {
                //(j = v ^ arr[i] => j ^ arr[i] = v ^ arr[i] ^ arr[i] => j ^ arr[i] = v
                dp[i][j] = dp[i-1][j] || dp[i-1][j ^ arr[i-1]];
            }
        }
        int max = K;
        for(int j = 1; j <= 1023; j++) {
            int v = dp[N][j] * (j ^ K);
            if ( max < v) {
                max = v;
            }
        }
        cout << max << endl;   
    }
    return 0;
}
