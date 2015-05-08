#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
const int MAXL = 22;
vector<int> adj[MAXN];
int a[MAXN], subtree[MAXN], pos[MAXN], path_xor[MAXN], depth[MAXN];
int par[MAXN][MAXL];
bool visited[MAXN];
int n, m, l;
void DFS(int u) {
    visited[u] = true;
    subtree[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            path_xor[v] = path_xor[u] ^ a[v]; depth[v] = depth[u] + 1;
            DFS(v);
            subtree[u] += subtree[v]; par[v][0] = u;
        }
    }
    pos[u] = m; m--;
}
void init() {
    scanf("%d\n", &n);
    assert((1 <= n) && (n <= 100000));
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        assert((1 <= a[i]) && (a[i] <= (int)(1e9)));
        adj[i].clear();
    }
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d\n", &u, &v);
        assert((1 <= u) && (u <= n));
        assert((1 <= v) && (v <= n));
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) visited[i] = false;
    m = n;
    path_xor[1] = a[1]; depth[1] = 0;
    DFS(1);
    l = (int)(log(n) / log(2)) + 1;
    for(int j = 1; j <= l; j++) {
        for(int i = 1; i <= n; i++) par[i][j] = par[par[i][j - 1]][j - 1];
    }
}
struct segment_tree {
    int T[8 * MAXN];
    int n;
    void init(int _n) {
        n = _n;
        for(int i = 0; i <= 8 * n; i++) T[i] = 0;
    }
    void lazy_propagation(int node, int from, int to) {
        if (from < to) {
            T[node * 2] ^= T[node]; T[node * 2 + 1] ^= T[node];
            T[node] = 0;
        }
    }
    void update(int node, int from, int to, int l, int r, int val) {
        lazy_propagation(node, from, to);
        if ((from > r) || (to < l)) return;
        if ((from >= l) && (to <= r)) {
            T[node] ^= val;
            return;
        }
        int mid = (from + to) / 2;
        update(node * 2, from, mid, l, r, val);
        update(node * 2 + 1, mid + 1, to, l, r, val);
    }
    void get_val(int node, int from, int to, int pos, int &result) {
        lazy_propagation(node, from, to);
        if ((from > pos) || (to < pos)) return;
        if (from == to) {
            result = T[node];
            return;
        }
        int mid = (from + to) / 2;
        get_val(node * 2, from, mid, pos, result);
        get_val(node * 2 + 1, mid + 1, to, pos, result);
    }
    void xor_range(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }
    int get_xor(int x) {
        int res = 0;
        get_val(1, 1, n, x, res);
        return res;
    }
} ST;
void jump(int &u, int height) {
    for(int i = l; i >= 0; i--) {
        if (height >= (1 << i)) {
            u = par[u][i];
            height -= (1 << i);
        }
    }
}
int lca(int u, int v) {
    if (depth[u] > depth[v]) jump(u, depth[u] - depth[v]); else jump(v, depth[v] - depth[u]);
    if (u == v) return(u);
    for(int i = l; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i]; v = par[v][i];
        }
    }
    return par[u][0];
}
int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases --) {
        init();
        int q;
        scanf("%d\n", &q);
        assert((1 <= q) && (q <= 100000));
        ST.init(n);
        for(int i = 1; i <= q; i++) {
            int t, u, v;
            scanf("%d %d %d\n", &t, &u, &v);
            assert((1 <= t) && (t <= 2));
            assert((1 <= u) && (u <= n));
            if (t == 1) {
                assert((1 <= v) && (v <= (int)(1e9)));
                ST.xor_range(pos[u], pos[u] + subtree[u] - 1, a[u] ^ v);
                a[u] = v;
            }
            else {
                assert((1 <= v) && (v <= n));
                int c = lca(u, v);
                int res = path_xor[u] ^ path_xor[v] ^ ST.get_xor(pos[u]) ^ ST.get_xor(pos[v]) ^ a[c];
                printf("%d\n", res);
            }
        }
    }
}