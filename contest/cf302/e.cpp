/*======================================================
# Author: whai
# Last modified: 2015-11-08 11:48
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 25;

char str[N][N];
int a[N][N];
int cost[N][N];
int state[N][N];
int dp[1<<N];

void gao(int n, int m) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			int maxx = 0;
			for(int k = 0; k < n; ++k) {
				if(str[i][j] == str[k][j]) {
					maxx = max(maxx, a[k][j]);
					cost[i][j] += a[k][j];
					state[i][j] |= (1 << k);
				}
			}
			cost[i][j] -= maxx;
		}
	}
	//for(int i = 0; i < n; ++i) {
	//	for(int j = 0; j < m; ++j) {
	//		cout<<cost[i][j]<<','<<state[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	int total = (1 << n);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < total; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i & (1 << j)) continue;
			for(int k = 0; k < m; ++k) {
				dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + a[j][k]);
				dp[i | state[j][k]] = min(dp[i | state[j][k]], dp[i] + cost[j][k]);
			}
		}
	}
	cout<<dp[total - 1]<<endl;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%s", str[i]);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	gao(n, m);
	return 0;
}

