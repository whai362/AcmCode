/*======================================================
# Author: whai
# Last modified: 2015-12-25 18:29
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
const int INF = 1e9 + 5;

P a[N];

int leave[N];

void gao(int n) {
	sort(a, a + n + 1);
	a[0].X = -INF;
	a[0].Y = 0;
	leave[0] = 0;
	leave[0] = 0;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int x = a[i].X - a[i].Y;
		int pos = upper_bound(a, a + n + 1, P(x, 0)) - a - 1;
		leave[i] = leave[pos] + 1;
		ans = max(ans, leave[i] + 1);
	}
	//for(int i = 1; i <= n; ++i) {
	//	cout<<leave[i]<<' ';
	//}
	//cout<<endl;
	cout<<n + 1 - ans<<endl;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i].X, &a[i].Y);
		}
		gao(n);
	}
	return 0;
}
