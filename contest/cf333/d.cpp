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

LL ans[N];

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

int _abs(int x) {
	if(x < 0) return -x;
	return x;
}


LL cur = 0;
void add(int x, int l, int r, int pos) {
	if(l == r) return ;
	if(pos == l) {
		int maxx = 0;
		for(int i = l + 1; i <= r; ++i) {
			int tmp = _abs(a[i] - a[i - 1]);
			maxx = max(maxx, tmp);
			cur += maxx;
		}
	} else {
		int maxx = 0;
		for(int i = r - 1; i >= l; --i) {
			int tmp = _abs(a[i + 1] - a[i]);
			maxx = max(maxx, tmp);
			cur += maxx;
		}
	}
}

void del(int x, int l, int r, int pos) {
	if(l == r) return ;
	if(pos == l) {
		int maxx = 0;
		for(int i = l + 1; i <= r; ++i) {
			int tmp = _abs(a[i] - a[i - 1]);
			maxx = max(maxx, tmp);
			cur -= maxx;
		}
	} else {
		int maxx = 0;
		for(int i = r - 1; i >= l; --i) {
			int tmp = _abs(a[i + 1] - a[i]);
			maxx = max(maxx, tmp);
			cur -= maxx;
		}
	}
}

void gao(int n, int m) {
	unit = sqrt(n);
	sort(q, q + m, cmp);
	int L = 1, R = 0;
	for(int i = 0; i < m; ++i) {
		while(R < q[i].y) {
			++R;
			add(a[R], L, R, R);
		}
		while(R > q[i].y) {
			del(a[R], L, R, R);
			--R;
		}
		while(L < q[i].x) {
			del(a[L], L, R, L);
			//cout<<L<<' '<<R<<' '<<cur<<endl;
			++L;
		}
		while(L > q[i].x) {
			--L;
			add(a[L], L, R, L);
		}
		ans[q[i].id] = cur;
	}
	for(int i = 0; i < m; ++i) {
		printf("%I64d\n", ans[i]);
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
