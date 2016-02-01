/*======================================================
# Author: whai
# Last modified: 2016-01-08 22:28
# Filename: b.cpp
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

const int N = 1e5 + 5;

vector<int> G[N];

int maxx[N];

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(maxx, 0, sizeof(maxx));
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].PB(v);
			G[v].PB(u);
		}
		for(int i = 1; i <= n; ++i) {
			maxx[i] = 1;
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < G[i].size(); ++j) {
				int v = G[i][j];
				if(v > i)
					maxx[v] = max(maxx[i] + 1, maxx[v]);
			}
		}
		LL ans = 0;
		for(int i = 1; i <= n; ++i) {
			//cout<<maxx[i]<<' '<<G[i].size()<<endl;
			ans = max(ans, (LL)maxx[i] * G[i].size());
		}
		cout<<ans<<endl;
	}
	return 0;
}
