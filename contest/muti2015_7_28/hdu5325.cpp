#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define LL __int64
#define PB push_back
const int N = 5 * 1e5 + 5;
LL a[N];
int ans[N];
int deg[N];
vector<int> G[N];
queue<int> que;
void gao(int n) {
	for(int i = 1; i <= n; ++i) {
		ans[i] = 1;
		if(deg[i] == 0) {
			que.push(i);
		}
	}
	while(!que.empty()) {
		int now = que.front(); que.pop();
		for(int i = 0; i < G[now].size(); ++i) {
			int ch = G[now][i];
			--deg[ch];
			ans[ch] += ans[now];
			if(deg[ch] == 0) {
				que.push(ch);
			}
		}
	}
	int out = 0;
	for(int i = 1; i <= n; ++i)
		out = max(out, ans[i]);
	printf("%d\n", out);
}

void init(int n) {
	memset(deg, 0, sizeof(deg));
	for(int i = 0; i <= n; ++i)
		G[i].clear();
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		init(n);
		for(int i = 1; i <= n; ++i)
			scanf("%I64d", &a[i]);
		for(int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(a[u] < a[v]) swap(u, v);
			G[u].PB(v);
			++deg[v];
		}
		gao(n);
	}
	return 0;
}
