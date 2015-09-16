#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

const int N = 1e5 + 5;

int du[N];
vector<int> G[N];
int ans;

int dfs(int u) {
	int max1 = 0, max2 = 0;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		int d = dfs(v);
		if(d > max1) max1 = d;
		else if(d > max2) max2 = d;
	}
	ans = max(max1 + max2, ans);
	return max1 + 1;
}

void gao(int n) {
	dfs(1);
	cout<<ans<<endl;
}

void init(int n) {
	ans = 1;
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
