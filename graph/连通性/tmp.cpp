#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e6 + 5;

#define PB push_back

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



int fr[N], to[N], e_tot;
int du[N];
int main() {
	int n;
	scanf("%d", &n);
	V = n;
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		--a;
		G[a].PB(i);
		rG[i].PB(a);
		fr[e_tot] = a;
		to[e_tot++] = i;
	}
	int scc_tot = scc();
	//cout<<scc_tot<<endl;
	for(int i = 0; i < e_tot; ++i) {
		int u = belong[fr[i]];
		int v = belong[to[i]];
		if(u == v) continue;
		++du[v];
	}

	int ans = 0;
	for(int i = 0; i < scc_tot; ++i)
		if(du[i] == 0) ++ans;
	cout<<ans<<endl;
	return 0;
}
