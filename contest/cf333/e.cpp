/*======================================================
# Author: whai
# Last modified: 2015-11-25 19:17
# Filename: e.cpp
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

const int N = 105;
const int M = 1005;

int a[N];

double dp[N * M];

double pre[N * M], tmp_dp[N * M];

void deal(int x, int n, int m) {
	pre[0] = 0;
	for(int i = 1; i <= n * m; ++i) {
		pre[i] = pre[i - 1] + dp[i - 1];
	}
	for(int i = 1; i <= n * m; ++i) {
		tmp_dp[i] = pre[i] - pre[max(0, i - m)];
		if(i >= x) tmp_dp[i] -= dp[i - x];
		tmp_dp[i] /= m - 1;
	}
	dp[0] = 0;
	for(int i = 1; i <= n * m; ++i) {
		dp[i] = tmp_dp[i];
	}
}

void gao(int n, int m) {
	if(m == 1) {
		cout<<1<<endl;
		return ;
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	int sum = 0;

	for(int i = 0; i < n; ++i) {
		sum += a[i];
		deal(a[i], n, m);
	}

	double ans = 0;
	for(int i = 1; i < sum; ++i) {
		ans += dp[i];
	}
	ans = ans * (m - 1) + 1;
	printf("%.10f\n", ans);
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		gao(n, m);
	}
}
