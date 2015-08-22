#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

const int N = 10005;

vector<int> G[N], rG[N];
vector<int> vs;
int belong[N];
bool used[N];

int cnt[N];

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

int out[N], o_tot;

void init(int n) {
	V = n;
	for(int i = 0; i <= n; ++i) {
		G[i].clear();
		rG[i].clear();
	}
	fill(cnt, cnt + V, 0);
	o_tot = 0;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	init(n);

	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		G[u].PB(v);
		rG[v].PB(u);
	}

	int scc_cnt = scc();

	//cout<<scc_cnt<<endl;
	//for(int i = 0; i < V; ++i) {
	//	cout<<belong[i]<<' ';
	//}
	//cout<<endl;

	int u = 0;
	for(int i = 0; i < V; ++i) {
		++cnt[belong[i]];
		if(belong[i] == scc_cnt - 1) {
			u = i;
			out[o_tot++] = i + 1;
		}
	}

	int flag = 1;
	if(cnt[belong[u]] == 1) flag = 0;

	int ans = 0;
	for(int i = 0; i < V; ++i) {
		if(cnt[i] > 1) ++ans;
	}
	printf("%d\n", ans);
	
	fill(used, used + V, 0);
	rdfs(u, 0);
	
	for(int i = 0; i < V; ++i) {
		if(!used[i]) {
			flag = 0;
			break;
		}
	}
	if(flag) {
		for(int i = 0; i < o_tot; ++i) {
			printf("%d%c", out[i], i == o_tot - 1 ? '\n' : ' ');
		}
	} else {
		puts("-1");
	}
}
