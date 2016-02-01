/*======================================================
# Author: whai
# Last modified: 2015-12-27 16:13
# Filename: h.cpp
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

bool cmp(int a, int b) {
	return a > b;
}

int t[N];
LL a[N];
bool ok(LL x, int n, int m, int k) {
	for(int i = 0; i < n; ++i) {
		a[i] = x - t[i];
		if(a[i] < 0) return false;
	}
	
	LL have = m;
	int t = 0;
	for(int i = 0; i < n; ++i) {
		while(t + k <= a[i] && have < n) {
			have *= 2;
			t += k;
		}
		--have;
		if(have < 0) return false;
		if(i < n - 1 && have <= 0) return false;
	}
	return true;
}

void gao(int n, int m, int k) {
	LL L = 0, R = 1e18;
	LL ans = R;
	while(L < R) {
		LL mid = (L + R) >> 1;
		if(ok(mid, n, m, k)) {
			ans = min(ans, mid);
			R = mid;
		} else {
			L = mid + 1;
		}
	}
	if(ok(L, n, m, k)) {
		ans = min(ans, L);
	} else {
		ans = min(ans, R);
	}
	cout<<ans<<endl;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &t[i]);
		}
		sort(t, t + n, cmp);
		gao(n, m, k);
	}
	return 0;
}

