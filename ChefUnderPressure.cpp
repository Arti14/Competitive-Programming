 #include <iostream>
 #include <vector>
 using namespace std;
 
 vector < vector < int > > city;
 
 #define MAX 10005
 
 static int dp[MAX][105];
 static int p[MAX];
 static bool visited[MAX];
 
 int* dfs(int x, int k) {
    if(visited[x]) {
        return NULL;
    }
    visited[x] = true;
    int pArr[105];
    for(int i = 0; i < k; i++) {
        pArr[i] = -1;
    }
    pArr[p[x]-1] = x; //product p is present in city i 
    for(int j = 0; j < city[x].size(); j++) {
        int *tempArr = dfs(city[x][j], k);
        for(int i = 0; i < k && tempArr != NULL; i++) {
            /*if(i == p[x] - 1) {
                continue;
            }*/
            if(tempArr[i] != -1) {
                if(pArr[i] > tempArr[i] || pArr[i] == -1) {
                    pArr[i] = tempArr[i];
                }
            }
        }
    }
    for(int i = 0; i < k; i++) {
        dp[x][i] = pArr[i];
    }
    return pArr;
 } 
 
 void dfs1(int x, int k, int parent) {
    if(visited[x]) {
         return;
    }
    visited[x] = true;
    if(parent != -1) {
        for(int i = 0; i < k; i++) {
            if(dp[x][i] == -1) {
                dp[x][i] = dp[parent][i];
            }
        }
    }
    for(int j = 0; j < city[x].size(); j++) {
        dfs1(city[x][j], k, x);
    }
 }
 
 int main() {
    int n, k, B, Q;
    cin >> n >> k;
    cin >> B;
    for(int i = 0; i < n; i++) {
        vector < int > edge;
        city.push_back(edge);
        visited[i] = false;
        for (int j = 0; j < k; ++j) dp[i][j] = -1;
    } 
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        city[x-1].push_back(y-1);
        city[y-1].push_back(x-1);
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    dfs(B-1, k);
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    dfs1(B-1, k, -1);
    cin >> Q;
    while(Q--) {
        int a, pr;
        cin >> a >> pr;
        if (dp[a - 1][pr - 1] == -1) {
            cout << "-1\n";
        } else {
            cout << dp[a-1][pr-1] + 1 << endl;
        }
    }     
    return 0;
 }
