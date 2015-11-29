/*======================================================
# Author: whai
# Last modified: 2015-11-23 20:47
# Filename: c.cpp
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

int a[N];
int b[N];

map<int, int> cnt;

void gao(int n) {
	sort(b, b + n);
	int ans = 0;
	int p = n - 1;
	while(p >= 0) {
		int ok = 0;
		++cnt[b[p]];
		if(cnt[b[p]] == 0) --ok;
		if(cnt[b[p]] == 1) ++ok;
		--cnt[a[p]];
		if(cnt[a[p]] == 0) --ok;
		if(cnt[a[p]] == -1) ++ok;
		while(p >= 0 && ok) {
			--p;
			++cnt[b[p]];
			if(cnt[b[p]] == 0) --ok;
			if(cnt[b[p]] == 1) ++ok;
			--cnt[a[p]];
			if(cnt[a[p]] == 0) --ok;
			if(cnt[a[p]] == -1) ++ok;
		}
		//cout<<p<<' ';
		++ans;
		--p;
	}
	//cout<<endl;
	cout<<ans<<endl;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		gao(n);
	}
	return 0;
}

