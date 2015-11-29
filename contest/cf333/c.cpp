/*======================================================
# Author: whai
# Last modified: 2015-11-25 01:18
# Filename: c.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 405;

const int INF = 0x3f3f3f3f;

bool used[N][N];

int dis[2][N];

vector<int> G[2][N];

void bfs(int id) {
	queue<int> q;
	q.push(1);
	dis[id][1] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < G[id][u].size(); ++i) {
			int v = G[id][u][i];
			if(dis[id][v] != INF) continue;
			q.push(v);
			dis[id][v] = dis[id][u] + 1;
		}
	}
}

void gao(int n, int m) {
	bfs(0);
	bfs(1);
	int ans = max(dis[0][n], dis[1][n]);
	if(ans == INF) puts("-1");
	else cout<<ans<<endl;
}

int main() {
	int n, m;
	
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(used, 0, sizeof(used));
		for(int i = 1; i <= n; ++i) {
			G[0][i].clear();
			G[1][i].clear();
		}
		memset(dis, 0x3f, sizeof(dis));
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			used[u][v] = used[v][u] = 1;
			G[0][u].PB(v);
			G[0][v].PB(u);
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				if(used[i][j]) continue;
				G[1][i].PB(j);
				G[1][j].PB(i);
			}
		}
		gao(n, m);
	}

	return 0;
}

