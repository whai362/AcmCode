#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

const int N = 1e5 + 5;

int w[N];
vector<int> G[N];

void dfs(int u, int fa = -1) {
	
}

void gao(int n, int a, int k) {
	for(int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	LL ans = INF;
	for(int i = 0; i <= k; ++i)
		ans = max(ans, dp[1][i]);
	cout<<ans<<endl;
}

int main() {
	int n, a, k;
	while(scanf("%d%d%d", &n, &a, &k) != EOF) {
		gao(n, a, k);
	}
	return 0;
}
