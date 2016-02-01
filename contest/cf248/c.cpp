/*======================================================
# Author: whai
# Last modified: 2015-12-08 11:13
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

const LL INF = 100000000000000LL;

const int N = 1e5 + 5;

LL a[N], b[N];
LL sum = 0;
vector<int> ind[N];
vector<int> adj[N];

LL _abs(LL x) {
    if(x < 0) return -x;
    return x;
}

//1µÄÇé¿ö

LL deal(LL x, LL y, int m) {
    LL ret = sum;
	for(int i = 0; i < ind[x].size(); ++i) {
		int p = ind[x][i];
		a[p] = y;
		if(p == 1) {
			if(b[p] != b[p + 1]) {
				ret -= _abs(b[p] - b[p + 1]);
			}
		} else if(p == m) {
			if(b[p] != b[p - 1]) {
				ret -= _abs(b[p] - b[p - 1]);
			}
		} else {
			if(b[p] != b[p - 1]) {
				ret -= _abs(b[p] - b[p - 1]);
			}
			if(b[p] != b[p + 1]) {
				ret -= _abs(b[p] - b[p + 1]);
			}
		}
	}
	for(int i = 0; i < ind[x].size(); ++i) {
		int p = ind[x][i];
		if(p == 1) {
			if(a[p] != a[p + 1]) {
				ret += _abs(a[p] - a[p + 1]);
			}
		} else if(p == m) {
			if(a[p] != a[p - 1]) {
				ret += _abs(a[p] - a[p - 1]);
			}
		} else {
			if(a[p] != a[p - 1]) {
				ret += _abs(a[p] - a[p - 1]);
			}
			if(a[p] != a[p + 1]) {
				ret += _abs(a[p] - a[p + 1]);
			}
		}
	}

	for(int i = 0; i < ind[x].size(); ++i) {
		a[ind[x][i]] = x;
	}
    return ret;
}

bool used[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%I64d", &a[i]);
		b[i] = a[i];
		ind[a[i]].PB(i);
        used[a[i]] = 1;
    }

	sum = 0;
	for(int i = 2; i <= m; ++i) {
		sum += _abs(a[i] - a[i - 1]);
	}

    LL ans = sum;

    for(int i = 1; i <= n; ++i) {
        if(used[i] == 0) continue;
		for(int j = 0; j < ind[i].size(); ++j) {
			int p = ind[i][j];
			if(p > 1 && a[p] != a[p - 1]) {
				adj[i].PB(a[p - 1]);
			}
			if(p < m && a[p] != a[p + 1]) {
				adj[i].PB(a[p + 1]);
			}
		}
		sort(adj[i].begin(), adj[i].end());
    }
	
	for(int i = 1; i <= n; ++i) {
		if(used[i] == 0) continue;
		if(adj[i].size() == 0) continue;
		int u = adj[i].size() / 2;
		LL tmp = deal(i, adj[i][u], m);
		if(u) tmp = min(tmp, deal(i, adj[i][u - 1], m));
		ans = min(tmp, ans);
	}
    cout<<ans<<endl;
    return 0;
}
