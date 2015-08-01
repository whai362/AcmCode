#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define PB push_back
const int N = 10;
int cnt[N];
int dye[N][N];
vector<int> G[N];

int dfs(int u, int p, int n){
	//cout<<u<<' '<<p<<' '<<cnt[u]<<endl;
	int ret = 0;

	if(u > n) return 1;
	
	if(p == G[u].size()){
		if(cnt[u] * 2 == G[u].size())
			return dfs(u + 1, 0, n);
		return 0;
	}

	//if((p - cnt[u]) * 2 > G[u].size()) return 0;

	int v = G[u][p];
	if(dye[u][v]) {
		return dfs(u, p + 1, n);
	}

	if(G[u].size() / 2 - cnt[u] > G[u].size() - p) return 0;
	
	dye[u][v] = dye[v][u] = 1;
	ret += dfs(u, p + 1, n);
	dye[u][v] = dye[v][u] = 0;

	if(cnt[u] + 1 <= G[u].size() / 2 && cnt[v] + 1 <= G[v].size() / 2){
		dye[u][v] = dye[v][u] = 1;
		++cnt[u];
		++cnt[v];
		ret += dfs(u, p + 1, n);
		dye[u][v] = dye[v][u] = 0;
		--cnt[u];
		--cnt[v];
	}
	
	return ret;
}

void gao(int n, int m){
	if(m % 2){
		puts("0");
		return ;
	}
	for(int i = 1; i <=n; ++i){
		if(G[i].size() % 2){
			puts("0");
			return ;
		}
	}
	int ans = dfs(1, 0, n);
	printf("%d\n", ans);
}
void init(int n){
	for(int i = 0; i <= n; ++i)
		G[i].clear();
	memset(cnt, 0, sizeof(cnt));
	memset(dye, 0, sizeof(dye));
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		init(n);
		for(int i = 0; i < m; ++i){
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].PB(v);
			G[v].PB(u);
		}
		gao(n, m);
	}
	return 0;
}
