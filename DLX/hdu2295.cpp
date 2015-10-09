/*======================================================
# Author: whai
# Last modified: 2015-10-08 22:44
# Filename: hdu2295.cpp
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
#define P pair<double, double>
#define X first
#define Y second

const int MAXM = 55;
const int MAXN = 55;
const int N = MAXN * MAXM;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
struct DLX {
	int n, m, size;
	int U[N], D[N], R[N], L[N], row[N], col[N];
	int H[MAXN], S[MAXM];
	int ans[MAXN], ans_cnt;
	void init(int _n, int _m) {
		ans_cnt = INF;
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++) {
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)H[i] = -1;
	}
	void link(int r, int c) {
		++S[col[++size] = c];
		row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)H[r] = L[size] = R[size] = size;
		else {
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c) {
		for (int i = D[c]; i != c; i = D[i])
			L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void resume(int c) {
		for (int i = U[c]; i != c; i = U[i])
			L[R[i]] = R[L[i]] = i;
	}
	bool v[MAXM];
	int f() {
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c])v[c] = true;
		for (int c = R[0]; c != 0; c = R[c])
			if (v[c]) {
				ret++;
				v[c] = false;
				for (int i = D[c]; i != c; i = D[i])
					for (int j = R[i]; j != i; j = R[j])
						v[col[j]] = false;
			}
		return ret;
	}
	void dance(int d) {
		if (d + f() >= ans_cnt) return;
		if (R[0] == 0) {
			if (d < ans_cnt)ans_cnt = d;
			return;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		for (int i = D[c]; i != c; i = D[i]) {
			remove(i);
			ans[d] = row[i];
			for (int j = R[i]; j != i; j = R[j]) remove(j);
			dance(d + 1);
			for (int j = L[i]; j != i; j = L[j]) resume(j);
			resume(i);
		}
	}
}dlx;

P city[N], radar[N];
bool used[MAXN];

double sqr(double x) {
	return x * x;
}

double dis(P a, P b) {
	return sqr(a.X - b.X) + sqr(a.Y - b.Y);
}

bool ok(P a, P b, double r) {
	return dis(a, b) <= r * r;
}

int need(double r, int n, int m) {
	dlx.init(m, n);
	memset(used, 0, sizeof(used));
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(ok(radar[i], city[j], r)) {
				dlx.link(i + 1, j + 1);
				used[j] = 1;
			}
		}
	}
	for(int i = 0; i < n; ++i)
		if(!used[i]) return INF;
	dlx.dance(0);
	return dlx.ans_cnt;
}

void gao(int n, int m, int k) {
	double L = 0, R = 1e7, ans = 1e7;
	while(fabs(L - R) > EPS) {
		double mid = (L + R) / 2;
		if(need(mid, n, m) > k) {
			L = mid;
		} else {
			ans = min(ans, mid);
			R = mid;
		}
	}
	printf("%.6f\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0; i < n; ++i) {
			scanf("%lf%lf", &city[i].X, &city[i].Y);
		}
		for(int i = 0; i < m; ++i) {
			scanf("%lf%lf", &radar[i].X, &radar[i].Y);
		}
		gao(n, m, k);
	}
	return 0;
}

