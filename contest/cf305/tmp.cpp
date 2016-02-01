/*======================================================
# Author: whai
# Last modified: 2015-12-09 14:26
# Filename: tmp.cpp
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

double dp[N][N * N];
double sum[N * N];
int main() {
	int n, a, b, x;
	while(cin>>n>>a>>b>>x) {
		memset(dp, 0, sizeof(dp));
		sum[1] = dp[0][0] = 1.0;
		for(int i = 2; i <= n * b; ++i) {
			sum[i] = sum[i - 1];
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = i * a; j <= n * b; ++j) {
				dp[i][j] = (sum[j - a + 1] - sum[max(j - b, 0)]) / (b - a + 1);
			}
			sum[1] = dp[i][0];
			for(int j = 2; j <= n * b; ++j) {
				sum[j] = sum[j - 1] + dp[i][j - 1];
			}
		}
		printf("%.4lf\n", dp[n][x]);
	}
	return 0;
}

