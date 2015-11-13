/*======================================================
# Author: whai
# Last modified: 2015-10-27 16:42
# Filename: poj3436.cpp
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

struct Edge {
	int to, cap, rev;
};
const int MAX_V = 405;
const int INF = 0x3f3f3f3f;

vector<Edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from, int to, int cap) {
	G[from].PB((Edge) { to, cap, G[to].size()});
	G[to].PB((Edge) {from, 0, G[from].size() - 1});
}

void bfs(int s) {
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while(!que.empty()) {
		int v = que.front();
		que.pop();
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
		if(e.cap > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0) {
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
	while(1) {
		bfs(s);
		if(level[t] < 0) return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while((f = dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
	return flow;
}

int q[MAX_V], s[MAX_V][15], d[MAX_V][15];

bool ok(int u, int v, int p) {
	for(int i = 0; i < p; ++i) {
		if(s[v][i] == 0 && d[u][i] == 1) return false;
		if(s[v][i] == 1 && d[u][i] == 0) return false;
	}
	return true;
}

int ans[MAX_V][MAX_V];

int main() {
	int n, p;
	scanf("%d%d", &p, &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &q[i]);
		for(int j = 0; j < p; ++j) {
			scanf("%d", &s[i][j]);
		}
		for(int j = 0; j < p; ++j) {
			scanf("%d", &d[i][j]);
		}
	}

	int st = 0, en = n + 1;
	for(int i = 1; i <= n; ++i) {
		int flag = 1;
		for(int j = 0; j < p; ++j) {
			if(s[i][j] == 1) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			//cout<<st<<' '<<i<<endl;
			add_edge(st, i, q[i]);
		}
		flag = 1;
		for(int j = 0; j < p; ++j) {
			if(d[i][j] == 0) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			//cout<<i<<' '<<en<<endl;
			add_edge(i, en, q[i]);
		}
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			if(ok(i, j, p)) {
				//cout<<i<<' '<<j<<endl;
				add_edge(i, j, q[i]);
				ans[i][j] = q[i];
			}
		}
	}
	cout<<max_flow(st, en)<<' ';
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < G[i].size(); ++j) {
			Edge e = G[i][j];
			int u = i;
			int v = e.to;
			ans[u][v] -= e.cap;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(ans[i][j] > 0) ++cnt;
		}
	}
	cout<<cnt<<endl;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(ans[i][j] > 0) {
				cout<<i<<' '<<j<<' '<<ans[i][j]<<endl;
			}
		}
	}
	return 0;
}

