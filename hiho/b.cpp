#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

const int N = 1e5 + 5;

int du[N];
vector<int> G[N];
int ans = 0;

int dfs(int u, int depth) {
	ans = max(depth, ans);
	int maxx = 0;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		int dis = dfs(v, depth + 1);
		if(maxx > 0) ans = max(ans, depth + maxx + dis);
		maxx = max(maxx, dis);
	}
	return maxx + 1;
}

void gao(int n) {
	for(int i = 1; i <= n; ++i) {
		if(du[i] == 0){
			dfs(i, 0);
			break;
		}
	}
	cout<<ans<<endl;
}

void init(int n) {
	ans = 0;
	for(int i = 0; i <= n; ++i) {
		G[i].clear();
		du[i] = 0;
	}
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		init(n);
		for(int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].PB(v);
			++du[v];
		}
		gao(n);
	}
	return 0;
}
