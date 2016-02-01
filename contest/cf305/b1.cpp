/*======================================================
# Author: whai
# Last modified: 2015-12-09 12:24
# Filename: b1.cpp
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

const int N = 505;

int G[N][N];

multiset<int> ans;

int now[N];

int deal(int *a, int n) {
	int ret = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] == 1) {
			int cnt = 0;
			int p = i;
			while(p <= n && a[p] == 1) {
				++cnt;
				++p;
			}
			ret = max(ret, cnt);
			i = p - 1;
		}
	}
	return ret;
}

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &G[i][j]);
		}
		now[i] = deal(G[i], m);
		ans.insert(now[i]);
	}
	for(int i = 0; i < q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans.erase(ans.find(now[x]));
		G[x][y] ^= 1;
		now[x] = deal(G[x], m);
		ans.insert(now[x]);
		cout<<(*ans.rbegin())<<endl;
	}
	return 0;
}

