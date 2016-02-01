/*======================================================
# Author: whai
# Last modified: 2016-01-17 11:10
# Filename: first.cpp
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

int dp[N];
int a[N];

bool ok(int L, int R) {
	if(L < 1) return false;
	int cnt = 0;
	for(int i = L; i < R; ++i) {
		int tmp = a[i + 1] - a[i];
		if(tmp <= 0) return false;
		cnt += (max(tmp - 10, 0) + 9) / 10;
	}
	return (cnt <= 4 - (R - L + 1));
}

int main() {
	int T;
	int cas = 0;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; ++i) {
			int tmp = dp[i - 1] + 3;
			if(ok(i - 1, i)) {
				tmp = min(tmp, dp[i - 2] + 2);
			}
			if(ok(i - 2, i)) {
				tmp = min(tmp, dp[i - 3] + 1);
			}
			if(ok(i - 3, i)) {
				tmp = min(tmp, dp[i - 4]);
			}
			dp[i] = tmp;
		}
		//for(int i = 1; i <= n; ++i) {
		//	cout<<dp[i]<<' ';
		//}
		//cout<<endl;
		printf("Case #%d: %d\n", ++cas, dp[n]);
	}

	return 0;
}

