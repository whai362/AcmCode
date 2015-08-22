#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

const int N = 10005;

vector<int> G[N];
vector<int> rG[N];
vector<int> vs;
bool used[N];
int cmp[N];

int V;

void dfs(int u) {
	used[u] = true;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(!used[v]) dfs(v);
	}
	vs.PB(u);
}

void rdfs(int u, int k) {
	used[u] = true;
	cmp[u] = k;
	for(int i = 0; i < rG[u].size(); ++i) {
		int v = rG[u][i];
		if(!used[v]) rdfs(v, k);
	}
}

int scc() {
	fill(used, used + V, 0);
	vs.clear();
	for(int i = 0; i < V; ++i)
		if(!used[i]) dfs(i);
	fill(used, used + V, 0);
	int k = 0;
	for(int i = vs.size() - 1; i >= 0; --i) {
		if(!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	V = n;
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		G[u].PB(v);
		rG[v].PB(u);
	}
	int scc_cnt = scc();
	int u = 0;
	int ans = 0;
	for(int i = 0; i < V; ++i) {
		if(cmp[i] == scc_cnt - 1) {
			u = i;
			++ans;
		}
	}

	fill(used, used + V, 0);
	rdfs(u, 0);
	for(int i = 0; i < V; ++i) {
		if(!used[i]) {
			ans = 0;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
