/*======================================================
# Author: whai
# Last modified: 2015-11-07 20:30
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 505;

LL dp[2][N][N];

int a[N];

int main() {
	int n, m, b, mod;
	cin>>n>>m>>b>>mod;
	for(int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	for(int i = 0; i < n; ++i) {
		dp[0][0][i] = 1;
	}
	for(int i = 1; i <= m; ++i) {
		int now = i % 2, pre = (i + 1) % 2;
		memset(dp[now], 0, sizeof(dp[now]));
		for(int j = 0; j <= b; ++j) {
			for(int k = 0; k < n; ++k) {
				if(j >= a[k]) {
					dp[now][j][k] = (dp[now][j][k] + dp[pre][j - a[k]][k]) % mod;
				}
			}
		}
		for(int j = 0; j <= b; ++j) {
			for(int k = 1; k < n; ++k) {
				dp[now][j][k] = (dp[now][j][k] + dp[now][j][k - 1]) % mod;
			}
		}
	}
	LL ans = 0;
	for(int i = 0; i <= b; ++i) {
		ans = (ans + dp[m % 2][i][n - 1]) % mod;
	}
	cout<<ans<<endl;
	return 0;
}

