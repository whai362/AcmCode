/*======================================================
# Author: whai
#
# Last modified: 2015-10-06 11:52
#
# Filename:	poj1222.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 105;

int f[N][N], ans[N];
void gauss(int n) {
	for(int i = 0; i < n; ++i) {
		int k = i;
		while(k < n && !f[k][i]) ++k;
		for(int j = 0; j <= n; ++j)
			swap(f[i][j], f[k][j]);
		for(int j = 0; j < n; ++j)
			if(i != j && f[j][i])
				for(int k = 0; k <= n; ++k)
					f[j][k] ^= f[i][k];
	}
	for(int i = 0; i < n; ++i)
		ans[i] = f[i][30];
}

void init() {
	memset(f, 0, sizeof(f));
}

bool in(int x, int y) {
	if(x >= 0 && x < 5 && y >= 0 && y < 6) return true;
	return false;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int a[10][10];

void deal(int x, int y) {
	int u = x * 6 + y;
	f[u][u] = 1;
	f[u][30] = a[x][y];
	for(int i = 0; i < 4; ++i) {
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];
		if(in(tmpx, tmpy)) {
			int v = tmpx * 6 + tmpy;
			f[v][u] = 1;
		}
	}
}

void gao() {
	for(int i = 0; i < 5; ++i) {
		for(int j = 0; j < 6; ++j) {
			deal(i, j);
		}
	}
	gauss(30);
	for(int i = 0; i < 5; ++i) {
		for(int j = 0; j < 6; ++j) {
			printf("%d%c", ans[i * 6 + j], j == 5 ? '\n' : ' ');
		}
	}
}

int main() {
	int T;
	int cas = 0;
	scanf("%d", &T);
	while(T--) {
		init();
		for(int i = 0; i < 5; ++i) {
			for(int j = 0; j < 6; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		printf("PUZZLE #%d\n",++cas);
		gao();
	}
	return 0;
}

