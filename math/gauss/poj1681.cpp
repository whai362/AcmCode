/*======================================================
# Author: whai
# Last modified: 2015-10-07 16:10
# Filename: poj1681.cpp
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

const int N = 20 * 20;

char str[N][N];

LL inv(LL a, LL m) {
	LL p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}

const int G_MOD = 2;
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

bool ok(int x, int y, int n) {
	if(x >= 0 && x < n && y >= 0 && y < n) return true;
	return false;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void deal(int x, int y, int n) {
	int u = x * n + y;
	g.f[u][u] = 1;
	int st = 0;
	if(str[x][y] == 'w') st = 1;
	g.f[u][n * n] = st ^ 0;
	for(int i = 0; i < 4; ++i) {
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];
		if(ok(tmpx, tmpy, n)) {
			int v = tmpx * n + tmpy;
			g.f[v][u] = 1;
		}
	}
}

void gao(int n) {
	g.init();
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			deal(i, j, n);
		}
	}

	int flag = g.gauss(n * n, n * n);
	
	if(flag == -1) puts("inf");
	else if(flag == 0){
		int ans = 0;
		for(int i = 0; i < n * n; ++i) {
			ans += g.f[i][n * n];
		}
		cout<<ans<<endl;
	} else {
		int maxx = (1<<flag);
		int var = n * n;
		int ans = var;
		for(int x = 0; x < maxx; ++x) {
			int cnt = 0;
			for(int i = 0; i < flag; ++i) {
				if(x & (1 << i)) {
					g.x[g.f_x[i]] = 1;
					++cnt;
				} else {
					g.x[g.f_x[i]] = 0;
				}
			}
			for(int i = var - 1 - flag; i >= 0; --i) {
				int tmp = g.f[i][var];
				for(int j = i + 1; j < var; ++j) {
					if(g.f[i][j])
						tmp ^= g.x[j];
				}
				cnt += tmp;
			}
			ans = min(ans, cnt);
		}
		cout<<ans<<endl;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%s", str[i]);
		}
		gao(n);
	}
	return 0;
}

