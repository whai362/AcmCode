#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

const int N = 1e5 + 5;

vector<int> G[N];

bool del[N];
int legs[N];

void dfs(int u, int fa = -1) {
	if(G[u].size() <= 2) {
		del[u] = true;
		for(int i = 0; i < G[u].size(); ++i) {
			int v= G[u][i];
			if(v == fa) continue;
			dfs(v, u);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].PB(v);
		G[v].PB(u);
	}
	for(int i = 1; i <= n; ++i) {
		if(G[i].size() == 1) dfs(i);
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < G[i].size(); ++j) {
			int u = i, v = G[i][j];
			if(del[v]) {
				legs[u] = min(legs[u] + 1, 2);
			}
		}
	}

	for(int i = 1; i <= n; ++i) {
		cout<<legs[i]<<' ';
	}
	cout<<endl;

	for(int i = 1; i <= n; ++i) {
		int cnt = 0;
		for(int j = 0; j < G[i].size(); ++j) {
			int u = i, v = G[i][j];
			if(!del[v] && G[v].size() - legs[v] > 1) {
				cout<<v<<endl;
				++cnt;
			}
			if(cnt > 2) {
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}
