/*======================================================
# Author: whai
# Last modified: 2015-10-10 15:12
# Filename: tsa1206.cpp
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 5 *1e4 + 5;

pair<LL, LL> ans[N];

struct Q {
	int x, y, id;
}q[N];

int unit;
int unit_id(Q a) {
	return (a.x - 1) / unit + 1;
}

bool cmp(Q a, Q b) {
	if(unit_id(a) == unit_id(b)) return a.y < b.y;
	return unit_id(a) < unit_id(b);
}

int a[N];
int cnt[N];

LL cur = 0;
void add(int x) {
	cur -= cnt[x] * (cnt[x] - 1);
	++cnt[x];
	cur += cnt[x] * (cnt[x] - 1);
}

void del(int x) {
	cur -= cnt[x] * (cnt[x] - 1);
	--cnt[x];
	cur += cnt[x] * (cnt[x] - 1);
}

void gao(int n, int m) {
	unit = sqrt(n);
	sort(q, q + m, cmp);
	int L = 1, R = 0;
	for(int i = 0; i < m; ++i) {
		while(R < q[i].y) {
			++R;
			add(a[R]);
		}
		while(R > q[i].y) {
			del(a[R]);
			--R;
		}
		while(L < q[i].x) {
			del(a[L]);
			++L;
		}
		while(L > q[i].x) {
			--L;
			add(a[L]);
		}
		if(cur == 0) ans[q[i].id].X = 0;
		else {
			LL tmp = __gcd(cur, (LL)(q[i].y - q[i].x + 1) * (q[i].y - q[i].x));
			ans[q[i].id].X = cur / tmp;
			ans[q[i].id].Y = (LL)(q[i].y - q[i].x + 1) * (q[i].y - q[i].x) / tmp;
		}
	}
	for(int i = 0; i < m; ++i) {
		if(!ans[i].X) puts("0/1");
		else printf("%lld/%lld\n", ans[i].X, ans[i].Y);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &q[i].x, &q[i].y);
		q[i].id = i;
	}
	gao(n, m);
	return 0;
}

