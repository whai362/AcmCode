/*======================================================
# Author: whai
# Last modified: 2016-01-31 22:32
# Filename: c.cpp
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
#define P pair<LL, LL>
#define X first
#define Y second

const int N = 1e5 + 5;

P a[N];

double deal(int m, int l, int r, LL p) {
	LL len = a[m].Y - a[m].X + 1;
	LL cnt = a[m].Y / p - (a[m].X - 1) / p;
	double ret = cnt * 2000;
	LL len_l = a[l].Y - a[l].X + 1;
	LL len_r = a[r].Y - a[r].X + 1;
	LL cnt_l = a[l].Y / p - (a[l].X - 1) / p;
	LL cnt_r = a[r].Y / p - (a[r].X - 1) / p;
	ret += (double)(len - cnt) * (1000.0 * cnt_l * len_r + 1000.0 * cnt_r * len_l) / (len_l * len_r);
	ret /= len;
	return ret;
}

int main() {
	int n, p;
	while(scanf("%d%d", &n, &p) != EOF) {
		//cout<<n<<' '<<p<<endl;
		double ans = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%I64d%I64d", &a[i].X, &a[i].Y);
		}
		for(int i = 0; i < n; ++i) {
			int L = (i - 1 + n) % n;
			int R = (i + 1) % n;
			//cout<<deal(i, L, R, p)<<' ';
			ans += deal(i, L, R, p);
		}
		//cout<<endl;
		printf("%.6f\n", ans);
	}
	return 0;
}

