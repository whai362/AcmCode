/*======================================================
# Author: whai
# Last modified: 2016-01-08 23:37
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
const int MOD = 1000000007;

int p[N];
int cnt[N];
int sum[N];

LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}


int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		++cnt[p[i]];
	}
	sort(p, p + n);
	int m = unique(p, p + n) - p;

	LL ans = 1;

	for(int i = 0; i < m; ++i) {
		for(int j = 1; j <= cnt[p[i]]; ++j) {
			ans = ans * a_b_MOD_c(a_b_MOD_c(p[i], j, MOD) % MOD, (1 << (n - cnt[p[i]])), MOD) % MOD;
		}
	}

	cout<<ans<<endl;

	return 0;
}

