/*======================================================
# Author: whai
# Last modified: 2015-12-09 19:49
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

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 5 * 1e5 + 5;

int a[N];
bool used[N];
int cnt[N];
LL ans = 0;

int mu[N];

void getMu() {
	for(int i = 1; i < N; ++i) {
		int tar = i == 1 ? 1 : 0;
		int delta = tar - mu[i];
		mu[i] = delta;
		for(int j = 2 * i; j < N; j += i)
			mu[j] += delta;
	}
}

void add(int x) {
	for(int i = 1; i * i <= x; ++i) {
		if(x % i == 0) {
			ans += mu[i] * cnt[i];
			int tmp = x / i;
			if(i != tmp)
				ans += mu[tmp] * cnt[tmp];
		}
	}
	for(int i = 1; i * i <= x; ++i) {
		if(x % i == 0) {
			++cnt[i];
			int tmp = x / i;
			if(i != tmp)
				++cnt[tmp];
		}
	}
}

void del(int x) {
	for(int i = 1; i * i <= x; ++i) {
		if(x % i == 0) {
			--cnt[i];
			int tmp = x / i;
			if(i != tmp)
				--cnt[tmp];
		}
	}
	for(int i = 1; i * i <= x; ++i) {
		if(x % i == 0) {
			ans -= mu[i] * cnt[i];
			int tmp = x / i;
			if(i != tmp)
				ans -= mu[tmp] * cnt[tmp];
		}
	}
}

int main() {
	getMu();
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		if(used[x] == 0) {
			add(a[x]);
			used[x] = 1;
		} else {
			del(a[x]);
			used[x] = 0;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

