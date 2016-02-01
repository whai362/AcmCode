/*======================================================
# Author: whai
# Last modified: 2015-12-10 01:28
# Filename: b1.cpp
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

struct E {
	int l, v, id, a, b;
} a[N];

int top[N];

bool cmp(E a, E b) {
	if(a.l == b.l) return a.v > b.v;
	return a.l < b.l;
}

bool cmp1(E a, E b) {
	return a.id < b.id;
}

vector<int> V;
P ans[N];

LL get_id(LL a, LL b) {
	return a * N + b;
}


int main() {

	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d", &a[i].l, &a[i].v);
			a[i].id = i;
		}
		int now = 1, st = 0, vi = 2, vj = 3;
		sort(a + 1, a + 1 + m, cmp);
		for(int i = 1; i <= n; ++i) top[i] = i + 1;
		int i;
		for(i = 1; i <= m; ++i) {
			if(a[i].v) {
				a[i].a = 1;
				a[i].b = ++now;
				st += now - 1;
			} else {
				if(i > st) break;
				if(top[vi] <= now) {
					a[i].a = vi;
					a[i].b = top[vi]++;
				} else {
					for(vi++; ;vi++) {
						if(vi == now) vi = 2;
						if(top[vi] <= now) break;
					}
					a[i].a = vi;
					a[i].b = top[vi]++;
				}
			}
		}
		if(i != m + 1) puts("-1");
		sort(a + 1, a + 1 + m, cmp1);
		for(int i = 1; i <= m; ++i) {
			printf("%d %d\n", a[i].a, a[i].b);
		}
	}

	return 0;
}

