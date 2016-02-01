/*======================================================
# Author: whai
# Last modified: 2015-12-07 12:38
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
#define P pair<int, int>
#define X first
#define Y second

#define LS (2 * n)
#define RS (2 * n + 1)

const int N = 5 * 1e4 + 5;

int a[N];
int ans[N];

struct Seg {
	int l, r, size;
}seg[4 * N];

void up(int n) {
	seg[n].size = seg[LS].size + seg[RS].size;
}

void build(int l, int r, int n) {
	seg[n].l = l; seg[n].r = r;
	if(l == r) {
		seg[n].size = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, LS);
	build(mid + 1, r, RS);
	up(n);
}

int get_id(int rank, int n) {
	if(seg[n].l == seg[n].r) return seg[n].l;
	if(rank <= seg[LS].size) {
		return get_id(rank, LS);
	} else {
		rank -= seg[LS].size;
		return get_id(rank, RS);
	}
}



void update(int p, int n) {
	if(seg[n].l == seg[n].r) {
		--seg[n].size;
		return ;
	}
	int mid = (seg[n].l + seg[n].r) >> 1;
	if(p <= mid) update(p, LS);
	else update(p, RS);
	up(n);
}

void gao(int n) {
	for(int i = n - 1; i > 0; --i) {
		a[i] -= a[i - 1];
	}
	for(int i = 0; i < n; ++i) {
		a[i] = i + 1 - a[i];
	}
	//for(int i = 0; i < n; ++i) {
	//	cout<<a[i]<<' ';
	//}
	//cout<<endl;
	
	build(1, n, 1);

	for(int i = n - 1; i >= 0; --i) {
		ans[i] = get_id(a[i], 1);
		update(ans[i], 1);
	}

	for(int i = 0; i < n; ++i) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		gao(n);
	}
	return 0;
}
