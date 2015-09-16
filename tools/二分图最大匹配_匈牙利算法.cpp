/*poj 3692
  题意：
  已知班级有g个女孩和b个男孩，所有女生之间都相互认识，所有男生之间也相互认识，给出m对关系表示哪个女孩与哪个男孩认识。现在要选择一些学生来组成一个团，使得里面所有人都互相认识，求此团最大人数。
  限制：
  1 <= g,b <= 200; 0 <= m <= b*g
  思路：
  求最大团。
  最大独立集=|V|-最大匹配
  最大团=补图的最大独立集

  由题意可得，互相不认识的连边，构成一个二分图，ans=|V|-最大匹配，匈牙利算法。
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define PB push_back
const int MAX_V = 1005;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
void add_edge(int u, int v) {
	G[u].PB(v);
	G[v].PB(u);
}
bool dfs(int v) {
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		int u = G[v][i];
		int w = match[u];
		if (w < 0 || !used[w] && dfs(w)) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
int bi_match() {
	int res = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < V; ++v) {
		if (match[v] < 0) {
			memset(used, 0, sizeof(used));
			if (dfs(v)) ++res;
		}
	}
	return res;
}

int mp[205][205];
void init() {
	memset(mp, 0, sizeof(mp));
	for (int i = 0; i < MAX_V; ++i)
		G[i].clear();
}
int main() {
	int n, m, k;
	int cas = 0;
	while (scanf("%d%d%d", &n, &m, &k) && (n || m || k)) {
		init();
		V = n + m;
		int u, v;
		for (int i = 0; i < k; ++i) {
			scanf("%d%d", &u, &v);
			--u, --v;
			mp[u][v] = 1;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (mp[i][j] == 0) add_edge(i, j + n);
		printf("Case %d: ", ++cas);
		int ans = V - bi_match();
		printf("%d\n", ans);
	}
	return 0;
}
