/*======================================================
# Author: whai
# Last modified: 2015-10-23 15:09
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 5 * 1e6 + 5;

int cnt[N];
bool used[N];
int deal(int x) {
	int ret = 0;
	for(int i = 2; i * i <= x; ++i) {
		while(x % i == 0) {
			++ret;
			x /= i;
		}
	}
	if(x > 1) ++ret;
	return ret;
}

void predo() {
	cnt[1] = 0;
	for(int i = 2; i < N; ++i) {
		if(used[i]) continue;
		cnt[i] = deal(i);

		int limit = min(i, N / i);

		for(int j = 2; j <= limit; ++j) {
			int tmp = i * j;
			if(tmp >= N) break;
			if(used[tmp]) continue;
			cnt[tmp] = cnt[i] + cnt[j];
			used[tmp] = 1;
		}
	}
	for(int i = 2; i < N; ++i) {
		cnt[i] += cnt[i - 1];
	}
}

int main() {
	predo();
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", cnt[a] - cnt[b]);
	}
	return 0;
}

