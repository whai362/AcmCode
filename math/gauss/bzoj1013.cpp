/*======================================================
# Author: whai
# Last modified: 2015-10-08 10:28
# Filename: bzoj1013.cpp
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

const int N = 105;
const int EPS = 1e-8;

double sqr(double x) { return x * x; }

struct Gauss {
	double f[N][N], x[N];
	bool gauss(int n, int m) {
		int i, c;
		for(i = 0, c = 0; i < n && c < m; ++c) {
			int k = i;
			while(k < n && fabs(f[k][c]) <= EPS) ++k;
			if(fabs(f[k][c]) <= EPS) continue;
			for(int j = c; j <= m; ++j)
				swap(f[i][j], f[k][j]);
			for(int j = 0; j < n; ++j)
				if(i != j && fabs(f[j][c]) > EPS) {
					double tmp = f[j][c] / f[i][c];
					for(int k = 0; k <= m; ++k)
						f[j][k] = f[j][k] - f[i][k] * tmp;
				}
			++i;
		}
		for(int j = i; j < n; ++j) if(fabs(f[j][m]) > EPS) return -1;
		if(i < m) return m - i;
		for(int j = m - 1; j >= 0; --j)
			x[j] = f[j][m] / f[j][j];
		return 0;
	}
}g;

double x[N][N];

void deal(int a, int n) {
	double R = 0;
	for(int i = 0; i < n; ++i) {
		R += sqr(x[a][i]) - sqr(x[a + 1][i]);
	}
	g.f[a][n] = R;
	for(int i = 0; i < n; ++i) {
		double fac = 2.0 * (x[a][i] - x[a + 1][i]);
		g.f[a][i] = fac;
	}
}

void gao(int n) {
	for(int i = 0; i < n; ++i) {
		deal(i, n);
	}
	g.gauss(n, n);
	for(int i = 0; i < n; ++i) {
		printf("%.3f%c", g.x[i], i == n - 1 ? '\n' : ' ');
	}
}

int main() {
	int n;
	cin>>n;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin>>x[i][j];
		}
	}
	gao(n);
	return 0;
}
