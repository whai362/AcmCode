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
#define P pair<LL, int>
#define X first
#define Y second

const int N = 1e6 + 5;

LL w[N];
LL a[N];
void gao(LL l, LL n, LL m, LL d) {
	priority_queue< P, vector<P>, greater<P> > pq;
	sort(w, w + n);
	for(int i = 0; i < n; ++i) {
		pq.push(P(w[i], i));
	}
	for(int i = 0; i < l; ++i) {
		P now = pq.top(); pq.pop();
		a[i] = now.X;
		pq.push(P(now.X + w[now.Y], now.Y));
	}


	queue<LL> q;
	LL maxx = 0;
	LL leave = m;
	for(int i = 0; i < l; ++i) {
		if(leave > 0) {
			LL now = a[i];
			q.push(now + d);
			maxx = max(maxx, now + d);
			--leave;
		} else {
			LL now = max(a[i], q.front()); q.pop();
			q.push(now + d);
			maxx = max(maxx, now + d);
		}
	}
	cout<<maxx<<endl;
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

