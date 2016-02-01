/*======================================================
# Author: whai
# Last modified: 2015-12-06 10:23
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

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int a[N];

multiset<int> myset;

int to_l[N];

bool ok(int s) {
	return ((*myset.rbegin()) - (*myset.begin()) <= s);
}

void predo(int n, int s, int l) {
	myset.clear();
	myset.insert(a[1]);
	to_l[1] = 1;
	int p = 1;
	for(int i = 2; i <= n; ++i) {
		myset.insert(a[i]);
		while(p < i && !ok(s)) {
			myset.erase(myset.find(a[p]));
			++p;
		}
		to_l[i] = p;
	}
	//for(int i = 1; i <= n; ++i) {
	//	cout<<to_l[i]<<' ';
	//}
	//cout<<endl;
}

int dp[N];

void gao(int n, int s, int l) {
	predo(n, s, l);
	memset(dp, 0x3f, sizeof(dp));
	myset.clear();
	int p = 1;
	for(int i = 1; i <= n; ++i) {
		int L = to_l[i] - 1, R = i - l;
		if(R > 0) myset.insert(dp[R]);
		if(L > R) continue;
		if(L == 0) {
			dp[i] = 1;
			continue;
		}
		while(p < L) {
			myset.erase(myset.find(dp[p]));
			++p;
		}
		int minn = (*myset.begin());
		if(minn != INF)
			dp[i] = minn + 1;
	}
	//for(int i = 1; i <= n; ++i) {
	//	cout<<dp[i]<<' ';
	//}
	//cout<<endl;
	if(dp[n] == INF) puts("-1");
	else {
		cout<<dp[n]<<endl;
	}
}

int main() {
	int n, s, l;
	while(scanf("%d%d%d", &n, &s, &l) != EOF) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		gao(n, s, l);
	}
	return 0;
}

