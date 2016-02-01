/*======================================================
# Author: whai
# Last modified: 2016-01-11 15:24
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
#define P pair<LL, LL>
#define X first
#define Y second
#define MP make_pair

const int N = 2005;

P a[N];

map< pair<P, LL>, int > cnt;
map< pair<P, LL>, int > :: iterator it;

LL sqr(LL x) {
	return x * x;
}

LL dis(P a, P b) {
	return sqr(a.X - b.X) + sqr(a.Y - b.Y);
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%lld%lld", &a[i].X, &a[i].Y);
		}
		cnt.clear();
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				LL d = dis(a[i], a[j]);
				++cnt[MP(a[i], d)];
				++cnt[MP(a[j], d)];
			}
		}
		LL ans = 0;
		for(it = cnt.begin(); it != cnt.end();  ++it) {
			LL tmp = (*it).Y;
			ans += tmp * (tmp - 1) / 2;
		}
		cout<<"Case #"<<++cas<<": ";
		cout<<ans<<endl;
	}
	return 0;
}

