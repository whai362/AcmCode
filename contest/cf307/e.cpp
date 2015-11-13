/*======================================================
# Author: whai
# Last modified: 2015-10-22 16:01
# Filename: e.cpp
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
#define MP make_pair

const int N = 1005;

int unit_sz, unit_tot;
vector< pair<LL, int> > unit[N];
LL add[N];

int unit_id(int x) {
	return x / unit_sz;
}

bool cmp(pair<LL, int> a, pair<LL, int> b) {
	return a.Y < b.Y;
}

void update(int l, int r, LL x) {
	int l_id = unit_id(l);
	int r_id = unit_id(r);
	if(l_id == r_id) {
		sort(unit[l_id].begin(), unit[l_id].end(), cmp);
		int ll = l % unit_sz;
		int rr = r % unit_sz;
		for(int i = ll; i <= rr; ++i) {
			unit[l_id][i].X += x;
		}
		sort(unit[l_id].begin(), unit[l_id].end());
	} else {
		int ll = l % unit_sz;
		int lr = unit_sz - 1;
		int rl = 0;
		int rr = r % unit_sz;
		sort(unit[l_id].begin(), unit[l_id].end(), cmp);
		for(int i = ll; i <= lr; ++i) {
			unit[l_id][i].X += x;
		}
		sort(unit[l_id].begin(), unit[l_id].end());

		sort(unit[r_id].begin(), unit[r_id].end(), cmp);
		for(int i = rl; i <= rr; ++i) {
			unit[r_id][i].X += x;
		}
		sort(unit[r_id].begin(), unit[r_id].end());
		
		for(int i = l_id + 1; i <= r_id - 1; ++i) {
			add[i] += x;
		}
	}
}

int get_l(LL x) {
	for(int i = 0; i < unit_tot; ++i) {
		int p = lower_bound(unit[i].begin(), unit[i].end(), MP(x - add[i], 0)) - unit[i].begin();
		if(p < unit[i].size() && unit[i][p].X + add[i] == x) {
			return unit[i][p].Y;
		}
	}
	return -1;
}

int get_r(LL x) {
	for(int i = unit_tot - 1; i >= 0; --i) {
		int p = lower_bound(unit[i].begin(), unit[i].end(), MP(x - add[i], N * N)) - unit[i].begin();
		--p;
		if(p >= 0 && unit[i][p].X + add[i] == x) {
			return unit[i][p].Y;
		}
	}
	return -1;
}

void print() {
	for(int i = 0; i < unit_tot; ++i) {
		for(int j = 0; j < unit[i].size(); ++j) {
			cout<<unit[i][j].X<<' ';
		}
		cout<<endl;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	unit_sz = sqrt(n) + 1;
	unit_tot = n / unit_sz;
	if(n % unit_sz) ++unit_tot;

	for(int i = 0; i < n; ++i) {
		LL x;
		scanf("%I64d", &x);
		int id = unit_id(i);
		unit[id].PB(MP(x, i));
	}
	

	for(int i = 0; i < unit_tot; ++i) {
		sort(unit[i].begin(), unit[i].end());
	}

	for(int i = 0; i < m; ++i) {
		int op, l, r;
		LL x;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d%d%I64d", &l, &r, &x);
			update(l - 1, r - 1, x);
		} else {
			scanf("%I64d", &x);
			int R = get_r(x);
			int L = get_l(x);
			if(L == -1) puts("-1");
			else printf("%d\n", R - L);
		}
		//print();
	}
	return 0;
}

