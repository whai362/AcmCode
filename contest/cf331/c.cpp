/*======================================================
# Author: whai
# Last modified: 2015-11-16 01:01
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

const int N = 1e5 + 5;
const int ADD = 100001;
P a[N];
int w[N];

set<P> b[2 * N];

P ans[N], c[N];

int maxx[N], minn[N];

bool cmp(P a, P b) {
	return (a.X <= b.X) && (a.Y <= b.Y);
}

int gao(int n) {
	for(int i = 0; i < N; ++i) {
		minn[i] = N;
	}
	for(int i = 0; i < n; ++i) {
		int tmp = a[i].Y - a[i].X;
		b[tmp + ADD].insert(a[i]);
	}

	for(int i = 0; i < n; ++i) {
		int id = w[i] + ADD;
		if(b[id].size() == 0) return -1;
		P now = *b[id].begin();
		b[id].erase(now);
		ans[i] = now;
		c[i] = now;
	}
	stable_sort(c, c + n, cmp);

	for(int i = 0; i < n; ++i) {
		if(c[i].X == ans[i].X && c[i].Y == ans[i].Y) continue;
		return -1;
	}
	return 1;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].X, &a[i].Y);
		}
		for(int i = 0; i < n; ++i) {
			scanf("%d", &w[i]);
		}
		sort(w, w + n);
		int flag = gao(n);
		if(flag == -1) {
			puts("NO");
		} else {
			puts("YES");
			for(int i = 0; i < n; ++i) {
				printf("%d %d\n", ans[i].X, ans[i].Y);
			}
		}
	}
	return 0;
}

