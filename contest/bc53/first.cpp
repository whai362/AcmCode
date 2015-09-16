#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define PB push_back

const int N = 1005;

vector<int> G[N];
int dis[N];
int cnt[N];
void init(int n) {
	for(int i = 0; i <= n; ++i)
		G[i].clear();
	memset(dis, 0, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
}

void dfs(int u, int d, int fa) {
	dis[u] = d;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v, d + 1, u);
	}
}

bool gao(int n) {
	dfs(1, 0, -1);
	int maxx = 0;
	for(int i = 1; i <= n; ++i) {
		//cout<<dis[i]<<' ';
		++cnt[dis[i]];
		maxx = max(maxx, dis[i]);
	}
	//cout<<endl;
	for(int i = 0; i < maxx; ++i) {
		if(cnt[i] != 1) return false;
	}
	return true;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		init(n);
		for(int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].PB(v);
			G[v].PB(u);
		}
		if(gao(n)) puts("YES");
		else puts("NO");
	}
	return 0;
}
