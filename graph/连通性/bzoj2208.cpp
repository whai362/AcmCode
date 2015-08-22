#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

#define LL long long
#define PB push_back

const int N = 2005;

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

char str[N][N];

int cnt[N];

int fr[N * N], to[N * N], e_tot;

vector<int> tG[N];
int du[N];

int que[N], f, t;

bitset<N> dp[N];

int main() {
	int n;
	scanf("%d", &n);
	V = n;
	for(int i = 0; i < n; ++i) {
		scanf("%s", str[i]);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(str[i][j] == '1') {
				if(i == j) continue;
				G[i].PB(j);
				rG[j].PB(i);
				fr[e_tot] = i;
				to[e_tot++] = j;
			}
		}
	}

	int scc_tot = scc();

	for(int i = 0; i < V; ++i) {
		++cnt[belong[i]];
	}

	for(int i = 0; i < e_tot; ++i) {
		int v = belong[fr[i]];
		int u = belong[to[i]];
		if(u == v) continue;
		tG[u].PB(v);
		++du[v];
	}
	
	f = t = 0;
	for(int i = 0; i < scc_tot; ++i) {
		dp[i][i] = 1;
		if(du[i] == 0){
			que[t++] = i;
		}
	}

	while(f != t) {
		int u = que[f++];
		for(int i = 0; i < tG[u].size(); ++i) {
			int v = tG[u][i];
			--du[v];
			dp[v] |= dp[u];
			if(du[v] == 0) que[t++] = v;
		}
	}

	//for(int i = 0; i < scc_tot; ++i)
	//	cout<<dp[i]<<endl;

	LL ans = 0;
	for(int i = 0; i < scc_tot; ++i) {
		LL tmp = 0;
		for(int j = 0; j < scc_tot; ++j) {
			if(dp[i][j] == 1) {
				tmp += cnt[j];
			}
		}
		ans += cnt[i] * tmp;
	}

	cout<<ans<<endl;

	return 0;
}
