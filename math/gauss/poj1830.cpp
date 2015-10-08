/*======================================================
# Author: whai
#
# Last modified: 2015-10-06 22:02
#
# Filename: poj1830.cpp
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
int f[N][N], x[N];

int gauss(int n) {
	int i, c;
	for(i = 0, c = 0; i < n && c < n; ++c) {
		int k = i;
		while(k < n && !f[k][c]) ++k;
		if(f[k][c]) {
			for(int j = 0; j <= n; ++j)
				swap(f[i][j], f[k][j]);
			for(int j = 0; j < n; ++j)
				if(i != j && f[j][c])
					for(int k = 0; k <= n; ++k)
						f[j][k] ^= f[i][k];
			++i;
		}
	}
	for(int j = i; j < n; ++j) if(f[j][n]) return -1;
	return n - i;
}
void init() {
	memset(f, 0, sizeof(f));
}
int a[N], b[N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		init();
		
		int u, v;
		while(scanf("%d%d", &u, &v) && (u || v))
			f[v - 1][u - 1] = 1;
		for(int i = 0; i < n; ++i)
			f[i][i] = 1;
		for(int i = 0; i < n; ++i)
			f[i][n] = a[i] ^ b[i];
		int ans = gauss(n);
		if(ans == -1) {
			puts("Oh,it's impossible~!!");
		} else {
			printf("%d\n", (1 << ans));
		}
	}
	return 0;
}

