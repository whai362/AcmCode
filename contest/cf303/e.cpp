/*======================================================
# Author: whai
# Last modified: 2015-10-26 21:01
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
#define P pair<LL, int>
#define X first
#define Y second
#define MP make_pair

const int N = 3 * 1e5 + 5;

struct edge {
	int to; LL cost; 
	edge() {}
	edge(int _to, LL _c) {
		to = _to;
		cost = _c;
	}
};
int V;
vector<edge> G[N];
LL d[N];
int pre[N];

const LL INF = 10000000000000000LL;

void dij(int s) {
	priority_queue< P, vector<P>, greater<P> > que;
	fill(d, d + V + 1, INF);

	d[s] = 0;
	que.push(P(0, s));
	while(!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.Y;
		if(d[v] < p.X) continue;
		for(int i = 0; i < G[v].size(); ++i) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

map< pair<int, int>, int > e_id;

int used[N];

LL minn[N];

int u[N], v[N], c[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	V = n;
	for(int i = 0; i < n; ++i) {
		minn[i] = INF;
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u[i], &v[i], &c[i]);
		if(u[i] > v[i]) swap(u[i], v[i]);
		G[u[i]].PB(edge(v[i], c[i]));
		G[v[i]].PB(edge(u[i], c[i]));
		e_id[MP(u[i], v[i])] = i;
	}
	int s;
	scanf("%d", &s);
	dij(s);
	
	//for(int i = 1; i <= n; ++i) {
	//	cout<<d[i]<<' '<<pre[i]<<endl;
	//}
	
	for(int i = 0; i < m; ++i) {
		int x = u[i], y = v[i];
		if(d[x] > d[y]) swap(x, y);
		if(d[x] + c[i] == d[y] && c[i] < minn[y]) {
			minn[i] = min((LL)c[i], minn[y]);
			pre[y] = x;
		}
	}

	for(int i = 1; i <= n; ++i) {
		int p = i;
		while(pre[p]) {
			int u = p;
			int v = pre[p];
			if(u > v) swap(u, v);
			int id = e_id[MP(u, v)];
			if(used[id]) break;
			used[id] = 1;
			p = pre[p];
		}
	}
	int cnt = 0;
	for(int i = 0; i < m; ++i) {
		if(used[i]) ++cnt;
	}
	cout<<cnt<<endl;
	for(int i = 0; i < m; ++i) {
		if(used[i]) {
			cout<<i + 1<<' ';
		}
	}
	cout<<endl;

	return 0;
}

