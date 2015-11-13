/*======================================================
# Author: whai
# Last modified: 2015-11-02 15:27
# Filename: d.cpp
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 2 * 1e5 + 5;
vector<int> G[N];

int a[N];

bool is_key[N];
int dis[N];
int f[N];
bool used[N];
bool in_r[N];

void dfs(int u, int d, int fa) {
	f[u] = fa;
	dis[u] = d;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v, d + 1, u);
	}
}

void init() {
	memset(dis, 0, sizeof(dis));
	memset(f, 0, sizeof(f));
}

int get_rt(int rt, int d, int n) {
	init();
	dfs(rt, 0, 0);
	int ret = N;
	for(int i = 1; i <= n; ++i) {
		if(is_key[i] && dis[i] == d) {
			ret = min(ret, i);
		}
	}
	return ret;
}

void gao(int n) {
	init();
	dfs(a[0], 0, 0);
	int maxx = -1;
	int rt = 0;
	for(int i = 1; i <= n; ++i) {
		if(is_key[i]) {
			if(dis[i] > maxx) {
				rt = i;
				maxx = dis[i];
			}
		}
	}
	
	init();
	dfs(rt, 0, 0);
	maxx = 0;
	for(int i = 1; i <= n; ++i) {
		if(is_key[i]) {
			if(dis[i] > maxx) {
				rt = i;
				maxx = dis[i];
			}
		}
	}
	int nxt = rt;

	while(nxt) {
		in_r[nxt] = 1;
		nxt = f[nxt];
	}
	int mid = maxx / 2;

	rt = N;
	if(maxx & 1) {
		int center1, center2;
		for(int i = 1; i <= n; ++i) {
			if(in_r[i] && dis[i] == mid) {
				center1 = i;
			} else if(in_r[i] && dis[i] == mid + 1){
				center2 = i;
			}
		}
		//cout<<center1<<' '<<center2<<' '<<mid<<endl;
		rt = min(rt, get_rt(center1, mid + 1, n));
		rt = min(rt, get_rt(center2, mid + 1, n));
	} else {
		int center;
		for(int i = 1; i <= n; ++i) {
			if(in_r[i] && dis[i] == mid) {
				center = i;
			}
		}
		rt = min(rt, get_rt(center, mid, n));
	}

	cout<<rt<<endl;
	init();
	dfs(rt, 0, 0);
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		if(is_key[i]) {
			int nxt = i;
			while(used[nxt] == 0 && nxt != 0) {
				++sum;
				used[nxt] = 1;
				nxt = f[nxt];
			}
		}
	}
	cout<<(sum - 1) * 2 - maxx<<endl;
}


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].PB(v);
		G[v].PB(u);
	}

	for(int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
		is_key[a[i]] = 1;
	}

	gao(n);

	return 0;
}
