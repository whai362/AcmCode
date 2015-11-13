/*======================================================
# Author: whai
# Last modified: 2015-11-12 20:56
# Filename: bzoj1101.cpp
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

const int N = 5 * 1e4 + 5;

int mu[N];
void getMu() {
	for(int i = 1; i < N; ++i) {
		int target = i == 1 ? 1 : 0;
		int delta = target - mu[i];
		mu[i] = delta;
		for(int j = 2 * i; j < N; j += i) {
			mu[j] += delta;
		}
	}
}

int sum[N];

void predo() {
	sum[0] = 0;
	for(int i = 1; i < N; ++i) {
		sum[i] = sum[i - 1] + mu[i];
	}
}

void gao(int a, int b) {
	LL ans = 0;
	for(int i = 1, ls = 0; i <= min(a, b); i = ls + 1) {
		ls = min(a / (a / i), b / (b / i));
		ans += ((LL)sum[ls] - sum[i - 1]) * (a / i) * (b / i);
	}
	printf("%lld\n", ans);
}

int main() {
	getMu();
	predo();
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		a /= d; b /= d;
		gao(a, b);
	}
	return 0;
}
