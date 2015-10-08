/*======================================================
# Author: whai
# Last modified: 2015-10-07 15:34
# Filename: poj2947_v2.cpp
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

const int N = 305;
const int MOD = 7;

LL inv(LL a, LL m) {
	LL p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}

struct Gauss {
	int f[N][N];
	int x[N];
	int f_x[N], f_tot;
	
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
					int tmp = f[j][c] * inv(f[i][c], MOD) % MOD;
					for(int k = 0; k <= m; ++k) {
						f[j][k] = ((f[j][k] - f[i][k] * tmp) % MOD + MOD) % MOD;
					}
				}
			++i;
		}
		for(int j = i; j < n; ++j) if(f[j][m]) return -1;
		if(i < m) return m - i;
		for(int j = m - 1; j >= 0; --j) {
			x[j] = f[j][m] * inv(f[j][j], MOD) % MOD;
		}
		return 0;
	}

	void init() {
		f_tot = 0;
		memset(f, 0, sizeof(f));
	}
}g;

string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int get_day(string str) {
	for(int i = 0; i < 7; ++i) {
		if(str == days[i]) return i;
	}
}

int main() {
	int n, m;
	while(cin>>n>>m && (n || m)) {
		g.init();
		for(int i = 0; i < m; ++i) {
			int k;
			string st, en;
			cin>>k>>st>>en;
			g.f[i][n] = (get_day(en) - get_day(st) + 1 + 7) % 7;
			for(int j = 0; j < k; ++j) {
				int type;
				scanf("%d", &type);
				++g.f[i][--type];
			}
			for(int j = 0; j < n; ++j)
				g.f[i][j] %= 7;
		}
		int flag = g.gauss(m, n);
		if(flag == -1) {
			cout<<"Inconsistent data."<<endl;
		} else if(flag > 0) {
			cout<<"Multiple solutions."<<endl;
		} else {
			for(int i = 0; i < n; ++i) {
				if(g.x[i] < 3)
					g.x[i] += 7;
				cout<<g.x[i]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}

