/*======================================================
# Author: whai
# Last modified: 2015-11-12 13:27
# Filename: g.cpp
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
#include <fstream>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

int in[N];
vector<int> G[N];

set<int> que1, que2;
vector<int> ans;
vector<P> ans_e;

void init(int n) {
	for(int i = 0; i < n; ++i) {
		G[i].clear();
	}
	memset(in, 0, sizeof(in));
	que1.clear();
	que2.clear();
	ans.clear();
	ans_e.clear();
}

int main() {
#ifndef __WHAI__
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
#endif
	int n, m, k;
	while(scanf("%d%d%d", &n, &m, &k) != EOF) {
		init(n);
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].PB(v);
			++in[v];
		}
		for(int i = 1; i <= n; ++i) {
			if(in[i] == 0) {
				que1.insert(i);
			}
		}
		while(que1.size() > 0 || que2.size() > 0) {
			if(que1.size() > 0) {
				int maxx = *que1.rbegin();
				if(que2.size() > 0) {
					maxx = max(maxx, *que2.rbegin());
				}
				int now = *que1.begin();
				que1.erase(now);
				if(k <= 0 || now == maxx) {
					ans.PB(now);
					for(int i = 0; i < G[now].size(); ++i) {
						int v = G[now][i];
						--in[v];
						if(in[v] == 0) {
							que1.insert(v);
						}
					}
				} else {
					que2.insert(now);
					--k;
				}
			} else {
				int now = *que2.rbegin();
				que2.erase(now);
				ans_e.PB(P(ans.back(), now));
				ans.PB(now);

				for(int i = 0; i < G[now].size(); ++i) {
					int v = G[now][i];
					--in[v];
					if(in[v] == 0) {
						que1.insert(v);
					}
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
		}
		printf("%d\n", ans_e.size());
		for(int i = 0; i < ans_e.size(); ++i) {
			printf("%d %d\n", ans_e[i].X, ans_e[i].Y);
		}
	}
	return 0;
}
