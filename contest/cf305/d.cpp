/*======================================================
# Author: whai
# Last modified: 2015-12-09 13:39
# Filename: d.cpp
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

const int N = 2 * 1e5 + 5;
int a[N];
int L[N], R[N];

P st[N];
int top = -1;

int ans[N];

void gao(int n) {
	top = -1;
	st[++top] = P(-1, 0);
	for(int i = 1; i <= n; ++i) {
		int j;
		for(j = top; j >= 0; --j) {
			if(a[i] >= st[j].X) break;
			else R[st[j].Y] = i - 1;
		}
		if(a[i] > st[j].X) L[i] = st[j].Y + 1;
		else L[i] = L[st[j].Y];
		top = j;
		st[++top] = P(a[i], i);
	}
	for(int i = 0; i <= top; ++i) {
		R[st[i].Y] = n;
	}
	for(int i = 1; i <= n; ++i) {
		//cout<<L[i]<<' '<<R[i]<<endl;
		int u = R[i] - L[i] + 1;
		ans[u] = max(ans[u], a[i]);
	}
	for(int i = n - 1; i > 0; --i) {
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
}

int main() {
	int n;
	while(cin>>n) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		gao(n);
	}
	return 0;
}

