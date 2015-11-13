/*======================================================
# Author: whai
# Last modified: 2015-11-01 12:23
# Filename: 1012.cpp
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

const int N = 1e3 + 5;

int a[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ok(int x, int y, int n, int m) {
	if(x >= 0 && x < n && y >= 0 && y < m) {
		return true;
	}
	return false;
}

LL deal(int x, int y, int n, int m) {
	LL ret = 1;
	for(int i = 0; i < 4; ++i) {
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];
		LL delta = a[x][y];
		if(ok(tmpx, tmpy, n, m)) {
			delta -= a[tmpx][tmpy];
		}
		if(delta > 0)
			ret += delta;
	}
	return ret;
}

void gao(int n, int m) {
	LL ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(a[i][j] == 0) continue;
			ans +=  deal(i, j, n, m);
		}
	}
	cout<<ans<<endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		gao(n, m);
	}
	return 0;
}

