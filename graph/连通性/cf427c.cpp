#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define LL __int64
#define PB push_back

const int N = 1e5 + 5;
const int MOD = 1000000007;
const LL INF = 1000000000000LL;

vector<int> G[N], rG[N];
vector<int> vs;
int belong[N];
bool used[N];
int V;

void dfs(int u) {
	used[u] = 1;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(used[v] == 0) dfs(v);
	}
	vs.PB(u);
}

void rdfs(int u, int k) {
	used[u] = 1;
	belong[u] = k;
	for(int i = 0; i < rG[u].size(); ++i) {
		int v = rG[u][i];
		if(used[v] == 0) rdfs(v, k);
	}
}

int scc() {
	fill(used, used + V, 0);
	vs.clear();
	for(int i = 0; i < V; ++i) {
		if(used[i] == 0) dfs(i);
	}

	fill(used, used + V, 0);
	int k = 0;
	for(int i = vs.size() - 1; i >= 0; --i) {
		int u = vs[i];
		if(used[u] == 0) rdfs(u, k++);
	}
	return k;
}

LL C[N];
int cnt[N];
LL minn[N];
int main() {
	int n;
	scanf("%d", &n);
	V = n;
	for(int i = 0; i < n; ++i)
		scanf("%I64d", &C[i]);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		G[u].PB(v);
		rG[v].PB(u);
	}

	int scc_tot = scc();
	fill(minn, minn + scc_tot + 1, INF);
	for(int i = 0; i < V; ++i) {
		minn[belong[i]] = min(minn[belong[i]], C[i]);
	}
	for(int i = 0; i < V; ++i) {
		if(minn[belong[i]] == C[i]) ++cnt[belong[i]];
	}

	LL ans_c = 0, ans_m = 1;
	for(int i = 0; i < scc_tot; ++i) {
		ans_c += minn[i];
		ans_m = ans_m * cnt[i] % MOD;
	}
	cout<<ans_c<<' '<<ans_m<<endl;
	return 0;
}
