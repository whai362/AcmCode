/*======================================================
# Author: whai
# Last modified: 2015-10-23 13:27
# Filename: b.cpp
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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int a[N];

int b[N], b_tot;
void lsh(int a[], int n) {
	for(int i = 0; i < n; ++i)
		b[i] = a[i];
	sort(b, b + n);
	b_tot = unique(b, b + n) - b;
	for(int i = 0; i < n; ++i)
		a[i] = lower_bound(b, b + b_tot, a[i]) - b;
}

LL dp[2][N];

int main() {
	LL n, l, k;
	scanf("%I64d%I64d%I64d", &n, &l, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	lsh(a, n);

	LL seg_num = l / n;
	int leave = l % n;
	if(leave) ++seg_num;
	else leave = n;

	LL ans = l % MOD;
	for(int i = 0; i < n; ++i) {
		++dp[0][a[i]];
	}
	int now = 1, pre = 0;
	for(int i = 1; i < min(seg_num, k); ++i) {
		dp[now][0] = 0;
		for(int j = 1; j < b_tot; ++j) {
			dp[pre][j] = (dp[pre][j] + dp[pre][j - 1]) % MOD;
			dp[now][j] = 0;
		}

		for(int j = 0; j < n; ++j) {
			dp[now][a[j]] = (dp[now][a[j]] + dp[pre][a[j]]) % MOD;
			if(j < leave) {
				ans = (ans + dp[pre][a[j]] * ((seg_num - i) % MOD)) % MOD;
			} else {
				ans = (ans + dp[pre][a[j]] * ((seg_num - i - 1) % MOD)) % MOD;
			}
		}
		swap(pre, now);
	}
	if(ans < 0) ans += MOD;
	cout<<ans<<endl;
	return 0;
}
