/*======================================================
# Author: whai
# Last modified: 2015-10-23 16:08
# Filename: e.cpp
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
using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 105;

int a[N], b[N];

struct Edge {
	int to, cap, rev;
};

const int MAX_V = 405;
const int INF = 0x3f3f3f3f;

vector<Edge> G[MAX_V];

int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap) {
	G[from].PB((Edge) {to, cap, G[to].size()});
	G[to].PB((Edge) {from, 0, G[from].size() - 1});
}

void bfs(int s) {
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for(int i = 0; i < G[v].size(); ++i) {
			Edge &e = G[v][i];
			if(e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if(v == t) return f;
	for(int &i = iter[v]; i < G[v].size(); ++i) {
		Edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
	while (1) {
		bfs(s);
		if (level[t] < 0) return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f = dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
	return flow;
}

int ans[N][N];

bool used[N][N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int sum0 = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum0 += a[i];
	}

	int sum1 = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		sum1 += b[i];
	}

	for(int i = 1; i <= n; ++i) {
		add_edge(0, i, a[i]);
		add_edge(i, i + n, a[i]);
		used[i][i] = 1;
		ans[i - 1][i - 1] = a[i];
		add_edge(i + n, 2 * n + 1, b[i]);
	}
	
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(used[u][v]) continue;
		used[u][v] = used[v][u] = 1;
		ans[u - 1][v - 1] = a[u];
		ans[v - 1][u - 1] = a[v];
		add_edge(u, v + n, a[u]);
		add_edge(v, u + n, a[v]);
	}
	//for(int i = 0; i < n; ++i) {
	//	for(int j = 0; j < n; ++j) {
	//		cout<<ans[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}

	int flow = max_flow(0, 2 * n + 1);
	//cout<<flow<<endl;
	if(sum0 == sum1 && flow == sum0) {
		cout<<"YES"<<endl;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < G[i].size(); ++j) {
				Edge e = G[i][j];
				int u = i - 1;
				int v = e.to;
				if(v > n) v = v - n - 1;
				else v = v - 1;
				ans[u][v] -= e.cap;
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				cout<<ans[i][j]<<' ';
			}
			cout<<endl;
		}

	} else {
		cout<<"NO"<<endl;
	}

	return 0;
}
