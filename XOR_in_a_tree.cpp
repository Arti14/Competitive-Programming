#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 100010
#define MAXL 20

vector <int> adj[MAXN];
int a[MAXN], pos[MAXN], subTreeNodesCount[MAXN];
int par[MAXN][MAXL], pathXOR[MAXN], depth[MAXN];
bool visited[MAXN];
int m, l, n;

void DFS(int u) {
    visited[u] = true;
    subTreeNodesCount[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            pathXOR[v] = a[v] ^ pathXOR[u]; 
            depth[v] = depth[u] + 1;
            DFS(v);
            par[v][0] = u;
            subTreeNodesCount[u] += subTreeNodesCount[v];
        }
    }
    pos[u] = m; 
    m--;
}

struct segmentTree {
    int t[8*MAXN];
    void init() {
        for(int i = 0; i <= 8*n; i++) {
            t[i] = 0;
        }
    }

    void lazyPropogation(int node, int s, int e) {
        if(s <= e) {
            t[node*2] = t[node*2] ^ t[node];
            t[node*2 + 1] = t[node*2 + 1] ^ t[node];
            t[node] = 0;
        }
    }

    void update(int node, int s, int e, int l, int r, int xorVal) {
        lazyPropogation(node, s, e);
        if(e < l || s > r) {
            return;
        }
        if(s >= l && e <= r) {
            t[node] ^= xorVal;
            return;
        }
        int mid = (e + s)/2;
        update(node*2, s, mid, l, r, xorVal);
        update(node*2 + 1, mid + 1, e, l, r, xorVal);
    }

    void xorRange(int l, int r, int xorVal) {
        update(1, 1, n, l, r, xorVal);
    }

    void getXORValue(int node, int s, int e, int pos, int &res) {
        lazyPropogation(node, s, e);
        if(e < pos || s > pos) {
            return;
        }
        if(e == s) {
            res = t[s];
            return;
        }
        int mid = (s + e) / 2;
        getXORValue(node*2, s, mid, pos, res);
        getXORValue(node*2 + 1, mid + 1, e, pos, res);
    }

    int updatedXOR(int pos) {
        int res = 0;
        getXORValue(1, 1, n, pos, res);
        return res;
    }

} st;

void init() {
    scanf("%d", &n);
    int u, v;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        visited[i] = false;
        adj[i].clear();
    }
    for(int i = 1; i <= n-1; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    m = n;
    pathXOR[1] = a[1];
    depth[1] = 1;
    DFS(1);
    l = (int)(log(n) / log(2)) + 1;
    for(int j = 1; j <= l; j++) {
        for(int i = 1; i <= n; i++) 
            par[i][j] = par[par[i][j - 1]][j - 1];
    }
}

void jump(int &node, int height) {
    for(int i = l; i >= 0 ; i--) {
        if(height >= (1 << i)) {
            node = par[node][i];
            height -= (1 << i);
        }
    }
}

int findLCA(int u, int v) {
    if (depth[u] > depth[v]) jump(u, depth[u] - depth[v]); else jump(v, depth[v] - depth[u]);
    if (u == v) return u;
    for(int i = l; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i]; v = par[v][i];
        }
    }
    return par[u][0];
}

int main() {
    int T;
    int q;
    scanf("%d", &T);
    while(T--) {
        int u, v, op;
        init();
        st.init();
        scanf("%d\n", &q);
        while(q--) {
            scanf("%d %d %d", &op, &u, &v);
            if(op == 1) { //update a[u] to v
                int xorVal = a[u] ^ v;
                st.xorRange(pos[u], pos[u] + subTreeNodesCount[u] - 1, xorVal);
                a[u] = v;
            } else { //XOR of path from u to v
                int lca = findLCA(u, v);
                int ans = pathXOR[u] ^ pathXOR[v] ^ st.updatedXOR(pos[u]) ^ st.updatedXOR(pos[v]) ^ a[lca];
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
