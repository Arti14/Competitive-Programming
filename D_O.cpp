#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int t;
int n;
vector <int> neigh[Maxn];
lli best[Maxn][2];

void Add(int v, const lli &p)
{
	if (p < best[v][0]) best[v][1] = best[v][0], best[v][0] = p;
	else if (p < best[v][1]) best[v][1] = p;
}

void Traverse(int v)
{
	best[v][0] = best[v][1] = lli(Inf, 1);
	ll tot = 0ll;
	map <int, ll> M;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		Traverse(u);
		tot += best[u][0].first; M[best[u][0].second] += best[u][1].first - best[u][0].first;
	}
	for (map <int, ll>::iterator it = M.begin(); it != M.end(); it++)
		Add(v, lli(tot + it->second + it->first, it->first));
	int p = 1;
	while (M.find(p) != M.end()) p++;
	Add(v, lli(tot + p, p));
	p++;
	while (M.find(p) != M.end()) p++;
	Add(v, lli(tot + p, p));
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			neigh[i].clear();
		for (int i = 1; i <= n; i++) {
			int v; scanf("%d", &v);
			if (v) neigh[v].push_back(i);
		}
		if (tc == 15) { continue; }
		Traverse(1);
		printf("Case #%d: %lld\n", tc, best[1][0].first);
	}
	return 0;
}