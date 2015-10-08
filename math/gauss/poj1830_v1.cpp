/*======================================================
# Author: whai
# Last modified: 2015-10-07 15:47
# Filename: poj1830_v1.cpp
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

LL inv(LL a, LL m) {
	LL p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}

const int N = 105;
const int G_MOD = 7;
struct Gauss {
	int f[N][N]; //第一维为等式0~n-1, 第二维为变元0~m-1, m是解
	int x[N]; //解
	int f_x[N], f_tot; //自由变元的列号
	
	//n表示等式个数，m表示变元个数
	int gauss(int n, int m) {
		int i, c;
		for(i = 0, c = 0; i < n && c < m; ++c) {
			int k = i;
			while(k < n && !f[k][c]) ++k;
			if(f[k][c] == 0) {
				f_x[f_tot++] = c;
				continue;
			}
			for(int j = c; j <= m; ++j)
				swap(f[i][j], f[k][j]);
			for(int j = 0; j < n; ++j)
				if(i != j && f[j][c]) {
					int tmp = f[j][c] * inv(f[i][c], G_MOD) % G_MOD;
					for(int k = 0; k <= m; ++k) {
						f[j][k] = ((f[j][k] - f[i][k] * tmp) % G_MOD + G_MOD) % G_MOD;
					}
				}
			++i;
		}
		for(int j = i; j < n; ++j) if(f[j][m]) return -1;
		if(i < m) return m - i;
		for(int j = m - 1; j >= 0; --j) {
			x[j] = f[j][m] * inv(f[j][j], G_MOD) % G_MOD;
		}
		return 0;
	}

	void init() {
		f_tot = 0;
		memset(f, 0, sizeof(f));
	}
}g;

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
		g.init();
		
		int u, v;
		while(scanf("%d%d", &u, &v) && (u || v))
			g.f[v - 1][u - 1] = 1;
		for(int i = 0; i < n; ++i)
			g.f[i][i] = 1;
		for(int i = 0; i < n; ++i)
			g.f[i][n] = a[i] ^ b[i];
		int ans = g.gauss(n, n);
		if(ans == -1) {
			puts("Oh,it's impossible~!!");
		} else {
			printf("%d\n", (1 << ans));
		}
	}
	return 0;
}
