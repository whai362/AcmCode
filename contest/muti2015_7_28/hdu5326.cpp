#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define PB push_back
const int N = 105;
int deg[N];
int cnt[N];

vector<int> G[N];

int dfs(int u) {
	//cout<<u<<endl;
	cnt[u] = 0;
	for(int i = 0; i < G[u].size(); ++i){
		int ch = G[u][i];
		cnt[u] += dfs(ch);
	}
	return cnt[u] + 1;
}

void gao(int n, int k){
	int rt;
	for(int i = 1; i <= n; ++i){
		if(deg[i] == 0){ rt = i; break; }
	}
	//cout<<rt<<endl;
	dfs(rt);
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		//cout<<cnt[i]<<' ';
		if(cnt[i] == k) ++ans;
	}
	//cout<<endl;
	printf("%d\n", ans);
}

void init(int n){
	memset(deg, 0, sizeof(deg));
	for(int i = 0; i <= n; ++i)
		G[i].clear();
}

int main() {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		init(n);
		int u, v;
		for(int i = 0; i < n - 1; ++i) {
			scanf("%d%d", &u, &v);
			G[u].PB(v);
			++deg[v];
		}
		gao(n, k);
	}
	return 0;
}
