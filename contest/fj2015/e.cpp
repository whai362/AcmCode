/*======================================================
# Author: whai
# Last modified: 2015-12-27 14:34
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

int sum[N];
int cnt;
bool ok(int L, int R) {
	int nd = R - L + 1 - (sum[R] - sum[L - 1]);
	return nd <= cnt;
}

int deal(int x) {
	int L = 1, R = x;
	int ret = 0;
	while(L < R) {
		int mid = (L + R) >> 1;
		if(ok(mid, x)) {
			ret = max(ret, x - mid + 1);
			R = mid;
		} else {
			L = mid + 1;
		}
	}
	if(ok(L, x)) ret = max(ret, x - L + 1);
	if(ok(R, x)) ret = max(ret, x - R + 1);
	return ret;
}

void init() {
	cnt = 0;
	memset(sum, 0, sizeof(sum));
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		init();
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if(x == 0) ++cnt;
			else {
				sum[x] = 1;
			}
		}
		for(int i = 1; i <= m; ++i) {
			sum[i] += sum[i - 1];
		}
		int ans = 1;

		for(int i = 1; i <= m; ++i) {
			ans = max(ans, deal(i));
		}
		cout<<ans<<endl;
	}
	return 0;
}

