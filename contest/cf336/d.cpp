/*======================================================
# Author: whai
# Last modified: 2015-12-25 19:03
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

const int N = 505;

int a[N];
int dp[N][N];


int deal(int L, int R) {
	if(L >= R) return 1;
	if(dp[L][R] != N) return dp[L][R];
	if(a[L] == a[R]) dp[L][R] = min(dp[L][R], deal(L + 1, R - 1));
	for(int i = L; i < R; ++i) {
		dp[L][R] = min(dp[L][R], deal(L, i) + deal(i + 1, R));
	}
	return dp[L][R];
}

void gao(int n) {
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			dp[i][j] = N;
	int ans = deal(0, n - 1);
	cout<<ans<<endl;
}

int main() {
	int n;
	while(cin>>n) {
		for(int i = 0; i < n; ++i) {
			cin>>a[i];
		}
		gao(n);
	}
	return 0;
}

