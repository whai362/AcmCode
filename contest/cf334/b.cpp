/*======================================================
# Author: whai
# Last modified: 2015-12-01 23:49
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
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

int s[N];

bool ok(int x, int k, int n) {
	int p = n - 1, q = 0;
	if(s[p] > x) return false;
	int cnt = 0;
	while(p >= q) {
		if(p != q && s[p] + s[q] <= x) {
			--p;
			++q;
		} else {
			--p;
		}
		++cnt;
	}
	//cout<<cnt<<endl;
	return cnt <= k;
}

void gao(int n, int k) {
	//cout<<ok(9, k, n)<<endl;
	int L = 0, R = 2 * 1e6 + 5;
	while(L < R) {
		int mid = (L + R) >> 1;
		if(ok(mid, k, n)) {
			R = mid;
		} else {
			L = mid + 1;
		}
	}
	int ans = R;
	if(ok(L, k, n)) ans = min(ans, L);
	cout<<ans<<endl;
}

int main() {
	int n, k;
	while(cin>>n>>k) {
		for(int i = 0; i < n; ++i) {
			cin>>s[i];
		}
		gao(n, k);
	}
	return 0;
}

