/*======================================================
# Author: whai
# Last modified: 2015-11-03 09:37
# Filename: 1001.cpp
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

const int N = 15;

int v[] = {0, 1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
int c[N];

LL sum[N];

int ans = 0;

void dfs(int remain, int use, int p) {
	if(remain < 0) return ;
	if(remain == 0) {
		ans = max(ans, use);
		return ;
	}
	if(p == 0) return ;
	int tmp = max(remain - sum[p - 1], (LL)0);
	int nd = tmp / v[p];
	if(tmp % v[p]) ++nd;
	if(nd > c[p]) return ;
	dfs(remain - nd * v[p], use + nd, p - 1);

	++nd;
	if(nd <= c[p])
		dfs(remain - nd * v[p], use + nd, p - 1);
}

void gao(int p) {
	sum[0] = 0;
	for(int i = 1; i <= 10; ++i) {
		sum[i] = sum[i - 1] + (LL)c[i] * v[i];
	}
	ans = 0;
	dfs(p, 0, 10);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int p;
		scanf("%d", &p);
		for(int i = 1; i <= 10; ++i) {
			scanf("%d", &c[i]);
		}
		gao(p);
		if(ans == 0) puts("-1");
		else cout<<ans<<endl;
	}

	return 0;
}
