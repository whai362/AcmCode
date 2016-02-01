/*======================================================
# Author: whai
# Last modified: 2016-01-17 13:40
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e6 + 5;
const LL INF = 1e17;
LL w[N];
LL a[N];

bool ok(LL x, LL l, LL n, LL m, LL d) {
	int cnt = 0;

	for(int i = 0; i < n; ++i) {
		for(LL j = 0; j + w[i] <= x; j += w[i]) {
			a[cnt++] = j + w[i];
			if(cnt == l) break;
		}
		if(cnt == l) break;
	}
	return cnt == l;
}

LL cal(LL x, LL l, LL n, LL m, LL d) {
	int cnt = 0;

	for(int i = 0; i < n; ++i) {
		for(LL j = 0; j + w[i] <= x; j += w[i]) {
			a[cnt++] = j + w[i];
			if(cnt == l) break;
		}
		if(cnt == l) break;
	}
	sort(a, a + cnt);
	LL leave = m;
	LL ti = 0;
	LL maxx = 0;
	queue<LL> q;
	for(int i = 0; i < cnt; ++i) {
		if(leave > 0) {
			ti = a[i];
			q.push(ti + d);
			maxx = max(maxx, ti + d);
			--leave;
		} else {
			ti = q.front(); q.pop();
			q.push(ti + d);
			maxx = max(maxx, ti + d);
		}
	}
	return max(maxx, x);
}

void gao(LL l, LL n, LL m, LL d) {
	LL L = 2, R = 2 * 1e16;

	while(L < R) {
		LL mid = (L + R) >> 1;
		if(ok(mid, l, n, m, d)) {
			R = mid;
		} else {
			L = mid + 1;
		}
	}
	R = 2 * 1e6;
	while(L + 2 < R) {
		LL m_l = (L + R) >> 1;
		LL m_r = (m_l + R) >> 1;
		LL v_l = cal(m_l, l, n, m, d);
		LL v_r = cal(m_r, l, n, m, d);
		if(v_l < v_r) R = m_r;
		else L = m_l;
	}
	LL ans = min(cal(L, l, n, m, d), min(cal((L + R) >> 1, l, n, m, d), cal(R, l, n, m, d)));
	cout<<ans<<endl;
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		LL l, n, m, d;
		scanf("%lld%lld%lld%lld", &l, &n, &m, &d);
		for(int i = 0; i < n; ++i) {
			scanf("%lld", &w[i]);
		}
		cout<<"Case #"<<++cas<<": ";
		gao(l, n, m, d);
	}
	return 0;
}

