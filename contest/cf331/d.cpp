/*======================================================
# Author: whai
# Last modified: 2015-11-16 01:49
# Filename: d.cpp
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

const int N = 2 * 1e3 + 5;

int x[N];

double dp[N][N][2][2];
double vis[N][N][2][2];
int L[N], R[N];

double deal(int l, int r, int fl, int fr, double p, double h, int n) {
	double ret = 0;
	double ll = h, rr = h;
	if(vis[l][r][fl][fr]) return dp[l][r][fl][fr];
	if(l > 1) {
		if(fl == 0)
			ll = min(ll, (double)x[l] - x[l - 1]);
		else
			ll = min(ll, max((double)x[l] - x[l - 1] - h, 0.0));
	}
	if(r < n) {
		if(fr)
			rr = min(rr, (double)x[r + 1] - x[r]);
		else
			rr = min(rr, max((double)x[r + 1] - x[r] - h, 0.0));
	}
	if(l == r) {
		ret = ll * p + rr * (1 - p);
		vis[l][r][fl][fr] = 1;
		return dp[l][r][fl][fr] = ret;
	}

	//cout<<l<<' '<<r<<endl;

	ret += (deal(l + 1, r, 0, fr, p, h, n) + ll) * 0.5 * p;
	ret += (deal(l, r - 1, fl, 1, p, h, n) + rr) * 0.5 * (1 - p);
	int right = R[l];
	if(right >= r) {
		double tmp = x[r] - x[l] + rr;
		ret += tmp * 0.5 * (1 - p);
	} else {
		double tmp = x[right] - x[l] + h;
		ret += (deal(right + 1, r, 1, fr, p, h, n) + tmp) * 0.5 * (1 - p);
	}

	int left = L[r];
	if(left <= l) {
		double tmp = x[r] - x[l] + ll;
		ret += tmp * 0.5 * p;
	} else {
		double tmp = x[r] - x[left] + h;
		ret += (deal(l, left - 1, fl, 0, p, h, n) + tmp) * 0.5 * p;
	}

	//cout<<l<<' '<<r<<' '<<ret<<endl;
	vis[l][r][fl][fr] = 1;
	return dp[l][r][fl][fr] = ret;
}

void gao(int n, int h, double p) {
	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; ++i) {
		int p = i;
		int right = i;
		while(p < n && x[p] + h > x[p + 1]) {
			right = p + 1;
			++p;
		}
		for(int j = i; j <= p; ++j) {
			R[j] = right;
		}
		i = p;
	}
	
	for(int i = n; i > 0; --i) {
		int p = i;
		int left = i;
		while(p > 1 && x[p] - h < x[p - 1]) {
			left = p - 1;
			--p;
		}
		for(int j = i; j >= p; --j) {
			L[j] = left;
		}
		i = p;
	}

	//for(int i = 1; i <= n; ++i) {
	//	cout<<L[i]<<' ';
	//}
	//cout<<endl;

	//for(int i = 1; i <= n; ++i) {
	//	cout<<R[i]<<' ';
	//}
	//cout<<endl;

	double ans = deal(1, n, 0, 1, p, h, n);
	printf("%.8f\n", ans);
}

int main() {
	int n, h;
	double p;
	while(scanf("%d%d%lf", &n, &h, &p) != EOF) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &x[i]);
		}
		sort(x + 1, x + 1 + n);
		gao(n, h, p);
	}
	return 0;
}

