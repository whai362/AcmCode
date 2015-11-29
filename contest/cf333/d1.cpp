/*======================================================
# Author: whai
# Last modified: 2015-11-25 12:48
# Filename: d1.cpp
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
const int INF = 0x3f3f3f3f;

int a[N];
int b[N];
int L[N], R[N];

int _abs(int x) {
	if(x < 0) return -x;
	return x;
}

P st[N];
int top = -1;

void predo(int n) {
	for(int i = 1; i < n; ++i) {
		b[i] = _abs(a[i + 1] - a[i]);
	}
	//for(int i = 1; i < n; ++i) {
	//	cout<<b[i]<<' ';
	//}
	//cout<<endl;
	top = -1;
	st[++top] = P(INF, 0);
	for(int i = 1; i < n; ++i) {
		int j;
		for(j = top; j >= 0; --j) {
			if(b[i] <= st[j].X) break;
			else R[st[j].Y] = i - 1;
		}
		L[i] = st[j].Y + 1;
		top = j;
		st[++top] = P(b[i], i);
	}
	for(int i = 0; i <= top; ++i) {
		R[st[i].Y] = n - 1;
	}
	//for(int i = 1; i < n; ++i) {
	//	cout<<L[i]<<' '<<R[i]<<endl;
	//}
}

void gao(int l, int r) {
	LL ans = 0;
	for(int i = l; i < r; ++i) {
		LL left = (i - max(L[i], l) + 1);
		LL right = (min(R[i], r - 1) - i + 1);
		ans += left * right * b[i];
	}
	cout<<ans<<endl;

}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	predo(n);
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		gao(u, v);
	}
	return 0;
}

