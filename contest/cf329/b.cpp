/*======================================================
# Author: whai
# Last modified: 2015-11-05 00:59
# Filename: b.cpp
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
using namespace std;

#define LL __int64
#define PB push_back
#define P pair<LL, LL>
#define X first
#define Y second

const int N = 1e5 + 5;

LL k[N], b[N];

P a[N];

priority_queue<LL> used;

int main() {
	int n;
	LL L, R;
	scanf("%d", &n);
	scanf("%I64d%I64d", &L, &R);
	for(int i = 0; i < n; ++i) {
		scanf("%I64d%I64d", &k[i], &b[i]);
		LL y1 = k[i] * L + b[i];
		LL y2 = k[i] * R + b[i];
		a[i] = P(y1, y2);
	}
	sort(a, a + n);
	
	bool flag = 0;

	for(int i = 0; i < n; ++i) {
		LL now = a[i].X;
		int p = i;
		while(p < n && a[p].X == now) {
			if(!used.empty() && used.top() > a[p].Y) {
				flag = 1;
				break;
			}
			++p;
		}
		if(flag) {
			break;
		}
		p = i;
		while(p < n && a[p].X == now) {
			used.push(a[p].Y);
			++p;
		}
		i = p - 1;
	}
	if(flag) puts("YES");
	else puts("NO");

	return 0;
}

